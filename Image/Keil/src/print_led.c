//------------------------------------------------------------------------------
// $COPYRIGHT
//------------------------------------------------------------------------------
//  Description : C print to led functions for simple string and complex printf 
//------------------------------------------------------------------------------

#include "messages.h"     // address map defines - to get LED address
#include <stddef.h>            // headers for the print functions
#include <stdarg.h>           // support variable length arguments (printf)
#include <debug_define.h>
#include "sh32f0xx_usart.h"

//char * my_i16toa(int n, char *buf);
//
typedef unsigned long long        uint64_t;
//typedef unsigned long	          uint32_t;
typedef long long	              int64_t;


static inline int is_digit(int ch)
{
        return (ch >= '0') && (ch <= '9');
}

//
size_t strnlen(const char *s, size_t count)
{
         const char *sc;
 
         for (sc = s; count-- && *sc != '\0'; ++sc)
                 /* nothing */;
         return sc - s;
}
 
uint32_t __attribute__((weak)) __div64_32(uint64_t *n, uint32_t base)
{
        uint64_t rem = *n;
        uint64_t b = base;
        uint64_t res, d = 1;
        uint32_t high = rem >> 32;

        /* Reduce the thing a bit first */
        res = 0;
        if (high >= base) {
                high /= base;
                res = (uint64_t) high << 32;
                rem -= (uint64_t) (high*base) << 32;
        }

        while ((int64_t)b > 0 && b < rem) {
                b = b+b;
                d = d+d;
        }

        do {
                if (rem >= b) {
                        rem -= b;
                        res += d;
                }
                b >>= 1;
                d >>= 1;
        } while (d);

        *n = res;
        return rem;
}


 
 /* The unnecessary pointer compare is there
  * to check for type safety (n must be 64bit)
  */

 # define do_div(n,base) ({                                              \
         unsigned int __base = (base);                                   \
         unsigned int __rem;                                             \
         (void)(((typeof((n)) *)0) == ((unsigned long long *)0));        \
         if (((n) >> 32) == 0) {                                         \
                 __rem = (unsigned int)(n) % __base;                     \
                 (n) = (unsigned int)(n) / __base;                       \
         } else                                                          \
                 __rem = __div64_32(&(n), __base);                       \
         __rem;                                                          \
  })

  
 static int skip_atoi(const char **s)
 {
    int i=0;

    while (is_digit(**s))
        i = i*10 + *((*s)++) - '0';
    return i;
 }
 
 #define ZEROPAD 1               /* pad with zero */
 #define SIGN    2               /* unsigned/signed long */
 #define PLUS    4               /* show plus */
 #define SPACE   8               /* space if plus */
 #define LEFT    16              /* left justified */
 #define SPECIAL 32              /* 0x */
 #define LARGE   64              /* use 'ABCDEF' instead of 'abcdef' */
 
 static char * number(char * str, unsigned long long num, int base, int size, int precision, int type)
 {
         char c,sign,tmp[66];
         const char *digits="0123456789abcdefghijklmnopqrstuvwxyz";
         int i;
 
         if (type & LARGE)
                 digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
         if (type & LEFT)
                 type &= ~ZEROPAD;
         if (base < 2 || base > 36)
                 return 0;
         c = (type & ZEROPAD) ? '0' : ' ';
         sign = 0;
         if (type & SIGN) {
                 if ((signed long long)num < 0) {
                         sign = '-';
                         num = - (signed long long)num;
                         size--;
                 } else if (type & PLUS) {
                         sign = '+';
                         size--;
                 } else if (type & SPACE) {
                         sign = ' ';
                         size--;
                 }
         }
         if (type & SPECIAL) {
                 if (base == 16)
                         size -= 2;
                 else if (base == 8)
                         size--;
         }
         i = 0;
         if (num == 0)
                 tmp[i++]='0';
         else while (num != 0) {
                 tmp[i++] = digits[do_div(num, base)];
         }
         if (i > precision)
                 precision = i;
         size -= precision;
         if (!(type&(ZEROPAD+LEFT)))
                 while(size-->0)
                         *str++ = ' ';
         if (sign)
                 *str++ = sign;
         if (type & SPECIAL) {
                 if (base==8)
                         *str++ = '0';
                 else if (base==16) {
                         *str++ = '0';
                         *str++ = digits[33];
                 }
         }
         if (!(type & LEFT))
                 while (size-- > 0)
                         *str++ = c;
         while (i < precision--)
                 *str++ = '0';
         while (i-- > 0)
                 *str++ = tmp[i];
         while (size-- > 0)
                 *str++ = ' ';
         return str;
 }
 
 int vsprintf(char *buf, const char *fmt, va_list args)
 {
         int len;
         unsigned long long num;
         int i, base;
         char * str;
         const char *s;
 
         int flags;              /* flags to number() */
 
         int field_width;        /* width of output field */
         int precision;          /* min. # of digits for integers; max
                                    number of chars for from string */
         int qualifier;          /* 'h', 'l', or 'L' for integer fields */
                                 /* 'z' support added 23/7/1999 S.H.    */
                                 /* 'z' changed to 'Z' --davidm 1/25/99 */
 
         
         for (str=buf ; *fmt ; ++fmt) {
                 if (*fmt != '%') {
                         *str++ = *fmt;
                         continue;
                 }
                         
                 /* process flags */
                 flags = 0;
                 repeat:
                         ++fmt;          /* this also skips first '%' */
                         switch (*fmt) {
                                 case '-': flags |= LEFT; goto repeat;
                                 case '+': flags |= PLUS; goto repeat;
                                 case ' ': flags |= SPACE; goto repeat;
                                 case '#': flags |= SPECIAL; goto repeat;
                                 case '0': flags |= ZEROPAD; goto repeat;
                                 }
                 
                 /* get field width */
                 field_width = -1;
                 if (is_digit(*fmt)) //if ('0' <= *fmt && *fmt <= '9')
		    field_width = skip_atoi(&fmt);
                 else if (*fmt == '*') {
                         ++fmt;
                         /* it's the next argument */
                         field_width = va_arg(args, int);
                         if (field_width < 0) {
                                 field_width = -field_width;
                                 flags |= LEFT;
                         }
                 }
 
                 /* get the precision */
                 precision = -1;
                 if (*fmt == '.') {
                         ++fmt;  
                         if (is_digit(*fmt))//if ('' <= *fmt && *fmt <= '9')
                                 precision = skip_atoi(&fmt);
                         else if (*fmt == '*') {
                                 ++fmt;
                                 /* it's the next argument */
                                 precision = va_arg(args, int);
                         }
                         if (precision < 0)
                                 precision = 0;
                 }
 
                 /* get the conversion qualifier */
                 qualifier = -1;
                 if (*fmt == 'l' && *(fmt + 1) == 'l') {
                         qualifier = 'q';
                         fmt += 2;
                 } else if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L'
                         || *fmt == 'Z') {
                         qualifier = *fmt;
                         ++fmt;
                 }
 
                 /* default base */
                 base = 10;
 
                 switch (*fmt) {
                 case 'c':
                         if (!(flags & LEFT))
                                 while (--field_width > 0)
                                         *str++ = ' ';
                         *str++ = (unsigned char) va_arg(args, int);
                         while (--field_width > 0)
                                 *str++ = ' ';
                         continue;
 
                 case 's':
                         s = va_arg(args, char *);
                         if (!s)
                                 s = "<NULL>";
 
                         len = strnlen(s, precision);
 
                         if (!(flags & LEFT))
                                 while (len < field_width--)
                                         *str++ = ' ';
                         for (i = 0; i < len; ++i)
                                 *str++ = *s++;
                         while (len < field_width--)
                                 *str++ = ' ';
                         continue;
 
                 case 'p':
                         if (field_width == -1) {
                                 field_width = 2*sizeof(void *);
                                 flags |= ZEROPAD;
                         }
                         str = number(str,
                                 (unsigned long) va_arg(args, void *), 16,
                                 field_width, precision, flags);
                         continue;
 
 
                 case 'n':
                         if (qualifier == 'l') {
                                 long * ip = va_arg(args, long *);
                                 *ip = (str - buf);
                         } else if (qualifier == 'Z') {
                                 size_t * ip = va_arg(args, size_t *);
                                 *ip = (str - buf);
                         } else {
                                 int * ip = va_arg(args, int *);
                                 *ip = (str - buf);
                         }
                         continue;
 
                 case '%':
                         *str++ = '%';
                         continue;
 
                 /* integer number formats - set up the flags and "break" */
                 case 'o':
                         base = 8;
                         break;
 
                 case 'X':
                         flags |= LARGE;
                 case 'x':
                         base = 16;
                         break;
 
                 case 'd':
                 case 'i':
                         flags |= SIGN;
                 case 'u':
                         break;
 
                 default:
                         *str++ = '%';
                         if (*fmt)
                                 *str++ = *fmt;
                         else
                                 --fmt;
                         continue;
                 }
                 if (qualifier == 'l') {
                         num = va_arg(args, unsigned long);
                         if (flags & SIGN)
                                 num = (signed long) num;
                 } else if (qualifier == 'q') {
                         num = va_arg(args, unsigned long long);
                         if (flags & SIGN)
                                 num = (signed long long) num;
                 } else if (qualifier == 'Z') {
                         num = va_arg(args, size_t);
                 } else if (qualifier == 'h') {
                         num = (unsigned short) va_arg(args, int);
                         if (flags & SIGN)
                                 num = (signed short) num;
                 } else {
                         num = va_arg(args, unsigned int);
                         if (flags & SIGN)
                                 num = (signed int) num;
                 }
                 str = number(str, num, base, field_width, precision, flags);
         }
         *str = '\0';
         return str-buf;
 }

//------------------------------------------------------------------------------
//  functions
//------------------------------------------------------------------------------

  // step_debug - 
 void print_step(char step_num) {
      //*(volatile char *)STEP_DEBUG_VISION = step_num;
      *(volatile char *)LED_REG_BASE = step_num;
  } // void print_step()

  void printf_step(char step_num, const char *fmt, ...) {
    int i;
    char    print_buffer[1024];
    char    pre_buffer1[]="The ";
    char    pre_buffer2[]="th Step: ";
    va_list ap;

    for(i=0;pre_buffer1[i] != '\0';i++) {
      *(volatile char *)LED_REG_BASE = pre_buffer1[i];
    }
    *(volatile char *)LED_REG_BASE = (char)(step_num+'0');
    for(i=0;pre_buffer2[i] != '\0';i++) {
      *(volatile char *)LED_REG_BASE = pre_buffer2[i];
    }
    
    va_start (ap, fmt);
    vsprintf (print_buffer, fmt, ap);
    va_end (ap);

    //*(volatile char *)STEP_DEBUG_VISION = step_num;
    *(volatile char *)LED_REG_BASE = step_num;
    
    for(i=0;print_buffer[i] != '\0';i++) {
      *(volatile char *)LED_REG_BASE = print_buffer[i];
    }
  } // void printf_step()

void print_enable(void)
{
	#if Channel == 1
	GPIOA->MODER |= 0x0400;
	GPIOA->DIRR  |= 0x0400;
	GPIOA->AFRH  |= 0x00000200;   // PA10
	
	USART1->US_BRGR = 130;        // 25M/162/16=9600;162=0xA2
	USART1->US_MR   = 0x000000C0;		
	#endif
	
	#if Channel == 2
	GPIOB->MODER |= 0x0100;
	GPIOB->DIRR  |= 0x0100;
	GPIOB->AFRH  |= 0x00000002;   // PB8
	
	USART2->US_BRGR = 130;        // 25M/162/16=9600;162=0xA2
	USART2->US_MR   = 0x000000C0;	
	#endif
}

  // print_led - print any size constant array of characters to the LED driver
  //           - faster than printf_led but less robust
/*  
 void print_led(char string_val []) {
    int i;
    for(i=0;string_val[i] != '\0';i++) {
      *(volatile char *)LED_REG_BASE = string_val[i];
    }
  } 
*/
void print_led(char string_val []) 
{  
  	int i;
	USART_TypeDef* USART_O;
	
	#if Channel == 1
	USART_O = USART1;
	#elif Channel == 2
	USART_O = USART2;
	#endif
	
	USART_O->US_CR = 0X0000000C; 
	USART_O->US_CR = 0X00000040; 
	
    for(i=0;string_val[i] != '\0';i++) 
	{
		while((USART_O->US_CSR & 0X00000002) == 0){};
		USART_O->US_THR = string_val[i];
		while((USART_O->US_CSR & 0x00000200) == 0x00000200){};
    }
	
	for(i = 0;i<20000;i++)
	{
		//__ISB();
	}
	
}
 void print_nothing(char string_val []) {

  } // void print_nothing()



  // prinf_led - printf type support outputting to the LED driver
  //            - requires stdio.h and stdarg.h to be included
  //            - slower than print_led but more robust
/*
  void printf_led(const char *fmt, ...) {
    int i;
    char    print_buffer[1024];
    va_list ap;
    
    va_start (ap, fmt);
    vsprintf (print_buffer, fmt, ap);
    va_end (ap);

    // the write through region must be set for the LED driver to display > 1
    
    for(i=0;print_buffer[i] != '\0';i++) {
      *(volatile char *)LED_REG_BASE = print_buffer[i];
    }
  } // void printf_led()

  void printf_nothing(const char *fmt, ...) {

  } //
 */
void printf_led(const char *fmt, ...) 
{
    int i;
    char print_buffer[1024];
	USART_TypeDef* USART_O;
	
	#if Channel == 1
	USART_O = USART1;
	#elif Channel == 2
	USART_O = USART2;
	#endif
	
    va_list ap;
    
    va_start (ap, fmt);
    vsprintf (print_buffer, fmt, ap);
    va_end (ap);

    // the write through region must be set for the LED driver to display > 1
    
	USART_O->US_CR = 0X0000000C; 
	USART_O->US_CR = 0X00000040; 
    for(i=0;print_buffer[i] != '\0';i++) 
	{
		while((USART_O->US_CSR & 0X00000002) == 0){};
		USART_O->US_THR = print_buffer[i];
		while((USART_O->US_CSR & 0x00000200) == 0x00000200){};
    }
			
	for(i = 0;i<20000;i++)
	{
		__ISB();
	}
} // void printf_led()

#ifdef DEBUG_VERB
  void print_verb(char string_val []) {
    int i;
    for(i=0;string_val[i] != '\0';i++) {
      *(volatile char *)LED_REG_BASE = string_val[i];
      //*(vu8 *) 0xe0047f00 = string_val[i];
    }
  }

  void printf_verb(const char *fmt, ...) {
    int i;
    char    print_buffer[1024];
    va_list ap;
    
    va_start (ap, fmt);
    vsprintf (print_buffer, fmt, ap);
    va_end (ap);

    // the write through region must be set for the LED driver to display > 1
    
    for(i=0;print_buffer[i] != '\0';i++) {
      *(volatile char *)LED_REG_BASE = print_buffer[i];
    }
  } // void printf_led()

  void print_info(char string_val []) {
    int i;
    for(i=0;string_val[i] != '\0';i++) {
      *(volatile char *)LED_REG_BASE = string_val[i];
      //*(vu8 *) 0xe0047f00 = string_val[i];
    }
  } 

  void printf_info(const char *fmt, ...) {
    int i;
    char    print_buffer[1024];
    va_list ap;
    
    va_start (ap, fmt);
    vsprintf (print_buffer, fmt, ap);
    va_end (ap);

    // the write through region must be set for the LED driver to display > 1
    
    for(i=0;print_buffer[i] != '\0';i++) {
      *(volatile char *)LED_REG_BASE = print_buffer[i];
    }
  } // void printf_led()

  void print_error(char string_val []) {
    int i;
    print_led("\nERRor Occurs:  ");
    for(i=0;string_val[i] != '\0';i++) {
      *(volatile char *)LED_REG_BASE = string_val[i];
      //*(vu8 *) 0xe0047f00 = string_val[i];
    }
  } 

  void printf_error(const char *fmt, ...) {
    int i;
    char    print_buffer[1024];
    va_list ap;
    
    print_led("\nERRor Occurs:  ");

    va_start (ap, fmt);
    vsprintf (print_buffer, fmt, ap);
    va_end (ap);

    // the write through region must be set for the LED driver to display > 1
    
    for(i=0;print_buffer[i] != '\0';i++) {
      *(volatile char *)LED_REG_BASE = print_buffer[i];
    }
  } // void printf_led()

      void print_finish(char string_val []) {
        int i;
        print_led("Success:  ");
        for(i=0;string_val[i] != '\0';i++) {
          *(volatile char *)LED_REG_BASE = string_val[i];
          //*(vu8 *) 0xe0047f00 = string_val[i];
        }
      }

      void printf_finish(const char *fmt, ...) {
        int i;
        char    print_buffer[1024];
        va_list ap;

        print_led("\nSuccess:  ");

        va_start (ap, fmt);
        vsprintf (print_buffer, fmt, ap);
        va_end (ap);

        // the write through region must be set for the LED driver to display > 1
        
        for(i=0;print_buffer[i] != '\0';i++) {
          *(volatile char *)LED_REG_BASE = print_buffer[i];
        }
      } // void printf_led()

#else
  #ifdef DEBUG_INFO
      void print_verb(char string_val []) {

      } 

      void printf_verb(const char *fmt, ...) {

      } 

      void print_info(char string_val []) {
        int i;
        for(i=0;string_val[i] != '\0';i++) {
          *(volatile char *)LED_REG_BASE = string_val[i];
          //*(vu8 *) 0xe0047f00 = string_val[i];
        }
      } 

      void printf_info(const char *fmt, ...) {
        int i;
        char    print_buffer[1024];
        va_list ap;
        
        va_start (ap, fmt);
        vsprintf (print_buffer, fmt, ap);
        va_end (ap);

        // the write through region must be set for the LED driver to display > 1
        
        for(i=0;print_buffer[i] != '\0';i++) {
          *(volatile char *)LED_REG_BASE = print_buffer[i];
        }
      } 

      void print_error(char string_val []) {
        int i;
        print_led("\nERRor Occurs:  ");
        for(i=0;string_val[i] != '\0';i++) {
          *(volatile char *)LED_REG_BASE = string_val[i];
          //*(vu8 *) 0xe0047f00 = string_val[i];
        }
      } 

      void printf_error(const char *fmt, ...) {
        int i;
        char    print_buffer[1024];
        va_list ap;

        print_led("\nERRor Occurs:  ");
        
        va_start (ap, fmt);
        vsprintf (print_buffer, fmt, ap);
        va_end (ap);

        // the write through region must be set for the LED driver to display > 1
        
        for(i=0;print_buffer[i] != '\0';i++) {
          *(volatile char *)LED_REG_BASE = print_buffer[i];
        }
      } // void printf_led()

      void print_finish(char string_val []) {
        int i;
        print_led("\nSuccess:  ");
        for(i=0;string_val[i] != '\0';i++) {
          *(volatile char *)LED_REG_BASE = string_val[i];
          //*(vu8 *) 0xe0047f00 = string_val[i];
        }
      } 

      void printf_finish(const char *fmt, ...) {
        int i;
        char    print_buffer[1024];
        va_list ap;

        print_led("\nSuccess:  ");

        va_start (ap, fmt);
        vsprintf (print_buffer, fmt, ap);
        va_end (ap);

        // the write through region must be set for the LED driver to display > 1
        
        for(i=0;print_buffer[i] != '\0';i++) {
          *(volatile char *)LED_REG_BASE = print_buffer[i];
        }
      } // void printf_led()


  #else
  
      #ifdef DEBUG_ERROR
          void print_verb(char string_val []) {

          } 

          void printf_verb(const char *fmt, ...) {

          }

          void print_info(char string_val []) {
          }

          void printf_info(const char *fmt, ...) {

          } // void printf_led()

          void print_error(char string_val []) {
            int i;
            print_led("\nERRor Occurs:  ");
            for(i=0;string_val[i] != '\0';i++) {
              *(volatile char *)LED_REG_BASE = string_val[i];
              //*(vu8 *) 0xe0047f00 = string_val[i];
            }
          } 

          void printf_error(const char *fmt, ...) {
            int i;
            char    print_buffer[1024];
            va_list ap;
            
            print_led("\nERRor Occurs:  ");

            va_start (ap, fmt);
            vsprintf (print_buffer, fmt, ap);
            va_end (ap);

            // the write through region must be set for the LED driver to display > 1
            
            for(i=0;print_buffer[i] != '\0';i++) {
              *(volatile char *)LED_REG_BASE = print_buffer[i];
            }
          } // void printf_led()

      void print_finish(char string_val []) {
        int i;
        print_led("\nSuccess:  ");
        for(i=0;string_val[i] != '\0';i++) {
          *(volatile char *)LED_REG_BASE = string_val[i];
          //*(vu8 *) 0xe0047f00 = string_val[i];
        }
      } 

      void printf_finish(const char *fmt, ...) {
        int i;
        char    print_buffer[1024];
        va_list ap;

        
        print_led("\nSuccess:  ");

        va_start (ap, fmt);
        vsprintf (print_buffer, fmt, ap);
        va_end (ap);

        // the write through region must be set for the LED driver to display > 1
        
        for(i=0;print_buffer[i] != '\0';i++) {
          *(volatile char *)LED_REG_BASE = print_buffer[i];
        }
      } // void printf_led()

      #else

          void print_verb(char string_val []) {}

          void printf_verb(const char *fmt, ...) {}

          void print_info(char string_val []) {}

          void printf_info(const char *fmt, ...) {}

          void print_error(char string_val []) {}

          void printf_error(const char *fmt, ...) {}

          void print_finish(char string_val []) {}

          void printf_finish(const char *fmt, ...) {}
      #endif
        
  #endif

#endif




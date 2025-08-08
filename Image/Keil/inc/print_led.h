
//------------------------------------------------------------------------------
//  Description : C header for led functions for string and complex printf 
//------------------------------------------------------------------------------

  extern void print_enable(void);
  extern void print_led(char string_val []);
  extern void print_nothing(char string_val []);
  extern void printf_led(const char *fmt, ...);
  extern void printf_nothing(const char *fmt, ...);
  extern void print_error(char string_val []);
  extern void printf_error(const char *fmt, ...);
  extern void print_info(char string_val []);
  extern void printf_info(const char *fmt, ...);
  extern void print_verb(char string_val []);
  extern void printf_verb(const char *fmt, ...);
  extern void print_finish(char string_val []);
  extern void printf_finish(const char *fmt, ...);

  extern void print_step(char step);  
  extern void printf_step(char step, const char *fmt, ...);

#define print_ok        print_finish
#define print_pass      print_finish

#define printf_ok       printf_finish
#define printf_pass     printf_finish


//------------------------------------------------------------------------------
// $Id: print_led.h,v 1.1 2017/03/15 01:49:12 fanwei Exp $
//------------------------------------------------------------------------------


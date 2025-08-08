
.include "messages.i"


.text

.global _halt_pass
.global _halt_fail
.global _write_ch
.global _write_msg
.global _write_msg_code
.global _exit_monitor  


/* 
** Exit monitor
** Input parameters:  None
** Output parameters: None
** Clobbers 	   :  r0, r1
** Notes: Never exits.
*/

_exit_monitor:
	LDR 	r1, =ARM_TERMINATE
	LDR 	r0, =LED_REG_BASE 
	STRH 	r1, [r0]	/* Write output char */
	LDRH 	r1, [r0]    /* Read it back so we can't leave until write happened */
	LDR 	r1, =QUIT
	STRH 	r1, [r0]	/* Write output char */
	LDRH 	r1, [r0]    /* Read it back so we can't leave until write happened */
	B       spin

/* 
** Write test pass message and exit
** Input parameters:  None
** Output parameters: None
**
** Clobbers 	   :  r0, r1
*/
_halt_pass:
	LDR	r1, =ARM_PASS
	LDR	r0, =LED_REG_BASE 
	STRH	r1, [r0]	/* Write output char */
    LDRH	r1, [r0]	/* Read it back so we can't leave until write happened */
    B 	_exit_monitor

/* 
** Write test fail message and exit
** Input parameters:  None
** Output parameters: None
**
** Clobbers 	   :  r0, r1
*/
_halt_fail:
	LDR	r1, =ARM_FAIL
	LDR	r0, =LED_REG_BASE 
	STRH	r1, [r0]	/* Write output char */
    LDRH	r1, [r0]	/* Read it back so we can't leave until write happened */
    B 	_exit_monitor

/* This loop is just to stop the processor running to undefined memory. */
spin:	
        NOP
	B      spin

/*
** write_msg_code (int msgcode)
**
** Input parameters: r1 - message code
** Output parameters: None
**
** Clobbers 	   :  r0, r1
*/
__FUNC_START__write_msg_code:
LnewLabel0:
        .align 4
_write_msg_code:
	LDR 	r1, =LED_REG_BASE 
    STRH	r0, [r1]		/* Write output char */
	LDRH	r0, [r1]		/* Read it back so we can't leave until write happened */

__FUNC_END__write_msg_code:
	BX      lr
/*EPILOGUE */
	
/*
** _write_ch(char msg)
** Character output routine. 
** Input parameters: r4 contains output character.
** Output parameters: None
**
** Clobbers: r0, r1 (complies with C calling convention).
*/
__FUNC_START__write_ch:
LnewLabel1:
        .align 4
_write_ch:
	LDR 	r1, =LED_REG_BASE 
    STRB	r0, [r1]		/* Write output char */
	LDRB	r0, [r1]		/* Read it back so we can't leave until write happened */
__FUNC_END__write_ch:
	BX      lr
/*EPILOGUE */

/*
** write_msg(char *msg)
** Message output routine. 
** Input parameters: r0 - points to output message in internal data memory space.
** Output parameters: None
**
** Clobbers: r0,r1,r2,r3 
*/
__FUNC_START__write_msg:
LnewLabel2:
        .align 4
_write_msg:
	LDR 	r1, =LED_REG_BASE 
ch_loop:
	/*LDRB	r3, [r0], #1		Get next character to output */
	LDRB	r3, [r0]        /* Get next character to output */
    ADD     r0, #1
	CMP	r3, #0			/* Always terminate if 0 found */
	BEQ	exit_msg		/* in case a string from a C program is passed. */

LnewLabel3:
	CMP	r3, #10			/* Always terminate when \n found */
	STRB	r3, [r1]	/* Write output char */
	LDRB	r3, [r1]	/* Read last char back so we can't leave until write happened*/
	BNE	ch_loop
exit_msg:

__FUNC_END__write_msg:
	BX      lr
/*EPILOGUE*/

.end


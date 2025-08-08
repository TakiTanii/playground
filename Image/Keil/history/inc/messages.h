// Global Signal
#define QUIT             0x00       // "NULL Char detected by led_model"; 
// ARM Signal 
#define ARM_START        0x80       // "Test start by ARM";
#define ARM_FINISH       0x81       // "Test complete by ARM";
#define ARM_FAIL         0x82       // "Msg code FAIL by ARM";
#define ARM_PASS         0x83       // "Msg code PASS by ARM";     
#define ARM_SLEEP        0x84       // "ARM entering sleep mode";
#define ARM_IDLE         0x85       // "ARM entering idle mode";
#define ARM_TSSTART      0x86       // "Test shell started by ARM";
#define ARM_DEAD         0x87       // "Test has failed by ARM";
#define ARM_ACED         0x88       // "Test has passed by ARM";
#define ARM_TERMINATE    0x89       // "Test terminated by ARM";
#define ARM_TSUNEXPECTED 0x8a       // "Unexpected return to Test Shell by ARM";
#define ARM_MAIN         0x8b       // "Enter into __main by ARM"
#define ARM_UND_TIPS     0x90       // "ARM interrupt und entering";
#define ARM_SWI_TIPS     0x91       // "ARM interrupt swi entering";
#define ARM_PABT_TIPS    0x92       // "ARM interrupt prefetch abort entering";
#define ARM_DABT_TIPS    0x93       // "ARM interrupt data abort entering";
#define ARM_IRQ_TIPS     0x94       // "ARM interrupt irq entering";
#define ARM_FIQ_TIPS     0x95       // "ARM interrupt fiq entering";


//#define LED_REG_BASE         0xE0047F00
#define LED_REG_BASE         0x400223F0           /*GPIO high addr*/

/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "include.h"


#if defined (__ghs__)
    #define __INTERRUPT_SVC  __interrupt
    #define __NO_RETURN _Pragma("ghs nowarning 111")
#elif defined (__ICCARM__)
    #define __INTERRUPT_SVC  __svc
    #define __NO_RETURN _Pragma("diag_suppress=Pe111")
#elif defined (__GNUC__)
    #define __INTERRUPT_SVC  __attribute__ ((interrupt ("SVC")))
    #define __NO_RETURN
#else
    #define __INTERRUPT_SVC
    #define __NO_RETURN
#endif

int main(void)
{
    SPLL_Init(PLL160);
    UART_Init(LPUART0, 115200);

    printf("This is my first test with S32K144\r\n");

    Test_LED();

    return 0;
}

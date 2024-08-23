#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_common.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include <FreeRTOS.h>
#include "semphr.h"
#include "usbh_core.h"

int main(void)
{
    BOARD_InitBootPins();
    BOARD_PowerMode_OD();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    CLOCK_SetupExtClocking(BOARD_XTAL0_CLK_HZ);
    
    usbh_initialize(0, USBHS1__USBC_BASE);
    vTaskStartScheduler();
    while (1)
    {
        ;
    }
}
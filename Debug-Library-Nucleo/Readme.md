## Debug Library For Nucleo Boards

Nucleo board comes with ST-Link and their STM32's UART2 pins are connected with ST-Link, which enables serial data transfer via UART. Just include this library, and pass the uart's address which is configured for the data transfer.

And you can use uprintf(char *) to print by passing an array of character to this function.

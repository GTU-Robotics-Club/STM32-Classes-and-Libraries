# STM32 Classes and Libraries

## Note: All the libraries developed here are compatible aadn tested with STM32F407VG and STM32F103RB, in order to make them compatible with your own board, just replace the `#include <stm32f4xx.h>` or `#include <stm32f1xx.h>` with your own board.

## 1. Motor Class (17-03-2021)

This class is compatible with `Cytron` and `Hercules` Motor Driver.

I'll be creating a tutorial on how to use this class soon.

## 2. Encoder Class (19-03-2021)

Library for interfacing `incremental encoders` with STM32, tested with STM32F103RB. 

This library solves the existing limitations, and gives us positive as well as negative values, also the encoder values are not limited up to 16-bits.

## 3. Base Class (21-03-2021)

Added base Library, supports Omni "like" bases. Tested on Omni Base as well.

I'll be adding the main project code which we'd tested on the bot, and some description on how to use all the mentioned libraries.

## 4. MPU6050 Library (21-03-2021)

Library for using `MPU6050` with STM32.

[-] Issues : For now we are just getting the value form the registers and returning them. 

[+] To do 
* Callibration of MPU.
* Returning the `euler angles`.

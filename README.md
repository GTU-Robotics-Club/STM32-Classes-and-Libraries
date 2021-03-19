# STM32 Classes and Libraries

## Note: All the libraries developed here are compatible with STM32F407VG, in order to make them compatible with your own board, just replace the `#include <stm32f4xx.h>` with your own board.

## 1. Motor Class (17-03-2021)

This class is compatible with `Cytron` and `Hercules` Motor Driver.

I'll be creating a tutorial on how to use this class soon.

## 2. Encoder Class (19-03-2021)

Library for interfacing `incremental encoders` with STM32, tested with STM32F103RB. 

This library solves the existing limitations, and gives us positive as well as negative values, also the encoder values are not limited up to 16-bits.

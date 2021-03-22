# STM32 Classes and Libraries

## Note: All the libraries developed here are compatible and tested with STM32F407VG and STM32F103RB, in order to make them compatible with your own board, just replace the `#include <stm32f4xx.h>` or `#include <stm32f1xx.h>` with your own board.

## 1. Motor Library (17-03-2021)

This class is compatible with `Cytron` and `Hercules` Motor Driver.

I'll be creating a tutorial on how to use this class soon.

## 2. Encoder Library (19-03-2021)

Library for interfacing `incremental encoders` with STM32, tested with STM32F103RB. 

This library solves the existing limitations, and gives us positive as well as negative values, also the encoder values are not limited up to 16-bits.

## 3. Base Library (21-03-2021)

Added base Library, supports Omni "like" bases. Tested on Omni Base as well.

I'll be adding the main project code which we'd tested on the bot, and some description on how to use all the mentioned libraries.

## 4. MPU6050 Library (21-03-2021)

Library for using `MPU6050` with STM32.

[-] Issues : For now we are just getting the value form the registers and returning them. 

[+] To do 
* Callibration of MPU.
* Returning the `euler angles`.

## 5. Base Code (21-03-2021)

The base code can be found in `Bot_STM32`. The `main.cpp` file is located in `Bot_STM32/Core/Src/main.ino` (Note : the `.h` and `.cpp` files will be organized properly, this is just for testing purposes, don't follow this style!!).

Below are the pinouts used in this project.

![Pin Outs](https://i.ibb.co/GVr5s44/Whats-App-Image-2021-03-21-at-10-20-03.jpg)

In `main.cpp`, we create motor object, and simply pass the address to the base class.

`Motor motor_1(GPIOB, GPIO_PIN_10, &htim1, TIM_CHANNEL_1, TIM1);`  // This is one of the motor object whose address we are passing to the Base class's constructor. 

This class accepts 5 parameters as constructor, where `GPIOB` is the port number of the input pinout, `GPIO_PIN_10` is the pin number of the input pin, `&htim1` is the address of the timer 1, `TIM_CHANNEL_1` is the channel number used, and `TIM1` is the timer number again. Note that the parameters can be reduced to 4 I believe, but I'm too lazy to do it (But you can always do a PR!).

And we are creating encoders object as well, in this project, we used 2 encoders (I wanted to use 4, but due to limitations of STM32F103 which had less numbers of timers, it was not possible.) 

`Encoder encoder_1(&htim2);` // This is an encoder object, and we are simply passing the address of the timer we wish to use.

That's all! I've shared you most of the details which are necessary for using the Base, Motor and Encoder class, I'll still create the example codes if time permits, but till that time, you can reach me out @ <a href="mailto:alpharomeo911@protonmail.ch">alpharomeo911@protonmail.ch</a>.

## 6. TFMini Library (22-03-2021)

Library for interfacing `TF-Mini` with `STM32`.

Connections : `UART`, with only `TX` pin of `TF-Mini` connected with `STM-32`'s `RX`.

/**
  @page GPIO_InfiniteLedToggling_Init GPIO example
  
  @verbatim
    ******************************************************************************
  * @file    Examples_LL/GPIO/GPIO_InfiniteLedToggling_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the GPIO example.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

@par Example Description

How to configure and use GPIOs to toggle the on-board user LEDs 
every 250 ms. This example is based on the STM32G0xx LL API. The peripheral 
is initialized with LL initialization function to demonstrate LL init usage.

PC.06 IO (configured in output pushpull mode) toggles in a forever loop.
On NUCLEO-G031K8 board this IO is connected to LED3.

In this example, HCLK is configured at 16 MHz.

@par Keywords

System, GPIO, Output, Alternate function, Push-pull, Toggle

@par Directory contents 

  - GPIO/GPIO_InfiniteLedToggling_Init/Inc/stm32g0xx_it.h          Interrupt handlers header file
  - GPIO/GPIO_InfiniteLedToggling_Init/Inc/main.h                  Header for main.c module
  - GPIO/GPIO_InfiniteLedToggling_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - GPIO/GPIO_InfiniteLedToggling_Init/Src/stm32g0xx_it.c          Interrupt handlers
  - GPIO/GPIO_InfiniteLedToggling_Init/Src/main.c                  Main program
  - GPIO/GPIO_InfiniteLedToggling_Init/Src/system_stm32g0xx.c      STM32G0xx system source file


@par Hardware and Software environment

  - This example runs on STM32G031K8Tx devices.
    
  - This example has been tested with NUCLEO-G031K8 board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


 */

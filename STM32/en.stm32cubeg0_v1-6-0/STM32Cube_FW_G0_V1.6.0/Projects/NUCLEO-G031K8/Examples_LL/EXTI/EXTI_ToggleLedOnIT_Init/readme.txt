/**
  @page EXTI_ToggleLedOnIT_Init EXTI example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/EXTI/EXTI_ToggleLedOnIT_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the EXTI example.
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

This example describes how to configure the EXTI and use
GPIOs to toggle the user LED available on the board when
a virtual button is connected/disconnected. This example is based on the
STM32G0xx LL API. Peripheral initialization is done using LL
initialization function to demonstrate LL init usage.

In this example, one EXTI line (External line 15) is configured to generate
an interrupt on each rising edge.

In the interrupt routine a led connected to a specific GPIO pin is toggled.

In this example:
    - External line 15 is connected to GPIO_PIN_15 pin
      - when rising edge is detected on External line 15 by putting and removing a jumper between PA.15 (Arduino D2) and GND, LED3 toggles

On NUCLEO-G031K8:
    - External line 15 is connected to PA.15 (Arduino D2)

@par Keywords

System, GPIO, Output, Alternate function, EXTI, Toggle


@par Directory contents 

  - EXTI/EXTI_ToggleLedOnIT_Init/Inc/stm32g0xx_it.h          Interrupt handlers header file
  - EXTI/EXTI_ToggleLedOnIT_Init/Inc/main.h                  Header for main.c module
  - EXTI/EXTI_ToggleLedOnIT_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - EXTI/EXTI_ToggleLedOnIT_Init/Src/stm32g0xx_it.c          Interrupt handlers
  - EXTI/EXTI_ToggleLedOnIT_Init/Src/main.c                  Main program
  - EXTI/EXTI_ToggleLedOnIT_Init/Src/system_stm32g0xx.c      STM32G0xx system source file

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

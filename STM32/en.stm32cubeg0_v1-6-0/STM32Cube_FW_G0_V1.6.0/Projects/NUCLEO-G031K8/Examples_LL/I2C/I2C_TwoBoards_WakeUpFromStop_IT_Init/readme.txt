/**
  @page I2C_TwoBoards_WakeUpFromStop_IT_Init I2C example (IT Mode)

  @verbatim
  ******************************************************************************
  * @file    Examples_LL/I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the I2C_TwoBoards_WakeUpFromStop_IT_Init I2C example (IT Mode).
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

How to handle the reception of a data byte from an I2C slave device in
Stop0 mode by an I2C master device, both using interrupt mode. The
peripheral is initialized with LL unitary service functions to optimize for
performance and size.

This example guides you through the different configuration steps by mean of LL API
to configure GPIO and I2C peripherals using two NUCLEO-G031K8.

Boards: NUCLEO-G031K8 (embeds a STM32G031K8 device)
SCL Pin: PB.8 (CN3, pin 11 (D8))
SDA Pin: PB.9 (CN3, pin 13 (D10))

   ______BOARD SLAVE_____                       _____BOARD MASTER_____
  |        ______________|                     |______________        |
  |       |I2C1          |                     |          I2C1|       |
  |       |              |                     |              |       |
  |       |          SCL |_____________________| SCL          |       |
  |       |              |                     |              |       |
  |       |              |                     |              |       |
  |       |          SDA |_____________________| SDA          |       |
  |       |______________|                     |______________|       |
  |         __           |                     |             __       |
  |        |__|          |                     |            |__|      |
  |        USER       GND|_____________________|GND         USER      |
  |___STM32G0xx_Nucleo_32___|                     |___STM32G0xx_Nucleo_32___|

The project is split in two parts the Master Board and the Slave Board
- Master Board
  I2C1 Peripheral is configured in Master mode with EXTI (Clock 100Khz).
  And GPIO associated to PA.15 (Arduino D2) is linked with EXTI.
- Slave Board
  I2C1 Peripheral is configured in Slave mode with EXTI (Clock 100Khz,
  Own address 7-bit enabled, WakeUpFromStop).

The user can choose between Master and Slave through "#define SLAVE_BOARD"
in the "main.h" file:
- Comment "#define SLAVE_BOARD" to select Master board.
- Uncomment "#define SLAVE_BOARD" to select Slave board.

The user can disable internal pull-up by opening ioc file.
For that, user can follow the procedure :
1- Double click on the I2C_TwoBoards_WakeUpFromStop_IT_Init.ioc file
2- When CUBEMX tool is opened, select System Core category
3- Then in the configuration of GPIO/I2C1, change Pull-up to No pull-up and no pull-down for the both pins
4- Last step, generate new code thanks to button "GENERATE CODE"
The example is updated with no pull on each pin used for I2C communication

A first program launch, BOARD SLAVE is in Stop0 mode and BOARD MASTER is waiting User action on PA.15 (Arduino D2).
LED3 blinks quickly on BOARD MASTER to wait for user-button press.

Example execution:
Put and remove a jumper between PA.15 (Arduino D2) and GND on BOARD MASTER to initiate a read request by Master.
This action will generate an I2C start condition with the Slave address and a read bit condition.
When address Slave match code is received on I2C1 of BOARD SLAVE, a wake up is initiate and an ADDR interrupt occurs.
I2C1 Slave IRQ Handler routine is then checking Address Match Code and direction Read.
This will allow Slave to enter in transmitter mode and then send a byte when TXIS interrupt occurs.
When byte is received on I2C1 of BOARD MASTER, an RXNE interrupt occurs.
When RXDR register is read, Master auto-generate a NACK and STOP condition
to inform the Slave that the transfer is finished.
The NACK condition generate a NACK interrupt in Slave side treated in the I2C1 Slave IRQ handler routine by a clear of NACK flag.
The STOP condition generate a STOP interrupt in both side (Slave and Master). Both I2C1 IRQ handler routine are then
clearing the STOP flag in both side.

LED3 is ON on Slave side if the byte is well transmitted.
LED3 is ON on Master side if the expected byte is well received.

In case of errors, LED3 is blinking slowly (1s).

@par Keywords

Connectivity, I2C, Communication, Transmission, Reception, SCL, SDA, Wake up, Interrupt

@par Directory contents

  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Inc/stm32g0xx_it.h          Interrupt handlers header file
  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Inc/main.h                  Header for main.c module
  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Src/stm32g0xx_it.c          Interrupt handlers
  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Src/main.c                  Main program
  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Src/system_stm32g0xx.c      STM32G0xx system source file

@par Hardware and Software environment

  - This example runs on STM32G031K8Tx devices.

  - This example has been tested with STM32G031K8Tx board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-G031K8 Set-up
    - Connect GPIOs connected to Board Slave I2C1 SCL/SDA (PB.8 and PB.9)
    to respectively Board Master SCL and SDA pins of I2C1 (PB.8 and PB.9).
      - I2C1_SCL  PB.8 (CN3, pin 11 (D8)) : connected to I2C1_SCL PB.8 (CN3, pin 11 (D8))
      - I2C1_SDA  PB.9 (CN3, pin 13 (D10)) : connected to I2C1_SDA PB.9 (CN3, pin 13 (D10))
    - Connect Master board GND to Slave Board GND

  - Launch the program.
  - Put and remove a jumper between PA.15 (Arduino D2) and GND to initiate a read request by Master
      then Slave after wake up from Stop0 mode send a byte.

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory (The user can choose between Master
   and Slave target through "#define SLAVE_BOARD" in the "main.h" file)
    o Comment "#define SLAVE_BOARD" and load the project in Master Board
    o Uncomment "#define SLAVE_BOARD" and load the project in Slave Board
 - Run the example


 */

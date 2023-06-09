/**
  @page SPI_FullDuplex_ComPolling_Master SPI Two Boards Communication example
  
  @verbatim
  ******************************************************************************
  * @file    SPI/SPI_FullDuplex_ComPolling_Master/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the SPI Full Duplex Polling example.
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

Data buffer transmission/reception between two boards via SPI using Polling mode.

Board: NUCLEO-G031K8 (embeds a STM32G031K8 device)
CLK Pin: PB3 (CN4, pin 15)
MISO Pin: PB4 (CN3, pin 15)
MOSI Pin: PB5 (CN3, pin 14)
   _________________________                       __________________________
  |           ______________|                      |______________           |
  |          |SPI1          |                      |          SPI1|          |
  |          |              |                      |              |          |
  |          |    CLK(PB.03)|______________________|(PB.03)CLK    |          |
  |          |              |                      |              |          |
  |          |   MISO(PB.04)|______________________|(PB.04)MISO   |          |
  |          |              |                      |              |          |
  |          |   MOSI(PB.05)|______________________|(PB.05)MOSI   |          |
  |          |              |                      |              |          |
  |          |______________|                      |______________|          |
  |      __                 |                      |                         |
  |     |__|                |                      |                         |
  |                      GND|______________________|GND                      |
  |                         |                      |                         |
  |_STM32G0xx Master________|                      |_STM32G0xx Slave_________|


At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 64 MHz.

The SPI peripheral configuration is ensured by the HAL_SPI_Init() function.
This later is calling the HAL_SPI_MspInit()function which core is implementing
the configuration of the needed SPI resources according to the used hardware (CLOCK & 
GPIO). You may update this function to change SPI configuration.
The Full-Duplex SPI transfer (16bit) is done using LL Driver functions 
LL_SPI_TransmitData16 and LL_SPI_ReceiveData16.

Example execution:
First step, after the user connects the PA.15 (Arduino D2) to GND, this action initiates a Full-Duplex transfer 
between Master and Slave.
After end of transfer, aRxBuffer and aTxBuffer are compared through Buffercmp() in order to 
check buffers correctness.

STM32 board LED can be used to monitor the transfer status:
 - LED3 toggles quickly on master board waiting PA.15 (Arduino D2) to be connected to GND
 - LED3 turns ON if transmission/reception is complete and OK.
 - LED3 toggles slowly when there is a timeout or an error in transmission/reception process.   

@note You need to perform a reset on Slave board, then perform it on Master board
      to have the correct behaviour of this example.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Connectivity, SPI, Full-duplex, Transmission, Reception, Master, MISO, MOSI, Polling

@par Directory contents 

  - SPI/SPI_FullDuplex_ComPolling_Master/Inc/stm32g0xx_hal_conf.h    HAL configuration file
  - SPI/SPI_FullDuplex_ComPolling_Master/Inc/stm32g0xx_it.h          Interrupt handlers header file
  - SPI/SPI_FullDuplex_ComPolling_Master/Inc/main.h                  Header for main.c module  
  - SPI/SPI_FullDuplex_ComPolling_Master/Src/stm32g0xx_it.c          Interrupt handlers
  - SPI/SPI_FullDuplex_ComPolling_Master/Src/main.c                  Main program
  - SPI/SPI_FullDuplex_ComPolling_Master/Src/system_stm32g0xx.c      stm32g0xx system source file
  - SPI/SPI_FullDuplex_ComPolling_Master/Src/stm32g0xx_hal_msp.c     HAL MSP file

@par Hardware and Software environment

  - This example runs on STM32G031K8Tx devices.

  - Take care to cable connection between Master and Slave Board:
    Cable shall be smaller than 5 cm and rigid if possible.

  - This example has been tested with NUCLEO-G031K8 board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-G031K8 Set-up
    - Connect Master board PB3 (CN4, pin 15) to Slave Board PB3 (CN4, pin 15)
    - Connect Master board PB4 (CN3, pin 15) to Slave Board PB4 (CN3, pin 15)
    - Connect Master board PB5 (CN3, pin 14) to Slave Board PB5 (CN3, pin 14)
    - Connect Master board GND to Slave Board GND

@par How to use it ? 

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files (master project) and load your image into target memory
    o Load the project in Master Board
 - Rebuild all files (slave project) and load your image into target memory
    o Load the project in Slave Board
 - Run the example


 */
 
/* Copyright (c) 2025 CTHINGS.CO. All Rights Reserved.
 *
 * See file LICENSE.txt for full license details.
 *
 */

/**
 * @file
 * Board definition for the
 * <a href="https://cthings.co/products/connectivity-cards">CTHINGS.CO Connectivity Card nRF9161 mPCIe/nRF9161 M.2/nRF9151 M.2</a>
 */
#ifndef BOARD_CTC_NRF91X1_BOARD_H_
#define BOARD_CTC_NRF91X1_BOARD_H_



// NRF_GPIO is mapped to NRF_P0 , for pins P0.00 ... P0.31
// With nrf_gpio.h, use SW_pin (logical pins, port-aware)

/**
 *              CTCC nRF9161 mPCIe  
 *              CTCC nRF9161 M.2
NRF_P0  SW_pin  CTCC nRF9151 M.2        Notes (recommended usage)
------------------------------------------------------------------------
P0.00    0      -
P0.01    1      -
P0.02    2      W_DISABLE
P0.03    3      SCK                     external flash memory SCK
P0.04    4      MOSI                    external flash memory MOSI
P0.05    5      MISO                    external flash memory MISO
P0.06    6      -
P0.07    7      -
P0.08    8      -
P0.09    9      -
P0.10   10      -
P0.11   11      LED2
P0.12   12      LED1
P0.13   13      -
P0.14   14      -
P0.15   15      -
P0.16   16      CS                      external flash memory CS
P0.17   17      -
P0.18   18      -
P0.19   19      -
P0.20   20      -
P0.21   21      TRACECLK
P0.22   22      TRACEDATA[0]            Debug connector
P0.23   23      TRACEDATA[1]            Debug connector
P0.24   24      TRACEDATA[2]            Debug connector
P0.25   25      TRACEDATA[3]            Debug connector
P0.26   26      -
P0.27   27      -
P0.28   28      UART_TX
P0.29   29      UART_RX
P0.30   30      -
P0.31   31      -
*/

// Serial port pins for UART1
#define BOARD_USART_TX_PIN              28
#define BOARD_USART_RX_PIN              29

// List of GPIO pins
#define BOARD_GPIO_PIN_LIST            {12, /* P0.12 LED-1 */\
                                        11, /* P0.11 LED-2 */\
                                        29} /* P0.29. required by the dual_mcu app. usart wakeup pin (= BOARD_USART_RX) */     

// User friendly name for GPIOs (IDs mapped to the BOARD_GPIO_PIN_LIST table)
#define BOARD_GPIO_ID_LED1              0  // mapped to pin P0.12
#define BOARD_GPIO_ID_LED2              1  // mapped to pin P0.11
#define BOARD_GPIO_ID_USART_WAKEUP      2  // mapped to pin P0.29

// List of LED IDs
#define BOARD_LED_ID_LIST              {BOARD_GPIO_ID_LED1, BOARD_GPIO_ID_LED2}

// Active low polarity for LEDs
#define BOARD_LED_ACTIVE_LOW            false

// The board supports DCDC (#define BOARD_SUPPORT_DCDC)
// Since SDK v1.2 (bootloader > v7) this option has been moved to
// board/<board_name>/config.mk. Set board_hw_dcdc to yes to enable DCDC.
#ifdef BOARD_SUPPORT_DCDC
#error This option has been moved to board/<board_name>/config.mk
#endif

// External Flash Memory
#define EXT_FLASH_SPI_MOSI             4  // P0.04
#define EXT_FLASH_SPI_MISO             5  // P0.05
#define EXT_FLASH_SPI_SCK              3  // P0.03
#define EXT_FLASH_CS                   16 // P0.16
#define EXT_FLASH_SPIM_P               NRF_SPIM1

#endif /* BOARD_CTC_NRF91X1_BOARD_H_ */

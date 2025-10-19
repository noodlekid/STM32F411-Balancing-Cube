#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include "stm32f4xx.h"

#define SPI1_PERIPH SPI1

#define SPI1_PORT     GPIOA
#define SPI1_SCK_PIN  5
#define SPI1_MISO_PIN 6
#define SPI1_MOSI_PIN 7
#define SPI1_CS_PIN   4
#define SPI1_AF       5

#define SPI1_PRESCALER SPI_CR1_BR_1
#define SPI1_MODE      0

#endif /* BOARD_CONFIG_H */

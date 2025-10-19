#ifndef SPI_H
#define SPI_H

#include "board_config.h"
#include "stm32f411xe.h"

#include <stdint.h>

typedef enum {
    SPI_BAUDRATE_DIV2 = 0,
    SPI_BAUDRATE_DIV4 = 1,
    SPI_BAUDRATE_DIV8 = 2,
    SPI_BAUDRATE_DIV16 = 3,
    SPI_BAUDRATE_DIV32 = 4,
    SPI_BAUDRATE_DIV64 = 5,
    SPI_BAUDRATE_DIV128 = 6,
    SPI_BAUDRATE_DIV256 = 7,
} SPI_Baud_t;

int spi1_init(void);
uint8_t spi1_tx_rx(uint8_t data);
void spi1_tx(uint8_t *data, uint16_t size);
void spi1_rx(uint8_t *data, uint16_t size);
void spi1_set_baud(SPI_Baud_t baud);

static inline void spi1_select(void)
{
    GPIOA->BSRR = (1U << (SPI1_CS_PIN + 16));
}

static inline void spi1_deselect(void)
{
    GPIOA->BSRR = (1U << SPI1_CS_PIN);
}

#endif // !SPI_H

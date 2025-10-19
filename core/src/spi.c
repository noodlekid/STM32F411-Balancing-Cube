#include "board_config.h"
#include "spi.h"
#include "stm32f411xe.h"

static inline void spi1_gpio_init()
{
    uint32_t moder = GPIOA->MODER;
    uint32_t afr = GPIOA->AFR[0];

    moder &= ~((3U << (SPI1_SCK_PIN * 2)) | (3U << (SPI1_MISO_PIN * 2)) |
               (3U << (SPI1_MOSI_PIN * 2)));

    moder |= (2U << (SPI1_SCK_PIN * 2)) | (2U << (SPI1_MISO_PIN * 2)) |
             (2U << (SPI1_MOSI_PIN * 2));

    GPIOA->MODER = moder;

    afr &= ~((0xF << (SPI1_SCK_PIN * 4)) | (0xF << (SPI1_MISO_PIN * 4)) |
             (0xF << (SPI1_MOSI_PIN * 4)));

    afr |= (SPI1_AF << (SPI1_SCK_PIN * 4)) | (SPI1_AF << (SPI1_MISO_PIN * 4)) |
           (SPI1_AF << (SPI1_MOSI_PIN * 4));

    GPIOA->AFR[0] = afr;

    GPIOA->OSPEEDR |= (3U << (SPI1_SCK_PIN * 2)) | (3U << (SPI1_MISO_PIN * 2)) |
                      (3U << (SPI1_MOSI_PIN * 2));

    GPIOA->MODER &= ~(3U << (SPI1_CS_PIN * 2));
    GPIOA->MODER |= (1U << (SPI1_CS_PIN * 2));
    GPIOA->OSPEEDR |= (3U << (SPI1_CS_PIN * 2));

    spi1_deselect();
}

static inline void spi1_periph_init()
{
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
    SPI1->CR1 = SPI_CR1_MSTR | SPI_CR1_BR_0 | SPI_CR1_SSI | SPI_CR1_SSM;
    SPI1->CR1 |= SPI_CR1_SPE;
}

int spi1_init()
{
    spi1_gpio_init();
    spi1_periph_init();
    return 0;
}

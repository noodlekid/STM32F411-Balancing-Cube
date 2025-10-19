#include <stdint.h>

// from linker
extern uint32_t _estack;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sidata;
extern uint32_t _sbss;
extern uint32_t _ebss;

extern void SystemInit(void);

extern int main(void);

/* Exception/Interrupt Handlers */
void Reset_Handler(void);
void Default_Handler(void);

/* Cortex-M4 Core Exception Handlers */
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

/* STM32F411 Peripheral Interrupt Handlers */
void WWDG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void ADC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void SDIO_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler(void) __attribute__((weak));
void DMA2_Stream5_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void USART6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FPU_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

/* Vector Table */
__attribute__((section(".isr_vector"))) const uint32_t VectorTable[] = {
    (uint32_t)&_estack, /* Initial Stack Pointer */
    (uint32_t)Reset_Handler, /* Reset Handler */
    (uint32_t)NMI_Handler, /* NMI Handler */
    (uint32_t)HardFault_Handler, /* Hard Fault Handler */
    (uint32_t)MemManage_Handler, /* MPU Fault Handler */
    (uint32_t)BusFault_Handler, /* Bus Fault Handler */
    (uint32_t)UsageFault_Handler, /* Usage Fault Handler */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    (uint32_t)SVC_Handler, /* SVCall Handler */
    (uint32_t)DebugMon_Handler, /* Debug Monitor Handler */
    0, /* Reserved */
    (uint32_t)PendSV_Handler, /* PendSV Handler */
    (uint32_t)SysTick_Handler, /* SysTick Handler */

    /* External Interrupts */
    (uint32_t)WWDG_IRQHandler, /* Window WatchDog */
    (uint32_t)PVD_IRQHandler, /* PVD through EXTI Line detection */
    (uint32_t)
        TAMP_STAMP_IRQHandler, /* Tamper and TimeStamps through the EXTI line */
    (uint32_t)RTC_WKUP_IRQHandler, /* RTC Wakeup through the EXTI line */
    (uint32_t)FLASH_IRQHandler, /* FLASH */
    (uint32_t)RCC_IRQHandler, /* RCC */
    (uint32_t)EXTI0_IRQHandler, /* EXTI Line0 */
    (uint32_t)EXTI1_IRQHandler, /* EXTI Line1 */
    (uint32_t)EXTI2_IRQHandler, /* EXTI Line2 */
    (uint32_t)EXTI3_IRQHandler, /* EXTI Line3 */
    (uint32_t)EXTI4_IRQHandler, /* EXTI Line4 */
    (uint32_t)DMA1_Stream0_IRQHandler, /* DMA1 Stream 0 */
    (uint32_t)DMA1_Stream1_IRQHandler, /* DMA1 Stream 1 */
    (uint32_t)DMA1_Stream2_IRQHandler, /* DMA1 Stream 2 */
    (uint32_t)DMA1_Stream3_IRQHandler, /* DMA1 Stream 3 */
    (uint32_t)DMA1_Stream4_IRQHandler, /* DMA1 Stream 4 */
    (uint32_t)DMA1_Stream5_IRQHandler, /* DMA1 Stream 5 */
    (uint32_t)DMA1_Stream6_IRQHandler, /* DMA1 Stream 6 */
    (uint32_t)ADC_IRQHandler, /* ADC1, ADC2 and ADC3s */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    (uint32_t)EXTI9_5_IRQHandler, /* External Line[9:5]s */
    (uint32_t)TIM1_BRK_TIM9_IRQHandler, /* TIM1 Break and TIM9 */
    (uint32_t)TIM1_UP_TIM10_IRQHandler, /* TIM1 Update and TIM10 */
    (uint32_t)TIM1_TRG_COM_TIM11_IRQHandler, /* TIM1 Trigger and Commutation and
                                                TIM11 */
    (uint32_t)TIM1_CC_IRQHandler, /* TIM1 Capture Compare */
    (uint32_t)TIM2_IRQHandler, /* TIM2 */
    (uint32_t)TIM3_IRQHandler, /* TIM3 */
    (uint32_t)TIM4_IRQHandler, /* TIM4 */
    (uint32_t)I2C1_EV_IRQHandler, /* I2C1 Event */
    (uint32_t)I2C1_ER_IRQHandler, /* I2C1 Error */
    (uint32_t)I2C2_EV_IRQHandler, /* I2C2 Event */
    (uint32_t)I2C2_ER_IRQHandler, /* I2C2 Error */
    (uint32_t)SPI1_IRQHandler, /* SPI1 */
    (uint32_t)SPI2_IRQHandler, /* SPI2 */
    (uint32_t)USART1_IRQHandler, /* USART1 */
    (uint32_t)USART2_IRQHandler, /* USART2 */
    0, /* Reserved */
    (uint32_t)EXTI15_10_IRQHandler, /* External Line[15:10]s */
    (uint32_t)RTC_Alarm_IRQHandler, /* RTC Alarm (A and B) through EXTI Line */
    (uint32_t)OTG_FS_WKUP_IRQHandler, /* USB OTG FS Wakeup through EXTI line */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    (uint32_t)DMA1_Stream7_IRQHandler, /* DMA1 Stream7 */
    0, /* Reserved */
    (uint32_t)SDIO_IRQHandler, /* SDIO */
    (uint32_t)TIM5_IRQHandler, /* TIM5 */
    (uint32_t)SPI3_IRQHandler, /* SPI3 */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    (uint32_t)DMA2_Stream0_IRQHandler, /* DMA2 Stream 0 */
    (uint32_t)DMA2_Stream1_IRQHandler, /* DMA2 Stream 1 */
    (uint32_t)DMA2_Stream2_IRQHandler, /* DMA2 Stream 2 */
    (uint32_t)DMA2_Stream3_IRQHandler, /* DMA2 Stream 3 */
    (uint32_t)DMA2_Stream4_IRQHandler, /* DMA2 Stream 4 */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    (uint32_t)OTG_FS_IRQHandler, /* USB OTG FS */
    (uint32_t)DMA2_Stream5_IRQHandler, /* DMA2 Stream 5 */
    (uint32_t)DMA2_Stream6_IRQHandler, /* DMA2 Stream 6 */
    (uint32_t)DMA2_Stream7_IRQHandler, /* DMA2 Stream 7 */
    (uint32_t)USART6_IRQHandler, /* USART6 */
    (uint32_t)I2C3_EV_IRQHandler, /* I2C3 event */
    (uint32_t)I2C3_ER_IRQHandler, /* I2C3 error */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    0, /* Reserved */
    (uint32_t)FPU_IRQHandler, /* FPU */
    0, /* Reserved */
    0, /* Reserved */
    (uint32_t)SPI4_IRQHandler, /* SPI4 */
    (uint32_t)SPI5_IRQHandler /* SPI5 */
};

void Reset_Handler(void)
{
    /* Copy data segment initializers from flash to SRAM */
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;

    while (dst < &_edata) {
        *dst++ = *src++;
    }

    /* Zero fill the bss segment */
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    /* Call system initialization */
    SystemInit();

    /* Call the application's entry point */
    main();

    /* Infinite loop */
    while (1)
        ;
}

void Default_Handler(void)
{
    /* Infinite loop */
    while (1)
        ;
}

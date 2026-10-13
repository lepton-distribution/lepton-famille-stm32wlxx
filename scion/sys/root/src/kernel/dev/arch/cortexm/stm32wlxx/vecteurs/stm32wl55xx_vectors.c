/*
 * Lepton — vecteurs d'interruption du STM32WL55, cœur Cortex-M4 du CPU1 (famille stm32wlxx ;
 * étape 6, ENV-6). Licence : voir LICENSE (MPL 1.1).
 *
 * Le démarrage générique ARMv7-M (kernel/core/arch/cortexm/startup_armv7m.c) fournit la table
 * des exceptions et des IRQ 0 à 63 sous les noms IRQ<n>_Handler (faibles). Ce fichier définit les
 * IRQ<n>_Handler utilisés par la carte, vers les gestionnaires aux noms CMSIS des pilotes du
 * portage IAR (USART2 et DMA : BSP ; radio : dev_stm32wlxx_bsp_radio_if.c). Le CPU1 du STM32WL55
 * a 62 IRQ (0 à 61) : la table générique suffit, pas de table étendue.
 * Numéros : RM0453, stm32wl55xx.h (CORE_CM4, IRQn_Type).
 */
void DMA1_Channel1_IRQHandler(void);
void DMA1_Channel2_IRQHandler(void);
void USART2_IRQHandler(void);
void SUBGHZ_Radio_IRQHandler(void);

void IRQ11_Handler(void) { DMA1_Channel1_IRQHandler(); }   /* DMA1_Channel1_IRQn */
void IRQ12_Handler(void) { DMA1_Channel2_IRQHandler(); }   /* DMA1_Channel2_IRQn */
void IRQ37_Handler(void) { USART2_IRQHandler(); }          /* USART2_IRQn */
void IRQ50_Handler(void) { SUBGHZ_Radio_IRQHandler(); }    /* SUBGHZ_Radio_IRQn */

/*
 * Lepton — base de temps des utilitaires STM32CubeWL pour la pile radio (famille STM32WLxx,
 * étape 6). Licence : voir LICENSE (MPL 1.1).
 * UTIL_TIMER_GetCurrentTime / UTIL_TIMER_GetElapsedTime sur le tick du noyau (comme HAL_GetTick) :
 * cibles de TimerGetCurrentTime / TimerGetElapsedTime (stm32_radio_target/timer.h, qui neutralise
 * les minuteries de la pile) ; Utilities/timer/stm32_timer.c (serveur sur RTC) n'est pas compilé.
 * Seul utilisateur : RadioIsChannelFree (radio.c, écoute avant émission), dont le corps est sous
 * #if 0 depuis l'import de 2024 et qu'aucun code de Lepton n'appelle : ces deux fonctions ne sont
 * donc pas liées dans l'exécutable (ENV-48 ; radio_subghz_phy/LEPTON-PROVENANCE.md).
 */
#include <stdint.h>

#include "kernel/core/kernelconf.h"
#include "kernel/core/types.h"
#include "kernel/core/interrupt.h"
#include "kernel/core/kernel.h"
#include "kernel/core/systime.h"

#include "stm32_timer.h"

UTIL_TIMER_Time_t UTIL_TIMER_GetCurrentTime(void){
   return (UTIL_TIMER_Time_t)((uint64_t)__kernel_get_timer_ticks() * 1000u / HZ);
}

UTIL_TIMER_Time_t UTIL_TIMER_GetElapsedTime(UTIL_TIMER_Time_t past){
   return UTIL_TIMER_GetCurrentTime() - past;
}

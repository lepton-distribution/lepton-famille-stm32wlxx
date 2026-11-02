# Fichiers SVD de la famille stm32wlxx

Vue des périphériques au débogage (DBG-4). Le BSP désigne son fichier par
`"svd": {"famille": "svd/<fichier>"}` dans son `lepton-greffon.json`.

Fichiers copiés sans modification du pack CMSIS `Keil::STM32WLxx_DFP` 2.1.0 (2025-09-17), téléchargé de
https://www.keil.com/pack/Keil.STM32WLxx_DFP.2.1.0.pack le 2026-11-02 (ENV-26, décision PA-39).

| Fichier | MCU | Chemin dans le pack | Octets | SHA-256 |
| --- | --- | --- | --- | --- |
| `STM32WL5x_CM4.svd` | STM32WL55JC, cœur Cortex-M4 seul (BSP nucleo-wl55jc1 ; le M0+ n'est pas utilisé) | `CMSIS/SVD/STM32WL5x_CM4.svd` | 1066385 | `bc8642b4f6c1de77af9686476693ab42976dd574e54872e8787f4e7e82768c75` |

Licence : Apache-2.0, selon l'en-tête de chaque fichier (`SPDX-License-Identifier: Apache-2.0`),
conservé tel quel. Texte de la licence : `LICENSE-Apache-2.0`.

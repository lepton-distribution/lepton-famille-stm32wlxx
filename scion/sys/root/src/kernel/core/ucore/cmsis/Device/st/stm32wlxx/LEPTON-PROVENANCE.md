# Provenance (chantier environnement de développement Lepton, ENV-37)

CMSIS device STM32WL V1.1.1. Révision retenue : `cmsis-device-wl` commit
`d248c5514fe294fec6eb52f49ed3f1a53cea45b0` (tag `v1.1.1`,
https://github.com/STMicroelectronics/cmsis-device-wl), Apache-2.0 (`LICENSE.md` de l'amont, non
repris). C'est le CMSIS device de STM32CubeWL `v1.2.0` (commit
`6d27fec2e59e2032d3d6cd55909b0bc73bae9356`) : il ne forme pas le couple de STM32CubeWL `v1.3.0`
avec la HAL V1.3.0 de la famille (STM32CubeWL `v1.3.0` porte le CMSIS device V1.2.0). Importé sans
provenance en migration, puis par ENV-6 ; audité en ENV-37
(`doc/devenv/rapports/env-37-wl-provenance.md` du dépôt lepton-tools).

Correspondance des chemins (amont → ce répertoire), sélection fichier par fichier, STM32WL55 seul :
- `Include/stm32wl55xx.h`, `Include/stm32wlxx.h`, `Include/system_stm32wlxx.h` → racine ;
- `Source/Templates/system_stm32wlxx.c` → racine ;
- `Source/Templates/iar/startup_stm32wl55xx_cm4.s` → `startup/iar/`.
Les 5 fichiers sont identiques à l'amont, non modifiés (code tiers, D1a). Répertoire amont
`Drivers/CMSIS/Device/ST/STM32WLxx` de STM32CubeWL, ici `cmsis/Device/st/stm32wlxx` (casse).

Non compilés : `system_stm32wlxx.c` et `startup/iar/startup_stm32wl55xx_cm4.s` (démarrage IAR) ;
en-têtes inclus : les trois de la racine. Non repris : autres puces, démarrages `arm/` et `gcc/`,
scripts d'édition de liens, `LICENSE.md`, `README.md`, notes de version.

Contrôle : copie de travail remise aux chemins amont
(`doc/devenv/rapports/env-37-wl-provenance/preparer-copies.sh`), puis
`scripts/tiers/verifier-import.sh <clone> v1.1.1 <copie>/cmsis` : 5 identiques.

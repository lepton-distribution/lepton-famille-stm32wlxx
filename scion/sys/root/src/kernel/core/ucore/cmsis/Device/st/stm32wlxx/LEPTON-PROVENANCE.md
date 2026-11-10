# Provenance (chantier environnement de développement Lepton, ENV-37, ENV-48, ENV-49)

CMSIS device STM32WL V1.4.0 : `cmsis-device-wl` tag `v1.4.0` = commit
`71a0b7860e700f7ca11afe4c4afd6cef684ad9bb` (amont
https://github.com/STMicroelectronics/cmsis-device-wl), Apache-2.0 (`LICENSE.md`). C'est le
sous-module `Drivers/CMSIS/Device/ST/STM32WLxx` de STM32CubeWL `v1.6.0` (commit
`f934cd298bf82d45f96aac2f335c0bbd26d0b946`) : il forme le couple avec la HAL V1.6.0 de la famille
(ENV-49, décision PA-85 ; jusqu'à ENV-48, V1.1.1, CMSIS device de STM32CubeWL `v1.2.0`, hors couple).
Code tiers non modifié (D1a).

Ce répertoire n'est pas une copie : scion **projette** les fichiers du dépôt tiers (clé
`tiers@cmsis-device-wl`, déclarée dans `scion/.scion/` de ce greffon, qui la porte). Source :
miroir de conservation https://github.com/lepton-distribution/mirror-cmsis-device-wl.git (tenu par
`scion mirror-sync`) ; clone partiel sous `<rootstock>/depots/tiers/cmsis-device-wl/v1.4.0`, au
commit du tag. Fichiers projetés, STM32WL55 seul, chemins aplatis :
- `Include/stm32wl55xx.h`, `Include/stm32wlxx.h`, `Include/system_stm32wlxx.h` → racine ;
- `Source/Templates/system_stm32wlxx.c` → racine ;
- `Source/Templates/iar/startup_stm32wl55xx_cm4.s` → `startup/iar/` ;
- `LICENSE.md` → racine.
Non projetés : autres puces, démarrages `arm/` et `gcc/`, scripts d'édition de liens, `README.md`,
notes de version. Seul ce fichier appartient au greffon.

Non compilés : `system_stm32wlxx.c` et `startup/iar/startup_stm32wl55xx_cm4.s` (démarrage IAR) ;
en-têtes inclus : les trois de la racine. Contenu : identique à `v1.4.0` par construction.
Exige scion ≥ 0.6.1.0.
Mise à jour : changer la version de la clé dans `scion/.scion/`, avec la HAL, la pile radio et les
utilitaires du même STM32CubeWL, puis regreffer.
Audit : `doc/devenv/rapports/env-37-wl-provenance.md`, `env-48-wl-projection.md` et
`env-49-wl-hal.md` du dépôt lepton-tools.

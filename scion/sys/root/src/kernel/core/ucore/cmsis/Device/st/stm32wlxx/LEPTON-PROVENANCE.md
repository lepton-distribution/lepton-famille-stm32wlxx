# Provenance (chantier environnement de développement Lepton, ENV-37, ENV-48)

CMSIS device STM32WL V1.1.1 : `cmsis-device-wl` tag `v1.1.1` = commit
`d248c5514fe294fec6eb52f49ed3f1a53cea45b0` (amont
https://github.com/STMicroelectronics/cmsis-device-wl), Apache-2.0 (`LICENSE.md`). C'est le CMSIS
device de STM32CubeWL `v1.2.0` (commit `6d27fec2e59e2032d3d6cd55909b0bc73bae9356`) : il ne forme
pas le couple de STM32CubeWL `v1.3.0` avec la HAL V1.3.0 de la famille (STM32CubeWL `v1.3.0` porte
le CMSIS device V1.2.0). Code tiers non modifié (D1a).

Depuis ENV-48, ce répertoire n'est plus une copie : scion **projette** les fichiers du dépôt tiers
(clé `tiers@cmsis-device-wl`, déclarée dans `scion/.scion/` de ce greffon, qui la porte). Source :
miroir de conservation https://github.com/lepton-distribution/mirror-cmsis-device-wl.git (tenu par
`scion mirror-sync`) ; clone partiel sous `<rootstock>/depots/tiers/cmsis-device-wl/v1.1.1`, au
commit du tag. Fichiers projetés, STM32WL55 seul, chemins aplatis :
- `Include/stm32wl55xx.h`, `Include/stm32wlxx.h`, `Include/system_stm32wlxx.h` → racine ;
- `Source/Templates/system_stm32wlxx.c` → racine ;
- `Source/Templates/iar/startup_stm32wl55xx_cm4.s` → `startup/iar/` ;
- `LICENSE.md` → racine (ajouté en ENV-48, décision C2, PA-83).
Non projetés : autres puces, démarrages `arm/` et `gcc/`, scripts d'édition de liens, `README.md`,
notes de version. Seul ce fichier appartient au greffon.

Non compilés : `system_stm32wlxx.c` et `startup/iar/startup_stm32wl55xx_cm4.s` (démarrage IAR) ;
en-têtes inclus : les trois de la racine. Contenu : identique à `v1.1.1` par construction.
Exige scion ≥ 0.6.1.0.
Mise à jour : changer la version de la clé dans `scion/.scion/`, avec la HAL du même STM32CubeWL,
puis regreffer.
Audit : `doc/devenv/rapports/env-37-wl-provenance.md` et `env-48-wl-projection.md` du dépôt
lepton-tools.

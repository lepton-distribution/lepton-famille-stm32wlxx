# Provenance (chantier environnement de développement Lepton, ENV-37, ENV-48, ENV-49)

HAL STM32WL V1.6.0 : `stm32wlxx-hal-driver` tag `v1.6.0` = commit
`5c87cf00992c6e4ecf56c7c129b8dcfc6aa6f88e` (amont
https://github.com/STMicroelectronics/stm32wlxx-hal-driver), BSD-3-Clause (`LICENSE.md`). C'est le
sous-module `Drivers/STM32WLxx_HAL_Driver` de STM32CubeWL `v1.6.0` (commit
`f934cd298bf82d45f96aac2f335c0bbd26d0b946`), qui forme le couple avec le CMSIS device V1.4.0, la
pile radio SubGHz_Phy V1.5.0 et les utilitaires de la même version (ENV-49, décision PA-85).
Code tiers non modifié (D1a).

Ce répertoire n'est pas une copie : scion **projette** les fichiers du dépôt tiers (clé
`tiers@stm32wlxx-hal-driver`, déclarée dans `scion/.scion/` de ce greffon, qui la porte). Source :
miroir de conservation https://github.com/lepton-distribution/mirror-stm32wlxx-hal-driver.git
(tenu par `scion mirror-sync`, `scion/.scion/.scion.mirrors`) ; clone partiel sous
`<rootstock>/depots/tiers/stm32wlxx-hal-driver/v1.6.0`, au commit du tag. Fichiers projetés :
`Inc/**` → `inc/`, `Src/**` → `src/` (la projection change la casse des répertoires),
`README.md`, `Release_Notes.html` et `LICENSE.md` → racine (157 fichiers) ; `_htmresc/`,
`.github/` et fichiers de contribution non projetés. Configuration (`stm32wlxx_hal_conf.h`) dans
`dev_stm32wlxx/` de la famille.

`inc/Legacy/stm32_hal_legacy.h` est projeté depuis ENV-49 (décision PA-85). Jusqu'alors, le
greffon gardait la version de STM32CubeWL `v1.3.0`, différente de celle du tag `v1.3.0` du dépôt
séparé. En V1.6.0, `stm32wlxx_hal_def.h` ne l'inclut plus ; aucun fichier de Lepton ne l'inclut.
Seul ce fichier appartient au greffon. `LICENSE.txt` (avis court ST hors amont) : retiré en ENV-48
(décision C2, PA-83).

Compilés : les 12 `src/*.c` listés dans `sources` de `lepton-greffon.json`, résolus par le trunk.
Contenu : identique à `v1.6.0` par construction (liens vers le clone tiers, que la greffe refuse
hors de son commit épinglé ou modifié). Exige scion ≥ 0.6.1.0.
Mise à jour : changer la version de la clé dans `scion/.scion/` (`.scion.sources.list`,
`.scion.ramifications`), avec le CMSIS device, la pile radio et les utilitaires du même
STM32CubeWL, puis regreffer (`scion seed-clone`, puis `scion graft`).
Audit : `doc/devenv/rapports/env-37-wl-provenance.md`, `env-48-wl-projection.md` et
`env-49-wl-hal.md` du dépôt lepton-tools.

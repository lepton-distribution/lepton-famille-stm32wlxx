# Provenance (chantier environnement de développement Lepton, ENV-37, ENV-48, ENV-49)

Pile radio SubGHz_Phy V1.5.0 : `stm32-mw-subghz-phy` tag `v1.5.0` = commit
`7dc059f353f359ec65c60a0549d53c1ebeaafa79` (amont
https://github.com/STMicroelectronics/stm32-mw-subghz-phy). Licences : Clear BSD Semtech
(`LICENSE`) pour les fichiers d'origine Semtech ; BSD-3-Clause ST (`LICENSE.md`). C'est le
sous-module `Middlewares/Third_Party/SubGHz_Phy` de STM32CubeWL `v1.6.0` (commit
`f934cd298bf82d45f96aac2f335c0bbd26d0b946`), du même couple que la HAL V1.6.0 de la famille
(ENV-49, décision PA-85).

Depuis la V1.4.0, l'amont range le pilote et les en-têtes de la racine sous `radio_driver/` (ancien
`stm32_radio_driver/`) et ajoute `lorawan/` (pile LBM). Les chemins de Lepton sont conservés
(décision PA-85) : la projection nomme chaque fichier et le place à son chemin d'avant.

Ce répertoire mêle deux dépôts projetés et des fichiers du greffon. Les deux clés sont déclarées
dans `scion/.scion/` de ce greffon, qui les porte :
- `tiers@stm32-mw-subghz-phy` : miroir https://github.com/lepton-distribution/mirror-stm32-mw-subghz-phy.git,
  clone partiel `<rootstock>/depots/tiers/stm32-mw-subghz-phy/v1.5.0` (20 fichiers) :
  - `radio_driver/radio.h`, `radio_def.h`, `radio_ex.h`, `lr_fhss_v1_base_types.h` → racine ;
  - `radio_driver/*.c` sauf `radio.c`, et `radio_driver/lr_fhss_mac.h`, `radio_driver.h`,
    `radio_fw.h`, `subghz_phy_version.h`, `wl_lr_fhss.h` → `stm32_radio_driver/` ;
  - `LICENSE`, `LICENSE.md` → racine ; `Conf/*` → `Conf/` (gabarits, dont `radio_template.h`
    depuis la V1.4.0 ; ni compilés ni inclus) ;
- `tiers@stm32cubewl::radio-core-inc` : miroir https://github.com/lepton-distribution/mirror-STM32CubeWL.git,
  clone partiel `<rootstock>/depots/tiers/stm32cubewl/v1.6.0`, partagé avec
  `tiers@stm32cubewl::utilities` ; `stm32_radio_core_inc/utilities_def.h`, tiré de
  `Projects/NUCLEO-WL55JC/Applications/SubGHz_Phy/SubGHz_Phy_PingPong/Core/Inc/` de STM32CubeWL
  `v1.6.0` (fichier d'application STM32CubeMX, source admise par la décision PA-61 ; identique de
  `v1.3.0` à `v1.6.0`).

Restent dans le greffon, exclus de la projection : les fichiers modifiés par Lepton ci-dessous
(écarts à D1a, décision PA-61) et ce fichier.
- `stm32_radio_driver/radio.c` : le corps de `RadioIsChannelFree` est sous `#if 0` ; la fonction
  rend toujours `false`. Compilé. Reporté en ENV-49 sur le `radio_driver/radio.c` de `v1.5.0`
  (correctif `doc/devenv/rapports/env-49-wl-hal/propose/reports/lepton-radio.patch` du dépôt
  lepton-tools ; mêmes lignes 810 et 844-846). La modification figure dès le premier commit du
  fichier (efa8106 du 2024-05-24 dans le dépôt du noyau, « added files from stm32cubemx-win-v6-11-0
  and stm32cubewl-v1-3-0 ») ; aucun écrit n'en donne la raison. Raison **probable, non établie**
  (ENV-48, décision C1) : le corps neutralisé est, dans `radio.c`, le seul utilisateur de
  `TimerGetCurrentTime` et `TimerGetElapsedTime`, que `stm32_radio_target/timer.h` du BSP ramène
  à `UTIL_TIMER_*` de `Utilities/timer/stm32_timer.c` ; les projets IAR de 2024 ne compilaient pas
  ce fichier, et la neutralisation évitait vraisemblablement ces symboles non résolus, comme les
  macros vides `TimerInit`, `TimerStart`… de `timer.h`. Aucun code de Lepton n'appelle
  `Radio.IsChannelFree` (seule l'entrée de la table `Radio` la référence).
- `stm32_radio_core_inc/subghz.h` : `main.h` remplacé par `stm32wlxx_hal.h` ; inclus.
- `stm32_radio_core_inc/utilities_conf.h` : `cmsis_compiler.h` retiré, branches `__CC_ARM`,
  `__ICCARM__`, `WIN32` supprimées ; inclus.
- `stm32_radio_core_inc/platform.h` : `main.h` et en-têtes BSP ST en commentaire ; ni compilé ni
  inclus.
Les trois derniers dérivent des fichiers de même nom du répertoire PingPong cité plus haut,
identiques de STM32CubeWL `v1.3.0` à `v1.6.0` : rien à reporter en ENV-49. `LICENSE.txt` : retiré
en ENV-48 (décision C2, PA-83). Non projetés : `lorawan/`, `README.md`, `Release_Notes.*`,
`SECURITY.md`, `SW_Security_Level.md`, `_htmresc/`, `.github/`, fichiers de contribution.

Diffs contre l'amont : `doc/devenv/rapports/env-37-wl-provenance/diffs/` (V1.3.0) et
`env-49-wl-hal/propose/reports/` du dépôt lepton-tools.
L'adaptation radio de la carte (`stm32_radio_target`) est dans le BSP `nucleo-wl55jc1`.
Compilés : les 5 `stm32_radio_driver/*.c` listés dans `sources` de `lepton-greffon.json`
(`radio.c` du greffon, 4 projetés), résolus par le trunk. Contenu projeté : identique aux commits
épinglés par construction. Exige scion ≥ 0.6.1.0.
Mise à jour : changer la version des clés dans `scion/.scion/` avec la HAL du même STM32CubeWL,
contrôler les lignes de projection contre la liste git de la nouvelle version, reporter `radio.c`,
puis regreffer.
Audit : `doc/devenv/rapports/env-37-wl-provenance.md`, `env-48-wl-projection.md` et
`env-49-wl-hal.md` du dépôt lepton-tools.

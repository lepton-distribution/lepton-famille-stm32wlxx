# Provenance (chantier environnement de développement Lepton, ENV-37, ENV-48)

Pile radio SubGHz_Phy V1.3.0 : `stm32-mw-subghz-phy` tag `v1.3.0` = commit
`1cad76816effd9679a056e57c02dd4b23d7cb772` (amont
https://github.com/STMicroelectronics/stm32-mw-subghz-phy). Licences : Clear BSD Semtech
(`LICENSE`) pour les fichiers d'origine Semtech ; BSD-3-Clause ST (`LICENSE.md`). Identique à
`Middlewares/Third_Party/SubGHz_Phy` de STM32CubeWL `v1.3.0` (commit
`378e461e469ef9826e857f8eda3346cea525b2fa`), sauf `radio.c` (ci-dessous).

Depuis ENV-48, ce répertoire mêle deux dépôts projetés et des fichiers du greffon. Les deux clés
sont déclarées dans `scion/.scion/` de ce greffon, qui les porte :
- `tiers@stm32-mw-subghz-phy` : miroir https://github.com/lepton-distribution/mirror-stm32-mw-subghz-phy.git,
  clone partiel `<rootstock>/depots/tiers/stm32-mw-subghz-phy/v1.3.0` ; `*.h`, `LICENSE`,
  `LICENSE.md` de la racine, `Conf/*`, `stm32_radio_driver/*` sauf `radio.c` (19 fichiers),
  chemins de l'amont sans renommage ;
- `tiers@stm32cubewl::radio-core-inc` : miroir https://github.com/lepton-distribution/mirror-STM32CubeWL.git,
  clone partiel `<rootstock>/depots/tiers/stm32cubewl/v1.3.0`, partagé avec
  `tiers@stm32cubewl::utilities` ; `stm32_radio_core_inc/utilities_def.h`, tiré de
  `Projects/NUCLEO-WL55JC/Applications/SubGHz_Phy/SubGHz_Phy_PingPong/Core/Inc/` de STM32CubeWL
  `v1.3.0` (fichier d'application STM32CubeMX, source admise par la décision PA-61).

Restent dans le greffon, exclus de la projection : les fichiers modifiés par Lepton ci-dessous
(écarts à D1a, décision PA-61) et ce fichier.
- `stm32_radio_driver/radio.c` : le corps de `RadioIsChannelFree` est sous `#if 0` ; la fonction
  rend toujours `false`. Compilé. La modification figure dès le premier commit du fichier
  (efa8106 du 2024-05-24 dans le dépôt du noyau, « added files from stm32cubemx-win-v6-11-0 and
  stm32cubewl-v1-3-0 ») ; aucun écrit n'en donne la raison. Raison **probable, non établie**
  (ENV-48, décision C1) : le corps neutralisé est, dans `radio.c`, le seul utilisateur de
  `TimerGetCurrentTime` et `TimerGetElapsedTime`, que `stm32_radio_target/timer.h` du BSP ramène
  à `UTIL_TIMER_*` de `Utilities/timer/stm32_timer.c` ; les projets IAR de 2024 ne compilaient pas
  ce fichier, et la neutralisation évitait vraisemblablement ces symboles non résolus, comme les
  macros vides `TimerInit`, `TimerStart`… de `timer.h`. Aucun code de Lepton n'appelle
  `Radio.IsChannelFree` (seule l'entrée de la table `Radio` la référence). Binaire inchangé.
- `stm32_radio_core_inc/subghz.h` : `main.h` remplacé par `stm32wlxx_hal.h` ; inclus.
- `stm32_radio_core_inc/utilities_conf.h` : `cmsis_compiler.h` retiré, branches `__CC_ARM`,
  `__ICCARM__`, `WIN32` supprimées ; inclus.
- `stm32_radio_core_inc/platform.h` : `main.h` et en-têtes BSP ST en commentaire ; ni compilé ni
  inclus.
Les trois derniers dérivent des fichiers de même nom du répertoire PingPong cité plus haut.
`LICENSE.txt` (avis court ST hors amont, origine probable : génération STM32CubeMX) : retiré en
ENV-48 (décision C2, PA-83). Non projetés : `README.md`, `Release_Notes.*`, `SECURITY.md`,
`_htmresc/`, `.github/`, fichiers de contribution.

Diffs contre l'amont : `doc/devenv/rapports/env-37-wl-provenance/diffs/` du dépôt lepton-tools.
L'adaptation radio de la carte (`stm32_radio_target`) est dans le BSP `nucleo-wl55jc1`.
Compilés : les 5 `stm32_radio_driver/*.c` listés dans `sources` de `lepton-greffon.json`
(`radio.c` du greffon, 4 projetés), résolus par le trunk. Contenu projeté : identique aux commits
épinglés par construction. Exige scion ≥ 0.6.1.0.
Audit : `doc/devenv/rapports/env-37-wl-provenance.md` et `env-48-wl-projection.md` du dépôt
lepton-tools.

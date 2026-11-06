# Provenance (chantier environnement de développement Lepton, ENV-37)

Pile radio SubGHz_Phy V1.3.0. Révision retenue : `stm32-mw-subghz-phy` commit
`1cad76816effd9679a056e57c02dd4b23d7cb772` (tag `v1.3.0`,
https://github.com/STMicroelectronics/stm32-mw-subghz-phy). Licences : Clear BSD Semtech
(`LICENSE`, repris) pour les fichiers d'origine Semtech ; BSD-3-Clause ST (`LICENSE.md` de
l'amont, non repris). Contenu identique à `Middlewares/Third_Party/SubGHz_Phy` de STM32CubeWL
`v1.3.0` (commit `378e461e469ef9826e857f8eda3346cea525b2fa`). Importée sans provenance en
migration, puis par ENV-6 ; auditée en ENV-37 (`doc/devenv/rapports/env-37-wl-provenance.md` du
dépôt lepton-tools).

Correspondance des chemins : racine de l'amont → ce répertoire, sans renommage.

Écarts à la règle D1a (code tiers non modifié), laissés en place (décision PA-61, 2026-11-06) :
- `stm32_radio_driver/radio.c` : **modifié par Lepton**, sans marque : le corps de
  `RadioIsChannelFree` est sous `#if 0` et la fonction rend toujours `false`. Compilé.
- `stm32_radio_core_inc/` : hors amont de la pile. Fichiers d'application STM32CubeMX de
  STM32CubeWL `v1.3.0`, `Projects/NUCLEO-WL55JC/Applications/SubGHz_Phy/SubGHz_Phy_PingPong/Core/Inc/`
  (source admise par la décision PA-61) :
  - `utilities_def.h` : identique ; inclus ;
  - `subghz.h` : modifié par Lepton (`main.h` remplacé par `stm32wlxx_hal.h`) ; inclus ;
  - `utilities_conf.h` : modifié par Lepton (`cmsis_compiler.h` retiré, branches `__CC_ARM`,
    `__ICCARM__`, `WIN32` supprimées) ; inclus ;
  - `platform.h` : modifié par Lepton (`main.h` et en-têtes BSP ST en commentaire) ; ni compilé ni
    inclus.
- `LICENSE.txt` : hors amont (avis court ST renvoyant à BSD-3-Clause, origine non établie).
- Non repris : `LICENSE.md`, `README.md`, `Release_Notes.*`, `SECURITY.md`, `_htmresc/`,
  `.github/`, fichiers de contribution.

Diffs contre l'amont : `doc/devenv/rapports/env-37-wl-provenance/diffs/` du dépôt lepton-tools.
L'adaptation radio de la carte (`stm32_radio_target`) est dans le BSP `nucleo-wl55jc1`.
Compilés : les 5 `stm32_radio_driver/*.c` listés dans `sources` de `lepton-greffon.json`.
Contrôle : `scripts/tiers/verifier-import.sh <clone> v1.3.0 <ce répertoire>` : 18 identiques,
1 `DIFF` (`radio.c`), 5 `TROP` (`LICENSE.txt`, `stm32_radio_core_inc/*`).

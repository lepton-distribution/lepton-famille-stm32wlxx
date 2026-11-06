# Provenance (chantier environnement de développement Lepton, ENV-37)

HAL STM32WL V1.3.0. Révision retenue : `stm32wlxx-hal-driver` commit
`e3966ab429c1711e5dd2b40918e1d987eed7a249` (tag `v1.3.0`,
https://github.com/STMicroelectronics/stm32wlxx-hal-driver), BSD-3-Clause (`LICENSE.md` de
l'amont). Copie identique à `Drivers/STM32WLxx_HAL_Driver` de STM32CubeWL `v1.3.0` (commit
`378e461e469ef9826e857f8eda3346cea525b2fa`, où la HAL est un arbre et non un sous-module).
Importée sans provenance en migration, puis par ENV-6 (commit 8ea1490 de ce greffon) ; auditée en
ENV-37 (`doc/devenv/rapports/env-37-wl-provenance.md` du dépôt lepton-tools).

Correspondance des chemins (amont → ce répertoire) : `Inc/` → `inc/`, `Src/` → `src/` (casse des
répertoires modifiée), `README.md` et `Release_Notes.html` → racine. `inc/` et `src/` complets,
non modifiés (code tiers, D1a). Configuration (`stm32wlxx_hal_conf.h`) dans `dev_stm32wlxx/` de la
famille.

Écarts constatés à la révision retenue :
- `inc/Legacy/stm32_hal_legacy.h` : version de STM32CubeWL `v1.3.0`
  (`#if defined(STM32U5) || defined(STM32MP2)`), différente de celle du tag `v1.3.0` du dépôt
  séparé (`#if defined(STM32U5)`).
- `LICENSE.txt` : hors amont (avis court ST renvoyant à BSD-3-Clause, origine non établie) ;
  `LICENSE.md` de l'amont non repris.
- Non repris : `_htmresc/`, `.github/`, fichiers de contribution.

Compilés : les 12 `src/*.c` listés dans `sources` de `lepton-greffon.json`.
Contrôle : copie de travail remise aux chemins amont
(`doc/devenv/rapports/env-37-wl-provenance/preparer-copies.sh`), puis
`scripts/tiers/verifier-import.sh <clone> v1.3.0 <copie>/hal` : 155 identiques, 1 `DIFF`
(`stm32_hal_legacy.h`), 1 `TROP` (`LICENSE.txt`).

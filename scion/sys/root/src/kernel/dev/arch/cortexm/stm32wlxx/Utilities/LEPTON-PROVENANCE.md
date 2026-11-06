# Provenance (chantier environnement de développement Lepton, ENV-37)

Utilitaires ST de STM32CubeWL. Révision retenue : `STM32CubeWL` commit
`378e461e469ef9826e857f8eda3346cea525b2fa` (tag `v1.3.0`,
https://github.com/STMicroelectronics/STM32CubeWL), sous-arbre `Utilities/`. Seul amont connu des
révisions copiées : `stm32-util-sequencer` et `stm32-util-advanced-trace` n'existent qu'en
versions 2.x réécrites. STM32CubeWL est admis comme source de cet ensemble, par exception étroite
à la décision du 2026-11-04 (décision PA-61, 2026-11-06). BSD-3-Clause ST (`LICENSE.md` de chaque
sous-répertoire amont, non repris). Importés sans provenance en migration, puis par ENV-6 ;
audités en ENV-37 (`doc/devenv/rapports/env-37-wl-provenance.md` du dépôt lepton-tools).

Correspondance des chemins : `Utilities/<d>/` → `<d>/`, sans renommage, pour `conf`, `Fonts`,
`lcd`, `lpm/tiny_lpm`, `misc`, `sequencer`, `timer`, `trace/adv_trace`.

Écarts à la règle D1a (code tiers non modifié), laissés en place (décision PA-61, 2026-11-06) :
- `timer/stm32_timer.h` : **modifié par Lepton** (`#include <cmsis_compiler.h>` mis en
  commentaire, « lepton removed ») ; inclus.
- `LICENSE.txt` dans `conf/`, `lpm/tiny_lpm/`, `misc/`, `sequencer/`, `timer/`,
  `trace/adv_trace/` : hors amont (avis court ST renvoyant à BSD-3-Clause, origine non établie).
- Non repris : `LICENSE.md`, notes de version, `_htmresc/`, `sequencer/html/`, `PC_Software/`.

Compilé : `misc/stm32_mem.c` (`sources` de `lepton-greffon.json`) ; inclus :
`misc/stm32_mem.h`, `misc/stm32_tiny_vsnprintf.h`, `timer/stm32_timer.h`,
`trace/adv_trace/stm32_adv_trace.h`.
Contrôle : copie de travail remise aux chemins amont
(`doc/devenv/rapports/env-37-wl-provenance/preparer-copies.sh`), puis
`scripts/tiers/verifier-import.sh <clone STM32CubeWL> v1.3.0 <copie>/cube-util` : 32 identiques,
1 `DIFF` (`stm32_timer.h`), 6 `TROP` (`LICENSE.txt`).

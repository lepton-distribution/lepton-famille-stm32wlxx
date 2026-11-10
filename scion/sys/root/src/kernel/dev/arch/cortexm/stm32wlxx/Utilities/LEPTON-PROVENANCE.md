# Provenance (chantier environnement de développement Lepton, ENV-37, ENV-48, ENV-49)

Utilitaires ST de STM32CubeWL : `STM32CubeWL` tag `v1.6.0` = commit
`f934cd298bf82d45f96aac2f335c0bbd26d0b946` (amont https://github.com/STMicroelectronics/STM32CubeWL),
sous-arbre `Utilities/` (dans l'arbre, pas un sous-module), du même STM32CubeWL que la HAL V1.6.0,
le CMSIS device V1.4.0 et la pile radio V1.5.0 de la famille (ENV-49, décision PA-85). Seul amont
connu des révisions utilisées : `stm32-util-sequencer` et `stm32-util-advanced-trace` n'existent
qu'en versions 2.x réécrites. STM32CubeWL est admis comme source de cet ensemble, par exception
étroite à la décision du 2026-11-04 (décision PA-61, 2026-11-06). BSD-3-Clause ST (`LICENSE.md` des
sous-répertoires amont qui en ont un).

Ce répertoire n'est pas une copie : scion **projette** les fichiers de STM32CubeWL (clé
`tiers@stm32cubewl::utilities`, déclarée dans `scion/.scion/` de ce greffon, qui la porte).
Source : miroir de conservation complet https://github.com/lepton-distribution/mirror-STM32CubeWL.git
(tenu par `scion mirror-sync`) ; clone partiel sous `<rootstock>/depots/tiers/stm32cubewl/v1.6.0`,
au commit du tag, partagé avec `tiers@stm32cubewl::radio-core-inc` (`radio_subghz_phy/`). Le clone
extrait l'arbre de `v1.6.0` (8 947 fichiers, environ 156 Mo ; les composants y sont des
sous-modules, non clonés) : scion n'a pas d'extraction partielle. Fichiers projetés :
- `Utilities/<d>/*.[ch]` → `<d>/` pour `conf`, `Fonts`, `lcd`, `lpm/tiny_lpm`, `misc`,
  `sequencer`, `timer`, `trace/adv_trace` (32 fichiers) ;
- `Utilities/<d>/LICENSE.md` → `<d>/` pour `conf`, `lpm/tiny_lpm`, `misc`, `sequencer`, `timer`,
  `trace/adv_trace` (6 fichiers).
Non projetés : notes de version, `_htmresc/`, `PC_Software/`.

Restent dans le greffon, exclus de la projection :
- `timer/stm32_timer.h` : **modifié par Lepton** (`#include <cmsis_compiler.h>` mis en
  commentaire, « lepton removed ») ; inclus (écart à D1a, décision PA-61). Reporté en ENV-49 sur le
  fichier de `v1.6.0` (déclaration de `UTIL_TIMER_GetTimerList` ajoutée en amont) ; correctif :
  `doc/devenv/rapports/env-49-wl-hal/propose/reports/lepton-timer.patch` du dépôt lepton-tools ;
- ce fichier.
`LICENSE.txt` ×6 (avis court ST hors amont) : retirés en ENV-48 (décision C2, PA-83).

Compilé : `misc/stm32_mem.c` (`sources` de `lepton-greffon.json`, résolu par le trunk) ; inclus :
`misc/stm32_mem.h`, `misc/stm32_tiny_vsnprintf.h`, `timer/stm32_timer.h`,
`trace/adv_trace/stm32_adv_trace.h`. `timer/stm32_timer.c` n'est pas compilé
(`dev_stm32wlxx/dev_stm32wlxx_util_timer.c` fournit les deux fonctions de temps de la pile radio).
Contenu projeté : identique à `v1.6.0` par construction. Exige scion ≥ 0.6.1.0.
Mise à jour : changer la version de la clé `stm32cubewl::utilities` et celle de
`stm32cubewl::radio-core-inc` ensemble (même clone), reporter `timer/stm32_timer.h`, puis regreffer.
Audit : `doc/devenv/rapports/env-37-wl-provenance.md`, `env-48-wl-projection.md` et
`env-49-wl-hal.md` du dépôt lepton-tools.

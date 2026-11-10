# Provenance (chantier environnement de développement Lepton, ENV-37, ENV-48)

HAL STM32WL V1.3.0 : `stm32wlxx-hal-driver` tag `v1.3.0` = commit
`e3966ab429c1711e5dd2b40918e1d987eed7a249` (amont
https://github.com/STMicroelectronics/stm32wlxx-hal-driver), BSD-3-Clause (`LICENSE.md`).
Identique à `Drivers/STM32WLxx_HAL_Driver` de STM32CubeWL `v1.3.0` (commit
`378e461e469ef9826e857f8eda3346cea525b2fa`, où la HAL est un arbre et non un sous-module), sauf
`stm32_hal_legacy.h` (ci-dessous). Code tiers non modifié (D1a).

Depuis ENV-48, ce répertoire n'est plus une copie : scion **projette** les fichiers du dépôt tiers
(clé `tiers@stm32wlxx-hal-driver`, déclarée dans `scion/.scion/` de ce greffon, qui la porte).
Source : miroir de conservation https://github.com/lepton-distribution/mirror-stm32wlxx-hal-driver.git
(tenu par `scion mirror-sync`, `scion/.scion/.scion.mirrors`) ; clone partiel sous
`<rootstock>/depots/tiers/stm32wlxx-hal-driver/v1.3.0`, au commit du tag. Fichiers projetés :
`Inc/**` → `inc/`, `Src/**` → `src/` (la projection change la casse des répertoires),
`README.md`, `Release_Notes.html` et `LICENSE.md` → racine (156 fichiers) ; `_htmresc/`,
`.github/` et fichiers de contribution non projetés. Configuration (`stm32wlxx_hal_conf.h`) dans
`dev_stm32wlxx/` de la famille.

Restent dans le greffon, exclus de la projection :
- `inc/Legacy/stm32_hal_legacy.h` : version de STM32CubeWL `v1.3.0`
  (`#if defined(STM32U5) || defined(STM32MP2)`), différente de celle du tag `v1.3.0` du dépôt
  séparé (`#if defined(STM32U5)`) ; copie conservée, une clé n'ayant qu'une révision ;
- ce fichier.
`LICENSE.txt` (avis court ST hors amont, origine probable : génération STM32CubeMX) : retiré en
ENV-48 (décision C2, PA-83), remplacé par le `LICENSE.md` projeté.

Compilés : les 12 `src/*.c` listés dans `sources` de `lepton-greffon.json`, résolus par le trunk.
Contenu : identique à `v1.3.0` par construction (liens vers le clone tiers, que la greffe refuse
hors de son commit épinglé ou modifié). Exige scion ≥ 0.6.1.0.
Mise à jour : changer la version de la clé dans `scion/.scion/` (`.scion.sources.list`,
`.scion.ramifications`), avec le CMSIS device et la pile radio du même STM32CubeWL, reporter
`stm32_hal_legacy.h`, puis regreffer.
Audit : `doc/devenv/rapports/env-37-wl-provenance.md` et `env-48-wl-projection.md` du dépôt
lepton-tools.

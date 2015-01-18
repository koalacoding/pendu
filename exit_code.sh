#!/bin/bash

set -o nounset  # sortir en cas de variable non initialisée
set -o errexit  # sortir à la moindre erreur

echo $var
ls -__
echo toto

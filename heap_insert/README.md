# Binary Trees

## Description
Ce projet porte sur la manipulation des arbres binaires en langage C, ainsi que sur l’implémentation d’un tas binaire maximal (*Max Binary Heap*).

## Exigences
- Compilation avec `gcc 4.8.4` et les options `-Wall -Werror -Wextra -pedantic`.
- Respect du style **Betty**.
- Aucun usage de variables globales.
- Maximum de 5 fonctions par fichier.
- Tous les prototypes doivent être déclarés dans `binary_trees.h`.
- Les fichiers d’en-tête doivent utiliser des gardes d’inclusion.
- Tous les fichiers doivent se terminer par une nouvelle ligne.

## Structures de données
Le projet utilise une structure d’arbre binaire contenant :
- `n` : la valeur du nœud.
- `parent` : un pointeur vers le parent.
- `left` : un pointeur vers le fils gauche.
- `right` : un pointeur vers le fils droit.

Le type `heap_t` est un alias de `struct binary_tree_s`.

## Compilation
Les fichiers sont compilés sous Ubuntu 14.04 LTS avec GCC 4.8.4.

## Tests
Des fichiers `main.c` peuvent être utilisés pour tester les fonctions, mais ils ne sont pas obligatoires dans le dépôt. Une fonction d’affichage est également fournie pour visualiser les arbres.

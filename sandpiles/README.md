# Sandpiles

## Description

Le projet **Sandpiles** consiste à implémenter en langage C un système de tas de sable (*sandpile model*). Il permet d'additionner deux grilles de sable de dimension 3 × 3, puis de stabiliser le résultat en redistribuant les grains lorsque certaines cases dépassent une limite.

Ce projet permet de comprendre les tableaux à deux dimensions, les fonctions récursives ou itératives et les mécanismes de stabilisation.

## Règles du jeu

Le système utilise une grille de 3 × 3. Chaque case contient un certain nombre de grains de sable.

- Lorsqu'une case contient **4 grains ou plus**, elle devient instable.
- Une case instable perd 4 grains.
- Un grain est ajouté à chacune de ses quatre cases voisines : haut, bas, gauche et droite.
- Les grains qui sortent de la grille sont perdus.
- Le processus est répété jusqu'à ce que toutes les cases soient stables, c'est-à-dire qu'elles contiennent au maximum 3 grains.

## Prototype

```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```

La fonction additionne les deux grilles, puis stabilise `grid1` en redistribuant les grains jusqu'à obtenir une configuration stable.

## Compilation

Le projet est compilé avec GCC et les options suivantes :

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o sandpiles
```

## Contraintes

- Langage : C.
- Compilateur : GCC 4.8.4.
- Respect du style Betty.
- Aucune variable globale.
- Maximum de 5 fonctions par fichier.
- Tous les prototypes doivent être déclarés dans `sandpiles.h`.
- Le fichier d'en-tête doit comporter une protection contre les inclusions multiples.
- Tous les fichiers doivent se terminer par une nouvelle ligne.

## Fichiers du projet

- `sandpiles.h` : contient les prototypes des fonctions.
- `sandpiles.c` : contient l'implémentation de l'addition et de la stabilisation des grilles.

## Exemple

Grille 1 :

```text
3 3 3
3 3 3
3 3 3
```

Grille 2 :

```text
1 1 1
1 1 1
1 1 1
```

Après l'addition, certaines cases dépassent le seuil de stabilité. Le système redistribue alors les grains jusqu'à ce que toutes les cases contiennent au maximum 3 grains.

## Ressource

- [Sandpiles – Numberphile](https://intranet.hbtn.io/rltoken/6Ft_wbSkMejwmfJQQjISlw)

## Auteur

Projet réalisé dans le cadre du cursus Holberton School.


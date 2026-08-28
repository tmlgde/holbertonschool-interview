Lockboxes
Description
Ce projet résout un problème classique de parcours de graphe : déterminer si une série de coffres verrouillés peuvent tous être ouverts, sachant que certains coffres contiennent les clés d'autres coffres.
Énoncé
On dispose de n coffres numérotés de 0 à n - 1. Chaque coffre peut contenir des clés permettant d'ouvrir d'autres coffres.

Le coffre boxes[0] est déjà déverrouillé au départ.
Une clé portant le numéro i permet d'ouvrir le coffre i.
Certaines clés peuvent ne correspondre à aucun coffre existant.
Toutes les clés sont des entiers positifs.

Le but : écrire une fonction qui détermine si, en partant du coffre 0, on peut ouvrir tous les coffres.
Prototype
def canUnlockAll(boxes)

boxes : une liste de listes. boxes[i] contient les clés présentes dans le coffre i.
Retourne True si tous les coffres peuvent être ouverts, sinon False.
Approche
L'algorithme utilisé est un parcours de graphe (proche d'un DFS itératif) :

On part du coffre 0, déjà ouvert.
On explore son contenu et on récupère ses clés.
Pour chaque clé valide (qui correspond à un coffre existant et pas encore ouvert), on déverrouille le coffre correspondant et on l'ajoute à la liste des coffres à explorer.
On répète l'opération jusqu'à ce qu'il n'y ait plus aucun coffre à explorer.
On vérifie si tous les coffres ont été ouverts.

Deux structures sont utilisées :

ouvert : une liste de booléens qui garde en mémoire, de façon permanente, quels coffres ont déjà été ouverts.
a_ouvrir : une liste de travail contenant les coffres restant à explorer.
Exemple
canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]

print(canUnlockAll(boxes))

# True

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]

print(canUnlockAll(boxes))

# True

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]

print(canUnlockAll(boxes))

# False

Dans le troisième exemple, le coffre 3 (via le coffre 2) et le coffre 6 ne sont jamais atteints par une chaîne de clés partant du coffre 0 : la fonction renvoie donc False.
Fichiers
Fichier
Description
0-lockboxes.py
Contient la fonction canUnlockAll

Utilisation
./0-main.py
Auteur
Projet réalisé dans le cadre de la préparation aux interviews techniques (Holberton School).



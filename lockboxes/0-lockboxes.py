#!/usr/bin/python3
"Module qui determine si tous les coffres peuvent êtres ouverts ou non"
def canUnlockAll(boxes):
    n = len(boxes)
    ouvert = [False] * n
    ouvert[0] = True
    a_ouvrir = [0]

    while a_ouvrir:
        coffre_actuel = a_ouvrir.pop()
        for cle in boxes[coffre_actuel]:
            if cle < n and not ouvert[cle]:
                ouvert[cle] = True
                a_ouvrir.append(cle)
    return all(ouvert)

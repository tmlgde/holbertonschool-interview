#!/usr/bin/python3
"""Lit des logs sur stdin et affiche des statistiques"""
import sys


def afficher(taille_totale, compteurs):
    """Affiche la taille totale et le nombre de lignes par code"""
    print("File size: {}".format(taille_totale))
    for code in sorted(compteurs):
        if compteurs[code] != 0:
            print("{}: {}".format(code, compteurs[code]))


if __name__ == "__main__":
    taille_totale = 0
    nb_lignes = 0
    compteurs = {"200": 0, "301": 0, "400": 0, "401": 0,
                 "403": 0, "404": 0, "405": 0, "500": 0}

    try:
        for ligne in sys.stdin:
            nb_lignes += 1
            morceaux = ligne.split()

            try:
                code = morceaux[-2]
                if code in compteurs:
                    compteurs[code] += 1
            except IndexError:
                pass

            try:
                taille_totale += int(morceaux[-1])
            except (ValueError, IndexError):
                pass

            if nb_lignes % 10 == 0:
                afficher(taille_totale, compteurs)

    except KeyboardInterrupt:
        afficher(taille_totale, compteurs)
        raise

    afficher(taille_totale, compteurs)

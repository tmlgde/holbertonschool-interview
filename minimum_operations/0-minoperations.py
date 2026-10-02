#!/usr/bin/python3
"""calcule le nombre minimale d'operations avec chiffres premiers"""


def minOperations(n) -> int:
    """nombre d'operations minimales pour arriver a un nombre/chiffre"""
    total = 0
    diviseur = 2
    while n > 1:
        if n % diviseur == 0:
            total += diviseur
            n //= diviseur
        else:
            diviseur += 1
    return total

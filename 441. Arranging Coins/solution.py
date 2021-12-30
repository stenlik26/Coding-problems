def arrangeCoins(self, n: int) -> int:
    d = 1 + (4 * 2 *n)
    k = (-1 + math.sqrt(d))
    k /= 2
    return int(k)
def func(jewels: str, stones):
    letters = {}
    rez = 0
    for c in stones:
        try: 
            letters[c] += 1
        except KeyError:
            letters[c] = 1

    for c in jewels:
        try: 
            if letters[c] != 0:
                rez += letters[c]
        except KeyError:
            continue

    return rez


if __name__ == "__main__":
    print(func('aA', 'aAAbbbb'))
    print(func('z', 'ZZ'))
def func(word: str):

    lowercase = 0
    uppercase = 0

    for c in word:
        if ord(c) < 97:
            uppercase += 1
        else:
            lowercase += 1

    if uppercase == 1 and lowercase != 0:
        if ord(word[0]) < 97:
            return True
        else:
            return False
    else:
        return(uppercase == 1 or uppercase == 0 or lowercase == 0)    


if __name__ == "__main__":
    print(func('USA'))
    print(func('leetcode'))
    print(func('Google'))
    print(func('FlaG'))
    print(func("ffffffffffffffffffffF"))
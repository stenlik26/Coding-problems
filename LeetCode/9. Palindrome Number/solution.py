def isPalindrome(self, x: int) -> bool:
    if x < 0:
        return False
    xs = str(x)
    xl = len(xs)
    print(xs,xl)
    if xl % 2 == 0:
        for i in range(int(xl / 2)):
            print(xs[i] + " " + xs[xl - 1 - i] + " " + str(i))
            if xs[i] != xs[xl - 1 - i]:
                return False               
        return True
    else:
        for i in range(int((xl - 1) / 2)):
            print(xs[i] + " " + xs[xl - 1 - i] + " " + str(i))
            if xs[i] != xs[xl - 1 - i]:
                return False               
        return True
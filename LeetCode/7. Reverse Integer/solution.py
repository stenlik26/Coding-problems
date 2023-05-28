def reverse(self, x: int) -> int:
    returnNum = 0
    minus = False
    if x < 0:
        x = abs(x)
        minus = True
    while(x != 0):
        num = x % 10
        x //= 10
        returnNum += num
        returnNum *= 10 
        print(str(x) + " " + str(num))
    
    returnNum //= 10

    if returnNum > 2**31 - 1:
        return 0
    
    if minus == True:
        return returnNum * -1
    else:
        return returnNum
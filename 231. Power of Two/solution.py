class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        
        if n == 0 or n < 0:
            return False
        
        x = math.log(n, 2)

        print(x)

        y = str(x)
        y = y.split('.')[1]

        print(x, y)

        if len(y) == 1 and y == '0':
            return True

        if len(y) >= 9 and y[:9] == '000000000':
            return True

        return False
        
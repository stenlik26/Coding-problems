class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        odd = 1
        while num != 0:
            if num - odd < 0:
                return False
            num -= odd
            odd += 2
        return True
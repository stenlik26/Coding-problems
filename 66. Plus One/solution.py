def plusOne(self, digits: List[int]) -> List[int]:
    digits_len = len(digits)
    for x in reversed(range(digits_len)):
        if int(digits[x]) != 9:
            digits[x] = digits[x] + 1
            print(digits[x])
            break
        else:
            digits[x] = 0

    if digits[0] == 0:
        digits.insert(0, 1)
    return digits
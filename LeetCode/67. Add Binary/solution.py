def addBinary(self, a: str, b: str) -> str:
    la = len(a)
    lb = len(b)
    if la > lb:
        diff = (la - lb) * '0'
        b = diff + b
        lb = la
    elif lb > la:
        diff = (lb - la) * '0'
        a = diff + a
        la = lb

    l = la - 1
    x = 0
    res = ''
    print(a, b, l)
    print('----------')
    while l != -1:
        print(a[l], b[l], x)
        if a[l] == '0' and b[l] == '0':
            if x >= 1:
                res += '1'
                x = 0
            else:
                res += '0'
        elif (a[l] == '0' and b[l] == '1') or (a[l] == '1' and b[l] == '0'):
            if x >= 1:
                res += '0'
            else:
                res += '1'
        elif a[l] == '1' and b[l] == '1':
            if x >= 1:
                res += '1'
                x += 1
            else:
                res += '0'
                x += 1
        l -= 1
    if x >= 1:
        res += '1'
    res = res[::-1]
    return res
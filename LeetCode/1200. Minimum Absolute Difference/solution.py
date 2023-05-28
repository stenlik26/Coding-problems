def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
    arr.sort()
    x = len(arr) - 1
    result = []
    mindiff = arr[1] - arr[0]
    for i in range(x):
        diff = arr[i+1] - arr[i]
        if mindiff > diff:
            mindiff = diff
        res = [arr[i], arr[i + 1]]
        result.append((res, diff))

    finalres = []
    for x in result:
        if x[1] == mindiff:
            finalres.append(x[0])

    return finalres
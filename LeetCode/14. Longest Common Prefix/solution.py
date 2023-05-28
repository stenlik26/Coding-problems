def longestCommonPrefix(self, strs: List[str]) -> str:
    res = ""
    for i in range(len(strs[0])):
        for j in range(len(strs)):
            #print([strs[0][:i+1],strs[j]])
            if not strs[j].startswith(strs[0][:i+1]):
                res = strs[0][:i]
                return res
            res = strs[0][:i+1]
    return res
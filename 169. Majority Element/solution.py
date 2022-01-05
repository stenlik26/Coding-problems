def majorityElement(self, nums: List[int]) -> int:
    d = {}
    for num in nums:
        if num in d.keys():
            d[num] += 1
        else:
            d[num] = 1
    maxelement = d[nums[0]]
    printelement = nums[0]
    for key in d.keys():
        print(maxelement, d[key])
        if maxelement < d[key]:
            maxelement = d[key]
            printelement = key
    return printelement

target = 7
nums = [1,3,5,6]

t = 0
for i in range(len(nums)):
    value = nums[i]
    if value > target:
        print('here',t)
        break
    if value == target:
        print('here2',i)
        break
    if value < target:
        t += 1

print(t)
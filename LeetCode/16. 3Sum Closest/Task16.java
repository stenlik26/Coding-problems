import java.util.Arrays;

class Task16 {

    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);

        int closest = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length - 1; i++) {
            int x = nums[i];
            int l = i + 1;
            int r = nums.length - 1;
            while (l < r) {
                int current = x + nums[l] + nums[r];
                if (Math.abs(target - current) < Math.abs(target - closest)){
                    closest = current;
                }
                if(current > target){
                    r--;
                }
                else if(current < target){
                    l++;
                }
                else{
                    return target;
                }
            }
        }
        return closest;
    }

    public static void main(String[] args) {

    }
}
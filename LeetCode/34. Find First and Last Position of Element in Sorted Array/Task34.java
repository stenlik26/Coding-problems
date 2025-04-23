class Task34 {

    public int binSearchAny(int[] nums, int target, boolean high) {
        int l = 0, r = nums.length - 1, idx = (l + r) / 2;

        while (l <= r) {
            idx = l + (r - l) / 2;
            if (nums[idx] < target) {
                l = idx + 1;
            } else if (nums[idx] > target) {
                r = idx - 1;
            } else if (!high && idx != 0 && nums[idx] == target && nums[idx] == nums[idx - 1]) {
                r = idx - 1;
            } else if (high && idx != nums.length - 1 && nums[idx] == target && nums[idx] == nums[idx + 1]) {
                l = idx + 1;
            } else if(nums[idx] == target){
                return idx;
            }
        }
        return -1;
    }

    public int[] searchRange(int[] nums, int target) {

        int low = binSearchAny(nums, target, false);
        int high = binSearchAny(nums, target, true);
        System.out.println(low);
        System.out.println(high);
        return new int[] {low, high};
    }

    public static void main(String[] args) {
        Task34 x = new Task34();
        System.out.println(x.searchRange(new int[] {1, 1}, 8));
        System.out.println(x.searchRange(new int[] {}, 6));
    }
}
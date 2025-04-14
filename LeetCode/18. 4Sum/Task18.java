import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

class Task18 {

    public List<List<Integer>> fourSum(int[] nums, int target) {
        //List<List<Integer>> results = new LinkedList<>();
        Set<List<Integer>> results = new HashSet<>();

        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 3; i++) {
            for (int j = i + 1; j < (nums.length - 2); j++) {
                int l = j + 1;
                int r = nums.length - 1;

                while (l < r) {
                    long res = nums[i];
                    res += nums[j];
                    res += nums[r];
                    res += nums[l];

                    if (res < (long)target) {
                        l++;
                    } else if (res > (long)target) {
                        r--;
                    } else {
                        results.add(List.of(nums[i], nums[j], nums[l], nums[r]));
                        l++;
                    }
                }
            }
        }

        return results.stream().toList();
    }

    public static void main(String[] args) {
        Task18 x = new Task18();
        System.out.println(x.fourSum(new int[] {1000000000,1000000000,1000000000,1000000000}, -294967296));
        System.out.println(x.fourSum(new int[] {2, 2, 2, 2, 2}, 8));
    }
}
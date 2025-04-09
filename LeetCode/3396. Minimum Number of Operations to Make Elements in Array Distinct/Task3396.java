import java.util.HashSet;
import java.util.Set;

class Task3396 {

    public int minimumOperations(int[] nums) {
        int n = nums.length;
        int offset = n % 3;
        int start = (offset == 0) ? n - 3 : n - offset;

        Set<Integer> seen = new HashSet<>();

        while (start >= 0) {
            for (int i = start; i < start + 3; i++) {
                if (i >= n) {
                    break;
                }
                if (seen.contains(nums[i])) {
                    return (int) Math.ceil((i + 1) / 3.0);
                }
                seen.add(nums[i]);
            }
            start -= 3;
        }
        return 0;
    }

    public static void main(String[] args) {
        Task3396 x = new Task3396();
//        System.out.println(x.minimumOperations(new int[] {1, 2, 3, 4, 2, 3, 3, 5, 7}));
//        System.out.println(x.minimumOperations(new int[] {4,5,6,4,4}));
//        System.out.println(x.minimumOperations(new int[] {6,7,8,9}));
        System.out.println(x.minimumOperations(new int[] {3,7,7,3}));
    }
}
import java.util.Arrays;
import java.util.Comparator;

class Task31 {

    public void sortLexicoSub(int[] arr, int from) {
        Arrays.sort(arr, from, arr.length);
    }

    public void nextPermutation(int[] nums) {
        int i = nums.length - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }
        if (i == 0) {
            sortLexicoSub(nums, 0);
        } else {
            i--;
            int x = nums[i];
            sortLexicoSub(nums, i);

            for (int j = i; j < nums.length; j++) {
                if (nums[j] == x) {
                    while (j < nums.length && nums[j] == x) {
                        j++;
                    }
                    if (j < nums.length) {
                        int temp = nums[j];
                        nums[j] = nums[i];
                        nums[i] = temp;
                    }
                    break;
                }
            }
            sortLexicoSub(nums, i + 1);
        }
    }

    public static void main(String[] args) {
        Task31 x = new Task31();
        int[] arr = new int[] {11, 12, 0, 27, 3, 11, 21, 9, 0, 15, 26, 27, 17, 24, 0, 16, 4,
            17, 14, 8, 15, 8, 2, 16, 10, 6, 6, 24, 16, 2, 18, 19, 6, 10, 17, 10, 21, 0, 11, 13, 7, 7, 2, 16, 24, 25, 2,
            20, 12, 9, 20, 19};
        x.nextPermutation(arr);
        for (int z : arr) {
            System.out.print(z);
            System.out.print(" ");
        }
    }
}
import java.util.Arrays;
import java.util.Collections;

class Task1399 {

    public int digitSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public int countLargestGroup(int n) {
        int[] counts = new int[50];
        for (int i = 1; i <= n; i++) {
            counts[digitSum(i)]++;
        }
        int res = 1;
        Arrays.sort(counts);

        for (int i = 49; i >= 1; i--) {
            if (counts[i] != counts[i - 1]) {
                break;
            }
            res++;
        }
        return res;
    }

    public static void main(String[] args) {
        Task1399 x = new Task1399();

        System.out.println(x.countLargestGroup(13));
    }
}
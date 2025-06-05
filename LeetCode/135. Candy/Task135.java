import java.util.Arrays;

class Task135 {

    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] res = new int[n];
        Arrays.fill(res, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                res[i] = res[i - 1] + 1;
            }
        }

        for (int i = n - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                res[i - 1] = Math.max(res[i] + 1, res[i - 1]);
            }
        }

        return Arrays.stream(res).sum();
    }

    public static void main(String[] args) {
        Task135 x = new Task135();

        System.out.println(x.candy(new int[] {1, 2, 2}));

    }

}
class Task1295 {

    public boolean isEvenDigit(int x) {
        return (x >= 10 && x <= 99) || (x >= 1000 && x <= 9999) || (x == 100000);
    }

    public int findNumbers(int[] nums) {
        int cnt = 0;
        for (int x : nums) {
            if (isEvenDigit(x)) {
                cnt++;
            }
        }
        return cnt;
    }

    public static void main(String[] args) {

    }
}
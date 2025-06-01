class Task2929 {

    public long distributeCandies(int n, int limit) {
        long res = 0;
        long to = Math.min(limit, n);
        for (long i = 0; i <= to; i++) {
            res += Math.max(Math.min(limit, n - i) - Math.max(0, n - i - limit) + 1, 0);
        }
        return res;
    }

    public static void main(String[] args) {

    }
}
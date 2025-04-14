class Task1534 {

    public boolean isGoodTriplet(int[] arr, int a, int b, int c, int i, int j, int k) {
        return Math.abs(arr[i] - arr[j]) <= a && Math.abs(arr[j] - arr[k]) <= b && Math.abs(arr[i] - arr[k]) <= c;
    }

    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int cnt = 0;

        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (Math.abs(arr[i] - arr[j]) > a) {
                    continue;
                }
                for (int k = j + 1; k < arr.length; k++) {
                    if (isGoodTriplet(arr, a, b, c, i, j, k)) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }

    public static void main(String[] args) {

    }
}
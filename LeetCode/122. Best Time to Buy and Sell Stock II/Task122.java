class Task122 {

    public int maxProfit(int[] prices) {
        int[] diff = new int[prices.length - 1];
        int res = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            diff[i] = prices[i + 1] - prices[i];
        }

        for (int i = 0; i < prices.length - 1; i++) {
            if (diff[i] > 0) {
                res += diff[i];
            }
        }
        return res;
    }

    public static void main(String[] args) {

    }
}
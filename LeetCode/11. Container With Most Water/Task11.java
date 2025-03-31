class Task11 {

    //Recursive version
    public int maxAreaRec(int[] height, int maxV, int i, int j) {
        if (i >= j) {
            return maxV;
        }
        int curV = (j - i) * Math.min(height[i], height[j]);
        maxV = Math.max(curV, maxV);

        if (height[i] == height[j]) {
            int a = maxAreaRec(height, maxV, i + 1, j);
            int b = maxAreaRec(height, maxV, i, j - 1);
            return Math.max(a, b);
        } else if (height[i] < height[j]) {
            return maxAreaRec(height, maxV, i + 1, j);
        } else {
            return maxAreaRec(height, maxV, i, j - 1);
        }
    }

    public int maxAreaRecursive(int[] height) {
        return maxAreaRec(height, 0, 0, height.length - 1);
    }

    //Iterative version
    public int maxArea(int[] height) {
        int i = 0;
        int j = height.length - 1;
        int maxV = 0;
        while (i < j) {
            int curV = (j - i) * Math.min(height[i], height[j]);
            maxV = Math.max(curV, maxV);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxV;
    }

    public static void main(String[] args) {
        Task11 x = new Task11();
        System.out.println(x.maxArea(new int[] {1, 8, 6, 2, 5, 4, 8, 3, 7}));
        System.out.println(x.maxAreaRec(new int[] {1, 8, 6, 2, 5, 4, 8, 3, 7}, 0, 0, 8));
    }
}
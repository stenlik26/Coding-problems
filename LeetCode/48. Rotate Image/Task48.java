class Task48 {

    public void rotate(int[][] matrix) {
        int n = matrix.length;

        //Transpose over main diagonal & diag
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i / 2; j++) {
                int t = matrix[j][i - j];
                matrix[j][i - j] = matrix[i - j][i - (i - j)];
                matrix[i - j][i - (i - j)] = t;
            }
        }

        //Transpose under main diag
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 0; j < (n - i) / 2; j++) {
                int t = matrix[i + j][n - 1 - j];
                matrix[i + j][n - 1 - j] = matrix[n - 1 - j][i + j];
                matrix[n - 1 - j][i + j] = t;
            }
        }
        //Reverse rows
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = t;
            }
        }
    }

    public static void main(String[] args) {
        int[][] mat = new int[][] {
            new int[] {1, 2, 3},
            new int[] {4, 5, 6},
            new int[] {7, 8, 9},
        };

//        int[][] mat = new int[][] {
//            new int[] {1, 2, 3, 4},
//            new int[] {5, 6, 7, 8},
//            new int[] {9, 10, 11, 12},
//            new int[] {13, 14, 15, 16}
//        };

        Task48 p = new Task48();
        p.rotate(mat);

        for (int[] arr : mat) {
            for (int x : arr) {
                System.out.print(x);
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}
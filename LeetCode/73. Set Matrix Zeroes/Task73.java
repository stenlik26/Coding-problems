class Task73 {

    public void setZeroes(int[][] matrix) {
        boolean firstRow = false;
        boolean firstCol = false;
        for (int r = 0; r < matrix.length; r++) {
            for (int c = 0; c < matrix[0].length; c++) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;

                    if (c == 0) {
                        firstCol = true;
                    }

                    matrix[r][0] = 0;

                    if (r == 0) {
                        firstRow = true;
                    }
                }
            }
        }

        for (int r = matrix.length - 1; r >= 1; r--) {
            for (int c = matrix[0].length - 1; c >= 1; c--) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (firstCol) {
            for (int r = 0; r < matrix.length; r++) {
                matrix[r][0] = 0;
            }
        }
        if (firstRow) {
            for (int c = 0; c < matrix[0].length; c++) {
                matrix[0][c] = 0;
            }
        }
    }

    public static void main(String[] args) {
        Task73 x = new Task73();
        x.setZeroes(new int[][] {
            new int[] {1, 2, 3, 4},
            new int[] {5, 0, 7, 8},
            new int[] {0, 10, 11, 12},
            new int[] {13, 14, 15, 0}
        });
    }

}
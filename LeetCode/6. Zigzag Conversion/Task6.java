import java.util.Arrays;

class Task6 {

    int pos = 0;
    char[] sChar;

    private char safeGetLetter() {
        if (pos >= sChar.length) {
            return ' ';
        } else {
            return sChar[pos++];
        }
    }

    private void fillSegment(char[][] matrix, int col, int numRows) {
        for (int i = 0; i < numRows; i++) {
            matrix[i][col] = safeGetLetter();
        }

        for (int o = 1; o <= numRows - 2; o++) {
            matrix[numRows - 1 - o][col + o] = safeGetLetter();
        }
    }

    public String convert(String s, int numRows) {
        int fragmentSize = 1 + (numRows - 2);
        int fragmentCapacity = (2 * numRows) - 2;
        if(numRows == 1){
            fragmentCapacity = 1;
            fragmentSize = 1;
        }

        int neededCols = (int) (Math.ceil((double) s.length() / fragmentCapacity) * fragmentSize);

        char[][] matrix = new char[numRows][neededCols];
        for (char[] chars : matrix) {
            Arrays.fill(chars, ' ');
        }
        sChar = s.toCharArray();

        for (int i = 0; i < neededCols; i += fragmentSize) {
            fillSegment(matrix, i, numRows);
        }
        StringBuilder sb = new StringBuilder();
        for (char[] chars : matrix) {
            for (char aChar : chars) {
                if (aChar != ' ') {
                    sb.append(aChar);
                }
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        Task6 x = new Task6();
        System.out.println(x.convert("A", 1));
    }
}
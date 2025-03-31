import java.util.Map;

class Task12 {

    public String intToRoman(int num) {
        Map<Integer, Character> romanMap = Map.of(
            1, 'I',
            5, 'V',
            10, 'X',
            50, 'L',
            100, 'C',
            500, 'D',
            1000, 'M'
        );
        StringBuilder result = new StringBuilder();

        for (int i = 1000; i >= 1; i /= 10) {
            int digit = num / i;
            num %= i;

            if (digit == 0)
                continue;

            if (digit == 4 || digit == 9) {
                result.append(romanMap.get(i));
                result.append(romanMap.get((digit + 1) * i));
            } else {
                int rem = digit;
                if (digit >= 5) {
                    rem = digit - 5;
                    result.append(romanMap.get(5 * i));
                }
                for (int j = 0; j < rem; j++) {
                    result.append(romanMap.get(i));
                }
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Task12 x = new Task12();
        System.out.println(x.intToRoman(58));
    }
}
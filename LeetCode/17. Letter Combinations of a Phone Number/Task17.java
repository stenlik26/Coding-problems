import java.util.LinkedList;
import java.util.List;
import java.util.Map;

class Task17 {

    private Map<String, List<String>> mapping = Map.of(
        "2", List.of("a", "b", "c"),
        "3", List.of("d", "e", "f"),
        "4", List.of("g", "h", "i"),
        "5", List.of("j", "k", "l"),
        "6", List.of("m", "n", "o"),
        "7", List.of("p", "q", "r", "s"),
        "8", List.of("t", "u", "v"),
        "9", List.of("w","x", "y", "z")
    );

    public List<String> letterCombinations(String digits) {
        if(digits.isBlank()){
            return List.of();
        }
        if (digits.length() == 1) {
            return mapping.get(digits);
        }

        List<String> rec = letterCombinations(digits.substring(1));
        List<String> current = mapping.get(digits.substring(0, 1));

        List<String> result = new LinkedList<>();
        for (String letter : current) {
            for (String nest : rec) {
                result.add(letter + nest);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Task17 x = new Task17();
        List<String> res = x.letterCombinations("23");
        System.out.println(res);
    }
}
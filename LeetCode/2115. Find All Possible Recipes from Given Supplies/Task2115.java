import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Task2115 {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Set<String> results = new HashSet<>();
        Set<String> supplySet = new HashSet<>(List.of(supplies));
        int n = recipes.length;

        boolean canCraft = true;
        while (canCraft) {
            canCraft = false;
            for (int i = 0; i < n; i++) {
                if(!results.contains(recipes[i]) && supplySet.containsAll(ingredients.get(i))){
                    results.add(recipes[i]);
                    supplySet.add(recipes[i]);
                    canCraft = true;
                }
            }
        }

        return results.stream().toList();
    }

    public static void main(String[] args) {
        Task2115 x = new Task2115();
        System.out.println(x.findAllRecipes(
            new String[] {"bread","sandwich"},
            List.of(
                List.of("yeast","flour"),
                List.of("bread","meat")
            ),
            new String[] {"yeast","flour","meat"}));
    }
}
import java.util.HashSet;
import java.util.Set;

class Task3375{

	public int minOperations(int[] nums, int k) {
        Set<Integer> mySet = new HashSet<>();

        int cnt = 0;

        for(int x : nums) {
            if(mySet.contains(x)){
                continue;
            }
            mySet.add(x);
            if(x > k){
                cnt++;
            }
            else if(x < k){
                return -1;
            }
        }
        return cnt;
    }
	
	public static void main(String[] args){
        Task3375 x = new Task3375();
		System.out.println(x.minOperations(new int[]{5,2,5,4,5}, 2)); //2
		System.out.println(x.minOperations(new int[]{2,1,2}, 2));     //-1
		System.out.println(x.minOperations(new int[]{9,7,5,3}, 1));   //1
	}

}
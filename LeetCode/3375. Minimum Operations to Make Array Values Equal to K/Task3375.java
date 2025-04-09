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
		System.out.println(minOperations(new int[]{5,2,5,4,5}, 2); //2
		System.out.println(minOperations(new int[]{2,1,2}, 2);     //-1
		System.out.println(minOperations(new int[]{9,7,5,3}, 1);   //1
	}

}
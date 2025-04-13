import java.util.Deque;
import java.util.LinkedList;

class Task2843 {

    private boolean isSym(int x){
        Deque<Integer> stack = new LinkedList<>();
        while(x != 0){
            stack.add(x % 10);
            x /= 10;
        }
        if(stack.size() % 2 != 0){
            return false;
        }
        int a = 0;
        int b = 0;
        int n = stack.size() / 2;

        for(int i = 0; i < n; i++){
            a += stack.peek();
            stack.poll();
        }

        for(int i = 0; i < n; i++){
            b += stack.peek();
            stack.poll();
        }
        return a == b;
    }

    public int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int x = low; x <= high; x++) {
            if(isSym(x)){
                cnt++;
            }
        }
        return cnt;
    }

    public static void main(String[] args) {

    }
}
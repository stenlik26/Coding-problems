class Task38 {

    public String calcRLE(String s) {
        char[] seq = s.toCharArray();
        char c = seq[0];
        int cnt = 1;
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i < seq.length; i++) {
            if (seq[i] != c) {
                sb.append(cnt);
                sb.append(c);
                c = seq[i];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        sb.append(cnt);
        sb.append(c);

        return sb.toString();
    }

    //Recursive
    public String countAndSayRec(int n) {
        if (n == 1) {
            return "1";
        }
        return calcRLE(countAndSay(n - 1));
    }

    //Iterative
    public String countAndSay(int n){
        String base = "1";
        for (int i = 1; i < n; i++){
            base = calcRLE(base);
        }
        return base;
    }

    public static void main(String[] args) {
        Task38 x = new Task38();
        System.out.println(x.countAndSay(4));
    }
}
class Task1922 {

    public long fastExpMod(long base, long exp, long res, long mod) {
        if (exp == 0) {
            return res;
        }
        if (exp % 2 == 0) {
            return fastExpMod((base * base) % mod, exp / 2, res, mod);
        } else {
            return fastExpMod(base, exp - 1, (base * res) % mod, mod);
        }
    }

    public int countGoodNumbers(long n) {
        long mod = (long) (Math.pow(10, 9) + 7);

        long result = fastExpMod(5, (long) Math.ceil((double) n / 2), 1, mod);
        result *= fastExpMod(4, (long) Math.floor((double) n / 2), 1, mod);

        return (int) (result % mod);
    }

    public static void main(String[] args) {
        Task1922 x = new Task1922();
        System.out.println( (long) Math.ceil((double) 51 / 2));
        System.out.println( (long) Math.floor((double) 51 / 2));
    }
}
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Task3335 {

    public int lengthAfterTransformations(String s, int t) {
        long[] freqMap = new long[26];
        final long MOD = 1000000007;
        for (char x : s.toCharArray()) {
            freqMap[x - 'a']++;
        }
        for (int i = 0; i < t; i++) {

            long addZ = freqMap[25] % MOD;

            for (int c = 24; c >= 0; c--) {
                if (freqMap[c] == 0) {
                    continue;
                }
                freqMap[c + 1] += freqMap[c];
                freqMap[c] = 0;
            }

            if (addZ != 0) {
                freqMap[0] += addZ;
                freqMap[0] %= MOD;

                freqMap[1] += addZ;
                freqMap[1] %= MOD;

                freqMap[25] -= addZ;
                freqMap[25] %= MOD;
            }
        }
        long result = 0;
        for (long x : freqMap) {
            result += x;
            result = result % 1000000007;
        }

        return (int) (result);
    }

    public static void main(String[] args) {
        Task3335 k = new Task3335();
        System.out.println(k.lengthAfterTransformations("bheanuyzjlwflksvyzuku", 9433));
    }

}
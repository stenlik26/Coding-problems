import java.util.Arrays;

class Task165 {

    public int compareVersion(String version1, String version2) {
        String[] nums1 = version1.split("\\.");
        String[] nums2 = version2.split("\\.");

        if (nums1.length > nums2.length) {
            int f = nums2.length;
            nums2 = Arrays.copyOf(nums2, nums1.length);
            for (int i = f; i < nums2.length; i++) {
                nums2[i] = "0";
            }
        } else if (nums1.length < nums2.length) {
            int f = nums1.length;
            nums1 = Arrays.copyOf(nums1, nums2.length);
            for (int i = f; i < nums1.length; i++) {
                nums1[i] = "0";
            }
        }

        for (int i = 0; i < nums1.length; i++) {
            Integer a = Integer.parseInt(nums1[i]);
            Integer b = Integer.parseInt(nums2[i]);

            if (a < b) {
                return -1;
            } else if (a > b) {
                return 1;
            }
        }

        return 0;
    }

    public static void main(String[] args) {
        Task165 x = new Task165();
        x.compareVersion("1.002", "1.002.0.0");
    }
}
import java.util.Arrays;

class Solution {
    // this function is used to compare two solutions
    boolean greater(int[] n1, int[] n2) {
        for (int i = 0; i < n1.length; i++) {
            if (n1[i] > n2[i]) {
                return true;
            } else if (n1[i] < n2[i]) {
                return false;
            }
        }
        return false;
    }

    void copy(int[] n1, int[] n2) {
        for (int i = 1; i < n1.length; i++) {
            n1[i] = n2[i - 1];
        }
    }

    int[] nextMaxNumber(int[] n1, int left1, int[] n2, int left2, int k) {
        int[] ans = new int[k];
        if (k == 0) {
            return ans;
        }
        int right1 = n1.length + n2.length - left2 - k + 1;
        if (right1 > n1.length) {
            right1 = n1.length;
        }
        int right2 = n2.length + n1.length - left1 - k + 1;
        if (right2 > n2.length) {
            right2 = n2.length;
        }
        int n1max = -1, n1maxIndex = 0;
        for (int cur = left1; cur < right1; cur++) {
            if (n1[cur] > n1max) {
                n1max = n1[cur];
                n1maxIndex = cur;
            }
        }
        int n2max = -1, n2maxIndex = 0;
        for (int cur = left2; cur < right2; cur++) {
            if (n2[cur] > n2max) {
                n2max = n2[cur];
                n2maxIndex = cur;
            }
        }
        if (n1max > n2max) {
            ans[0] = n1max;
            var temp = this.nextMaxNumber(n1, n1maxIndex + 1, n2, left2, k - 1);
            this.copy(ans, temp);
        } else if (n1max < n2max) {
            ans[0] = n2max;
            var temp = this.nextMaxNumber(n1, left1, n2, n2maxIndex + 1, k - 1);
            this.copy(ans, temp);
        } else {
            ans[0] = n1max;
            var temp1 = this.nextMaxNumber(n1, n1maxIndex + 1, n2, left2, k - 1);
            var temp2 = this.nextMaxNumber(n1, left1, n2, n2maxIndex + 1, k - 1);
            if (this.greater(temp1, temp2)) {
                this.copy(ans, temp1);
            } else {
                this.copy(ans, temp2);
            }
        }
        return ans;
    }

    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        return nextMaxNumber(nums1, 0, nums2, 0, k);
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        sln.maxNumber(new int[] { 0 }, new int[] { 1, 0, 1 }, 4);
    }
}

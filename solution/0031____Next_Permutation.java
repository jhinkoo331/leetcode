class Solution {
    // perf: 1.5%, 27.5%
    public void nextPermutation(int[] nums) {
        int maxIndex;
        for (maxIndex = nums.length - 1; maxIndex > 0; maxIndex--) {
            if (nums[maxIndex - 1] < nums[maxIndex]) {
                break;
            }
        }
        if (maxIndex == 0) {
            // System.out.println("This is the last perm");
            int left = maxIndex, right = nums.length - 1;
            while (left < right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
            }
            return;
        }
        System.out.printf("maxindex=%d", maxIndex);

        int index2;
        for (index2 = nums.length - 1;; index2--) {
            if (nums[index2] > nums[maxIndex - 1]) {
                break;
            }
        }
        System.out.printf("index2=%d", index2);

        var temp = nums[maxIndex - 1];
        nums[maxIndex - 1] = nums[index2];
        nums[index2] = temp;
        int left = maxIndex, right = nums.length - 1;
        while (left < right) {
            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
        return;
    }
}
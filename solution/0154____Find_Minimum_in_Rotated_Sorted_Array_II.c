
/**
 * @perf: [4ms, 83]
 */
int _1(int* nums, int numsSize){
        if(nums[0] < nums[numsSize - 1])
                return nums[0];
        int left = 0, right = numsSize - 1;
        while(left + 1 < right){
                while(left < numsSize - 1 && nums[left] == nums[left + 1])
                        ++left;
                while(right && nums[right - 1] == nums[right])
                        --right;
                if(left + 1 >= right)
                        break;
                if(nums[left] < nums[left + 1])
                        ++left;
                else if(nums[right - 1] < nums[right])
                        --right;
                int mid = left + (right - left) / 2;
                if(nums[left] < nums[mid])
                        left = mid;
                else if(nums[mid] < nums[right])
                        right = mid;
        }
        return nums[right];
}

int findMin(int* nums, int numsSize){
        return _1(nums, numsSize);
}
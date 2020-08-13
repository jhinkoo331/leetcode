

int _1(int s, int* nums, int numsSize);

/**
 * @brief               the sub-array's sum should satisfy: sum(nums[left, right)) >= s
 * @param s             positive
 * @param nums          all elements are positive
 */
int minSubArrayLen(int s, int* nums, int numsSize){
        return _1(s, nums, numsSize);
}

/**
 * @perf: [90, 55]
 */
int _1(int s, int* nums, int numsSize){
        unsigned left = 0, right = 0;		//* the sub-array are nums[left, right)
        unsigned sum = 0;
        unsigned min_len = 0xffffffff;
        while(right < numsSize){
                while(sum < s && right < numsSize)
                        sum += nums[right++];
                if(right == numsSize && sum < s)
                        break;
                while(sum >= s)
                        sum -= nums[left++];
                min_len = min_len < right - left ? min_len : right - left;
        }
        return min_len == 0xffffffff ? 0 : min_len + 1;
}


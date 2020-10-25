
inline int max(int i, int ii){
        return i > ii ? i : ii;
}

inline int max3(int i, int ii, int iii){
        return i > ii ? i > iii ? i : iii : ii > iii ? ii : iii;
}

/**
 * @perf: 0ms, 97
 * @todo: in a decent approach
 */
int _1(int* nums, int numsSize){
        if(numsSize == 0){
                return 0;
        } else if(numsSize == 1){
                return nums[0];
        } else if(numsSize == 2){
                return max(nums[0], nums[1]);
        } else if(numsSize == 3){
                return max3(nums[0], nums[1], nums[2]);
        }
        int max_profit = 0;
        // condition 1: the first house is not robbed
        int take = 0, take_notake = 0, notake_notake = 0;
        for(int i = 1; i < numsSize; ++i){
                int temp_take = max(take_notake, notake_notake) + nums[i];
                int temp_take_notake = take;
                int temp_notake_notake = max(take_notake, notake_notake);
                take = temp_take;
                take_notake = temp_take_notake;
                notake_notake = temp_notake_notake;
        }
        max_profit = max(take, take_notake);

        // condition 2: the first house is robbed
        take = nums[0] + nums[2];
        take_notake = nums[0];
        notake_notake = nums[0];
        for(int i = 3; i < numsSize; ++i){
                int temp_take = max(take_notake, notake_notake) + nums[i];
                int temp_take_notake = take;
                int temp_notake_notake = max(take_notake, notake_notake);
                take = temp_take;
                take_notake = temp_take_notake;
                notake_notake = temp_notake_notake;
        }
        max_profit = max3(max_profit, take_notake, notake_notake);
        return max_profit;
}

int rob(int* nums, int numsSize){
        return _1(nums, numsSize);
}

int main(){
        int arr[] = {1,2,3,1};
        rob(arr, 4);
        return 0;
}

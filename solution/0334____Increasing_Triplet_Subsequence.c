#include <stdbool.h>

/**
 * @brief 4ms, 69
 */
bool _1(int* nums, int numsSize){
        if(numsSize == 0)
                return false;
        int a = nums[0];
        int b, bb;              //* bb is as small as possible, when bb is fixed, b is as small as possible
        int i = 1;
        while(i < numsSize){
                if(nums[i] < a)
                        a = nums[i];
                else if(nums[i] > a){
                        b = a;
                        bb = nums[i];
                        break;
                }
                ++i;
        }
        // if(i == numsSize)
        //         return false;
        ++i;
        while(i < numsSize){
                if(nums[i] > bb)
                        return true;
                else if (nums[i] < a)
                        a = nums[i];
                else if(nums[i] > a && nums[i] < bb){
                        b = a;
                        bb = nums[i];
                }else if(nums[i] > b && nums[i] < bb)
                        bb = nums[i];
                ++i;
        }
        return false;
}

bool increasingTriplet(int* nums, int numsSize){
        return _1(nums, numsSize);
}

int main(){
        int v[] = {1,2,-10,-8,-7};
        increasingTriplet(v, 5);
        return 0;
}

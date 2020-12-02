#include <stdbool.h>

inline int max(int i, int ii){
        return i > ii ? i : ii;
}

inline int min(int i, int ii){
        return i < ii ? i : ii;
}

double _1(int* nums1, int nums1Size, int* nums2, int nums2Size) {
        int total_len = nums1Size + nums2Size;
        int left_len = (total_len + 1) / 2;
        int len1, len2;
        int min_len1 = left_len - nums2Size > 0 ? left_len - nums2Size : 0;
        int max_len1 = nums1Size;
        while(min_len1 != max_len1){
                len1 = (min_len1 + max_len1) / 2;
                len2 = left_len - len1;
                if(len1 > 0 && len2 < nums2Size && len2 > 0 && nums1[len1 - 1] > nums2[len2])
                        max_len1 = len1 - 1;
                else if(len1 < nums1Size && len2 > 0 && nums1[len1] < nums2[len2 - 1])
                        min_len1 = len1 + 1;
                else
                        break;
        }
        if(total_len % 2 == 0){
                float sum = 0;
                if(len1 == 0)
                        sum += nums2[len2 - 1];
                else if(len2 == 0)
                        sum += nums1[len1 - 1];
                else
                        sum += nums1[len1 - 1] > nums2[len2 - 1] ? nums1[len1 - 1] : nums2[len2 - 1];
                if(len1 == nums1Size)
                        sum += nums2[len2];
                else if(len2 == nums2Size)
                        sum += nums1[len1];
                else
                        sum += nums1[len1] < nums2[len2] ? nums1[len1] : nums2[len2];
                return sum / 2;
        } else {
                if(len1 == 0)
                        return nums2[len2 - 1];
                else if(len2 == 0)
                        return nums1[len1 - 1];
                else
                        return nums1[len1 - 1] > nums2[len2 - 1] ? nums1[len1 - 1] : nums2[len2 - 1];
        }
        return -1;
}


/**
 * @brief binary search
 * @perf: 84, 84
 * @time: O(n)
 * @space: in-place
 */
double _2(int* nums1, int len1, int* nums2, int len2){
        int left_len = (len1 + len2) / 2;
        int min_len = left_len - len2 > 0 ? left_len - len2 : 0;
        int max_len = left_len > len1 ? len1 : left_len;
        while(min_len != max_len){
                int l = (min_len + max_len) / 2;
                int ll = left_len - l;
                if(l > 0 && ll < len2 && nums1[l - 1] > nums2[ll])
                        max_len = l - 1;
                else if(l < len1 && ll > 0 && nums1[l] < nums2[ll - 1])
                        min_len = l + 1;
                else
                        break;  //* this line is critical for conditions such as [0, 0], [0, 0]
        }
        int l = (min_len + max_len) / 2;
        int ll = left_len - l;
        if((len1 + len2) % 2 == 0){
                float sum;
                if(l == 0)
                        sum = nums2[ll - 1];
                else if(ll == 0)
                        sum = nums1[l - 1];
                else
                        sum = max(nums1[l - 1], nums2[ll - 1]);
                if(l == len1)
                        sum += nums2[ll];
                else if(ll == len2)
                        sum += nums1[l];
                else
                        sum += min(nums1[l], nums2[ll]);
                return sum / 2;
        }else{
                if(l == len1)
                        return nums2[ll];
                else if(ll == len2)
                        return nums1[l];
                else
                        return nums1[l] < nums2[ll] ? nums1[l] : nums2[ll];
        }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
        return _2(nums1, nums1Size, nums2, nums2Size);
}



int main(){
        int arr[] = {1,3};
        int arr2[] = {2};
        float ans = findMedianSortedArrays(arr, 2, arr2, 1);
        return 0;
}



/**
 * @brief 
 * @perf: 63, 69
 * @param nums 
 * @param numsSize 
 * @return int 
 */
int singleNumber(int* nums, int numsSize){
	int ans = 0;
	unsigned mask = 1;
	for(int i = 0; i < 32; ++i){
		int count = 0;
		for(int ii = 0; ii < numsSize; ++ii)
			if(nums[ii] & mask)
				++count;
		if(count % 3)
			ans ^= mask;
		mask <<= 1;
	}
	return ans;
}

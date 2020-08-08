from typing import List


class Solution:
	def singleNonDuplicate(self, nums: List[int]) -> int:
		return self._1(nums)
	
	def _1(self, nums: List[int]) -> int:
		left, right = 0, len(nums) - 1
		while left != right:
			print(left, right)
			mid = (left + right) // 2
			left_odd = (mid - left) % 2
			same = nums[mid] == nums[mid - 1]
			if left_odd and same:
				left = mid + 1
			elif left_odd and not same:
				right = mid - 1
			elif not left_odd and same:
				right = mid - 2
			else:
				left = mid
		return nums[left]
		

if __name__ == "__main__":
	sln = Solution()
	ans = 	sln.singleNonDuplicate([1,1,2,3,3,4,4,8,8])
from typing import List

class Solution:
	def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
		return self._2(nums)

	def _1(self, nums):
		"""
		perf: 31, 59
		"""
		for i in range(len(nums)):
			temp = abs(nums[i])
			if nums[temp - 1] > 0:
				nums[temp - 1] *= -1
		ans = []
		for i in range(len(nums)):
			if nums[i] > 0:
				ans.append(i + 1)
		return ans
	def _2(self, nums):
		nums.append(0)
		#* we process the trailing 0
		for i in range(len(nums)):
			temp = abs(nums[i])
			if nums[temp] > 0:
				nums[temp] = -nums[temp]
		ans = []
		for i in range(1, len(nums)):
			if nums[i] >= 0:		# the last element is 0
				ans.append(i)
		return ans
			
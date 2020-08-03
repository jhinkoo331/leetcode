from typing import List

class Solution:
	def thirdMax(self, nums: List[int]) -> int:
		return self._1(nums)

	def _1(self, nums):
		"""
		*perf 85, 69
		"""
		a, b, c = [float('-inf')] * 3
		for i in nums:
			if i > a:
				a, b, c = i, a, b
			elif i == a:
				pass
			elif i > b:
				b, c = i, b
			elif i == b:
				pass
			elif i > c:
				c = i
			else:		#* i is not equal or less than c
				pass
		if c != float('-inf'):
			return c
		else:
			return a

if __name__ == "__main__":
	nums = [1,2,3]
	sln = Solution()
	sln.thirdMax(nums)
			
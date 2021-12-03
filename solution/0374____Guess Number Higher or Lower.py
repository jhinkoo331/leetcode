# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
def guess(num: int) -> int:
	ans = 6
	if num > ans:
		return 1
	elif num == ans:
		return 0
	else:
		return -1

class Solution:
	def guessNumber(self, n: int) -> int:
		low = 1
		high = n
		while(True):
			mid = (low + high) / 2
			if guess(mid) == 0:
				return mid
			elif guess(mid) == 1:
				high = mid - 1
			else:
				low = mid + 1
				
sln = Solution()
sln.guessNumber(10)   
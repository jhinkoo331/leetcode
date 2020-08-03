from typing import List

class Solution:
	def fizzBuzz(self, n: int) -> List[str]:
		return self._1(n)

	def _1(self, n: int) -> List[str]:
		"""perf: 87, 11
		"""
		ans = [str(i) for i in range(0, n + 1)]
		for i in range(0, n + 1, 3):
			ans[i] = "Fizz"
		for i in range(0, n + 1, 5):
			ans[i] = "Buzz"
		for i in range(0, n + 1, 15):
			ans[i] = "FizzBuzz"
		ans.pop(0)
		return ans




if __name__ == "__main__":
	sln =  Solution()
	sln.fizzBuzz(1)
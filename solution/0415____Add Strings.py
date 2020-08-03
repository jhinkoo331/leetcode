
class Solution:
	def addStrings(self, num1: str, num2: str) -> str:
		return self._1(num1, num2)

	def _1(self, num1: str, num2: str) -> str:
		"""[summary]
		perf: 75, 5
		"""
		ans = []
		if(len(num1) < len(num2)):
			num1, num2 = num2, num1
		i, ii = len(num1) - 1, len(num2) - 1
		while ii >= 0:
			sum = ord(num1[i]) + ord(num2[ii]) - ord('0') * 2
			ans.append(sum)
			i -= 1
			ii -= 1
		while i >= 0:
			ans.append(ord(num1[i]) - ord('0'))
			i -= 1
		carry = 0
		for i in range(len(ans)):
			ans[i] += carry
			carry = ans[i] // 10
			ans[i] %= 10
		if(carry != 0):
			ans.append(carry)
		return ''.join(str(i) for i in ans[::-1])
        
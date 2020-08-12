
class Solution:
	def reverseVowels(self, s: str) -> str:
		return self._1(s)

	def _1(self, s: str) -> str:
		#* perf: 57, 26
		vowel = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
		chars = list(s)
		left, right = 0, len(chars) - 1
		while left < right:
			while left < right and chars[left] not in vowel:
				left += 1
			while left < right and chars[right] not in vowel:
				right -= 1
			chars[left], chars[right] = chars[right], chars[left]
			left += 1
			right -= 1
		return ''.join(chars)
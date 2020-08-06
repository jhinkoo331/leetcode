from typing import List

class Solution:
	def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
		return self._1(timeSeries, duration)

	def _1(self, timeSeries: List[int], duration: int) -> int:
		"""[summary]
		perf: 70, 86
		Args:
		    timeSeries (List[int]): [description]
		    duration (int): [description]

		Returns:
		    int: [description]
		"""
		if len(timeSeries) == 0:
			return 0
		total_time = 0
		pre = timeSeries[0]
		for i in timeSeries:
			total_time += min(duration, i - pre)
			pre = i
		return total_time + duration


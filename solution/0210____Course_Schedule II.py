from typing import List
import queue


class Solution:
	#! perf: 46, 85
	def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
		# pre_count[i] = k means there are k courses to be finished before you could launch course i
		pre_count = [0] * numCourses
		# courses to be launched
		q = queue.Queue()
		# post_count[i] is the list of courses can be launched after course i finished
		post_list = [[] for i in range(numCourses)]
		# the sequence of courses to be launched
		launch_seq = []

		for relation in prerequisites:
			post_list[relation[1]].append(relation[0])
			pre_count[relation[0]] += 1

		# initialize q
		for i in range(numCourses):
			if not pre_count[i]:
				q.put(i)
		
		while(not q.empty()):
			cur = q.get()		# get() would remove and return the leading item
			launch_seq.append(cur)
			for item in post_list[cur]:
				pre_count[item] -= 1
				if pre_count[item] == 0:
					q.put(item)
		
		if len(launch_seq) == numCourses:
			return launch_seq
		else:
			return []


if __name__ == "__main__":
	sln = Solution()
	sln.findOrder(2, [[1, 0]])




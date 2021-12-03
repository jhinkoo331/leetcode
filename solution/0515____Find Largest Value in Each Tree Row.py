# Definition for a binary tree node.
class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right


from queue import Queue
from typing import List

class Solution:
	def largestValues(self, root: TreeNode) -> List[int]:
		return self._1(root)

	def _1(self, root: TreeNode) -> List[int]:
		"""perf: 5, 74

		Args:
		    root (TreeNode): [description]

		Returns:
		    List[int]: [description]
		"""
		ans = []
		q = Queue()
		if root is not None:
			q.put(root)
		while not q.empty():
			_max = float('-inf')
			sz = q.qsize()
			while sz != 0:
				sz -= 1
				temp = q.get()
				_max = max(_max, temp.val)
				if temp.left is not None:
					q.put(temp.left)
				if temp.right is not None:
					q.put(temp.right)
			ans.append(_max)
		return ans

	def _2(self, root: TreeNode) -> List[int]:
		"""perf: 80, 31

		Args:
		    root (TreeNode): [description]

		Returns:
		    List[int]: [description]
		"""
		ans = []
		row = [root]
		while any(row):
			ans.append(max(e.val for e in row))
			row = [child for node in row for child in (node.left, node.right) if child]
		return ans

package main

// The worst of the journey is still to come

type TreeNode struct {
	Left  *TreeNode
	Right *TreeNode
}

func helper968(root *TreeNode) (camera int, rootHasCamera bool, rootIsMonitored bool) {
	if root == nil {
		return 0, false, true
	}
	leftCamera, leftHasCamera, leftMonitored := helper968(root.Left)
	rightCamera, rightHasCamera, rightMonitored := helper968(root.Right)
	if leftMonitored == false || rightMonitored == false {
		return leftCamera + rightCamera + 1, true, true
	}

	if leftHasCamera || rightHasCamera {
		return leftCamera + rightCamera, false, true
	}
	return leftCamera + rightCamera, false, false
}

// perf: 4ms 83%, 100%
func minCameraCover(root *TreeNode) int {
	camera, _, rootIsMonitored := helper968(root)
	if rootIsMonitored == false {
		return camera + 1
	}
	return camera
}

func main() {
	minCameraCover(&TreeNode{
		Left: &TreeNode{
			Left:  &TreeNode{},
			Right: &TreeNode{},
		},
	})
}

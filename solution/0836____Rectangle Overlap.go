package main

func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	return e836(rec1, rec2)
}

// perf: 0ms, 36
func e836(rec1 []int, rec2 []int) bool {
	//              3
	//      0               2
	//              1
	if rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] || rec2[1] == rec2[3] {
		return false
	}
	if rec1[0] >= rec2[2] || rec2[0] >= rec1[2] {
		return false
	}
	if rec1[1] >= rec2[3] || rec1[3] <= rec2[1] {
		return false
	}
	return true
}

func main() {

}

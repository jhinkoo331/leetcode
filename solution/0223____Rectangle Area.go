package main

func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
	return t223(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2)
}

// perf: 72, 15
// time, space: constant
func t223(ax, ay, axx, ayy, bx, by, bxx, byy int) int {
	overlapped_area := t223_h(ax, axx, bx, bxx) * t223_h(ay, ayy, by, byy)
	return t223_hh(ax, ay, axx, ayy) + t223_hh(bx, by, bxx, byy) - overlapped_area
}

func t223_h(x, xx, y, yy int) int {

	var min, max int
	if x < y {
		min = x
	} else {
		min = y
	}
	if xx > yy {
		max = xx
	} else {
		max = yy
	}
	total_len := (xx - x) + (yy - y)
	if ans := total_len - (max - min); ans > 0 {
		return ans
	} else {
		return 0
	}
}

func t223_hh(ax, ay, axx, ayy int) int {
	ans := (ax - axx) * (ay - ayy)
	if ans < 0 {
		return -ans
	} else {
		return ans
	}
}

func main() {
	computeArea(-3, 0, 3, 4, 0, -1, 9, 2)
}

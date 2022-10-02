package main

// be happy, be confident.

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func bit1count1318(n int) int {
	bit := 0
	for n != 0 {
		if n&1 != 0 {
			bit += 1
		}
		n >>= 1
	}
	return bit
}

// 0ms, 5% 1.9MB
func minFlips(a, b, c int) int {
	//				c = 0			c = 1
	// a|b = 0		0				1
	// a|b = 1		1, 2			0
	ans := 0
	ans += bit1count1318((^(a | b)) & c)
	ans += bit1count1318(a & (^c))
	ans += bit1count1318(b & (^c))
	return ans
}

// 0ms, 100% 1.8MB
func minFlips_(a, b, c int) int {
	flipCount := 0
	for mask := 1; mask != 0; mask <<= 1 {
		aa := (a & mask) != 0
		bb := (b & mask) != 0
		cc := (c & mask) != 0
		if cc {
			if (aa == false) && (bb == false) {
				flipCount += 1
			}
		} else {
			if aa {
				flipCount += 1
			}
			if bb {
				flipCount += 1
			}
		}
	}
	return flipCount
}

// 理解错了题目的意思, 但这是一个非常有趣的dp解法
func minFlips_(a int, b int, c int) int {
	ab := 0
	aB := 0
	Ab := 0
	AB := 0
	for mask := 1; mask != 0; mask <<= 1 {
		println(ab, aB, Ab, AB)
		aa := (a & mask) != 0
		bb := (b & mask) != 0
		cc := (c & mask) != 0
		if aa {
			if bb {
				if cc {
					ab, aB, Ab, AB = ab, aB, Ab, 1+minInt(aB, Ab)
				} else {
					ab, aB, Ab, AB = 2+AB, 1+AB, 1+AB, AB
				}
			} else {
				if cc {
					ab, aB, Ab, AB = ab, aB, 1+minInt(ab, AB), AB
				} else {
					ab, aB, Ab, AB = 1+Ab, 2+Ab, Ab, 1+Ab
				}
			}
		} else {
			if bb {
				if cc {
					ab, aB, Ab, AB = ab, 1+minInt(AB, ab), Ab, AB
				} else {
					ab, aB, Ab, AB = 1+aB, aB, 2+aB, 1+aB
				}
			} else {
				if cc {
					ab, aB, Ab, AB = 1+minInt(aB, Ab), aB, Ab, AB
				} else {
					ab, aB, Ab, AB = ab, 1+ab, 1+ab, 2+ab
				}
			}
		}
	}
	return ab
}

func main() {
	minFlips(2, 6, 5)
}

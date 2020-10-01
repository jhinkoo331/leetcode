package main

// perf: 100, 79
func _10_2(n int) int {
	const mod = 1e9 + 7
	i, ii := 1, 0
	for n >= 0 {
		i, ii = ii, i+ii
		if ii > mod {
			ii %= mod
		}
		n--
	}
	if ii == mod {
		return 1
	} else {
		return ii
	}
}

func numWays(n int) int {
	return _10_2(n)
}

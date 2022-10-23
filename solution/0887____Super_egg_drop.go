package main

var inited = false
var f_egg_level [][]int

func help0887() {
	if inited {
		return
	}
	inited = true
	k, n := 100, 10000
	for i := 0; i <= k; i += 1 {
		f_egg_level = append(f_egg_level, make([]int, n+1))
	}
	for level := 1; level <= n; level += 1 {
		f_egg_level[1][level] = level
	}
	for egg := 1; egg <= k; egg += 1 {
		f_egg_level[egg][1] = 1
	}
	for egg := 2; egg <= k; egg += 1 {
		for level := 2; level <= n; level += 1 {
			min := 10000000
			for test_level := 1; test_level <= level; test_level += 1 {
				broken := 1 + f_egg_level[egg-1][test_level-1]
				not_broken := 1 + f_egg_level[egg][level-test_level]
				if broken < not_broken {
					broken = not_broken
				}
				if broken < min {
					min = broken
				}
			}
			f_egg_level[egg][level] = min
		}
	}
}

func superEggDrop(k, n int) int {
	help0887()
	return f_egg_level[k][n]
}

func main() {
	println(superEggDrop(7, 10000))
}

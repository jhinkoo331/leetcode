package main

import "strings"

func isValidSerialization(preorder string) bool {
	return t331(preorder)
}

// perf: 0ms, 23
func t331(preorder string) bool {
	list := strings.Split(preorder, ",")
	if len(list) == 0 {
		return true
	}
	if len(list) == 1 {
		return list[0] == "#"
	}
	if list[0] == "#" {
		return false
	}
	level_node_count := 1
	next_level_start_index := 1
	for level_node_count != 0 {
		if next_level_start_index+2*level_node_count > len(list) {
			return false
		} else {
			next_level_node_count := t331_check(
				list[next_level_start_index:next_level_start_index+2*level_node_count],
				level_node_count)
			next_level_start_index += level_node_count * 2
			level_node_count = next_level_node_count
		}
	}
	return next_level_start_index == len(list)
}

func t331_check(list []string, i int) (ans int) {
	for _, s := range list {
		if s != "#" {
			ans++
		}
	}
	return ans
}

func main() {
	isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#")
}

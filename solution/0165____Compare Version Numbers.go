package main

func compareVersion(version1 string, version2 string) int {
	return _165_2(version1, version2)
}

// perf: 100, 100
func _165_2(version1, version2 string) int {
	ver1 := _0165_split(version1)
	ver2 := _0165_split(version2)
	i := 0
	for ; i < len(ver1) && i < len(ver2); i += 1 {
		if ver1[i] > ver2[i] {
			return 1
		}
		if ver1[i] < ver2[i] {
			return -1
		}
	}
	if i == len(ver1) {
		for ; i < len(ver2); i += 1 {
			if ver2[i] > 0 {
				return -1
			}
		}
	} else {
		for ; i < len(ver1); i += 1 {
			if ver1[i] > 0 {
				return 1
			}
		}
	}
	return 0
}

func _0165_split(s string) (value []int) {
	temp := 0
	for _, n := range s {
		if n == '.' {
			value = append(value, temp)
			temp = 0
			continue
		}
		temp *= 10
		temp += int(n - '0')
	}
	value = append(value, temp)
	return value
}

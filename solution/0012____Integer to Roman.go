package main

// 0ms, 9
func _0012(num int) string {
	var ans []rune
	for num >= 1000 {
		num -= 1000
		ans = append(ans, 'M')
	}
	if num >= 900 {
		num -= 900
		ans = append(ans, 'C', 'M')
	}
	for num >= 500 {
		num -= 500
		ans = append(ans, 'D')
	}
	if num >= 400 {
		num -= 400
		ans = append(ans, 'C', 'D')
	}
	for num >= 100 {
		num -= 100
		ans = append(ans, 'C')
	}
	if num >= 90 {
		num -= 90
		ans = append(ans, 'X', 'C')
	}
	for num >= 50 {
		num -= 50
		ans = append(ans, 'L')
	}
	if num >= 40 {
		num -= 40
		ans = append(ans, 'X', 'L')
	}
	for num >= 10 {
		num -= 10
		ans = append(ans, 'X')
	}
	if num >= 9 {
		num -= 9
		ans = append(ans, 'I', 'X')
	}
	if num >= 5 {
		num -= 5
		ans = append(ans, 'V')
	}
	if num >= 4 {
		num -= 4
		ans = append(ans, 'I', 'V')
	}
	for num >= 1 {
		num -= 1
		ans = append(ans, 'I')
	}
	return string(ans)
}

// num is a positive number not exceeding 3999
func intToRoman(num int) string {
	return _0012(num)
}

func main() {

}

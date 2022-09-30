package main

// be happy, be confident.

// 0ms, 58
func minFlips(target string) int {
	i := 0
	for ; i < len(target); i += 1 {
		if target[i] == '1' {
			break
		}
	}
	if i == len(target) {
		return 0
	}
	count := 1
	for ; i+1 < len(target); i += 1 {
		if target[i+1] != target[i] {
			count += 1
		}
	}
	return count
}

func main() {
	println(minFlips(""))
	println(minFlips("0000"))
	println(minFlips("101010"))
	println(minFlips("11001100"))
	println(minFlips("10000000001010"))
	println(minFlips(""))
	println(minFlips(""))
}

package main

// The worst of the journey is still to come

// 题意: 给两个string, 能够将s1的任意两个字符(可以是同一字符)交换位置得到s2

// 阿里tl面, 面的很水, 最后的题目也是非常简单

func fn(s, ss string) bool {
	var d, dd []uint8
	for i := range s {
		if s[i] != ss[i] {
			d = append(d, s[i])
			dd = append(dd, ss[i])
		}
	}
	if len(d) == 0 {
		return true
	}
	if len(d) == 2 && d[0] == dd[1] && d[1] == dd[0] {
		return true
	}
	return false
}

func main() {
	println(fn("bank", "kanb"))
	println(fn("attack", "defend"))
	println(fn("kelb", "kelb"))
	println(fn("abcd", "bcda"))
}

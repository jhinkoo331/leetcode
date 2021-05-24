package main

func findLadders(beginWord string, endWord string, wordList []string) [][]string {
	return o126(beginWord, endWord, wordList)
}

// perf: 88, 95
func o126(beginWord string, endWord string, wordList []string) (ans [][]string) {
	used := make([]bool, len(wordList), len(wordList))

	paths := [][]string{{beginWord}}
	var new_paths [][]string

	for len(paths) > 0 {
		flag := false
		used_temp := make(map[string]bool)
		for _, path := range paths {
			for i := range wordList {
				if used[i] && wordList[i] != endWord {
					continue
				}
				if o126_helper(path[len(path)-1], wordList[i]) {
					temp := make([]string, len(path), len(path)+1)
					copy(temp, path)
					temp = append(temp, wordList[i])
					new_paths = append(new_paths, temp)
					used_temp[wordList[i]] = true
					if wordList[i] == endWord {
						flag = true
					}
				}
			}
		}
		for i := range wordList {
			if used_temp[wordList[i]] {
				used[i] = true
			}
		}
		paths = new_paths
		new_paths = [][]string{}
		if flag {
			break
		}
	}
	for _, path := range paths {
		if path[len(path)-1] == endWord {
			ans = append(ans, path)
		}
	}
	return ans
}

func o126_helper(s, ss string) bool {
	i := 0
	for ; i < len(s); i++ {
		if s[i] != ss[i] {
			break
		}
	}
	if i == len(s) {
		// s == ss
		return false
	}
	i++
	for ; i < len(s); i++ {
		if s[i] != ss[i] {
			break
		}
	}
	return i == len(s)
}

func main() {
	ans := findLadders("hit", "cog", []string{"hot", "dot", "dog", "lot", "log", "cog"})
	ans = findLadders("red", "tax", []string{"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"})
	println(ans)
}

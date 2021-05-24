package main

func ladderLength(beginWord string, endWord string, wordList []string) int {
	return o127(beginWord, endWord, wordList)
}

// perf: 12, 95
func o127(beginWord string, endWord string, wordList []string) (ans int) {

	used := make([]bool, len(wordList), len(wordList))
	queue := []string{beginWord}

	for len(queue) > 0 {
		ans++
		var queue_temp []string
		for _, word := range queue {
			for i := range wordList {
				if used[i] {
					continue
				}
				if o127_helper(word, wordList[i]) {
					if wordList[i] == endWord {
						return ans + 1
					}
					queue_temp = append(queue_temp, wordList[i])
					used[i] = true
				}
			}
		}
		queue = queue_temp
	}
	return 0
}

func o127_helper(s, ss string) bool {
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

}

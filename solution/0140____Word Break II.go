package main

import (
	"strings"
)

func wordBreak(s string, wordDict []string) []string {
	return o140(s, wordDict)
}

type o149_trie struct {
	is_word bool
	child   [148]*o149_trie
}

func o140_init_trie(ss []string) *o149_trie {
	root := &o149_trie{}
	for _, s := range ss {
		cur := root
		for _, r := range s {
			if cur.child[int(r)] == nil {
				cur.child[int(r)] = &o149_trie{}
			}
			cur = cur.child[int(r)]
		}
		cur.is_word = true
	}
	return root
}

// perf: 0ms, 30
func o140(s string, wordDict []string) []string {
	tree := o140_init_trie(wordDict)
	var ans [][]string
	o140_helper([]rune(s), &ans, tree, []string{})
	var ss []string
	for _, s := range ans {
		ss = append(ss, strings.Join(s, " "))
	}
	return ss
}

func o140_get_words(s []rune, root *o149_trie) (ans []int) {
	for i, r := range s {
		if root.child[int(r)] == nil {
			break
		} else if root.child[int(r)].is_word == true {
			ans = append(ans, i+1)
		}
		root = root.child[int(r)]
	}
	return ans
}

func o140_helper(s []rune, ans *[][]string, root *o149_trie, cur []string) {

	if len(s) == 0 {
		temp := make([]string, len(cur), len(cur))
		copy(temp, cur)
		*ans = append(*ans, temp)
	}
	ss := o140_get_words(s, root)
	for _, length := range ss {
		o140_helper(s[length:], ans, root, append(cur, string(s[:length])))
	}
}

func main() {
	wordBreak("aaaaaaa", []string{"a", "aa"})
}

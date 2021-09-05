package main

func wordBreak_1(s string, wordDict []string) bool {
	return o139(s, wordDict)
}

type o139_trie struct {
	is_word bool
	child   [148]*o139_trie
}

func o139_init_trie(ss []string) *o139_trie {
	root := &o139_trie{}
	for _, s := range ss {
		cur := root
		for _, r := range s {
			if cur.child[int(r)] == nil {
				cur.child[int(r)] = &o139_trie{}
			}
			cur = cur.child[int(r)]
		}
		cur.is_word = true
	}
	return root
}

// perf: 4ms, 5.1
func o139(s string, wordDict []string) bool {
	tree := o139_init_trie(wordDict)
	return o139_helper([]rune(s), tree, make(map[int]bool))
}

func o139_get_words(s []rune, root *o139_trie) (ans []int) {
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

func o139_helper(s []rune, root *o139_trie, impossible map[int]bool) bool {

	if len(s) == 0 {
		return true
	}
	if impossible[len(s)] {
		return false
	}
	ss := o139_get_words(s, root)
	for _, length := range ss {
		if o139_helper(s[length:], root, impossible) {
			return true
		}
	}
	impossible[len(s)] = true
	return false
}

func main() {

}

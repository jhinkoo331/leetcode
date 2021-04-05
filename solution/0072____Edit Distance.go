package main

// insert, remove, replace a char with another to make word1 into word2,
// return the minimum steps to do this.
func minDistance(word1 string, word2 string) int {
        return _72(word1, word2)
}

func _72(w, ww string) (ans int) {
        // make ww shorter
        if len(w) < len(ww) {
                w, ww = ww, w
        }
        w_left_index := -1
        ww_left_index := -1
        char_index := make(map[rune][]int)
        for i, r := range w {
                char_index[r] = append(char_index[r], i)
        }
        return
}

func main() {
	
}

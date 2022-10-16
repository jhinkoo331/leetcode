package main

// The worst of the journey is still to come

func generateParenthesis(n int) []string {
	if n == 0 {
		return nil
	}
	pop := make([]rune, 0, n*2)
	ss := make([]string, 0)
	helper(n, 0, &pop, &ss)
	return ss
}

func helper(remainLeft int, pushedLeft int, pop *[]rune, ss *[]string) {
	if remainLeft == 0 && pushedLeft == 0 {
		*ss = append(*ss, string(*pop))
	}
	if remainLeft != 0 {
		*pop = append(*pop, '(')
		helper(remainLeft-1, pushedLeft+1, pop, ss)
		*pop = (*pop)[:len(*pop)-1]
	}
	if pushedLeft != 0 {
		*pop = append(*pop, ')')
		helper(remainLeft, pushedLeft-1, pop, ss)
		*pop = (*pop)[:len(*pop)-1]
	}
}
func main() {
	//generateParenthesis(1)
	generateParenthesis(3)
}

package main
func addOperators(num string, target int) []string {
        return t282(num, target)
}

func t282(num string, target int) []string {
        var nums []int
        for _, r := range num {
                nums = append(nums, int(r - '0'))
        }

}

func main() {
	
}

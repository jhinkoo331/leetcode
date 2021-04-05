package main
func originalDigits(s string) string {
        return f243(s)
}

func f243(s string) string {
        mp := make(map[rune]int)
        for _, r := range s {
                mp[r]++
        }
        // z___, ___, _w_, _____, __u_, ____, __x, _____, __g__, ____
        // zero, one, two, three, four, five, six, seven, eight, nine

}

func main() {
	
}

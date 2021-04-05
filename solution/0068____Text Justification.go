package main

import (
        "fmt"
        "strings"
)

func fullJustify(words []string, maxWidth int) []string {
        return _0068(words, maxWidth)
}

// perf: 0ms, 70
func _0068(words []string, maxWidth int) (ans []string) {
        var b strings.Builder
        for i := 0; true; {
                word_count := 0
                char_count := 0
                for i + word_count < len(words) { // there are still words to process
                        if char_count + word_count + len(words[i + word_count]) > maxWidth {
                                break
                        }
                        char_count += len(words[i + word_count])
                        word_count++
                }
                if i + word_count < len(words) {     // not the last line, left and right edges should be both aligned
                        if word_count == 1 {
                                b.Reset()
                                b.WriteString(words[i])
                                i++
                                for b.Len() < maxWidth {
                                        b.WriteRune(' ')
                                }
                                ans = append(ans, b.String())
                        } else {
                                b.Reset()
                                space := maxWidth - char_count         // how many spaces should be inserted
                                more_space := space % (word_count - 1) // some gap should plus one more space
                                less_space := word_count - more_space - 1
                                space /= word_count - 1
                                for ; more_space != 0; more_space-- {
                                        b.WriteString(words[i])
                                        for ii := 0; ii < space; ii++ {
                                                b.WriteRune(' ')
                                        }
                                        b.WriteRune(' ')
                                        i++
                                }
                                for ; less_space != 0; less_space-- {
                                        b.WriteString(words[i])
                                        for ii := 0; ii < space; ii++ {
                                                b.WriteRune(' ')
                                        }
                                        i++
                                }
                                b.WriteString(words[i])
                                i++
                                ans = append(ans, b.String())
                        }
                } else {        // the last line
                        b.Reset()
                        b.WriteString(strings.Join(words[i:], " "))
                        for b.Len() < maxWidth {
                                b.WriteRune(' ')
                        }
                        ans = append(ans, b.String())
                        break
                }
        }
        return
}


func main() {
        arr := []string {"This"}
        fmt.Println(fullJustify(arr, 16))

}

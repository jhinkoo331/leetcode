package main

import "fmt"

// 4ms, 52%
func getHint(secret string, guess string) string {
	var sameIndex, diffIndex int
	secretCount := make(map[uint8]int)
	for i := range secret {
		if secret[i] == guess[i] {
			sameIndex += 1
		} else {
			secretCount[secret[i]] += 1
		}
	}
	for i := range secret {
		if secret[i] != guess[i] && secretCount[guess[i]] > 0 {
			diffIndex += 1
			secretCount[guess[i]] -= 1
		}
	}
	ans := fmt.Sprintf("%dA%dB", sameIndex, diffIndex)
	return ans
}

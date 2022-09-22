package main

import (
	"strconv"
)

// be happy, be confident.

func fractionToDecimal(numerator int, denominator int) string {
	return o166(numerator, denominator)
}

// perf: 42, 60
func o166(numerator int, denominator int) string {
	if numerator == 0 {
		return "0"
	}
	negative := (numerator < 0) != (denominator < 0)
	if numerator < 0 {
		numerator = -numerator
	}
	if denominator < 0 {
		denominator = -denominator
	}
	// case 1: 100/5 = 20
	// case 2: 1/2 = 0.5
	// case 3:
	integerPart := strconv.Itoa(numerator / denominator)
	if negative {
		integerPart = "-" + integerPart
	}
	var decimalPart string
	remainder := numerator % denominator
	if remainder == 0 {
		return integerPart
	}
	var arr, decimalNumbers []int
	arr = append(arr, numerator%denominator*10)
	decimalNumbers = append(decimalNumbers, arr[0]/denominator)

	for {
		arrNext := (arr[len(arr)-1] - decimalNumbers[len(decimalNumbers)-1]*denominator) * 10
		if arrNext == 0 { // decimal part is finite
			for _, num := range decimalNumbers {
				decimalPart = decimalPart + strconv.Itoa(num)
			}
			return integerPart + "." + decimalPart
		}
		for i, v := range arr {
			if arrNext == v { // find recurrence
				for ii := 0; ii < i; ii += 1 {
					decimalPart = decimalPart + strconv.Itoa(decimalNumbers[ii])
				}
				decimalPart += "("
				for ii := i; ii < len(decimalNumbers); ii += 1 {
					decimalPart += strconv.Itoa(decimalNumbers[ii])
				}
				decimalPart += ")"
				return integerPart + "." + decimalPart
			}
		}
		arr = append(arr, arrNext)
		decimalNumbers = append(decimalNumbers, arrNext/denominator)
	}
}

func main() {
	fractionToDecimal(4, 333)
}

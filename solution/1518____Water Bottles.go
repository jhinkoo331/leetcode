package main

// the problem has problems itself!
func f1518(numBottles int, numExchange int) int {
	return numBottles + numBottles/(numExchange-1)
}

func numWaterBottles(numBottles int, numExchange int) int {
	return f1518(numBottles, numExchange)
}

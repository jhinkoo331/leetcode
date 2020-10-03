package main

// perf: 100, 46
func _0605(flowerbed []int, n int) bool {
	flowerbed = append(flowerbed, 0, 1)
	left, right := -1, 0
	for right < len(flowerbed) {
		for right < len(flowerbed) && flowerbed[right] == 0 {
			right++
		}
		// flowerbed[left] == 0 and flowerbed[right] == 1
		n -= (right - left - 1) / 2
		if n <= 0 {
			return true
		}
		for right < len(flowerbed) && flowerbed[right] == 1 {
			right++
		}
		left = right
	}
	return false
}

func canPlaceFlowers(flowerbed []int, n int) bool {
	return _0605(flowerbed, n)
}

func main() {
	arr := []int{1, 0, 0, 0, 0, 1}
	canPlaceFlowers(arr, 2)
}

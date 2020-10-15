package main

func main() {
        arr := []int {1,2,3}
        println(arr)
        for _, val := range arr {
                val++
        }
        println(arr)
}

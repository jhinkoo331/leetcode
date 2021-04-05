package main

func canMeasureWater(x int, y int, z int) bool {
        return t365(x, y, z)
}

func t365(x, y, z int) bool {
        // make x < y
        if x > y {
                x, y = y, x
        }
        // we have y = kx + b
        k := y / x
        b := y % x
        if z % x == 0 && z / x <= k + 1 {
                return true
        }
        if z == (k + 1) * x + b {
                return true
        }
        z += b
        if z % x == 0 && z / x <= k + 1 {
                return true
        }
        if z == (k + 1) * x + b {
                return true
        }
        return false
}

func main() {
	
}

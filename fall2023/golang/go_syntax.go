package main

import (
	"encoding/json"
	"fmt"
	"reflect"
	"time"
)

// The worst of the journey is still to come

var i int // 初始值为0
var ii int = 10
var iii = 10 // 自动推断类型

func variableDeclare() {
	iiii := 10 // 自动推断类型
	_ = iiii
}

const constF = 0.0
const constF1 = 0.1

func constFF() {
	var i int
	i = constF
	i = 0.0
	i = int(constF)
	//i = int(constF1)
	//i = 0.1
	fmt.Println(reflect.TypeOf(i))
}

type Arr10int [10]int

func len_and_cap() {
	var arr Arr10int
	println(len(arr))
	println(cap(arr))

	slc := make([]int, 0, 20)
	slc = append(slc, 1, 2, 3)
	println(len(slc))
	println(cap(slc))

	ch := make(chan int, 10)
	ch <- 1
	ch <- 2
	println(len(ch))
	println(cap(ch))

	m := make(map[int]bool, 20)
	println(len(m))
	//println(cap(m))
}

func for_range_chan_read() {
	ch := make(chan int)
	go func() {
		ch <- 0
		time.Sleep(10)
		close(ch)
	}()
	for i := range ch {
		println(i)
	}
	println("exit")
}

func fallthrough_() {
	i := 12
	switch {
	case i%2 == 0:
		println(2)
	case i%3 == 0:
		println(3)
	case i%4 == 0:
		println(4)
	case i%9 == 0:
		println(9)
	default:
		println("default")
	}
	switch {
	case i%2 == 0:
		println(2)
		fallthrough
	case i%3 == 0:
		println(3)
		fallthrough
	case i%4 == 0:
		println(4)
		fallthrough
	case i%9 == 0: // fallthrough does not check bool expr
		println(9)
	default:
		println("default")
	}
}

func bitOps() {
	i, ii := 6, 1
	println(i & ii)
	println(i | ii)
	println(^i)
	println(i ^ ii)
}

// switch 后面可以不跟表达式
func switch_() {
	for i := 0; i < 4; i += 1 {
		switch i {
		case 1:
			println(i)
		case 2:
			println(i)
		default:
			println("not 1 not 2")
		}
		switch {
		case i == 1:
			println(i)
		case i == 2:
			println(i)
		default:
			println("not 1 not 2")
		}
	}
}

type book struct {
	Name string
	Ch   chan any
}

func marshal() {
	b := &book{
		Name: "Math",
		Ch:   make(chan any),
	}
	bytes, err := json.Marshal(b)
	if err != nil {
		println(err.Error())
	} else {
		println(string(bytes))
	}
}

func init() {
	println("init1 in main pkg")
}

func init() {
	println("init2 in main pkg")
}

func callInit() {
	//init()        // this line raises compile error
}

type Stringer interface {
	String() string
}

type S1 struct{}

func (s S1) String() string {
	return "s1"
}

type S2 struct{}

func (s *S2) String() string {
	return "s2"
}

func define() {
	var ss Stringer
	ss = new(S1)
	//ss = S1   // error
	ss = &S1{}
	ss = S1{}
	ss = new(S2)
	//ss = S2   // error
	ss = &S2{}
	//ss = S2{}       // error
	_ = ss
}

func add(nums ...int) int {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	return sum
}
func main() {
	println(add(1, 2, 3))
	println(add([]int{1, 2, 3, 4}...))
}

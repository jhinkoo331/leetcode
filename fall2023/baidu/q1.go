package baidu

import "fmt"

// be happy, be confident.

func sln(users []int) (good, comment int) {
	for _, user := range users {
		switch user {
		case 1:
			comment += 1
		case 2:
			good += 1
		case 3:
			if good > comment {
				good += 1
			} else if good < comment {
				comment += 1
			} else {
				good += 1
				comment += 1
			}
		case 4:
			continue
		default:
			panic("")
		}
	}
	return
}

func main1() {
	var userCount int
	fmt.Scan(&userCount)
	users := make([]int, userCount, userCount)
	for i := range users {
		fmt.Scan(&users[i])
	}
	good, cmt := sln(users)
	fmt.Printf("%d %d", cmt, good)
}

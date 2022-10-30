package main

import "sort"

// The worst of the journey is still to come

// error
func eraseOverlapIntervals(intervals [][]int) (ans int) {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] != intervals[j][0] {
			return intervals[i][0] < intervals[j][0]
		}
		return intervals[i][1] < intervals[j][1]
	})
	lastInterval := intervals[0]
	for _, interval := range intervals[1:] {
		if lastInterval[0] == interval[0] {
			ans += 1
			continue
		}
		if lastInterval[1] > interval[0] {
			lastInterval = interval
			ans += 1
			continue
		}
		lastInterval = interval
	}
	return ans
}

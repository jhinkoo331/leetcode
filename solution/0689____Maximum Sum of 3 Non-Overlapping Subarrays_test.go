package main

import (
	"reflect"
	"testing"
)

// The worst of the journey is still to come

func Test_maxSumOfThreeSubarrays(t *testing.T) {
	type args struct {
		nums []int
		k    int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			name: "2",
			args: args{
				nums: []int{1, 2, 1, 2, 1, 2, 1, 2, 1},
				k:    2,
			},
			want: []int{0, 2, 4},
		},
		{
			name: "1",
			args: args{
				nums: []int{1, 2, 1, 2, 6, 7, 5, 1},
				k:    2,
			},
			want: []int{0, 3, 5},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := maxSumOfThreeSubarrays(tt.args.nums, tt.args.k); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("maxSumOfThreeSubarrays() = %v, want %v", got, tt.want)
			}
		})
	}
}

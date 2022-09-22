package main

import (
	"reflect"
	"testing"
)

// be happy, be confident.

func Test_getToken0241(t *testing.T) {
	type args struct {
		exp string
	}
	var tests = []struct {
		name     string
		args     args
		wantNums []int
		wantOps  []uint8
	}{
		{
			name: "first positive",
			args: args{
				exp: "1+1-11*111/1111",
			},
			wantNums: []int{1, 1, 11, 111, 1111},
			wantOps:  []uint8{Add0241, Sub0241, Mul0241, Div0241},
		},
		{
			name: "first negative",
			args: args{
				exp: "-1+1-11*111/1111",
			},
			wantNums: []int{-1, 1, 11, 111, 1111},
			wantOps:  []uint8{Add0241, Sub0241, Mul0241, Div0241},
		},
		{
			name: "4",
			args: args{
				exp: "10000",
			},
			wantNums: []int{10000},
			wantOps:  nil,
		},
		{
			name: "3",
			args: args{
				exp: "-1",
			},
			wantNums: []int{-1},
			wantOps:  nil,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			gotNums, gotOps := getToken0241(tt.args.exp)
			if !reflect.DeepEqual(gotNums, tt.wantNums) {
				t.Errorf("getToken0241() gotNums = %v, want %v", gotNums, tt.wantNums)
			}
			if !reflect.DeepEqual(gotOps, tt.wantOps) {
				t.Errorf("getToken0241() gotOps = %v, want %v", gotOps, tt.wantOps)
			}
		})
	}
}

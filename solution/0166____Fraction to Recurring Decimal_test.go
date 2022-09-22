package main

import "testing"

// be happy, be confident.

func Test_o166(t *testing.T) {
	type args struct {
		numerator   int
		denominator int
	}
	tests := []struct {
		name string
		args args
		want string
	}{
		{
			name: "100/5",
			args: args{
				numerator:   100,
				denominator: 5,
			},
			want: "20",
		},
		{
			name: "0/100",
			args: args{
				numerator:   0,
				denominator: 100,
			},
			want: "0",
		},
		{
			name: "1/3",
			args: args{
				numerator:   1,
				denominator: 3,
			},
			want: "0.(3)",
		},
		{
			name: "20/3",
			args: args{
				numerator:   20,
				denominator: 3,
			},
			want: "6.(6)",
		},
		{
			name: "100/27",
			args: args{
				numerator:   100,
				denominator: 27,
			},
			want: "3.(703)",
		},
		{
			name: "1/8",
			args: args{
				numerator:   1,
				denominator: 8,
			},
			want: "0.125",
		},
		{
			name: "1/6",
			args: args{
				numerator:   1,
				denominator: 6,
			},
			want: "0.1(6)",
		},
		{
			name: "4/333",
			args: args{
				numerator:   4,
				denominator: 333,
			},
			want: "0.(012)",
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := o166(tt.args.numerator, tt.args.denominator); got != tt.want {
				t.Errorf("o166() = %v, want %v", got, tt.want)
			}
		})
	}
}

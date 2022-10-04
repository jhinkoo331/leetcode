package main

import "testing"

// be happy, be confident.

func Test_getHint(t *testing.T) {
	type args struct {
		secret string
		guess  string
	}
	tests := []struct {
		name string
		args args
		want string
	}{
		{
			name: "2",
			args: args{
				secret: "1123",
				guess:  "0111",
			},
			want: "1A1B",
		},
		{
			name: "1",
			args: args{
				secret: "1807",
				guess:  "7810",
			},
			want: "1A3B",
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := getHint(tt.args.secret, tt.args.guess); got != tt.want {
				t.Errorf("getHint() = %v, want %v", got, tt.want)
			}
		})
	}
}

class Solution {
public:
	double angleClock(int hour, int minutes) {
		hour %= 12;
		double min_pointer = minutes * 6;
		double hour_pointer = hour * 30 + minutes * 0.5;
		min_pointer -= hour_pointer;
		min_pointer = min_pointer < 0 ? -min_pointer : min_pointer;
		return min_pointer < 180 ? min_pointer : 360 - min_pointer;
	}
private:
	double min = 6;
	double min_hour = 0.5;
};

int main(){
	Solution sln;
	double ret;
	ret = sln.angleClock(12, 30);
	ret = sln.angleClock(3, 30);
	ret = sln.angleClock(3, 15);
	ret = sln.angleClock(4 ,50);
	ret = sln.angleClock(12, 0);
	return 0;
}



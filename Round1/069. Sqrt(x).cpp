// Implement int sqrt(int x).

// Compute and return the square root of x.

class Solution {
public:
    int mySqrt(int x) {
		return solve(1, x, x);
	}

	//need mathmatic knowledge

	long long solve(long long start, long long end, long long x) {
		long long mid = (start + end) / 2;
		long long val = mid * mid;
		// cout<<start<< "  " <<end<<endl;
		if(val == x) {
			return mid;
		} else if(start == end) {
			if(val > x){
				return start -1;
			} else {
				return start;
			}
		} else if( val < x) {
			// cout<<"small" <<endl;
			return solve(mid+1, end, x);
		} else {
			// cout<<"big" <<start << "  " << mid << endl;
			if(start > mid -1) {
				return solve(start, start, x);
			} else {
				return solve(start, mid-1, x);
			}
		}
	}
};
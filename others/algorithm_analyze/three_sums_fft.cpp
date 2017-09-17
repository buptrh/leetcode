#include <map>
#include <vector>
using namespace std;
bool ThreeSum_FFT(vector<int> nums) {
	//1.transform to coefficient representation and Double degree-bound
	//because degrees can't be negative, so add all degrees by 200n. and we need to double the degree before we start FFT.
	vector<int> A(400*n, 0);
	for(int i = 0; i < nums.size(); i++) {
		A[nums[i] + 200*n]++;
	}

	//2.Evaluate with FFT
	vector<int> B = RECURSIVE_FFT(A);

	//3.Pointwise Multiply
	vector<int> C(400*n, 0);
	for(int i = 0; i < 400*n; i++) {
		C[i] = B[i] * B[i] * B[i];
	}

	//4.Interpolate with FFT-1
	vector<int> D = INVERSE_FFT(C);

	//5.Remove duplicates
	//so the coefficient of x0 should be the count of combination whose 3-sum is zero.
	int output = D[200*n];
	map<int> table;

	for(int i = 0; i < nums.size(); i++) {
		table[nums[i] * (-2)] ++;
	}
	for(int i = 0; i < nums.size(); i++) {
		output -= table[nums[i]];
	}
	return (output != 0);
}

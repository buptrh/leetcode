#include <iostream>
int minSubLen(vector<int> & array, int target) {
	int sum = 0, res = INT_MAX, left = 0;
	int allSum[array.size()];
	queue<int> minSumQueue;
	for(int i = 0; i < array.size(); i++) {
		sum += array[i];
		if( i > 0) {
			allSum[i] = allSum[i-1] + array[i];
		} else {
			allSum[i] = array[i];
		}
		if(array[i] < 0) {
			while(!minSumQueue.empty() && allSum[minSumQueue.front()] < allSum[i]) {
				minSumQueue.pop();
			}
			minSumQueue.push(i);
		}
		while((sum > target || array[left] < 0 || allSum[minSumQueue.front()] - allSum[left] < 0) && left < i ) {
            if(sum > target) {
			    res = min(res, i - left + 1);
            }
			if(res == 1) {
				return res;
			}
			sum -= array[left];
            left++;
		}
		while(!minSumQueue.empty() && minSumQueue.front() < left) {
			minSumQueue.pop();
		}
        cout << left << "  " << i << " . " << sum << " :: " << res << endl;
	}
	return res;
}
int main() {
    vector<int> vec{5, 4, -8, 5, 6, 2, 4, -4, -2, -6, 8};
    cout << minSubLen(vec, 10) << endl;
    std::cout << "Hello World!\n";
}
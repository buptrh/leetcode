// insert a number in ordered array with duplicates

int insert(vector<int> arr, int target) {
	int start = 0, end = arr.size()-1;
	int cur = 0;
	while(start + 1< end) {
		cur = start + (end - start) / 2;
		if(arr[cur] < target) {
			start = cur;
		} else {
			end = cur;
		}
	}
	if(arr[start] >= target) {
		return start;
	} else if(arr[end] >= target) {
		return end;
	} else {
		return end+1;
	}
}
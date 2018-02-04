int minAndMaxSubset(vector<int> & arr, int k) {
	int right = arr.size()-1, res = 0;
	vector<int> dp(arr.size(), 1);
    dp[0] = 1;
    int count = 2;
	for(int i = 1; i < arr.size(); i++) {
		if(arr[i] == arr[i-1]) {
			dp[i] = dp[i-1]/count*(count+1);
            count++;
		} else {
			dp[i] = dp[i-1]*2;
            count = 2;
		}
        // cout<<i << "  " << dp[i]<< "  " << endl;
	}
    // cout<<"!!!!!"<<endl;
    count = 1;
	for(int i = 0; i < arr.size()-1; i++) {
		if(arr[i] == arr[i+1]) {
			count++;
			continue;
		}
		while(right > i && arr[i] + arr[right] >= k) {
			right--;
		}
		if(right > i) {
			res += (dp[right] - dp[i])*count;//right - i + 1;
		} else {
			break;
		}
		count = 1;
	}
	return res;
}
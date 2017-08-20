class Solution {
public:
    int newInteger(int n) {
    	string sn = to_string(n);
        if(n < 9) {
        	return n;
        }
        int count = 0;
        vector<int> arr;
        arr.emplace_back(0);
        int index = 0;
        while(arr.size() < sn.size() + 1) {
        	index = arr.size()-1;
        	int current = arr[index] * 9 + pow(10, index);
        	arr.emplace_back(current);
        	count += arr[index+1];
        	// cout << current << endl;
        	if(pow(10, index+1) - count > n) {
        		break;
        	}
        }
        index = arr.size()-1;
        // cout <<"~~~ " << index << endl;
        int ret = 0;
        while(n > 0) {
        	int dev = (pow(10, index) - arr[index]);
        	if(n >= dev) {
        		ret += pow(10, index) * (n/dev);
        		// cout<<"n:" << n << "  " << dev << "  " << ret<< endl;
        		n = n % dev;
        	} else {

        	}
        	index --;
        	if(index == 0) {
        		break;
        	}
        }
        cout << n << endl;
        return ret + n;
    }


};
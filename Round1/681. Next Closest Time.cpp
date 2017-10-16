class Solution {
public:
    string nextClosestTime(string time) {


    	set<int> s;
    	int hour = stoi(time.substr(0,2));
    	int minu = stoi(time.substr(3,2));
        for(int i = 0; i < time.size(); i++) {
        	if(time[i] != ':') {
        		s.insert((int)(time[i] - '0'));
        	}
        }

        vector<int> arr;

        // copy(s.begin(), s.end(), arr.begin());
        for(auto it = s.begin(); it != s.end(); it++) {
        	arr.emplace_back(*it);
        }
        for(int i = 0; i < arr.size(); i++) {
        	if(arr[i] > (minu%10)) {
        		int val = minu + arr[i] - (minu%10);
        		return time.substr(0,2) + ":" + (val < 10 ? "0" + to_string(val) : to_string(val));
        	}
        }

        for(int i = 0; i < arr.size(); i++) {
        	if(arr[i] > (minu/10)) {
        		if(arr[i] < 6) {
        			return time.substr(0,2) + ":" + to_string(arr[i]) + to_string(arr[0]);
        		}
        	}
        }


        for(int i = 0; i < arr.size(); i++) {
        	if(arr[i] > (hour%10) && (hour/10 < 2 || arr[i] <= 4)) {
        		int val = hour + arr[i] - hour%10;
        		return (val < 10 ? "0" + to_string(val) : to_string(val)) + ":" + to_string(arr[0]) + to_string(arr[0]);
        	}
        }

        for(int i = 0; i < arr.size(); i++) {
        	if(arr[i] > (hour/10) && (arr[i] < 2 || (arr[i] == 2 && arr[0] < 4))) {
        		return to_string(arr[i]) + to_string(arr[0]) + ":" + to_string(arr[0]) + to_string(arr[0]);
        	}
        }

        return to_string(arr[0]) + to_string(arr[0]) + ":" + to_string(arr[0]) + to_string(arr[0]) ;
    }



};
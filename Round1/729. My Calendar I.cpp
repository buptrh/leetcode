class MyCalendar {
public:
	vector<pair<int, int>> starts;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
    	// cout<<"book" << start << "  " << end <<endl;
        int index = binarySearch(0, starts.size()-1, start, starts);
        if(index != -1 && (index == 0 || starts[index-1].second <= start) && (index == starts.size() || starts[index].first >= end)) {
        	starts.insert(starts.begin() + index, make_pair(start, end));
        	// cout<<"~~~~~get" << start << endl;
        	return true;
        } else {
        	return false;
        }
    }

    int binarySearch(int left, int right, int target, vector<pair<int, int>> & starts) {
    	if(right < left) {
    		return 0;
    	}
    	int ret = 0;
    	int mid = 0;
    		// cout<<"ss" << left << " " << right <<" " << target << endl;
    	while(left < right) {
    		mid = left + (right - left) / 2;
    		// cout<<"!!!" << mid<<endl;
    		if(starts[mid].first == target) {
    			return -1;
    		} else if(starts[mid].first < target) {
    			left = mid + 1;
    		} else {
    			right = mid;
    		}
    	}
    	if(starts[left].first > target) {
    		ret = left;
    	} else if(starts[right].first > target) {
    		ret = right;
    	} else {
    		ret = right + 1;
    	}
		// cout<<"eee" << ret << endl;
    	return ret;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
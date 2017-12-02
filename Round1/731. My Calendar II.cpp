class MyCalendarTwo {
public:
	vector<pair<int, int>> starts1;
	vector<pair<int, int>> starts2;
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
    	vector<pair<int, int>> intervals, intervalsFinish;
        if(book22(start, end, starts1, intervals, intervalsFinish, true) ) {
        	return true;
        } else {
        	for(pair<int, int> interval : intervals) {
    			vector<pair<int, int>> intervals2;
	        	if(!book22(interval.first, interval.second, starts2, intervalsFinish, intervals2)) {
	        		// cout<<"book2" << start << "  " << end << endl;
	        		return false;
	        	}
        	}
        	return true;
        }
    }


    bool book22(int start, int end, vector<pair<int, int>> & starts, vector<pair<int, int>> & intervals, vector<pair<int, int>> & intervalsFinish bool add) {
        int index = binarySearch(0, starts.size()-1, start, starts);
    	// cout<<"book2. " << start << "  " << end << "  " << index << endl;
        if(index != -1 && (index == 0 || starts[index-1].second <= start) && (index == starts.size() || starts[index].first >= end)) {
        	if(add) {
        		starts.insert(starts.begin() + index, make_pair(start, end));
        	} else {
        		intervalsFinish.push_back(make_pair(start, end));
        	}
        	// cout<<"~~~~~insert" << start << "  " << end << endl;
        	return true;
        } else {
        	// cout<<"ERRR: " << starts[index-1].second << "  " << start << " : " << starts[index].first << "  " << end << endl;
        	if(!(index == 0 || starts[index-1].second <= start)) {
        		// cout<<"1111111"<<endl;
        		intervals.push_back(make_pair(start, starts[index-1].second));
        		book22(starts[index-1].second, end ,starts, intervals, false);
        	} else {
        		// cout<<"2222222"<<endl;
        		intervals.push_back(make_pair(starts[index].first, end));
        		book22(start, starts[index].first ,starts, intervals, false);
        	}
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
    			return mid;
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
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
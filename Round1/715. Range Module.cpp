class RangeModule {
public:
	vector<pair<int, int> > intervals;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
    	int start = -1, end = -1;
    	bool added = false;
        for(auto it = intervals.begin(); it != intervals.end();) {
        	if(it->first <= left && it->second >= right) {
        		return;
        	} else if(it->first <= left && it->second >= left) {
        		it->second = right;
        		added = true;
        		it++;
        	} else if(it->first <= right && it->second >= right) {
        		it->first = left;
        		added = true;
        		it++;
        	} else if(it->first >= left && it->second <= right) {
        		intervals.erase(it);
        	} else {
        		it++;
        	}
        }
        if(!added) {
	    	intervals.emplace_back(make_pair(left, right));
	    	auto comp = [](pair<int, int> a, pair<int, int> b) {
			    return a.first < b.first;
			};
	    	sort(intervals.begin(), intervals.end(), comp);
        }

        // cout<<"add " << left<<". " << right<<endl;
        output();
    }
    
    bool queryRange(int left, int right) {
        for(pair<int, int> interval : intervals) {
        	if(interval.first <= left && interval.second >= right) {
        		return true;
        	}
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        for(auto it = intervals.begin(); it != intervals.end(); ) {
        	if(it->first >= left && it->second <= right) {
        		intervals.erase(it);
        	} else if(it->first <= left && it->second >= right) {

        		int temp = it->second;
        		if(it->second == left) {
        			intervals.erase(it);
        		}
        		it->second = left;
        		addRange(right, temp);
        		break;
        	} else if(it->first <= left && it->second >= left) {
        		it->first = left;
        		it++;
        	} else if(it->first <= right && it->second >= right) {
        		it->first = right;
        		break;
        	} else {
        		it++;
        	}
        }
        // cout<<"Remove " << left<<". " << right<<endl;
        output();
    }

    void output() {
        for(pair<int, int> interval : intervals) {
        	// cout<<interval.first <<".  " << interval.second<<endl;
        }

    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
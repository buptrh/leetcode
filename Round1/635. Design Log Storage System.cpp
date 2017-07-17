class LogSystem {
public:
	vector<string> timeString;
	map<int, vector<int> > logs;
    LogSystem() {
        timeString.push_back("Year");
        timeString.push_back("Month");
        timeString.push_back("Day");
        timeString.push_back("Hour");
        timeString.push_back("Minute");
        timeString.push_back("Second");
    }
    
    void put(int id, string timestamp) {
        logs[id] = separateTime(timestamp);
    }

    std::vector<int> separateTime(string timestamp) {
        vector<int> time;
        int pos = 0, pos2 = 0;
        while(pos >= 0) {
        	pos2 = timestamp.find(":", pos);
        	string val = timestamp.substr(pos, pos2-pos);
        	// cout<<val<<endl;
        	time.push_back(stoi(val));
        	if(pos2 < 0) {
        		break;
        	}
        	// cout<<pos2<<endl;
        	pos = pos2 + 1;
        }
    	return time;
    }
    vector<int> retrieve(string s, string e, string gra) {

        vector<int> start, end, ret;
        int pos = 0;
        for(int i = 0; i < timeString.size(); i++) {
        	if(timeString[i] == gra) {
        		pos = i;
        	}
        }
        // cout<<"gra"<<pos<<endl;
        if(pos < 0) {
        	return ret;
        }

        start = separateTime(s);
        end = separateTime(e);
        set<int> dup;
        for(auto it = logs.begin(); it != logs.end(); it++) {
        	if(dup.find(it->first) != dup.end()) {
        		continue;
        	}
        	bool flag = true;
    		bool flag1 = false, flag2= false;
        	for(int i = 0; i <= pos; i++) {
        		// cout<<it->second[i] << " start" << start[i] << " end" << end[i] <<endl;
        		if(it->second[i] > start[i]) {
        			flag1 = true;
        		} else if(!flag1 && it->second[i] < start[i] ) {
        			flag = false;
        			// cout<<"false1" <<endl;
        			break;
        		}
        		if(it->second[i] < end[i]) {
        			flag2 = true;
        			// cout<<"true2" <<endl;
        		} else if(!flag2 && it->second[i] > end[i] ) {
        			flag = false;
        			// cout<<"false2" <<endl;
        			break;
        		}
        		if(flag1 && flag2) {
        			break;
        		}
	        }
	        if(flag) {
    			ret.emplace_back(it->first);
				dup.insert(it->first);

	        }
        }
        return ret;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
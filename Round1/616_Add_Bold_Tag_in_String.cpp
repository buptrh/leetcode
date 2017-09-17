class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
    	vector<pair<int, int> > pairs;
        for(int i = 0; i < dict.size(); i ++) {
        	int pos = 0;
        	int size = dict[i].size();
        	do{
        		pos = s.find(dict[i], pos);
        		// cout<<pos<<endl;
        		if(pos >= 0) {
        			pair<int, int> p(pos, pos+size - 1);
        			pairs.push_back(p);
        			// cout<<pos<<". " << p.second<<endl;
        			pos ++;
        		}
        	} while(pos >= 0);
        }
        if(pairs.size() == 0) {
        	return s;
        }
        sort(pairs.begin(), pairs.end());
        string ret = "";
        int start = -1, end = -1;
        for(int i = 0; i < pairs.size(); i++) {
        	// cout<<"start"<<pairs[i].first<<". " << pairs[i].second<<endl;
        	if(start < 0) {
        		start = pairs[i].first;
        		end = pairs[i].second;
        		ret = ret + s.substr(0, start);
        		ret = ret + "<b>";
        	} else {
        		if(pairs[i].first > end+1) {
        			// cout<<"output" << start << "  " << end<<endl;
        			ret = ret + s.substr(start, end-start+1) + "</b>";
					ret = ret + s.substr(end+1, pairs[i].first-end-1) + "<b>" ;
        			start = pairs[i].first;
        		}
        		end = max(end, pairs[i].second);
        		// cout<<"end:" <<start << "  " <<end<<endl;
        	}
        }
        if(start >= 0) {
        	ret = ret + s.substr(start, end-start+1);
			// cout<<"output" << start << "  " << end<<endl;
        }
		ret = ret + "</b>";
        if( end < s.size()-1) {
			ret = ret + s.substr(end+1, -1);
        }
		return ret;
    }
};
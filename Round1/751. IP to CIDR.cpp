class Solution {
public:
    vector<string> ipToCIDR(string ip, int range) {
    	vector<string> res;
    	vector<int> ips;
        vector<string> s = split(ip, '.');
        for(int i = 0; i < s.size(); i++) {
        	ips.push_back(stoi(s[i]));
        }
    	// cout<<"helper: " << outputStr(ips) << "  " << range << endl;
    	helper(ips, range, res);
    	// cout<<"All"<<endl;
    	return res;
    }
	vector<string> split(string t, char sp) {
        vector<string> words;
        istringstream iss(t);
        string s;
        while (getline(iss, s, sp)) {
            words.push_back(s);
        }
        return words;
    }
//     vector<string> split(const string &s, char delim) {
// 	    stringstream ss(s);
// 	    string item;
// 	    vector<string> tokens;
// 	    while (getline(ss, item, delim)) {
// 	        tokens.push_back(item);
// 	    }
// 	    return tokens;
// }


    void helper(vector<int>& ips, int range, vector<string>& res) {
    	if(range <= 0) {
    		// cout<<"Finish"<<endl;
    		return;
    	}
        int size = 0;
    	int count = 1;
    	int bits = 0;
    	// cout<<"helper: " <<outputStr(ips) << "  " << range << endl;
        for(int i = 3; i >= 0; i--) {
        	int num = ips[i];
        	int curCount = 0;
        	while(curCount < 8 && (count * 2 <= range) && ((num & 1) == 0)) {
        		count *= 2;
        		num = num >> 1;
        		bits++;
        		// cout<< "curr: " << num << "  " << count <<endl;
        		curCount ++;
        	}
        	// cout<<"~~~ " << ips[i] <<". " << count << endl;
        	if( (count * 2 > range) || ((num & 1) != 0)) {
        		if(bits == 0) {
        			// bits = 1;
        		}
        		res.push_back(outputStr(ips)+"/"+to_string(32-bits));
        		ips[3] = ips[3] + count;
        		// cout<<".  !!!res: " << outputStr(ips) << "  " << i << "  " << count << endl;
        		int j = 3;
        		while(j > 0 && ips[j] > 255) {
        			ips[j-1] += ips[j]/256;
        			ips[j] = ips[j] % 256;
        			j--;
        		}
        		helper(ips, range - count, res);
    		// cout<<"Finish: " << range<<endl;
        		return;
        	}
        }
    }

    string outputStr(vector<int>& ips) {
		string s;
		for(int j = 0; j < 4; j++) {
			s += to_string(ips[j])+".";
		}
		s.pop_back();
		return s;
    }
};
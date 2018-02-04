class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

    	vector<string> res;
    	helper(s, 0, 0, "", res);
        return res;
    }

    void helper(string s, int start, int index, string ip, vector<string> & res) {
    	if(index == 4) {
    		if(start >= s.size()) {
    			res.push_back(ip);
    		}
    		return;
    	}
    	if(start >= s.size()) {
    		return;
    	}
    	string temp;
    	temp.push_back(s[start]);
    	string currentIP = ip;
    	// cout<< temp << "  " << stoi(temp) << endl;
    	while(stoi(temp) < 256) {
    		start++;
    		if(to_string(stoi(temp)) == temp) {
	    		if(index == 0) {
	    			currentIP = ip + temp;
	    		} else {
	    			currentIP = ip + "." + temp;
	    		}
	    		// cout<< "!!" << currentIP << "  ~~ " <<<< endl;
	    		helper(s, start, index+1, currentIP, res);
    		}
    		if(start >= s.size()) {
    			break;
    		}
    		temp.push_back(s[start]);
    	}
    }
};
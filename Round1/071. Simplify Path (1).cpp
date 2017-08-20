class Solution {
public:
    string simplifyPath(string path) {
        vector<string> splits = split(path, '/');
        string ret = "";
        vector<string> retpath;
        for(int i = 0; i < splits.size(); i++) {
        	string str = splits[i];
        	if(str.size() == 0) {
        		continue;
        	} else if(str == ".") {
        		continue;
        	} else if(str == "..") {
        		if(retpath.size() > 0) {
        			retpath.pop_back();
        		}
        	} else {
    			retpath.push_back(str);
        	}
        }
       	for(int i = 0; i < retpath.size(); i++) {
        	ret += "/" + retpath[i];
        	// cout<<ret <<endl;
        }
        if(ret.size() == 0) {
        	ret = "/";
        }
        return ret;
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

};
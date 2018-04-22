class Solution {
public:
	vector<string> split(string t, char sp) {
        vector<string> words;
        istringstream iss(t);
        string s;
        while (getline(iss, s, sp)) {
            words.push_back(s);
        }
        return words;
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> table;
        for(string s : cpdomains) {
        	vector<string> doms = split(s, ' ');

        	int count = stoi(doms[0]);
        	vector<string> subs = split(doms[1], '.');
        	string temp;
        	for(int i = subs.size()-1; i >= 0; i--) {
	        	// cout<<"!! " << temp << endl;
        		if(temp.size() > 0) {
        			temp = "." + temp;
        		}
        		temp = subs[i] + temp;
        		table[temp] += count;
        	}
        }

        vector<string> res;
        for(auto data : table) {
        	string temp;
        	temp += to_string(data.second);
        	temp += " ";
        	temp += data.first;
        	res.push_back(temp);
        }
        return res;

    }
};
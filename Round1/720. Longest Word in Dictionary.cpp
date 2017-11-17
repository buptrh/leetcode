class Solution {
public:
    string longestWord(vector<string>& words) {
        auto comp = [](string a, string b) {
        	if(a.size() == b.size()) {
        		return a < b;
        	} else {
        		return a.size() > b.size();
        	}
		};
		sort(words.begin(), words.end(), comp);
		set<string> dup;

		for(string test : words) {
			dup.insert(test);
			cout<<test<<endl;
		}

		for(string test : words) {
			bool good = true;
			for(int i = 1; i < test.size(); i++) {
				if(dup.find(test.substr(0, i)) == dup.end()) {
					good = false;
				}
			}
			if(good) {
				return test;
			}
		}

		return "";
    }
};
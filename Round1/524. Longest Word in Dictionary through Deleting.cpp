class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        
    	auto comp = [](string & a, string & b ) {
		    if(a.size() == b.size()) {
		    	return a < b;
		    } else {
		    	return a.size() > b.size();
		    }
		};
		sort(d.begin(), d.end(), comp);
		int left = 0, right = 0;
		for(int i = 0; i < d.size(); i++) {
			while(left < d[i].size() && right < s.size()){
				if(d[i][left] == s[right]) {
					left ++;
				}
				if(left == d[i].size()) {
					return d[i];
				}
				right++;
				if(right == s.size() || d[i].size() - left > s.size() - right) {
					break;
				}
			}
			left = 0;
			right = 0;
		}
		return "";
    }
};
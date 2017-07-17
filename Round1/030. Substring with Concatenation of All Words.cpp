class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

    	vector<int> ret;
    	if(words.size() == 0) {
    		return ret;
    	}
    	int len = words[0].size();
    	int count = words.size();

    	vector<int> comp(words.size(), -1);
    	for(int start = 0; start < len; start++) {
			for(int j = 0; j < words.size(); j++) {
				comp[j] = -1;
			}
			count = words.size();
			
			for(int i = start; i < s.size()-len+1; i += len) {
				bool flag = false;
				string sub = s.substr(i, len);
				vector<int> dup;
				for(int j = 0; j < words.size(); j++) {
					if(words[j] == sub) {
						if(comp[j] < 0) {
							comp[j] = i;
							count--;
							flag = true;
							// cout<<" find" << i << "  " << sub << endl;
	 						break;
						} 
					}
				}
				if(!flag) {
					if(count != words.size()) {
						for(int j = 0; j < words.size(); j++) {
							comp[j] = -1;
						}
						i -= len * (words.size()-count);
						count = words.size();
					}
					// cout<<"clear all" <<endl;
				}
				if(count == 0) {
					int left = s.size(), leftIndex = 0;
					for(int m = 0; m < comp.size(); m++) {
						if(comp[m] < left) {
							left = comp[m];
							leftIndex = m;
						}
					}
					// cout<<" push" << left << endl;
					ret.push_back(left);
					comp[leftIndex] = -1;
					count++;
				}
			}
    	}
		return ret;
    }
};
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    	vector<string> vRet;
        for(int i = 0; i < list1.size()+list2.size(); i++) {
        	vRet.clear();
        	for(int j = 0; j < list1.size(); j++) {
        		if(i - j >=  list2.size()) {
        			continue;
        		}
        		if(list1[j] == list2[i-j]) {
        			vRet.emplace_back(list1[j]);
        		}
        	}
        	if(vRet.size() != 0) {
        		return vRet;
        	}
        }
        return vRet;
    }
};
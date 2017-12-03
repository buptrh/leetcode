class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
       	int ma = INT_MIN, mi = INT_MAX, val = 0;
       	int maNext = ma, miNext = mi;
        std::vector<int> vMin;
        for(int i = 0; i < arrays.size(); i++) {
        	ma = max(ma, maNext);
        	mi = min(mi, miNext);
        	maNext = INT_MIN;
        	miNext = INT_MAX;
        	for(int j = 0; j < arrays[i].size(); j++) {
        		maNext = max(maNext, arrays[i][j]);
        		miNext = min(miNext, arrays[i][j]);
        		if(maNext > mi) {
        			val = max(val, maNext - mi);
        		}
        		if(ma > miNext) {
        			val = max(val, ma - miNext);
        		}
        		// cout<< val << "  " << maNext << "  " << miNext <<endl;
        	}
        	// cout<<"this" << maNext<<". " << miNext<<endl;
        }

        return val;
    }
};
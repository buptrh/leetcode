// class Solution {
// public:
//     int kEmptySlots(vector<int>& flowers, int k) {
//         set<int> s;
//         for(int i=0; i<flowers.size(); i++) {
//             s.insert(flowers[i]);
//             auto i1 = s.find(flowers[i]);
//             if(i1 != s.end() and *next(i1) - *i1 - 1 == k) return i + 1;
//             if(i1 != s.begin() and *i1 - *prev(i1) - 1 == k) return i + 1;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
    	int res = INT_MAX;
        
        vector<int> positions(flowers.size(), 0);
        for(int i = 0; i < flowers.size(); i++){
            positions[flowers[i] - 1] = i + 1;
        }
        
        int left = 0, right = k+1;
        for(int i = 0; right < flowers.size(); i++) {
        	if(positions[i] > positions[left] && positions[i] > positions[right]) {
        		continue;
        	}
        	if(i == right) {
        		res = min(res, max(positions[left], positions[right]));
        	}
    		left = i;
    		right = i + k + 1;
        }
        return res == INT_MAX ? -1 : res;
    }
};

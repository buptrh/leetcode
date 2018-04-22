class Solution {
public:
    int numRabbits(vector<int>& answers) {
        multiset<int> as;
        for(int i : answers) {
        	as.insert(i);
        }
        int res = 0;
        while(as.size() > 0) {
        	int v = *as.begin();
        	int count = v+1;
        	for(auto it = as.begin(); it != as.end();) {
        		if(*it == v) {
        			as.erase(it++);
        			count--;
        			if(count <= 0) {
        				break;
        			}
        		} else {
        			it++;
        		}
        	}
        	res += (v+1);
        }
        return res;
    }
};
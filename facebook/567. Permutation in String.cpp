class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> table;
        for(char c : s1) {
        	table[c] ++;
        }
        int n = s1.size();
        map<char, int> table2 = table;
        int index = 0;
        for(int i = 0; i < s2.size(); i++) {
        	if(table2.find(s2[i]) == table2.end()) {
        		table2 = table;
        		n = s1.size();
        		index = i+1;
        		continue;
        	}

    		while(table2[s2[i]] <= 0) {
    			table2[s2[index]]++;
    			index++;
    			n++;
    		}

    		table2[s2[i]]--;
    		n--;
    		if(n == 0) {
    			return true;
    		}
        }
        return false;
    }
};
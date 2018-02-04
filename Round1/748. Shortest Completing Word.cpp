class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int minL = INT_MAX, mLeft = INT_MAX, count = 0;
        map<int, int> table;
        for(char c : licensePlate) {
        	if(c >= 'a' && c <= 'z') {
        		if(table[c-'a'] == 0) {
        			count++;
        		}
        		table[c-'a']++;
        	} else if(c >= 'A' && c <= 'Z') {
        		if(table[c-'A'] == 0) {
        			count++;
        		}
        		table[c-'A']++;
        	}
        }
        string res ;
        for(string s : words) {
        	map<int, int> table2 = table;
        	int temp = count;
        	int j = 0;
        	for(; j < s.size(); j++) {
        		char c = s[j];
        		if(table2[c - 'a'] > 0) {
        			table2[c-'a']--;
        			if(table2[c-'a'] == 0) {
        				temp --;
        			}
        		} else if(table2[c - 'A'] > 0) {
        			table2[c-'A']--;
        			if(table2[c-'A'] == 0) {
        				temp --;
        			}
        		} 
        		if(temp == 0) {
        			break;
        		}
        	}
        	if(temp == 0) {
        		if(minL > s.size()) {
        			mLeft = j;
        			minL = s.size();
        			res = s;
        		}
        	}
        }
        return res;
    }
};
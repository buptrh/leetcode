class Solution {
public:
    int romanToInt(string s) {
        
    	unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        int res = 0, val = 0;
        stack<int> sta;
        for(int i = 0; i < s.size(); i++) {
        	val = 0;
        	int current = T[s[i]];
	        while(sta.size() != 0 && sta.top() < current) {
	        	val -= 2*sta.top();
	        	sta.pop();
	        }
	        sta.push(current);
	        res += val;
	        res += current;
        }
        return res;
    }
};

//VIIXIVI
class Solution {
public:
	int romanToInt(string s) {
	    unordered_map<char, int> T = { { 'I' , 1 },
	                                   { 'V' , 5 },
	                                   { 'X' , 10 },
	                                   { 'L' , 50 },
	                                   { 'C' , 100 },
	                                   { 'D' , 500 },
	                                   { 'M' , 1000 } };
	                                   
	   int sum = 0;
	   for (int i = 0; i < s.size(); i++) {
	       if (i+1 < s.size() && T[s[i]] < T[s[i + 1]]) {
	           sum -= T[s[i]];
	       }  else {
	           sum += T[s[i]];
	       }
	   }
	   
	   return sum;
	}
};
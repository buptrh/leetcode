class Solution {
public:
    string countAndSay(int n) {
        string val = "1";
        string next = "";
        while(n > 1) {
			// cout<<val<<endl;
        	int count = 1;
        	char last = 0;
        	for(int i = 0; i < val.size(); i++) {
        		if(last == val[i]) {
        			count++;
        		} else  {
        			if(last != 0) {
	        			next += to_string(count);
	        			next.push_back(last);
        			}
        			last = val[i];
        			count = 1;
        		}
        	}
			next += to_string(count);
			next.push_back(last);
			val = next;	
			next = "";
        	n--;
        }
        return val;
    }
};
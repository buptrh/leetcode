class Solution {
public:
    string numberToWords(int num) {
    	string ret;
    	vector<string> app {"", "Thousand", "Million", "Billion", "Trillion"}
        if(num / 1000 == 0) {

        } else {
        	vector<string> subs;
        	while(num != 0) {
        		subs.push_back(numberToWords(num%1000));
        		num = num / 1000;
        	}
        	for(int i = subs.size()-1; i >= 0; i++) {
        		ret += subs[i] + " " + app[i];
        	}
        }
        return ret;
    }
};
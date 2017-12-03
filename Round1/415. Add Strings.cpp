class Solution {
public:
    string addStrings(string num1, string num2) {
    	int add = 0, index = 0, val = 0;
    	string ret;
        while(-1-index + (int)num1.size() >= 0 || -1-index + (int)num2.size() >= 0) {
        	val = add;
        	if(-1-index + (int)num1.size() >= 0) {
        		int m = num1[num1.size()-1-index]- '0';;
        		// cout << m << "  ";
        		val += num1[num1.size()-1-index]- '0';
        	}
        	if(-1-index + (int)num2.size() >= 0) {
        		int m = num2[num2.size()-1-index]- '0';;
        		// cout << -index -1+num2.size() << "  "  << m ;
        		val += num2[num2.size()-1-index] - '0';
        	}
        	// cout<<endl;
        	add = val / 10;
        	ret += val%10 + '0';
        	index++;
        }
        if(ret.size() == 0){
        	ret = "0";
        }
        if(add != 0) {
        	ret += add + '0';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
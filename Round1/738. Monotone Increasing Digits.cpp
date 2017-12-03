class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int left = -1, res = 0;
        while(true) {
        	left = -1;
        	bool flag = false;
	        for(int i = 0; i < s.size()-1; i++) {
	        	if(s[i] > s[i+1]) {
	        		left = i;
	        		flag = true;
	        		break;
	        	}
	        }

	        if(!flag) {
	        	break; 
	        } else {
		        s[left] = s[left] - 1;
		        for(int j = left+1; j < s.size(); j++) {
		        	s[j] = '9';
		        }
	        }
        }
        // cout<<s<<endl;
        return stoi(s);
    }
};
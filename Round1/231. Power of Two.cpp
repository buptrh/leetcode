class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool flag = false;
        while(n != 0) {
        	if(n & 1 != 0) {
        		if(flag) {
        			cout<<n<<endl;
        			return false;
        		} else {
        			flag = true;
        		}
         	}
         	n = n >> 1;
        }
        return flag;
    }
};
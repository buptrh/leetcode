class Solution {
public:
    int findNthDigit(int n) {
        int index = 0;
        int current = 1;
        int n1 = n;
        while(n1 > 9 * pow(10, index) * (index+1)) {
        	n1 -= 9 * pow(10, index) * (index+1) ;
        	index ++;
        }

        int val = pow(10, index) - 1 + (n1+1)/(index+1);
        if(index == 0) {
        	val--;
        }
        // cout<<val << "  " << index<< "  " << n1 << endl;
        int m = n1%(index+1);
        if(m != 0 ) {
        	// cout<<index << "   " << n1%(index+1) << "  " << index-n1%(index+1);
       		val /= pow(10, index+1 - m);
        }
        // cout<< val;
        return val % 10;
     }
};
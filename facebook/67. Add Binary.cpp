class Solution {
public:
    string addBinary(string a, string b) {
    	if(a.size() < b.size()) {
    		return addBinary(b, a);
    	}
        bool carry = false;
        string res = a;
    	int j = a.size()-1;
        for(int i = b.size()-1; i >= 0; i--, j--) {
        	if(a[j] == '1' && b[i] == '1' && carry) {
        		res[j] = '1';
        		carry = true;
        	} else if(a[j] == '0' && b[i] == '0' && !carry) {
        		res[j] = '0';
        		carry = false;
        	} else if((carry && (a[j] == '0' && b[i] == '0')) || (!carry && !(a[j] == '1' && b[i] == '1'))) {
        		res[j] = '1';
        		carry = false;
        	} else {
        		res[j] = '0';
        		carry = true;
        	}
        }
        cout<<res<<endl;

        while(carry && j >= 0) {
        	if(a[j] == '1') {
        		res[j] = '0';
        		carry = true;
        	} else {
        		res[j] = '1';
        		carry = false;
        	}
        	j--;
        }
        if(carry) {
        	res = '1' + res;
        }
        return res;
    }
};
class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string product = "";
        for(int i = 0; i < num1.size(); i++) {
        	int add = 0;
        	int val = -1;
        	int current1 = num1[i] - '0';
        	for(int j = 0; j < num2.size(); j++ ){
        		int current2 = num2[j] - '0';
        		val = current1 * current2;
        		int position = i+j;

        		while(true) {
        			if(product.size() <= position) {
        				product.push_back('0' + val % 10);
        			} else {
        				val += product[position] - '0';
        				product[position] = '0' + val % 10;
        			}
        			if(val == 0) {
        				break;
        			}
        			position++;
    				val = val / 10;
    				if( val == 0 && i == num1.size() -1 && j == num2.size() - 1) {
    					break;
    				}
        		}
        	}
        }
        int end = 0;
        for(int i = product.size()-1; i >= 0; i--) {
        	if(product[i] == '0') {
        		end++;
        	} else {
        		break;
        	}
        }
        product.erase (product.end()-end, end);
        reverse(product.begin(), product.end());
        return product;
    }
};
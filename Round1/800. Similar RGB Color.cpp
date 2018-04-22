class Solution {
public:
    string similarRGB(string color) {
        string ret = "#";
        map<char, int> table;
        map<int, char> table2;
        for(int i = 0; i < 10; i++) {
        	table[i+'0'] = i;
        	table2[i] = i+'0';
        }
        
        for(int i = 0; i < 7; i++) {
        	table[i+'a'] = i+10;
        	table2[i+10] = i+'a';
        }

    	int val = 0;
        for(int i = 1; i < 6; i += 2) {
        	int a = table[color[i]];
        	int b = table[color[i+1]];
        	if((abs(a * 16 + a - a * 16 - b) <  abs((a+1) * 16 + a+1 - a * 16 - b) || (a == 15)) 
        		&& (abs(a * 16 + a - a * 16 - b) <  abs((a-1) * 16 + a-1 - a * 16 - b) || a == 0)) {
        		int temp = abs(a * 16 + a - a * 16 - b);
        		// cout<< a << "  " << temp  << endl;;
        		val += temp * temp;
        		ret += table2[a];
        		ret += table2[a];
        	} else if((abs(a * 16 + a - a * 16 - b) >  abs((a+1) * 16 + a+1 - a * 16 - b) && (a <= 15)) 
        		&& (abs(a * 16 + a - a * 16 - b) <  abs((a-1) * 16 + a-1 - a * 16 - b) || a == 0)) {
        		int temp = abs((a+1) * 16 + a+1 - a * 16 - b);
        		val += temp * temp;
        		// cout<< a+1 << "  " << temp  << endl;;
        		ret += table2[a+1];
        		ret += table2[a+1];
        	} else {
        		int temp = abs((a-1) * 16 + a-1 - a * 16 - b);
        		val += temp * temp;
        		// cout<< a+1 << "  " << temp  << endl;;
        		ret += table2[a-1];
        		ret += table2[a-1];
        	}
        }
        // ret = "-" + to_string(val);
        return ret;
    }
};
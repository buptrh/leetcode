class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
    	int res = 0;
    	char let = 0;
    	int count = 0;
    	int pos = 0;
        for(string cur : words) {
        	bool flag = true;
        	for(int i = 0; i < S.size(); i++) {
        		char c = S[i];
        		// cout<<"!!  "<< cur[pos] << "  " << c <<endl;
        		if(c == cur[pos]) {
        			if(let != c) {
        				// if(count == 2 && pos > 1) {
        				// 	cout<<let << "  " << cur[pos-2] << "  " << cur[pos-1] << "  " << cur[pos] << " : " << pos<<endl;
        				// }
	        			if(count == 2 && (pos <= 1 || cur[pos-2] != cur[pos-1])) {
	        				flag = false;
        					// cout<< "~!#false. " << i << "  " << c << endl;
	        				break;
	        			}
        				count = 0;
        			}
        			pos++;
        			let = c;
        			count ++;
        		} else {
        			if(let == c) {
        				count++;
        			} else if(count < 3) {
        				// cout<< "false. " << i << "  " << cur << endl;
        				flag = false;
        				break;
        			}
        		}
        		// cout<< c << "  " << pos << "  " << count << endl;
        	}
        	if(flag && pos == cur.size() ) {
        		// cout<<"~~"<< cur <<endl;
        		res++;
        	}
        	let = 0;
        	count = 0;
        	pos = 0;
        }
        return res;
    }
};
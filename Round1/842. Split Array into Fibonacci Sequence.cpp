class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        for(int i = 0; i < S.size()-1 && i < 9; i++) {
        	int v1 = stoi(S.substr(0, i+1));
        	if(S[0] == '0' && i != 0) {
        		continue;
        	}
        	for(int j = i+1; j < S.size()-1 && j < i+9; j++) {
	        	if(S[i+1] == '0' && j != i+1) {
	        		continue;
	        	}
        		int v2 = stoi(S.substr(i+1, j-i));
    			vector<int> res;
    			res.push_back(v1);
    			res.push_back(v2);
        	bool flag = true;
    			int m = j+1;
    			// cout<<i << "  " << j << " : " <<v1<<". " << v2<<endl;
    			int t1 = v1;
        		for( ; m < S.size() ; ){
        			int v3 = t1+v2;

        			if(v3<0) {
        				flag = false;
        				break;
        			}
    				res.push_back(v3);
        			string s3 = to_string(v3);
        			// cout<<". |" << v3<<". "<<s3<<endl;
        			if(S.substr(m, s3.size()) != s3) {
        				// cout<<"!!!flase;" << m<<" " <<S.substr(m+1, s3.size()) << "  : "<<s3<<endl;
        				flag = false;
        				break;
        			}
        			t1 = v2;
        			v2 = v3;
        			m = m+s3.size();
        		}
        		if(flag && m >= S.size() && res.size() >= 3) {
        			return res;
        		}
        	}
        }
        return vector<int>();
    }
};
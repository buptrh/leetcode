class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
    	std::vector<int> vNumber;
    	std::vector<char> vCal;
    	int num = 0;
        for(int i = 0; i < input.size(); i++) {
        	if(input[i] >= '0' && input[i] <= '9') {
        		num = num * 10 + (input[i] - '0');
        	} else {
        		vNumber.emplace_back(num);
        		vCal.emplace_back(input[i]);
        		cout<<num<<input[i]<<endl;
        		num = 0;
        	}
        }
        vNumber.emplace_back(num);
        int numberCount = vNumber.size();
        std::vector<int> vRet;
        if(numberCount == 0) {
        	return vRet;
        } else if(numberCount == 1) {
        	vRet.emplace_back(vNumber[0]);
        	return vRet;
        }
        vector<int>  resultsDP[numberCount][numberCount];
        // cout <<"numberCount"<<numberCount<<endl;
        for(int i = 0; i < numberCount; i++) {
        	for(int j = 0; j < numberCount - i; j++) {
	        	std::vector<int> vec;
    			// cout<<"~~" << j<< "  " << j+i  << endl;
    			
        		if( i <= 1 ) {
					int val = calcFromArray(vNumber, vCal, j, j+i);
					// cout<<"out m: val: " <<j << "  " << j+i << " | " << val <<endl;
	        		vec.emplace_back(val);
        		} else {
	        		for(int m = 0; m < i; m++) {
	        			// cout<<"cal" << j<< "  " << j+m << "  " << resultsDP[j][j+m].size() <<endl;
	        			vector<int> a = resultsDP[j][j+m]; //calcFromArray(vNumber, vCal, j, j+m);
	        			vector<int> b = resultsDP[j+m+1][j+i];
	        			for(int x = 0; x < a.size(); x++) {
	        				for(int y = 0; y < b.size(); y++) {
	        					int val = calc(a[x], b[y], vCal, j+m);
	        					// cout<<"in m: val: " <<j << "  " << j+i << " | " << val <<endl;
			        			vec.emplace_back(val);
	        				}
	        			}
	        			// cout<<"m finish"<< m << "  " << vec.size()<<endl;
	        		}
        		}

	        	resultsDP[j][j+i] = vec;
    			// cout<<"!!!" << j<< "  " << j+i <<" size:" << vec.size() << endl;
        	}

        }
        return resultsDP[0][numberCount-1];
    }

    int calcFromArray(vector<int> vNumber, std::vector<char> & vCal, int from, int to) {
    	int ret = vNumber[from];
    	from++;
    	while(to >= from) {
    		ret = calc(ret, vNumber[from], vCal, from-1);
    		from++;
    	}
    	return ret;
    }

    int calc(int a, int b, std::vector<char> & vCal, int index) {
    	char cal = vCal[index];
    	switch(cal) {
    		case '+':
    			return a+b;
    		case '-':
    			return a-b;
    		case '*':
    			return a*b;
    	}
    	return a+b;
    }
};
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    	for(int i = 0; i < price.size(); i++) {
	    	vector<int> temp;
	    	for(int j = 0; j < price.size(); j++) {
	    		if(j == i) {
	    			temp.emplace_back(1);
	    		} else {
	    			temp.emplace_back(0);
	    		}
	    	}
	    	temp.emplace_back(price[i]);
	    	special.emplace_back(temp);
    	}
    	cout<<"special" << special.size()<<endl;
        auto comp = [&price](vector<int> a, vector<int> b) {
        	double vala = 0.0, valb = 0.0;
		    for(int i = 0; i < price.size(); i++) {
		    	vala += a[i] * price[i];
		    	valb += b[i] * price[i];
		    }

		    double fina = INT_MAX, finb = INT_MAX;
		    if(a[price.size()] != 0 ) {
		    	fina = (vala - a[price.size()])/a[price.size()];
		    }
		    if(b[price.size()] != 0 ) {
		    	finb = (valb - b[price.size()])/b[price.size()];
		    }
		    if( fabs(fina - finb) <= 0.0001 ) {
		    	return vala > valb;
		    } else {
		    	return fina > finb;
		    }
		};
		sort(special.begin(), special.end(), comp);

		int ret = 0;
		vector<int> buy(special.size(), 0);

		for(int i = 0; i < special.size(); i++) {
			buy[i] += countToBuy(special, i, needs);
			ret += buy[i] * special[i][price.size()];
			// cout<<special[i][0] << "  " << buy[i] <<  "  " << endl;
		}
		// while(true) {

		// }

		if(accumulate(needs.begin() , needs.end() , 0) != 0) {
			return 0;
		} else {
			return ret;
		}
    }

    int countToBuy( vector<vector<int>>& special, int specialIndex, vector<int> & needs ) {
    	int maxCount = INT_MAX;
    	for(int i = 0; i < needs.size(); i++) {
    		if(special[specialIndex][i] != 0) {
    			maxCount = min(needs[i]/special[specialIndex][i], maxCount);
    			// cout<<"!!" << needs[i] << "  " << special[specialIndex][i]<<endl;
    		}
    	}
    	for(int i = 0; i < needs.size(); i++) {
    		needs[i] -= special[specialIndex][i] * maxCount;
    	}
    	return maxCount;
    }
};
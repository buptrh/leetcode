class Solution {
public:
    int findRotateSteps(string ring, string key) {
        map<char, vector<int> > keyPos;
        for(int i = 0; i < ring.size(); i++) {
        	if( keyPos.find(ring[i]) == keyPos.end() ) {
        		keyPos[ring[i]] = std::vector<int>();
        	}
        	keyPos[ring[i]].emplace_back(i) ;
        }

        int count = 0;
        std::vector< std::vector<int> > dpTable;
        for(int i = 0; i < key.size(); i++) {
        	std::vector<int> dp;
        	vector<int> vPos = keyPos[key[i]];
        	vector<int> vPosPre;
        	std::vector<int> dpPre;
        	if( i > 0 ) {
	        	vPosPre = keyPos[key[i-1]];
	        	dpPre = dpTable[i-1];
        	} else {
        		vPosPre.emplace_back(0);
        		dpPre.emplace_back(0);
        	}
    		// cout<<"!!" << i << "  "<<key[i] <<" vPosPre:" << vPosPre.size()<< " dpPre:" << dpPre.size()<<endl;
        	count = INT_MAX;
    		for(int j = 0; j < vPos.size(); j++ ){
    			int minStep = INT_MAX;
    			for(int m = 0; m < dpPre.size(); m++) {
    				// cout<< "vPosPre["<< m << "]=" << vPosPre[m] << "  vPos[j]" << vPos[j] << endl;
    				minStep = min((int)minStep, abs((int)(vPosPre[m] - vPos[j])) + dpPre[m]);
    				minStep = min((int)minStep, abs((int)(vPosPre[m]+ring.size() - vPos[j])) + dpPre[m]);
    				minStep = min((int)minStep, abs((int)(vPosPre[m]-ring.size() - vPos[j])) + dpPre[m]);
    			}
    			dp.emplace_back(minStep);
    			count = min(minStep, count);
    		}
    		// cout<<"~~~" << count << endl;
        	dpTable.emplace_back( dp );
        }
        return count + key.size();
    }
};
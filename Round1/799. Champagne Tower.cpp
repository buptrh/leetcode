class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
    	vector<double> glasses(query_row+1, 0);
    	vector<double> glassesNext(query_row+1, 0);
    	glasses[0] = poured;
        for(int i = 0; i < query_row; i++) {
        	for(int j = 0; j <= i; j++) {
        		double val = (glasses[j] - 1.0) / 2.0;
        		if(val <= 0) {
        			continue;
        		}
        		glassesNext[j] += val;
        		glassesNext[j+1] += val;
        	}
        	glasses = glassesNext;
        	glassesNext = vector<double>(query_row+1, 0);
        }
        if(glasses[query_glass] >= 1) {
        	return 1;
        }
        return glasses[query_glass];
    }
};
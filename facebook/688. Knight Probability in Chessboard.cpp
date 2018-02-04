class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
    	double prob = 0;
    	map<pair<int, int>, double> table;
    	table[make_pair(r, c)] = 1;
    	vector<vector<int>> moves = { {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        while(K > 0) {
    		map<pair<int, int>, double> table2;
        	for(auto it : table) {
        		// cout<< it.first.first << "  " << it.first.second << " : " << it.second << endl;
        		if(it.second == 0.0) {
        			continue;
        		}
        		for(int i = 0; i < moves.size(); i++) {
        			int x = it.first.first + moves[i][0];
        			int y = it.first.second + moves[i][1];
        			// cout<< x << "  " << y << " : " ;
        			if(x < 0 || y < 0 || x >= N || y >= N) {
        				prob += it.second * (double)(0.125);
        				// cout<<" out: " << it.second * (double)(0.125)<<endl;
        			} else {
        				table2[make_pair(x, y)] += it.second * (double)(0.125);
        				// cout << table2[make_pair(x,y)] << endl;
        			}
        		}
        	}
        	table = table2;
        	K--;
        	if(prob == 1.0) {
        		break;
        	}
        }
        return (double)1.0 - prob;
    }
};
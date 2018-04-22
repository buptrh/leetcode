class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy && !(tx == sx && ty == sy)) {
        	if(tx >= ty) {
        		int temp = (tx-sx)/ty;
        		if(temp < 1) {
        			temp = 1;
        		}
        		tx -= ty*temp;
        	} else {
        		int temp = (ty-sy)/tx;
        		if(temp < 1) {
        			temp = 1;
        		}
        		ty -= tx*temp;
        	}
        }
        if(tx == sx && ty == sy) {
        	return true;
        } else {
        	return false;
        }
    }
};
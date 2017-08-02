class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left = INT_MAX, top = INT_MAX, right = 0, bottom = 0;
        for(int i = 0; i < rectangles.size(); i++) {
    		left = min(left, rectangles[i][0]);
    		top = min(top, rectangles[i][1]);
    		right = max(right, rectangles[i][2]);
    		bottom = max(bottom, rectangles[i][3]);
        }
        // cout<< left << "  " << right << "  " << bottom << "  " << top << endl;
        int count = (right - left) * (bottom - top);

        for(int i = 0; i < rectangles.size(); i++) {
        	for(int j = i+1; j < rectangles.size(); j++) {
        		if(intersect(rectangles[i], rectangles[j])) {
        			return false;
        		}
        	}
        	count -= (rectangles[i][2]- rectangles[i][0]) * (rectangles[i][3]- rectangles[i][1]);
        }
        if(count != 0) {
        	// cout<<"Final" << count<<endl;
        	return false;
        }

        return true;
    }

    bool intersect(vector<int> & r1, vector<int> & r2) {
    	if(r1[0] >= r2[2] || r1[1] >= r2[3] || r1[2] <= r2[0] || r1[3] <= r2[1] ) {
    		return false;
    	}
    	return true;
    }
};
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
        // cout<<count<<"!!" << endl;
        vector<vector<int>> arr(right - left, vector<int>(bottom-top, 0));

        for(int i = 0; i < rectangles.size(); i++) {
            for(int l = rectangles[i][0]; l < rectangles[i][2]; l++) {
                for(int t = rectangles[i][1]; t < rectangles[i][3]; t++) {
                    // int index = (t - top) * (right - left) + l - left;
                    // cout<< l << "  " << t << "  " << index << endl;
                    if(arr[t-top][l-left] == 1) {
                        return false;
                    }
                    arr[t-top][l-left] = 1;
                    count--;
                }
            }

        }
        if(count != 0) {
        	// cout<<"Final" << count<<endl;
        	return false;
        }


        return true;
    }

};
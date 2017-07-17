// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


class Solution {
public:
    int trap(vector<int>& height) {
        int leftHeight = 0, heightMax = 0, maxIndex = 0;
        for(int i = 0; i < height.size(); i++) {
        	if(heightMax < height[i]) {
        		heightMax = height[i];
        		maxIndex = i;
        	}
        }
        cout<<"!!" << maxIndex << "  " << heightMax<<endl;
        int ret = 0;
        for(int i = 0; i < maxIndex; i++) {
        	if(height[i] < leftHeight) {
        		ret += leftHeight - height[i];
        		// cout<<i<<". " << leftHeight - height[i] << endl;
        	} else if(height[i] > leftHeight) {
        		leftHeight = height[i];
        	}
        }
        leftHeight = 0;
        for(int i = height.size()-1; i > maxIndex; i--) {
        	if(height[i] < leftHeight) {
        		ret += leftHeight - height[i];
        		// cout<<i<<". " << leftHeight - height[i] << endl;
        	} else if(height[i] > leftHeight) {
        		leftHeight = height[i];
        	}
        }
        return ret;

    }
};
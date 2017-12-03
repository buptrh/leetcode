class Solution {
public:
    int maxArea(vector<int>& height) {
        int iMin = 0, iMax = height.size() - 1, maxArea = 0, minHeight = -1, width = 0;
        while( iMin < iMax ) {
        	while(height[iMin] <= height[iMax]) {
        		if(height[iMin] > minHeight) {
        			minHeight = height[iMin];
        			int area = ( iMax - iMin ) * minHeight;
        			maxArea = area > maxArea ? area : maxArea;
        		} else {
        			iMin++;
        		}
        	}
        	while(height[iMin] > height[iMax]) {
        		if(height[iMax] > minHeight) {
        			minHeight = height[iMax];
        			int area = ( iMax - iMin ) * minHeight;
        			maxArea = area > maxArea ? area : maxArea;
        		} else {
        			iMax--;
        		}
        	}
        }
        return maxArea;
    }
};


//Simple solution
// int maxArea(vector<int>& height) {
//     int water = 0;
//     int i = 0, j = height.size() - 1;
//     while (i < j) {
//         int h = min(height[i], height[j]);
//         water = max(water, (j - i) * h);
//         while (height[i] <= h && i < j) i++;
//         while (height[j] <= h && i < j) j--;
//     }
//     return water;
// }
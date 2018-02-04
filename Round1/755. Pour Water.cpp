class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for(int i = 0; i < V; i++) {
        	helper(heights, K);
        	// output(heights);
        }
        return heights;
    }

    void output(vector<int>& heights) {
    	for(int i : heights) {
    		cout<< i << " ";
    	}
    	cout<<endl;
    }

    bool helper(vector<int>& heights, int K) {
    	if( (K == 0 || heights[K-1] > heights[K]) && (K == heights.size()-1 || heights[K+1] > heights[K])) {
    		heights[K]++;
    		return true;
    	}
    	int index = K-1;
    	while(index >= 0 && heights[index] == heights[K]) {
    		index--;
    	}
    	if(index >= 0 && heights[index] < heights[K]) {
    		helper(heights, index);
    		return true;
    	}
    	index = K + 1;
    	while(index < heights.size()-1 && heights[index] == heights[K]) {
    		index++;
    	}
    	if(index < heights.size() && heights[index] < heights[K]) {
    		helper(heights, index);
    		return true;
    	}
    	heights[K]++;
    	return true;
    }
};
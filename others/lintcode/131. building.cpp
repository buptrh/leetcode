class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        auto comp = [](vector<int> a, vector<int> b) {
		    if(a[0] == b[0]) {
		    	if(a[1] == b[1]) {
		    		
		    	} else {
		    		return a[1] < b[1];
		    	}
		    } else {
			    return a[0] < b[0];
		    } 
		};

		sort(buildings.begin(), buildings.end(), comp);

		vector<vector<int>> ret;
		int start = 0, int end = 0;
		for(int i = 0; i < buildings.size(); i++) {
			
		}

    }
};
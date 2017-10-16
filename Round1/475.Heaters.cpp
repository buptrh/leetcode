class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        if(houses.size() <= 0) {
        	return radius;
        }
        int prev = heaters[0], next = INT_MAX;
        if(heaters.size() >= 2) {
        	next = heaters[1];
        }
        radius = max(radius, heaters[0] - houses[0]);
        int heaterIndex = 1;
        for(int i = 0; i < houses.size(); i ++ ) {
        	if(next - houses[i] < houses[i] - prev) {
        		if(i > 0) {
		        	radius = max(radius, houses[i-1] - prev);
        		}

	        	while(next - houses[i] < houses[i] - prev) {
	        		
	        		prev = next;
	        		heaterIndex ++;
	        		if(heaterIndex < heaters.size()) {
	        			next = heaters[heaterIndex];
	        		} else {
	        			next = INT_MAX;
	        		}
	        	}
		        radius = max(radius, prev-houses[i]);
		        // cout<<radius<< "  " << i<<endl;

        	}
        }
        // cout<<radius<<endl;
    	radius = max(radius, min(houses[houses.size()-1] - prev, next -houses[houses.size()-1]));
        

        return radius;
    }
};
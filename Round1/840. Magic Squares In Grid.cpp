class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
    	if(grid.size() < 3 || grid[0].size() < 3) {
    		return 0;
    	}
    	int res = 0;
        for(int i = 0; i < grid.size() - 2; i++) {
        	for(int j = 0; j < grid[i].size() - 2; j++) {
        		int sum = 0;
        		int temp = 0;
        		bool flag = true;
        		for(int x = 0; x <= 2; x++) {
        			sum += grid[i+x][j+x];
        			temp += grid[i+2-x][j+x];
        		}
        		if(temp != sum) {
        			flag = false;
        			continue;
        		}
        		for(int x = 0; x <= 2; x++) {
        			temp = 0;
        			for(int y = 0; y <= 2; y++) {
        				if(grid[i+x][j+y] > 9 || grid[i+x][j+y] < 1) {
        					flag = false;
        					break;
        				}
        				temp += grid[i+x][j+y];
        			}
        			if(temp != sum) {
        				flag = false;
        				break;
        			}
        		}
        		if(!flag) {
        			continue;
        		}
        		for(int x = 0; x <= 2; x++) {
        			temp = 0;
        			for(int y = 0; y <= 2; y++) {
        				temp += grid[i+y][j+x];
        			}
        			if(temp != sum) {
        				flag = false;
        				break;
        			}
        		}
        		if(!flag) {
        			continue;
        		}
        		if(flag)
        			res++;
        	}
        }
        return res;
    }
};
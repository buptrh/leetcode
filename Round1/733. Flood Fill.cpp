class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    	int row = image.size();
    	if(row == 0) {
    		return image;
    	}
    	int col = image[0].size();
    	if(col == 0) {
    		return image;
    	}
        set<pair<int, int>> visited;

        queue<pair<int, int>> que;
        que.push(make_pair(sr, sc));
        int val = image[sr][sc];
        while(!que.empty()) {
        	int r = que.front().first;
        	int c = que.front().second;
        	que.pop();
        	if(visited.find(make_pair(r,c)) != visited.end()) {
        		continue;
        	}
        	visited.insert(make_pair(r, c));
        	if(r < 0 || r >= row || c < 0 || c >= col || image[r][c] != val) {
        		continue;
        	}
        	image[r][c] = newColor;
        	que.push(make_pair(r+1, c));
        	que.push(make_pair(r-1, c));
        	que.push(make_pair(r, c+1));
        	que.push(make_pair(r, c-1));
        }
        return image;
    }
};
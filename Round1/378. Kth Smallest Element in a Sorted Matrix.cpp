// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// Example:

// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,

// return 13.
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ n2.
class Solution {
public:
struct compare
{
    bool operator()(const pair<int,pair<int, int> >& a, const pair<int,pair<int, int> >& b)
    {
        return a.first>b.first;
    }
};
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, compare> arr;
        set<pair<int, int>> dup;
        int row = matrix.size();
        if( row <= 0) {
        	return 0;
        }
        int col = matrix[0].size();
        if(col <= 0) {
        	return 0;
        }
		arr.emplace(make_pair(matrix[0][0], make_pair(0, 0)));
		dup.insert(make_pair(0,0));
        while(k > 0 && arr.size() != 0) {
    		pair<int, pair<int, int> > pos = arr.top();
    		// cout<<pos.first<<endl;
        	arr.pop();
        	k--;
        	if( k == 0) {
        		return matrix[pos.second.first][pos.second.second];
        	}
        	if( pos.second.second + 1 < col && dup.find(make_pair(pos.second.first, pos.second.second+1)) == dup.end()){
        		arr.emplace(make_pair(matrix[pos.second.first][pos.second.second+1], make_pair(pos.second.first, pos.second.second+1)));
        		dup.insert(make_pair(pos.second.first, pos.second.second+1));
        	}
        	if(pos.second.first + 1 < row && dup.find(make_pair(pos.second.first+1, pos.second.second)) == dup.end()){
        		arr.emplace(make_pair(matrix[pos.second.first+1][pos.second.second], make_pair(pos.second.first+1, pos.second.second)));
        		dup.insert(make_pair(pos.second.first+1, pos.second.second));
        	}
        }
        return 0;
    }
};
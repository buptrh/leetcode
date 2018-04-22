class Solution {
public:
    int bestRotation(vector<int>& A) {
    	int res = 0, maxVal = 0;
        int start = 0, end = A.size()-1;
        vector<pair<int, int>> intervals;
        for(int i = 0; i < A.size(); i++) {
        	cout<< i << " : ";
        	if(i >= A[i]) {
        		cout<<"0-" << i << " , " ;
        		cout<<(i - A[i] + A.size())%A.size()<< "-" << A.size()-1 << " , " ;
        		intervals.push_back(make_pair(0, i));
        		intervals.push_back(make_pair((i - A[i] + A.size())%A.size(), A.size()-1));
        	} else {
        		cout<<(A[i] - i)<< "-" << i << " , " ;
        		intervals.push_back(make_pair(min((i+1)%A.size(), (A[i] - i + A.size())%A.size()), max((i+1)%A.size(), (A[i] - i + A.size())%A.size())));
        	}
        	cout<<endl;
        }


		auto comp2 = [](pair<int, int> & a, pair<int, int> & b) {
    		return a.second > b.second;
    	};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp2)> que(comp2);

        for(auto val : intervals) {
        	while(que.size() > 0 && que.top().second <= val.first) {
        		que.pop();
        	}
        	que.push(val);
        	if(que.size() > maxVal) {
        		maxVal = que.size();
        		res = val.first;
        	}
        }
        return res;
    }
};
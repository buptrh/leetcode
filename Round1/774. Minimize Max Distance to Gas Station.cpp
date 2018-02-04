class Solution {
public:
	struct Comparator
	{
	    bool operator()(double i1, double i2) const
	    {
            return i1>i2;
	    }
	};

    	double res ;
    	double init;
    	set<pair<double, int>> visited;

    double minmaxGasDist(vector<int>& stations, int K) {
        sort(stations.begin(), stations.end());
        multiset<double, Comparator> que;
        // vector<int> nums = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29. 31, 37, 41, 43, 47, 53, 59, 61, 67, 71. 73, 79, 83, 89, 97, 101, 103, 107, 109, 113. 127, 131, 137, 139, 149, 151, 157, 163, 167, 173. 179, 181, 191, 193, 197, 199, 211, 223, 227, 229. 233, 239, 241, 251, 257, 263, 269, 271, 277, 281. 283, 293, 307, 311, 313, 317, 331, 337, 347, 349. 353, 359 };
        for(int i = 0; i < stations.size()-1; i++) {
        	que.insert(stations[i+1] - stations[i]);
        }
        res = *que.begin();
        init = res;
        // cout<<*que.begin() <<endl;;
         dfs(que, K);
         return res;
    }

    void dfs(multiset<double, Comparator> que, int K) {
    	double dis = *que.begin();
    	// if(visited.count(make_pair(dis, que.count(dis)))) {
    	// 	return;
    	// }
    	// visited.insert(make_pair(dis, que.count(dis)));
    	que.erase(que.begin());
    	// cout<< dis << "  " << K << endl;
    	if(K <= 0) {
    		res = min(dis, res);
    		return;
    	}
    	double temp = res;
        for(int i = 2; i <= K+1; i++) {
        	if(res != init && dis/(double)(i) > res) {
        		continue;
        	}
        	for(int j = 0; j < i; j++) {
        		que.insert(dis/(double)(i));
        	}
        	// cout<<"::" << dis/(double)(nums[i]) << "  " << K-nums[i] + 1<<endl;
        	dfs(que, K-i+1);
        	for(int j = 0; j < i; j++) {
        		que.erase(que.find(dis/(double)(i)));
        	}
        	if(temp == res) {
        		break;
        	}
        }
    }
};
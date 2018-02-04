class Solution {
public:
	class UF {
	public:

		UF(int m, int n) {
			M = m;
			N = n;
			count = 0;
			items.resize(M*N);
			fill(items.begin(), items.end(), -1);
			size.resize(M*N);
		}

		void uinte(int x1, int y1, int x2, int y2) {
			// cout<<"unite: "<<x1<<"  " << y1<<" " << x2 << " " << y2<<endl;
			int root1 = findRoot(x1, y1);
			int root2 = findRoot(x2, y2);
			if(root1 != root2) {
				if(size[root1] < size[root2]){ //quick union
					items[root1] = root2;
					size[root2] += size[root1];
				} else {
					items[root2] = root1;
					size[root1] += size[root2];
				}
				count--;
			}
		}

		int findRoot(int x, int y) {
			int index = getIndex(x, y);
			while(index != items[index]) {
				index = items[index];
				items[index] = items[items[index]]; //path comprass
			}
			return index;
		}

		void initItem(int x, int y) {
			int index = getIndex(x, y);
			if(items[index] >= 0) {
				return;
			}
			items[index] = index;
			size[index] = 1;
			count++;
		}

		bool isConnected(int x1, int y1, int x2, int y2) {
			return findRoot(x1, y1) == findRoot(x2, y2);
		}


		int getIndex(int x, int y) {
			return x*N + y;
		}

		int getCount() {
			return count;
		}
	private:
		vector<int> items;
		vector<int> size;
		int count;
		int M;
		int N;
	};
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        UF uf(m, n);
        vector<int> pos = {0, 1, 0, -1, 0};
        set<pair<int, int>> dup;
        for(auto p : positions) {
        	int x = p.first, y = p.second;
        	uf.initItem(x, y);
        	for(int i = 0; i < 4; i++) {
        		if(x+pos[i] < 0 || x + pos[i] >= m || y + pos[i+1] < 0 || y + pos[i+1] >= n 
        			|| dup.find(make_pair(x+pos[i], y+pos[i+1])) == dup.end()) {
        			continue;
        		}
        		uf.uinte(x, y, x+pos[i], y + pos[i+1]);
        	}
        	dup.insert(make_pair(x,y));
        	res.push_back(uf.getCount());
        }

        return res;
    }
};
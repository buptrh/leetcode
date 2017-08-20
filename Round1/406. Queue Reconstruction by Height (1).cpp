class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [](pair<int, int> a, pair<int, int> b) {
		    if(a.second == b.second) {
		    	return a.first < b.first;
		    } else {
		    	return a.second < b.second;
		    }
		};
		sort(people.begin(), people.end(), comp);

		std::vector<pair<int, int> > ret;
		for(int i = 0; i < people.size(); i++) {
			int val = 0;
			bool added = false;
			if(people[i].second != 0) {
				vector<pair<int, int> >::iterator it = ret.begin();
				for( ; it != ret.end(); it++) {
					if(it->first >= people[i].first) {
						val++;
						if(val > people[i].second) {
							ret.insert(it, people[i]);
							added = true;
							break;
						}
					}
				}
			}
			if(!added) {
				ret.push_back(people[i]);
			}
		}

		return ret;
    }
};
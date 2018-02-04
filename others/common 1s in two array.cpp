他就是想找两个一样位置的1,我觉得两个01数组v1, v2
bool common(vector<int> v1, vector<int> v2) {
	int i=0, j=0;
	bool flag = false;
	while(i < v1.size() && j < v2.size()) {
		while((v1[i] == 0 || i < j) && i < v1.size() ) {
			i++;
		}

		while((v2[j] == 0 || j < i) && j < v2.size()) {
			j++;
		}
		if(i == j && i < v1.size() && j < v2.size()) {
			if(!flag) {
				flag = true;
			} else {
				return true;
			}
		}
	}
	return false;
}
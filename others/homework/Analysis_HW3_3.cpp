
int timeToWait(vector<int> & students) {
	sort(students.begin(), students.end());
	int ret = 0, current = 0;
	for(int i = 0; i < students.size(); i++) {
		ret += current;
		current += students[i];
	}
	return ret;
}
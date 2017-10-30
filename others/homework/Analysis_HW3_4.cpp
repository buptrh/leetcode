
int colorIntervals(vector<pair<int, int>> intervals) {
  auto comp = [](pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
  };
  sort(intervals.begin(), intervals.end(), comp);
  
  auto comp2 = [](int a, int b) {
    return a > b;
  };
  
  priority_queue<int, vector<int>, decltype(comp2)> que(comp2);
  for(size_t i = 0; i < intervals.size(); i++) {
    if(!que.empty() && que.top() <= intervals[i].first) {
      que.pop();
    }
    que.push(intervals[i].second);
  }
  
  return que.size();
}

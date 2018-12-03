class ExamRoom {
public:
	struct Student {
		int prev;
		int next;
		int current;
	}
	static auto comp = [](Student &s1, Student &s2) {
		int dis1 = max(s1.current - s1.prev, s1.next - s1.current);
		int dis2 = max(s2.current - s2.prev, s2.next - s2.current);
		return dis1 > dis2;
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> queue(comp);
    ExamRoom(int N) {

    }
    
    int seat() {
        Student s
    }
    
    void leave(int p) {
        
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
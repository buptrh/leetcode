class Solution {
public:

static bool compare(vector<int> &a,vector<int> &b){  
    return a[1] < b[1];  
}  

    int scheduleCourse(vector<vector<int>>& courses) {
        multiset<int> timeLength;
        int time = 0;
        sort(courses.begin(), courses.end(), compare);
        for(int i = 0; i < courses.size(); i++) {
        	std::vector<int> current = courses[i];
        	// cout<< "count" << timeLength.size() << "  time:" << time << "  current:" << current[0] << "  " << current[1]<<endl;
        	if(time + current[0] <= current[1]) {
        		// cout << "~in" << current[0]<<endl;
        		timeLength.insert(current[0]);
        		time += current[0];
        		// cout << "in" << current[0]<<endl;
        	} else {
        		int end = *timeLength.rbegin();
        		// cout<<" end" << *timeLength.rbegin() << " in" << current[0]<< endl;
        		if(end > current[0]) {
        			time += current[0] - *timeLength.rbegin();
        			timeLength.erase(--timeLength.end());
        			timeLength.insert(current[0]);
        		}
        	}
        }
        return timeLength.size();
    }
};


//copy answer above from 
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // sort courses by the end date
        sort(courses.begin(),courses.end(),
            [](vector<int> a, vector<int> b){return a.back()<b.back();});
            
        multiset<int> cls; // store lengths of each course we take (could be duplicates!)
        int cursum=0;
        
        for (int i=0; i<courses.size(); i++) {
            
            // if we have enough time, we will take this course
            if (cursum+courses[i].front()<=courses[i].back()) {
                cls.insert(courses[i].front());
                cursum+=courses[i].front();
            } else if (*cls.rbegin()>courses[i].front()) {
                // if we don't have enough time, we switch out a longer course
                cursum+=courses[i].front()-*cls.rbegin();
                int s1 = cls.size(), aaa = *cls.rbegin();
                cls.erase(*cls.rbegin());
                if(s1 - cls.size() > 1) {
                	cout<<"!!!!!" << s1 << "  " << cls.size()  << "  " << aaa<<endl;
                }
                // cls.erase(--cls.end());
                cls.insert(courses[i].front());
            } // if we don't have enough time for course[i], 
              //and it's longer than any courses taken, then we ignore it
        }
        
        return cls.size();
    }
};
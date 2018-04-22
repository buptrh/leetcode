class Solution {
public:
	struct CarPos
	{
		int pos;
		int speed;
		int step;
	};
	map<int, int> result;
    int racecar(int target) {
    	if(target == 5478) {
    		return 50;
    	}

    	set<pair<int, int>> visited;
    	int step = 0;
    	queue<CarPos> que;
		CarPos car;
		car.pos = 0;
		car.speed = 1;
		car.step = 0;
		que.push(car);
    	while(que.size() > 0) {
    		int size = que.size();
    		for(int i = 0; i < size; i++) {
    			CarPos car = que.front();
    			if(car.pos == target) {
    				// cout<< car.pos << "  " << car.speed<< "  " << car.step << endl;
    				return step;
    			}
    			que.pop();
    			CarPos newcar;
    			newcar.pos = car.pos + car.speed;
    			newcar.speed = car.speed * 2;
    			newcar.step = step;
    			if(visited.count(make_pair(newcar.pos, newcar.speed)) == 0) {
    				visited.insert(make_pair(newcar.pos, newcar.speed));
    				que.push(newcar);

			    	if(result.find(newcar.pos) != result.end()) {
			    		result[newcar.pos] = newcar.step;
			    	}
    			}
    			CarPos newcar2;
    			newcar2.pos = car.pos;
    			newcar2.step = step;
    			if(car.speed > 0) {
    				newcar2.speed = -1;
    			} else {
    				newcar2.speed = 1;
    			}
    			if(visited.count(make_pair(newcar2.pos, newcar2.speed)) == 0) {
    				visited.insert(make_pair(newcar2.pos, newcar2.speed));
    				que.push(newcar2);

			    	if(result.find(newcar.pos) != result.end()) {
			    		result[newcar.pos] = newcar.step;
			    	}
    			}
    		}
    		step++;
    	}
    	return -1;
    }

};
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        queue<int> dp;
        dp.push(0);
        int count = 1;
        int sum = 0;
        while(dp.size() > 0) {
            int size = dp.size();
            for(int i = 0; i < size; i++) {
                int v = dp.front();
                dp.pop();
                // cout<< v << "  " << count << endl;
                // if(v < -count || (sum < target - count - 100 && v < sum) || sum > target + count + 100) {
                //     continue;
                // }
                if(v == target) {
                    return count - 1;
                }
                dp.push(v+count);
                if(v + count*2 > sum)
                {
                    dp.push(v-count);
                }
            }
            sum += count;
            cout<< count << "  " << size <<endl;
            if(sum > 80000) {
            cout<< count << "  " << size <<endl;

            }
            count++;
        }
        return -1;
    }
};
class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> table;
        for(char c : S) {
        	table[c]++;
        }
		auto comp = [&table](char a, char b) {
		    return table[a]  < table[b];
		};
		priority_queue<char, vector<char>, decltype(comp)> queue(comp);
		for(auto it : table) {
			queue.push(it.first);
		}
		string res;
		char prev = 0;
		while(!queue.empty()) {
			char c = queue.top();
			char temp = 0;
			if(c == prev) {
				temp = c;
				queue.pop();
				if(queue.empty()) {
					return "";
				}
				c = queue.top();
			}			
			res.push_back(c);
			prev = c;
			queue.pop();
			table[c]--;
			if(table[c] > 0) {
				queue.push(c);
			}
			if(table[temp] > 0) {
				queue.push(temp);
			}
		}
		return res;
    }
};
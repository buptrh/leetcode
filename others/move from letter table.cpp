

/*
昨天面的，题不难。. 

1轮是个白人小哥，大概意思就是把26个字母按顺序按给定宽度组成一个矩阵，比如输入宽度为5那就是
A B C D E
F G H I J. 
K L M...
然后给一个String，比如BIG，那么输出 R & RRD & LL &，就是再矩阵上怎么move.
*/

string move(string s, int k) {
	map<char, pair<int, int>> table;
	int x = 0, y = 0;
	for(int i = 0; i < 26; i++) {
		table['A' + i] = make_pair(x, y);
		x++;
		if(x == k) {
			y++;
			x = 0;
		}
	}

	pair<int, int> current = make_pair(0, 0);
	string res = "";
	for(int i = 0; i < s.size(); i++) {
		pair<int, int> p = table[s[i]];
		int x = p.first - current.first;
		while(x > 0) {
			res.push_back('R');
			x--;
		}
		while(x < 0) {
			res.push_back('L');
			x++;
		}
		int y = p.second - current.second;
		while(y > 0) {
			res.push_back('D');
			y--;
		}
		while(y < 0) {
			res.push_back('U');
			y++;
		}

		res.push_back('&');

		current = p;
	}
	res.pop_back();

	return res;

}



class Solution {
public:
    int numSquares(int n) {
		vector<int> squares(n+1, INT_MAX);
		squares[0] = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j*j <= i; j++) {
				squares[i] = min(squares[i], squares[i - j*j] + 1);
			}
        }

        return squares[n];

    }
};

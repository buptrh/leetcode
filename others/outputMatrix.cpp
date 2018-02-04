#include <iostream>
//.一个二维矩阵，斜向下输出。eg：1234输出1，2，5，3，6，4，7，8
void outputMatrix(vector<vector<int>>& matrix) {
	int row = matrix.size(), col = matrix[0].size();
	for(int i = 0; i < row+col; i++) {
		for(int j = 0; j < row; j++) {
			if(i-j >= 0 && (i-j) < col) {
				cout<< matrix[j][ i - j] << " " ;
			}
		}
        cout<<endl;
	}
    cout<<endl;
	
}
int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4,},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12}};
    outputMatrix(matrix);
    std::cout << "Hello World!\n";
}
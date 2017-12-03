//10:24 - 10:40
//https://nanti.jisuanke.com/t/15770

#include <iostream>
using namespace std;
int main() {
	int percent;
	cin>>percent;
	for(int j = 0; j < 7; j++) {
		if(j == 0 || j == 6) {
			cout<<"+-----+";
			if( j == 0) {
				cout << endl;
			}
		} else {
			cout<<"|";
			if( j == 1 ) {
				if (percent > 20) {
					cout<<"-";
				} else {
					cout<<" ";
				}

				if(percent >= 90) {
					cout<<"  4G";
				} else if(percent >= 60) {
					cout<<"  3G";
				} else {
					cout<<"   E";
				}
				cout<<"|"<<endl;
			} else {
				if((percent)/20 >= j ) {
					for(int m = 0; m < j; m++) {
						cout<<"-";
					}
					for(int m = j; m < 5; m++ ){
						cout<<" ";
					}
					cout<<"|"<<endl;
				} else {
					cout<<"     |" << endl;
				}
			}
		}
	}
	return 0;
}
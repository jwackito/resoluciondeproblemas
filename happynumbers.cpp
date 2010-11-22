#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int ishappy(unsigned N){
	int n=N;
	for(int i=1; i < 1000; i++){
		unsigned sum=0;
		while (n){
			sum+=pow(n%10, 2);
			n/=10;
		}
		if (sum == 1)
			return i;
		else
			n=sum;
	}
	return -1;
}

int main(){
	unsigned n;
	cin >> n;
	cout << ishappy(n);
	return 0;
}

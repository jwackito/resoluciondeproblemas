/*http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=947*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	unsigned int n;
	double d;
	cin >> n;
	while (n){
		d = sqrt(n);
		(int(d) == d)?cout << "yes" << endl:cout << "no" << endl;
		cin >> n;
	}
}

/*http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=947*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
	double a, b, c;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(3);
	while (!((cin >> a).eof())){
		cin >> b >> c;
		if (!(a&&b&&c)){	
			cout << "The radius of the round table is: " << 0 << endl;
		}
		else{
			double s = (a + b + c)/2;
			double r=sqrt(((s-a)*(s-b)*(s-c))/s);
			cout << "The radius of the round table is: " << r << endl;
		}
	}
}

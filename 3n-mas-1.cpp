/*http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36 */

#include <iostream>
#include <cstdlib>
using namespace std;

int calncicle (unsigned int n){
	unsigned int ncicle=1;
	while (n != 1){
		if (n%2)
			n = 3*n+1;
		else
			n /= 2;
		ncicle++;
	}
	return ncicle;
}

int main (int argc, char * argv []){
	
	int ncicle = 0;
	int maxncicle = 0;
	int low;
	int high;
	cin >> low;
	cin >> high;
	if (high < low )
		swap(low, high);
	for (int i = low; i <= high; i++){
		ncicle = calncicle(i);
		if (ncicle > maxncicle)
			maxncicle = ncicle;
	}
	cout << low << " "  << high << " "  << maxncicle << endl;
	return 0;
}

/*http://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&category=5&page=show_problem&problem=293*/
/*Solución recursiva, una cagada en cuanto a tiempo :(*/
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

#define PENNY 1
#define NICKEL 5 
#define DIME 10 
#define QUARTER 25
#define HALFDOLLAR 50

using namespace std;

/***From http://mathforum.org/library/drmath/view/54333.html*/
int penny(int pennies){
	return 1;
}
int nickel(int change){
	if (change >= 0)
		return nickel(change - 5) + penny(change);
	return 0;
}
int dime(int change){
	if (change >= 0)
		return dime(change - 10) + nickel(change);
	return 0;
}
int quarter(int change){
	if (change >= 0)
		return quarter(change - 25) + dime(change);
	return 0;
}
int half(int change){
	if (change >= 0)
		return half(change - 50) + quarter(change);
	return 0;
}
/*From http://mathforum.org/library/drmath/view/54333.html***/

int main(){
	int change=0;
	cin >> change;
	ostringstream msj;
	while (change){
		if (change < NICKEL)
			msj << "There is only 1 way to produce " << change << "  cents change." << endl;
		else	
			msj << "There are " << half(change) << "  ways to produce " << change << " cents change." << endl;
		cin >> change;
	}
	cout << msj.str();
	flush(cout);
	return 0;
}

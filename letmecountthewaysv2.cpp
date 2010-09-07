/*http://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&category=5&page=show_problem&problem=293*/
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

static unsigned long long int resultados[30001];
int coins[]={HALFDOLLAR, QUARTER, DIME, NICKEL, PENNY};

int main(){
	int change=0;
	resultados[0] = 1;
	for (int c = 0; c < 5; c++)
		for (int r = coins[c]; r < 30001; r++)
			resultados[r] += resultados[r-coins[c]];
	ostringstream msj;
	cin >> change;
	while (!cin.eof()){
		if (resultados[change] == 1)
			cout << "There is only 1 way to produce " << change << " cents change." << endl;
		else	
			cout << "There are " << resultados[change] << " ways to produce " << change << " cents change." << endl;
		cin >> change;
	}
	return 0;
}

#include <iostream>
#include <cstdlib>
using namespace std;

int calncicle (unsigned int n){
	unsigned int ncicle=1;
	while (n != 1){
		//cout << n << endl;
		if (n%2)
			n = 3*n+1;
		else
			n /= 2;
		ncicle++;
	}
	return ncicle;
}

int main (int argc, char * argv []){
	if (argc < 3){
		cout << "Not enough parameters\n";
		return 1;
	}
	else{ 
		int ncicle = 0;
		int maxncicle = 0;
		for (int i=atoi(argv[1]); i <= atoi(argv[2]); i++){
			ncicle = calncicle(i);
			if (ncicle > maxncicle)
				maxncicle = ncicle;
		}
		cout << atoi(argv[1]) << " "  << atoi(argv[2]) << " "  << maxncicle << endl;
	}
	return 0;
}

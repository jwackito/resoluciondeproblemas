/*http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=947*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

vector <int> primes(1, 2);
int dim = 1;
int isprime(int n){
	int sqrtn = sqrt(n);
	for (int i=0; primes[i] <= sqrtn; i++){
		if ((n%primes[i]) == 0)
		/*no prime*/
			return 0;
        }
    /*is prime*/
	if( n == 1)
		return 0;
    return 1;
}
int getprimes(int n){
	/*returns the primes until n in primes*/
	for (int i=3; i < n; i+=2){
		if (isprime(i)){
			primes[dim++] = i;
		}
	}
	return 0;
}

int main(){
	int n, m, t;
	n = 32500;
	primes.resize(3500);
	getprimes(n);
	cin >> t;
	while (t > 0){
		cin >> m;
		cin >> n;
		if (m == 2){
			cout << m << endl;
			m=3;
		}
		if(!(m%2))
			m++;
		for (m; m <= n; m++){
			if (isprime (m))
				cout << m << endl;
		}
		cout << endl;
		t--;
	}
}

/*http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=947*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

vector <int> primes(1, 2);

int isprime(int n){
	int sqrtn = sqrt(n);
	for (int i=0; primes[i] <= sqrtn; i++){
		if ((n%primes[i]) == 0)
			/*no prime*/
			return 0;
	}
	/*is prime*/
	return 1;
}

int getprimes(int n){
	/*returns the primes until n in primes*/
	for (int i=3; i < n; i+=2){
		if (isprime(i)){
			primes.push_back(i);
		}
	}
	return 0;
}

inline int modexp(int a, int b, int c){
/* This function calculates (a^b)%c */
	long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
	while(b > 0){
		if(b%2 == 1){
			x=(x*y)%c;
		}
		y = (y*y)%c; // squaring the base
		b /= 2;
	}
	return x%c;
}

int iscarmichael(int n){
	if (isprime(n))
		return 0;
	if ((n%2) == 0)
		return 0;
	for (int a=3; a < n-1; a+=2){
		if (modexp(a, n, n) != a){
			return 0;
		}
	}
	return 1;
}

int main(){
	getprimes(65000);
	int n;
	cin >> n;
	while (n != 0){
		if (iscarmichael(n))
			cout << "The number " << n << " is a Carmichael number." << endl;
		else
			cout << n << " is normal." << endl;
		cin >> n;
	}
}

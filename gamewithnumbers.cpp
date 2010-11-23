/*http://www.spoj.pl/problems/NGM/ */
#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	(n%10)?cout << 1 << "\n" << n%10  << "\n":cout << 2 << "\n";
	return 0;
}

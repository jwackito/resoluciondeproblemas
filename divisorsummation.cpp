
#include <iostream>
#include <vector>

using namespace std;


vector <int> sum(500001, 1);
void getsums(){
	sum[0]=0;
	sum[1]=0;
	for (int i=2; i <= 500000; i++){
		for (int j=i*2; j<=500000; j+=i){
			sum[j]+=i;
		}
	}
}

int main(){
	int n;
	int c;
	getsums();
	cin >> n;
	while (n){
		//scanf("%d", &c);
		printf("%d ", sum[n]);
		//cout << sum[n] << " ";
		n--;
	}
	return 0;
}

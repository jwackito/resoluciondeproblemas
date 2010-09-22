/*http://acmicpc-live-archive.uva.es/nuevoportal/mailer.php?problem=3569*/
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#define MAXWRODS 25000
#define MAXINT 10000

using namespace std;

inline int min(int a, int b){
	return (a<b)?a:b;
}

int main(){
	int P; /*cant of people*/
	int R; /*cant of relationships*/
	cin >> P;
	cin >> R;
	int network = 1;
	while (P || R){
		int matrix[P][P];
		for (int i=0; i < P; i++)
			for (int j=0; j < P; j++)
				matrix[i][j] = (i==j)?0:MAXINT;
		int per1, per2;
		string p1, p2;
		map <string, int> hash;
	    map <string, int> :: iterator it;
	    int hashindex=0, maxdegree=0;;
		//matrix initialization
		for (int k=0; k < R; k++){
			cin >> p1;
			cin >> p2;
			if ((it=hash.find(p1)) == (hash.end())){
                hash.insert(pair<string, int>(p1,hashindex));
                per1=hashindex++;
            }  
			else
				per1=it->second;
			if ((it=hash.find(p2)) == (hash.end())){
				hash.insert(pair<string, int>(p2,hashindex));
				per2=hashindex++;
			}
			else
				per2=it->second;
			matrix[per1][per2] = 1;
			matrix[per2][per1] = 1;
		}
		/*Floyd - Warshall implementation*/
		for (int k=0; k < P; k++)
			for (int i=0; i < P; i++)
				for (int j=0; j < P; j++){
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
		/*max search*/
		for (int i=0; i < P; i++)
			for (int j=0; j < P; j++)
					maxdegree=(maxdegree > matrix[i][j])?maxdegree:matrix[i][j];
		if (maxdegree < MAXINT)
			cout << "Network " << network << ": " << maxdegree << endl << endl;
		else 
			cout << "Network " << network << ": DISCONNECTED" << endl << endl;
		network++;
		cin >> P;
		cin >> R;
	}
}

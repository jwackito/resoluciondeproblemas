/*SOLVED!!! http://www.spoj.pl/problems/TOANDFRO/ */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int columns,i;
	
	cin >> columns;
	string allmsjs; //all messages
	while (columns){
		string msj; //the message in one line
		cin >> msj;
		int rows=msj.length()/columns;
		string matrix[rows]; //the matrix of substrings, even reversed, odd verbatim
		for (i=0; i < rows; i++){
			matrix[i] = msj.substr(i*columns,columns);
			if (i%2)
				reverse(matrix[i].begin(),matrix[i].end());
			
		}
		for (i=0; i < columns; i++)
			for (int j=0; j < rows; j++)
				allmsjs.insert(allmsjs.end(), matrix[j][i]);
		allmsjs.insert(allmsjs.end(), '\n');
		cin >> columns;
	}
	cout << allmsjs;
	return 0;
}


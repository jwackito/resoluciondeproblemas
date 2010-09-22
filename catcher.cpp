/*http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=4&problem=167&mosmsg=Submission+received+with+ID+8270054*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	int h;
	cin >> h;
	int testn=1;
	while (h > -1){
		vector <int> height;
		while (h  > -1){
			height.push_back(h);
			cin >> h;
		}
		vector <int> length(height.size() + 1, 1);
		for (int i = 0; i < height.size() - 1; i++){
			for (int j = i + 1; j < height.size(); j++){
				if (height[i] > height[j])
					if (length[i] + 1 > length[j])
						length[j] = length[i]+1;
			}	
		}
		int max = -1;
		for (int i=0; i < length.size(); i++)	
			max = (max > length[i])?max:length[i];
		cout << "Test #" << testn++ << ":" << endl << "  maximum possible interceptions: " << max << endl;
		cin >> h;
		if (h > -1)
			cout << endl;
	}
	return 0;
}

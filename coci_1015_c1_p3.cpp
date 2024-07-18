#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <cstring>
#include <deque>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int v[1000000], m[1000000];


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int shot = 0;
    int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> v[i];

	for(int i = 1; i <= n; i++){
		if(m[v[i]] == 0){
			shot++;
			m[v[i] - 1]++;
		}
		else{
			m[v[i] - 1]++;
			m[v[i]]--;
		}
	}
	cout << shot << "\n";
	return 0;
}
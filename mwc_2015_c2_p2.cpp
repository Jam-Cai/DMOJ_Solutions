#include <unordered_set>
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
#include <set>
using namespace std;
typedef long long ll;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int N, inp;
	cin >> N;
	deque<pair<int,int>> heights;
	heights.push_back(make_pair(0, 1000001));
	
	for (int i = 0; i < N; i++) {
		cin >> inp; 
		while(heights.empty() == false && inp >= heights.back().second) {
			heights.pop_back(); 
		}
		cout << i - heights.back().first << " "; 
		heights.push_back(make_pair(i, inp));
	}
}
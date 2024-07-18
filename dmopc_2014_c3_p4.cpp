#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    int factors[100001];
    vector<int> factorsVec[100001];   
    for(int i = 1; i < 100001; i++)
    {
        for(int j = i; j < 100001; j+=i)
        {
            factors[j]++;
        }
    }
    for(int i = 0; i < 100001; i++)
    {
        factorsVec[factors[i]].push_back(i);
    }
    for(int i = 0; i < T; i++)
    {
        int A,B,K;
        cin >> K >> A >> B;
        auto a = upper_bound(factorsVec[K].begin(), factorsVec[K].end(), B);
        auto b = lower_bound(factorsVec[K].begin(), factorsVec[K].end(), A);
        int c = a - b;
        cout << c << endl;
    }
}
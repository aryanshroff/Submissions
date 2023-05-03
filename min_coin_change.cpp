#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;



template <typename T>
void print1d(vector<T> v){
    cout<<" 1D VECTOR "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}

template <typename T> 
void print2d(vector<vector<T>> v){
    cout<<" 2D VECTOR "<<endl;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

template <typename T>
void printstack(stack<T> s ){
    cout<<" STACK "<<endl;
    while(s.empty()==false){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
    cout<<endl;
}

template <typename T>
void printq(queue<T> q){
    cout<<" QUEUE "<<endl;
    while(q.empty()==false){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    cout<<endl;
}

template <class K ,class V>
void printhash(unordered_map<K,V> h){
    cout<<" HASHMAP "<<endl;
    for(auto it=h.begin();it!=h.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
    cout<<endl;
}




int solve(vector<int> &coins, int amount)
{
    int r = coins.size() + 1;
    int c = amount + 1;
    vector<vector<int>> dp(r, vector<int>(c, INT16_MAX));
    cout << "Tabulated Matrix" << endl;
    print2d(dp);

    cout << "Filling the base cases" << endl;
    for (int j = 1; j < c; j++)
    {
        dp[0][j] = INT16_MAX;
    }
    for (int i = 0; i < r; i++)
    {
        dp[i][0] = 0;
    }
    print2d(dp);
    long res1, res2 = 0;
    int cell = 0;
    cout << "Filling the general cases" << endl;
    // filling 1,1 to r,c th cell
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            // if excluding current coin
            res1 = dp[i - 1][j];
            // if including current coin
            cell = j - coins[i - 1];
            if (cell > -1)
            {
                res2 = dp[i][j - coins[i - 1]] + 1;

                // taking minimum of both cases

                dp[i][j] = min(res1, res2);
            }
            else
            {
                dp[i][j] = res1;
            }
        }
    }
    print2d(dp);
    return dp[r - 1][c - 1];
}

int main()
{
    // take all input here
    vector<int> coins = {1, 2, 5};
    int amount = 25;
    // input end
    chrono::system_clock::time_point start = high_resolution_clock::now();
    int res = solve(coins, amount);
    cout<<"Coins array: ";
    print1d(coins);
    cout<<"Required amount: "<<amount<<endl;
    cout << "Minimum number of coins needed :" << res << endl;
    chrono::system_clock::time_point stop = high_resolution_clock::now();
    chrono::milliseconds duration = duration_cast<milliseconds>(stop - start);

    double time = duration.count();
    string unit = "ms";
    if (time >= 1000 and time < 60000)
    {
        time = time / 1000;
        unit = "sec";
    }
    cout << endl;
    cout << endl;
    cout << "Code Execution Time: " << time << " " << unit << endl;
    return 0;
}
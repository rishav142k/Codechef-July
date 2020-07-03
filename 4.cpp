#include <bits/stdc++.h>
#define F first
 #define S second
#define PB push_back
#define MP make_pair
#define ll long long int
#define vi vector<int>
#define vii vector<int, int>
#define vc vector<char>
#define vl vector<ll>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll resx = 0;
        ll resy = 0;

        for(int i = 1; i < 4*n; i++)
        {
            ll x, y;
            cin >> x >> y;
            resx ^= x;
            resy ^= y;

        }
        cout << resx << " " << resy << "\n";
    
        
    }
}
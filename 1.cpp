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
        vi A(n+1);
        ll res = 0;
        for(int i = 0 ;i  < n; i++) {
            cin >> A[i];
            if(i)
            {
                res += abs(A[i] - A[i-1]);
                res--;
            }
        }
        
        
        cout << res << "\n";
        
    }
}
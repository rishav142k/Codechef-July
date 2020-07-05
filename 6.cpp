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
        ll x;
        cin >> n >> x;
        vl A(n);
        for(int i = 0 ; i < n; i++) {
            cin >> A[i];
        }
        ll days = 0;
        sort(A.begin(), A.end(), greater<int>());

        for(int i = 0; i < n; i++) {
            while(1) {
                if(A[i] <= x) {
               //     cout << A[i] << " " << days << "\n";
                    x = 2*A[i];
                    days++;
                    break;
                }
                ll temp = A[i];
                A[i] -= x;
                x = 2*x;
                days++;
                A[i] = min(2*A[i],temp);
              //  cout << A[i] << " " << x << "\n";

            }
        }
        cout << days << "\n";
        

        
    }
}

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
ll sumofdigits(int n)
{
    ll sum = 0;
    while(n)
    {
        sum += n%10;
        n = n/10;
    }
    return sum;
}
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
        ll win1 = 0, win2 = 0;
        while(n--) {
            ll a, b;
            cin >> a >> b;

            ll sum1 = sumofdigits(a);
            ll sum2 = sumofdigits(b);

            if(sum1 >= sum2) {
                win1++;
            }
            if(sum2 >= sum1) {
                win2++;
            }


        }
        if(win1 == win2) {
            cout << 2 << " " <<  win1 << "\n";
        }
        else if(win1 > win2) {
            cout << 0 << " " <<  win1 << "\n";
        }
        else {
            cout << 1 << " " << win2 << "\n";
        }
        
    }
}
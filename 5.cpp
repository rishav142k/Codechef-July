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
        ll temp;
        vl A(n); 
        vl B(n);
        vl firstt, secondd;

        ll maxx = INT_MAX;
        unordered_map<ll, ll> freq, mapp, mappp;

    // freq contains frequency of both the arrays.

        for(int i = 0; i <  n; i++) {
            cin >> A[i];
               maxx = min(maxx, A[i]);
            freq[A[i]]++;
        }
        // Same for B as well

        for(int i = 0; i < n; i++) {
            cin >> B[i];
            maxx = min(maxx, B[i]);
            freq[B[i]]++;
        }
        int flg= 1;
        for(auto x: freq) {
            if(x.second % 2 != 0) {
                flg = 0;
                cout << "-1\n";
                break;
            }
        }
        if(!flg) {
            continue;
        }

        for(auto x: freq) {
            mapp[x.first]  = (ll)x.second/2;

        }
        mappp = mapp;

        for(int i = 0 ;i  < n; i++) {
            if(mapp[A[i]]) {
                mapp[A[i]]--;
            }
            else {
                firstt.PB(A[i]);
            }
        }
        // same for second one

        for(int i = 0; i < n; i++) {
            if(mappp[B[i]] ) {
                mappp[B[i]]--;
            }
            else {
                secondd.PB(B[i]);
            }
        }
        //now sort the arrays.  1 increasing , 1 decreasing...
        sort(firstt.begin(), firstt.end());
        sort(secondd.begin(), secondd.end(), greater<ll>());


        // for(int i = 0; i < firstt.size(); i++) {
        //     cout << firstt[i] << ' ';
        // }
        // cout << "\n";
        // for(int i = 0 ; i < secondd.size(); i++) {
        //     cout << secondd[i] << " ";
        // }
        // cout << "\n";
    
    if(!firstt.size()) {
        cout << "0\n";
        continue;
    }
    ll ans = 0;
    for(int i = 0; i < firstt.size(); i++) {
            ans  += min({2*maxx, firstt[i], secondd[i]});
    }
    cout << ans << "\n";

    }

return 0;
}
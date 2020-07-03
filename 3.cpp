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
        int k;
        cin >> k;
        int flag= 0;
        int cnt = 0;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(i == 7 && j == 7) {
                    cout << "O";
                }
                else if(64-cnt == k or flag == 1) {
                    cout << ".";
                    flag = 1;
                }
                else {
                    cout << "X";
                }
                cnt++;

            }
            cout << "\n";
        }
cout << "\n";
        
        
    }
}
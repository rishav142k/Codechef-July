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
        deque<ll> q;
        ll temp;
        for(int i = 0 ; i < n; i++) {
            cin >> temp;
            q.PB(temp);
        }
        sort(q.begin(), q.end());
        ll days = 0;
        deque<ll> ass;
        
        while(q.size() != 0) {
        	if(q.front()*2  < x ) {
        		ass.PB(q.front());
        		q.pop_front();
        		
			}
			else {
				break;
			}
        	
		}
        while(q.size() != 0) {
            if(x >= q.front()) {
                x = 2*q.front();
                q.pop_front();
            }
            else {
                ll temp = q.back();  
                q.back() -= x;
                x = 2* x;
                q.back() = min(2*q.back(), temp);
            }
            
        days++;
        
        }
        sort(ass.begin(), ass.end()) ;
        
        
        while(ass.size() != 0) {
        	if(x >= ass.front()) {
        		x = 2 * ass.front();
        		ass.pop_front();
			}
			else {
				ll temp = ass.back();
				ass.back() -= x;
				x = 2*x;
				ass.back() = min(2*ass.back(), temp);
			}
			days++;
			
		}
		cout << days << "\n";
        
        
        

        
    }
}

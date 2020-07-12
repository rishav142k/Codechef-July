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
	
	
	pair<ll, ll> to_find_maximum_in_range(ll left, ll right, vector<pair<ll, ll>> &st, ll low, ll high, ll pos);
	pair<ll, ll> maximum_compare(pair<int, int> a, pair<int, int> b);
	void buildT(vector<ll> &height, vector<pair<ll, ll>> &st, ll l, ll r, ll pos);
	pair<ll, ll> max_between(vector<pair<ll, ll>> &st, ll left, ll right, ll low, ll high, ll pos);
	
	
	void sieve() {
	int n = 1000000;
	vector<char> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}
	for(int i = 1;i <= n; i++) cout << i << " "<< is_prime[i] << "\n";
	}
	
	
	bool primality(int n) {
		bool flag = 1;
		if(n == 1){
			return false;
		}
		for(int i = 2; i <= sqrt(n); i++) {
			if(n % i == 0) return false;
		}
		return true;
	}
	
	void primeFact(int n) {
		for(int i = 2; i <= sqrt(n); i++)
		{
			if(n% i == 0)
			{
				int cnt = 0;
				while(n % i == 0)
				cnt++, n /= i;
				cout << i << "^" << cnt << "  ";
			}
		}
		if(n > 1) cout << n << "^" << 1 << "   ";
	}
	void binaryexpn(ll a, ll n)
	{
		 ll res = 1l;
		 while(n)
		 {
		 	if(n % 2)
		 	{
		 		res *= a;
		 		n--;
			}
	
			a *= a;
			n /= 2;
	
		 }
		 cout << res << "\n";
	}
	void primefactSieve(int n)
	{
		vi A(n+1, -1);
	
	
		for(int i = 2; i <= sqrt(n); i++)
		{
			if(A[i] == -1)
			{
				for(int j = i; j <= n; j+= i)
				{
					if(A[j] == -1) A[j] = i;
				}
			}
		}
		while(n > 1)
		{
			cout << A[n] << " ";
			n /= A[n];
	
		}
	
	}
	
	void buildT(vector<ll> &height, vector<pair<ll, ll>> &st, ll left, ll right, ll pos) {
		if (left == right) {
			st[pos] = {left, height[left]};
			return;
		}
		ll mid = left + (right - left) / 2;
		buildT(height, st, left, mid, 2 * pos + 1);
		buildT(height, st, mid + 1, right, 2 * pos + 2);
		st[pos] = maximum_compare(st[2 * pos + 1], st[2 * pos + 2]);
	}
	
	
	pair<ll, ll> maximum_compare(pair<int, int> a, pair<int, int> b) {
		
		if (a.first == -1)
		{
			return b;
		}
		else if (b.first == -1) {
			return a;
		}
		if (a.second > b.second) {
			return a;
		}
		return b;
	}
	
	
	pair<ll, ll> to_find_maximum_in_range(ll left, ll right, vector<pair<ll, ll>> &st, ll low, ll high, ll pos)
	{
		if (left <= low && right >= high)
		{
			return st[pos];
		}
		if (left > high || right < low)
		{
			return {-1, INT_MIN};
		}
		int mid = low + (high - low) / 2;
	
	return maximum_compare(to_find_maximum_in_range(left, right, st, low, mid, pos * 2 + 1), to_find_maximum_in_range(left, right, st, mid + 1, high, pos * 2 + 2));
	}
	
	pair<ll, ll> max_between(vector<pair<ll, ll>> &st, ll left, ll right, ll low, ll high, ll pos)
	{
		if (left > right)
		{
			ll temp = left;
			left = right;
			right = temp;
		}
		return to_find_maximum_in_range(left, right, st, low, high, pos);
	}
	
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		ll n, q;
		cin >> n >> q;
		vl height(n);
		vl taste(n);
		
		for (ll i = 0; i < n; i++)
		{
			cin >> height[i];
		}
		for (ll i = 0; i < n; i++)
		{
			cin >> taste[i];
		}
		vector<pair<ll, ll>> st;
		for (int i = 0; i < 2 * n; i++)
		{
			st.PB({-1, INT_MIN});
		}
		buildT(height, st, 0, n - 1, 0);
	
		while (q--)
		{
			int a, b, c;
			cin >> a >> b >> c;
			if (a == 1)
			{
				taste[b - 1] = c;
			}
			else
			{
				ll start = b - 1;
				ll end = c - 1;
				
				if (start == end)
				{
					cout << taste[start] << "\n";
					continue;
				}
				if (height[start] <= height[end])
				{
					cout << "-1\n";
					continue;
				}
				ll ass = (end - start) / abs(end - start);
				ll curr = start;
				
				ll result = taste[start];
				while (curr != end)
				{
					pair<ll, ll> peak = max_between(st, curr + ass, end, 0, n - 1, 0);
					if (peak.second > height[curr])
					{
						result = -1;
						break;
					}
					else if (peak.second == height[curr])
					{
						if (curr == start)
						{
							result = -1;
							break;
						}
						result -= taste[curr];
					}
					result += taste[peak.first];
					curr = peak.first;
				}
				cout << result << "\n";
			}
		}
		return 0;
	}

#include<bits/stdc++.h>
#define pb push_back
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std;

class custom_hash_t
{
    inline static uint64_t xor_shift( const uint64_t x, const int k )
    {
        return x ^ ( x >> k );
    }

    inline static uint64_t xor_shift_multiply( const uint64_t x, const int k, const uint64_t y )
    {
        return xor_shift( x, k ) * y;
    }

    inline static uint64_t splitmix64( uint64_t x )
    {
        /// http://x...content-available-to-author-only...i.it/splitmix64.c

        x += 0x9e3779b97f4a7c15,
        x  = xor_shift_multiply( x, 30, 0xbf58476d1ce4e5b9 ),
        x  = xor_shift_multiply( x, 27, 0x94d049bb133111eb );

        return xor_shift( x, 31 );
    }

public:

    size_t operator()( uint64_t x ) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64( x + FIXED_RANDOM );
    }
};

#define SAFE_SET( STL, KEY         ) typedef unordered_##STL< KEY,         custom_hash_t > safe_##STL
#define SAFE_MAP( STL, KEY, Mapped ) typedef unordered_##STL< KEY, Mapped, custom_hash_t > safe_##STL

typedef long long ll;

SAFE_SET(      set, ll );
SAFE_SET( multiset, ll );
SAFE_MAP(      map, ll, int );
SAFE_MAP( multimap, ll, int );

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

gp_hash_table< ll, int, custom_hash_t > safe_gp_hash_table;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int sq=(int)sqrtl(n);

        vector<unordered_map<int,int>> mp(sq);
        for(int i=0;i<sq;i++){
            int val=a[0]*(i+1)-b[0];
            if(1<=val && val<=2*n) mp[i][val]++;
        }
        vector<unordered_map<int,int>> bs(n+1);
        bs[a[0]][b[0]]++;
        ll ans=0;
        for(int i=1;i<n;i++){
            if(a[i]<=sq){
                ans+=mp[a[i]-1][b[i]];
            }else{
                int l=(2+a[i]-1)/a[i],r=2*n/a[i];
                for(int j=l;j<=r;j++){
                    int val=a[i]*j-b[i];
                    if(1<=val && val<=n) ans+=bs[j][val];
                }
            }
            for(int j=0;j<sq;j++){
                int val=a[i]*(j+1)-b[i];
                if(1<=val && val<=2*n) mp[j][val]++;
            }
            bs[a[i]][b[i]]++;
        }
        cout<<ans<<"\n";
	}
	return 0;
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* bitwise and boolean operations
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

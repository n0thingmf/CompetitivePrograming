#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        ll n;
        cin>>n;
        ll u=n/2,v=n-u;
        if(n%2==1 && v%10==0){
            ll e=1,cnt=0;
            while((v/e)%10==0){
                cnt++;
                e*=10;
            }
            if(cnt%2){
                u-=4;
                v+=4;
            }
            for(ll i=cnt%2,e=1+9*(cnt%2);i<cnt;i++,e*=10){
                if(i&1){
                    v+=9*e;
                    u-=9*e;
                }
            }
        }
        cout<<u<<" "<<v<<"\n";
	}
	cout << setprecision(12) << fixed;
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

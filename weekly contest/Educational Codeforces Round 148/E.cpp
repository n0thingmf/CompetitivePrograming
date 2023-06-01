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
	ll n,q;
	cin>>n>>q;
	ll totals=0;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i],totals+=a[i];
    sort(all(a));
    vector<ll> a2=a;
    for(int i=0;i<n;i++) a2[i]+=n-i;

    vector<ll> sl(n,0),sr(n,0);
    sl[0]=a2[0];
    for(int i=1;i<n;i++) sl[i]=min(a2[i],sl[i-1]);
    sr[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--) sr[i]=min(sr[i+1],a[i]);

    while(q--){
        ll k;
        ll dif=0,b,up=0;
        cin>>k;
        if(k>=n){
            if(k%2==n%2){
                dif=(k-n)/2;
                b=sl[n-1]+(k-n);
                up=totals+k*(k+1)/2-(k-n)*(k-n+1)/2-b*n;
            }
            else{
                dif=(k-n+1)/2;
                b=min(sl[n-2]+(k-n),sr[n-1]);
                up=totals+k*(k+1)/2-(k-n+1)*(k-n+2)/2-b*n;
            }
        }else{
            b=min(sl[k-1]+(k-n),sr[k]);
            up=totals+k*(k+1)/2-b*n;
        }
        if(dif>up){
            dif-=up;
            cout<<b-(dif+n-1)/n<<" ";
        }else{
            cout<<b<<" ";
        }

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

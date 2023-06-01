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
	int n,q;
	cin>>n>>q;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(all(a));
    while(q--){
        vector<ll> b=a;
        int k;
        ll dif=0;
        cin>>k;
        if(k>n){
            if(k%2==n%2){
                dif=(k-n)/2;
                for(int i=0;i<n;i++){
                    b[i]+=k-i;
                }
            }
            else{
                dif=(k-n+1)/2;
                for(int i=0;i<n-1;i++){
                    b[i]+=k-i;
                }
            }
        }else{
            for(int i=0;i<k;i++){
                b[i]+=k-i;
            }
        }

        sort(all(b));
        ll up=0;
        for(int i=0;i<n;i++){
            up+=b[i]-b[0];
        }
        if(dif>up){
            dif-=up;
            cout<<b[0]-(dif+n-1)/n<<" ";
        }else{
            cout<<b[0]<<" ";
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

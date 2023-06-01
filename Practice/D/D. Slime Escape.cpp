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
        int n,k;
        cin>>n>>k;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        if(k==1 || k==n){
            cout<<"YES\n";
            continue;
        }
        int l=k-2,r=k;
        bool ok=false;
        ll now=a[k-1],suml=0,sumr=0;
        while(l>=0 && r<n){
            while(l>=0 && suml+a[l]+now>=0){
                //cout<<"loopeando1 "<<l<<" "<<suml<<"\n";
                suml+=a[l];
                l--;
                if(suml>0) break;
            }
            if(l==-1){
                ok=true;
                break;
            }
            if(suml>0){
                now+=suml;
                suml=0;
                continue;
            }

            while(sumr<=0 && r<n && sumr+a[r]+now>=0){
                //cout<<"loopeando2 "<<r<<" "<<sumr<<"\n";
                sumr+=a[r];
                r++;
                if(sumr>0) break;
            }
            if(r==n){
                ok=true;
                break;
            }
            if(sumr>0){
                now+=sumr;
                sumr=0;
                continue;
            }
            break;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
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

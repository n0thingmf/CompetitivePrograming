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
        int n;
        cin>>n;
        int r[3],c[3];
        for(int i=0;i<3;i++) cin>>r[i]>>c[i];
        int x=(r[0]+r[1]+r[2]+1)/3;
        int y=(c[0]+c[1]+c[2]+1)/3;
        //cout<<x<<" "<<y<<" mid\n";
        int u,v;
        cin>>u>>v;
        bool ans;
        if((x==1 && y==1) || (x==n && y==1) || (x==1 && y==n) || (x==n && y==n)){
            ans=(u==x)||(v==y);
        }else if((x&1) && (y&1)){
            ans=((u&1)==1)||((v&1)==1);
        }else if(x&1){
            if(u&1) ans=true;
            else ans=(v&1)==0;
        }else if(y&1){
            if(v&1) ans=true;
            else ans=(u&1)==0;
        }else{
            ans=((u&1)==0)||((v&1)==0);
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
	}
	return 0;
	// you should actually read the stuff at the bottom
}

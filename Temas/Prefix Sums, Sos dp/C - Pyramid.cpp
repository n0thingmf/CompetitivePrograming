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

const ll mod=1e9+9,P=1e9+7;
const int maxq=1e6,maxn=1e3;

int tab[maxn*3][maxn*3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	int a,b,d,ma,mb,md,aa,ab,ad;
	a--,b--,d--;
	cin>>a>>ma>>aa;
	cin>>b>>mb>>ab;
	cin>>d>>md>>ad;
    for(int iq=0;iq<q;iq++){
        //up
        tab[maxn+a-d][maxn+b-1]+=1;
        tab[maxn+a-d+1][maxn+b-1]+=1;
        tab[maxn+a-d][maxn+b]-=1;
        tab[maxn+a-d+1][maxn+b]-=1;
        //left
        tab[maxn+a][maxn+b-d-1]-=1;
        tab[maxn+a][maxn+b-d]-=1;
        tab[maxn+a+1][maxn+b-d-1]+=1;
        tab[maxn+a+1][maxn+b-d]+=1;
        //right
        tab[maxn+a][maxn+b+d-1]+=1;
        tab[maxn+a][maxn+b+d]+=1;
        tab[maxn+a+1][maxn+b+d-1]-=1;
        tab[maxn+a+1][maxn+b+d]-=1;
        //down
        tab[maxn+a+d][maxn+b-1]-=1;
        tab[maxn+a+d][maxn+b]+=1;
        tab[maxn+a+d+1][maxn+b-1]-=1;
        tab[maxn+a+d+1][maxn+b]+=1;
        a=(a*ma+aa)%n+1;
        b=(b*mb+ab)%m+1;
        d=(d*md+ad)%max(n,m)+1;
    }
    for(int j=0;j<3*maxn;j++){
        for(int i=1;i<3*maxn;i++){
            tab[i][j]+=tab[i-1][j];
        }
    }
    for(int i=0;i<3*maxn;i++){
        for(int j=1;j<3*maxn;j++){
            tab[i][j]+=tab[i][j-1];
        }
    }
    for(int d=0;d<6*maxn-1;d++){
        int init;
        if(d<3*maxn) init=0;
        else init=d-3*maxn+1;
        for(int i=init+1,j=d-i;i<3*maxn && j>=0;i++,j=d-i){
            tab[i][j]+=tab[i-1][j+1];
        }
    }
    for(int d=0;d<6*maxn-1;d++){
        int init;
        if(d<3*maxn) init=0;
        else init=d-3*maxn+1;
        for(int j=init+1,i=3*maxn-1+j-d;i<3*maxn && j<3*maxn;j++,i=3*maxn-1+j-d){
            tab[i][j]+=tab[i-1][j-1];
        }
    }
    ll ans=0;
    for(int i=maxn;i<maxn+n;i++){
        for(int j=maxn;j<maxn+m;j++){
           // cout<<tab[i][j]<<" ";
            ans=(ans*P+tab[i][j])%mod;
        }
       // cout<<"\n";
    }
    cout<<ans<<"\n";
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

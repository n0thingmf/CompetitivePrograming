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

const int maxn=1e5;
vector<int> child[maxn];
int dad[maxn];
bool ded[maxn];
int dfs(int now,int mv){
    if(!ded[now]) return now;
    int next=upper_bound(all(child[now]),mv)-child[now].begin();
    for(;next<child[now].size();next++){
        int nk=dfs(child[now][next],mv);
        if(nk!=-1) return nk;

    }
    return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n=1,king=0;
	dad[0]=-1;
	ded[0]=false;
	int q;
	cin>>q;
	while(q--){
        int t,x;
        cin>>t>>x;
        x--;
        if(t==1){
            child[x].pb(n);
            dad[n]=x;
            n++;
        }else{
            ded[x]=true;
            if(ded[king]){
                for(int par=king,lim=-1;par!=-1;lim=par,par=dad[par]){
                    int res=dfs(par,lim);
                    //cout<<par<<" "<<res<<"\n";
                    if(res!=-1){
                        king=res;
                        break;
                    }
                }
                cout<<king+1<<"\n";

            }else cout<<king+1<<"\n";
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

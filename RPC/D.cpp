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
const ll maxv=1e12;
const ll inf=LLONG_MAX;

vector<bool> visit;
vector<int> cycle,pos,p1,p2;
vector<vector<int>> cycles;
void dfs(int now,int id){
   pos[now]=cycles[id].size();
   cycles[id].pb(now);
   cycle[now]=id;
   visit[now]=true;
   int next=p2[p1[now]];
   if(!visit[next]) dfs(next,id);
}

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

ll bezout(ll a,ll b,ll& x_0,ll& y_0){
	if(b==0){
		x_0=1;
		y_0=0;
		return a;
	}
	ll x_1,y_1;
	ll g=bezout(b,a%b,x_1,y_1);
	x_0=y_1;
	y_0=x_1-(a/b)*y_1;
	return g;
}
long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	p1.resize(n);
	p2.resize(n);
	vector<int> inv(n);
	for(int i=0;i<n;i++){
        cin>>p1[i];
        p1[i]--;
        inv[p1[i]]=i;
	}
	for(int i=0;i<n;i++){
        cin>>p2[i];
        p2[i]--;
	}
	visit.assign(n,false);
	cycle.resize(n);
	pos.resize(n);
	vector<int> m;
	int nc=0;
	for(int i=0;i<n;i++){
        if(!visit[i]){
            cycles.pb(vector<int>());
            dfs(i,nc);
            m.pb(cycles[nc].size());
            nc++;
        }
	}
	ll ans1=1;
	for(int i=0;i<nc;i++){
        ans1=(ans1*m[i])/gcd(ans1,m[i]);
        //if(ans1*2>maxv){
        //    ans1=inf;
        //    break;
        //}
	}
	if(ans1!=inf) ans1*=2;
	ll ans2=1;
	vector<int> k(nc);
	for(int j=0;j<nc;j++){
        int dist=-1;
        for(int i:cycles[j]){
            if(cycle[inv[i]]!=j){
                ans2=inf;
                break;
            }
            int len=m[j];
            int d=(pos[inv[i]]-pos[i]+len)%len;
            if(dist==-1) dist=d;
            else{
                if(d!=dist){
                    ans2=inf;
                    break;
                }
            }
        }
        if(ans2==inf) break;
        else{
            k[j]=dist;
        }
	}
	if(ans2!=inf){
        ans2=k[0];
        ll x=m[0];
        for(int i=1;i<nc;i++){
            ll x1,y1;
            ll d=bezout(x,m[i],x1,y1);
            if((k[i] - ans2) % d != 0) {
                ans2=inf;
                break;
            }
            //ll temp=ans2 + (x1 * (k[i] - ans2) / d  )%(m[i] / d) * x;
            ans2 = normalize(ans2 + (x1 * (k[i] - ans2) / d )%(m[i] / d) * x, x * m[i] / d);
            //if(2*ans2+1>maxv){
            //    ans2=inf;
            //    break;
            //}
            x = x*m[i]/d; // you can save time by replacing above lcm * n[i] /d by lcm = lcm * n[i] / d
        }
	}
	if(ans2!=inf) ans2=ans2*2+1;
	if(min(ans1,ans2)==inf) cout<<"huge\n";
	else cout<<min(ans1,ans2)<<"\n";
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

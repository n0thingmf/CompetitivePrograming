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

vector<int> box;
vector<int> id;
vector<int> p;
vector<vector<int>> boxv;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	box.resize(n);
	id.resize(n);
	boxv.resize(n);
	p.resize(n+1);
	for(int i=0;i<n;i++){
        box[i]=i+1;
        id[i]=i;
        boxv[i].pb(i+1);
        p[i+1]=i;
	}
	while(q--){
        int type,x,y;
        cin>>type;
        if(type==1){
            cin>>x>>y;
            x--,y--;
            if(boxv[id[x]].size()>=boxv[id[y]].size()){
                for(int num:boxv[id[y]]){
                    boxv[id[x]].pb(num);
                    p[num]=id[x];
                }
                boxv[id[y]].clear();
            }else{
                for(int num:boxv[id[x]]){
                    boxv[id[y]].pb(num);
                    p[num]=id[y];
                }
                boxv[id[x]].clear();
                swap(box[id[x]],box[id[y]]);
                swap(id[x],id[y]);
            }
        }else if(type==2){
            cin>>x;
            x--;
            boxv[id[x]].pb(p.size());
            p.pb(id[x]);
        }else{
            cin>>x;
            cout<<box[p[x]]<<"\n";
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

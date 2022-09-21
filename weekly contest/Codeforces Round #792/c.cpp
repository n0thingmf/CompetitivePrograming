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
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        bool res=true,allgood=true;
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            bool ok=true;
            vector<int> c;
            for(int j=1;j<m;j++){
                if(a[i][j-1]>a[i][j]){
                    ok=false;
                    c.pb(j);
                }
            }
            if(!ok){
                allgood=false;
                if(c.size()==1){
                    int k,x=-1;
                    for(int k=c[0]-1;k>=0;k--){
                        if(a[i][k]==a[i][c[0]-1]){
                            x=k;
                        }
                    }
                    if(x!=-1) ans.pb({x,c[0]});
                    x=-1;
                    for(int k=c[0];k<m;k++){
                        if(a[i][k]==a[i][c[0]]){
                            x=k;
                        }
                    }
                    if(x!=-1) ans.pb({c[0]-1,x});


                }else if(c.size()==2){
                    //cout<<"case2 "<<c[0]<<" "<<c[1]<<"\n";
                    ans.pb({c[0]-1,c[1]});
                }else{
                    res=false;
                }
                break;
            }
        }
        if(!res){
            //cout<<"part1\n";
            cout<<"-1\n";
            continue;
        }
        if(allgood){
            cout<<"1 1\n";
            continue;
        }
        res=false;
        for(auto p:ans){
            //cout<<"pos: "<<p.first+1<<" "<<p.second+1<<"\n";
            bool ok=true;
            for(int i=0;i<n && ok;i++){
                swap(a[i][p.first],a[i][p.second]);
                for(int j=1;j<m && ok;j++){
                    if(a[i][j-1]>a[i][j]) ok=false;
                }
                swap(a[i][p.first],a[i][p.second]);
            }
            if(ok){
                res=true;
                cout<<p.first+1<<" "<<p.second+1<<"\n";
                break;
            }
        }
        if(!res){
            //cout<<"part2\n";
            cout<<"-1\n";
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

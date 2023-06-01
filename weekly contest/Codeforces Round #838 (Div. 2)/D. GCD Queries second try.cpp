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
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	int maxn=2e4;
	vector<int> dp(maxn);
	dp[1]=1;
	for(int i=2;i<maxn;i++){
        int ndiv=0;
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                ndiv++;
                if(i/j!=j) ndiv++;
            }
        }
        dp[i]=max(ndiv,dp[i-1]);
	}
	while(t--){
        int n;
        cin>>n;
        if(n==2){
            cout<<"! 1 2"<<endl;
            int res;
            cin>>res;
            if(res==-1) return 0;
            continue;
        }
        if(n==3){
            bool ok=true;
            for(int i=1;i<=3 && ok;i++){
                for(int j=i+1;j<=3 && ok;j++){
                    cout<<"? "<<i<<" "<<j<<endl;
                    int g;
                    cin>>g;
                    if(g==-1) return 0;
                    if(g==2){
                        cout<<"! "<<i<<" "<<j<<endl;
                        int res;
                        cin>>res;
                        if(res==-1) return 0;
                        ok=false;
                    }
                }
            }
            continue;
        }
        vector<set<int>> g(n);

        vector<bool> pos(n,true);
        set<pair<int,int>> qs;
        bool solved=false;

        set<int> candidates;
        for(int i=0;i<n;i++) candidates.insert(i);
        for(int i=0;i<n && !solved;i++){
            if(!pos[i]) continue;
            if(candidates.size()==2){
                cout<<"!";
                for(auto c:candidates) cout<<" "<<c+1;
                cout<<endl;
                int ans;
                cin>>ans;
                if(ans==-1) return 0;
                solved = true;
                break;
            }
            if(candidates.size()==1){
                int id=*candidates.begin();
                cout<<"! "<<id+1<<" "<<(id+1)%n+1<<endl;
                int ans;
                cin>>ans;
                if(ans==-1) return 0;
                solved=true;
                break;
            }
            if(g[i].size()>dp[n-1]){
                    cout<<"! "<<i+1<<" "<<(i+1)%n+1<<endl;
                    int ans;
                    cin>>ans;
                    if(ans==-1) return 0;
                    solved=true;
                    break;
            }
            for(int d=1;d<n && pos[i] && !solved;d++){
                int j=(i+d)%n;
                if(qs.count(make_pair(i,j))) continue;
                cout<<"? "<<i+1<<" "<<j+1<<endl;
                qs.insert({i,j});
                qs.insert({j,i});
                int gc;
                cin>>gc;
                if(gc==-1) return 0;
                if(g[i].count(gc)){
                    pos[i]=false;
                    candidates.erase(i);
                }else g[i].insert(gc);

                if(g[j].count(gc)){
                    pos[j]=false;
                    candidates.erase(j);
                }else g[j].insert(gc);

                if(g[i].size()>dp[n-1]){
                    cout<<"! "<<i+1<<" "<<(i+1)%n+1<<endl;
                    int ans;
                    cin>>ans;
                    if(ans==-1) return 0;
                    solved=true;
                    break;
                }
            }
            if(pos[i]){
                candidates.erase(i);
            }
        }
        assert(solved);
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

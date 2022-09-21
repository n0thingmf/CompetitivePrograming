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
	cout << setprecision(12) << fixed;
	int n,sum=0;
	cin>>n;
	vector<int> g(n);
	for(int i=0;i<n;i++){
        cin>>g[i];
        sum+=g[i];
	}
	sum/=n;
	for(int i=0;i<n;i++) g[i]-=sum;
	ll ans1=0,ans2=0;
	vector<int> g2=g;
	stack<pair<int,int>> st,st2;
	for(int j=0;j<2*n;j++){
        int i=j%n;
        if(g[i]==0) continue;
        if(g[i]>0){
            st.push({j,g[i]});
            g[i]=0;
        }else{
            while(g[i]<0 && !st.empty()){
                auto pr=st.top();
                st.pop();
                if(pr.second+g[i]>=0){
                    ans1+=1ll*abs(g[i])*(j-pr.first);
                    //cout<<abs(g[i])<<" "<<j<<" "<<pr.first<<" "<<pr.second<<"\n";
                   // cout<<ans1<<"\n";
                    if(pr.second+g[i]>0) st.push({pr.first,pr.second+g[i]});
                    g[i]=0;
                }else{
                    ans1+=1ll*pr.second*(j-pr.first);
                   // cout<<j<<" "<<pr.first<<" "<<pr.second<<"\n";
                   // cout<<pr.second<<" "<<j-pr.first<<"\n";
                   // cout<<ans1<<"\n";
                    g[i]+=pr.second;
                }
            }
        }

	}
	for(int j=0;j<2*n;j++){
        int i=(2*n-1-j)%n;
        if(g2[i]==0) continue;
        if(g2[i]>0){
            st2.push({j,g2[i]});
            g2[i]=0;
        }else{
            while(g2[i]<0 && !st2.empty()){
                auto pr=st2.top();
                st2.pop();
                if(pr.second+g2[i]>=0){
                    ans2+=1ll*abs(g2[i])*(j-pr.first);
                    if(pr.second+g2[i]>0) st2.push({pr.first,pr.second+g2[i]});
                    g2[i]=0;
                }
                else{
                    ans2+=1ll*pr.second*(j-pr.first);
                    g2[i]+=pr.second;
                }
            }
        }

	}
	//cout<<ans1<<" "<<ans2<<"\n";
	cout<<min(ans1,ans2)<<"\n";
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

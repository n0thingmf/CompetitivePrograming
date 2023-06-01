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

pair<int,int> p(int a,int b){
    return make_pair(min(a,b),max(a,b));
}
int main(){
	/*ios::sync_with_stdio(false);
	cin.tie(0);*/
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b;
        vector<set<int>> cnt(n);
        map<pair<int,int>,int> ans;
        for(int i=0;i<n;i++) a[i]=i;
        for(int d=1;2*d<n;d++){
            if(a.size()<=2) break;
            for(int x:a){
                if(b.size()==1 && x==a.back()){
                    b.pb(x);
                    break;
                }
                int l=(x-d+n)%n,r=(x+d)%n,g1,g2;
                if(ans.count(p(l,x))) g1=ans[p(l,x)];
                else{
                    cout<<"? "<<l+1<<" "<<x+1<<endl;
                    cin>>g1;
                    if(g1==-1) return 0;
                    ans[p(l,x)]=g1;
                }
                if(cnt[x].count(g1)) continue;
                cnt[x].insert(g1);
                if(ans.count(p(x,r))) g2=ans[p(x,r)];
                else{
                    cout<<"? "<<x+1<<" "<<r+1<<endl;
                    cin>>g2;
                    if(g2==-1) return 0;
                    ans[p(x,r)]=g2;
                }
                if(cnt[x].count(g2)) continue;
                cnt[x].insert(g2);
                b.pb(x);
            }
            a=b;
            b.clear();
        }
        if(n%2==0 && a.size()>2){
            int d=n/2;
            for(int x:a){
                if(b.size()==1 && x==a.back()){
                    b.pb(x);
                    break;
                }
                int l=(x-d+n)%n,r=(x+d)%n,g1,g2;
                if(ans.count(p(l,x))) g1=ans[p(l,x)];
                else{
                    cout<<"? "<<l+1<<" "<<x+1<<endl;
                    cin>>g1;
                    if(g1==-1) return 0;
                    ans[p(l,x)]=g1;
                }
                if(cnt[x].count(g1)==0){
                    cnt[x].insert(g1);
                    b.pb(x);
                }
            }
            a=b;
        }
        assert(a.size()<=2);
        if(a.size()>1) cout<<"! "<<a[0]+1<<" "<<a[1]+1<<endl;
        else cout<<"! "<<a[0]+1<<" "<<a[0]+1<<endl;
        int res;
        cin>>res;
        if(res==-1) return 0;
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

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
	int n,q;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ll last=-1;
	set<int> checked;
	cin>>q;
	for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){
            cin>>last;
            checked.clear();
        }else if(type==2){
            int id,x;
            cin>>id>>x;
            id--;
            if(last==-1){
                a[id]+=x;
            }else{
                if(checked.count(id)>0){
                    a[id]+=x;
                }else{
                    a[id]=last+x;
                    checked.insert(id);
                }
            }
        }else if(type==3){
            int id;
            cin>>id;
            id--;
            if(last==-1){
                cout<<a[id]<<"\n";
            }else{
                if(checked.count(id)>0){
                    cout<<a[id]<<"\n";
                }else{
                    a[id]=last;
                    cout<<a[id]<<"\n";
                    checked.insert(id);
                }
            }
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

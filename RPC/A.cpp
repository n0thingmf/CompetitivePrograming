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
	int n;
	cin>>n;
	vector<int> cil;
	vector<int> cub;
	for(int i=0;i<n;i++){
        string type;
        int l;
        cin>>type>>l;
        if(type=="cube") cub.pb(l);
        if(type=="cylinder") cil.pb(l);
	}
	sort(all(cil));
	sort(all(cub));
	vector<pair<int,int>> stck;
	stck.pb({1,0});
	for(int i:cil){
        stck.pb({0,i});
	}
	stck.pb({1,INT_MAX});
	int i=1;
	for(int j:cub){
        while(i<stck.size()){
            bool ok1,ok2;
            if(stck[i-1].first){
                ok1=j>=stck[i-1].second;
            }else{
                ok1=j>=2*stck[i-1].second;
            }
            if(stck[i].first){
                ok2=j<=stck[i].second;
            }else{
                ok2=(double)j*sqrt(2)<=2*stck[i].second;
            }
            if(ok1&&ok2){
                stck.insert(stck.begin()+i,{1,j});
                i++;
                break;
            }
            i++;
        }
        if(i==stck.size()){
            cout<<"impossible\n";
            return 0;
        }
	}
	for(int k=1;k<stck.size()-1;k++){
        if(stck[k].first){
            cout<<"cube "<<stck[k].second<<"\n";
        }else{
            cout<<"cylinder "<<stck[k].second<<"\n";
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

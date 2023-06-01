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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int sum=0,last=2;
        vector<int> color(n);
        set<int> uniq;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
               if(sum==0 && last!=1) last=1;
               sum+=1;
            }
            else{
                if(sum==0 && last!=-1) last=-1;
                sum-=1;
            }
            uniq.insert(last);
            color[i]=last;
        }
        if(sum!=0){
            cout<<"-1\n";
            continue;
        }
        if(uniq.size()==1){
            cout<<"1\n";
            for(int i=0;i<n;i++) cout<<"1 ";
            cout<<"\n";
        }else{
            cout<<"2\n";
            for(int i=0;i<n;i++){
                if(color[i]>0) cout<<"2 ";
                else cout<<"1 ";
            }
            cout<<"\n";
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

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
	int n;
	cin>>n;
	vector<pair<int,int>> a(n),b(n);
    ll ta=0,tb=0;
	for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]={x,i};
	}
	for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b[i]={x,i};
	}
	sort(all(a));
	sort(all(b));
	vector<int> marked(n,0);
	int i=n-1,j=n-1,cnt=(n/2)+1,leasta=0,leastb=0;
	while(cnt>0 && i>=0 && j>=0){
        //for(int i=0;i<n;i++) cout<<marked[i]<<" ";
        //cout<<"marked\n";
        //cout<<"least "<<leasta<<" "<<leastb<<"\n";
        if(cnt==1){
            while(marked[a[i].second]==1) i--;
            marked[a[i].second]=1;
            cnt--;
            continue;
        }
        while(marked[a[i].second]) i--;
        while(marked[b[j].second]) j--;
        //cout<<"testing "<<i<<" "<<j<<"\n";
        if(a[i].second==b[j].second){
            marked[a[i].second]=1;
            cnt--;
        }else{
            marked[a[i].second]=1;
            marked[b[j].second]=1;
            cnt-=2;
            if(a[i].second==b[leastb].second){
                while(leastb<n && marked[b[leastb].second]) leastb++;
            }
            if(b[j].second==a[leasta].second){
                while(leasta<n && marked[a[leasta].second]) leasta++;
            }
            if(leasta==n || leastb==n) continue;
            if(a[leasta].second==b[leastb].second){
                marked[a[leasta].second]=2;
                while(leasta<n && marked[a[leasta].second]) leasta++;
                while(leastb<n && marked[b[leastb].second]) leastb++;
            }else{
                marked[a[leasta].second]=2;
                while(leasta<n && marked[a[leasta].second]) leasta++;
                marked[b[leastb].second]=2;
                while(leastb<n && marked[b[leastb].second]) leastb++;
            }
        }
	}
	cout<<(n/2)+1<<"\n";
	for(int i=0;i<n;i++) if(marked[i]==1) cout<<i+1<<" ";
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

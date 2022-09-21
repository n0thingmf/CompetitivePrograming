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
vector<int> z_fun(string s){
    int n=s.size();
    vector<int> z(n,0);
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<=r) z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r){
            r=i+z[i]-1;
            l=i;
        }
    }
    return z;
}
vector<int> phi_fun(string s){
    int n=s.size();
    vector<int> phi(n,0);
    for(int i=1;i<n;i++){
        int j=phi[i-1];
        while(j>0 && s[i]!=s[j]) j=phi[j-1];
        if(s[i]==s[j]) j++;
        phi[i]=j;
    }
    return phi;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b;
	getline(cin,a);
	getline(cin,b);
	if(a.size()!=b.size()){
        cout<<"-1 -1\n";
        return 0;
	}
	int n=a.size();
	string reva=string(a.rbegin(),a.rend());
	vector<int> z=z_fun(b+string(1,0)+a);
	vector<int> phi=phi_fun(reva+string(1,0)+b);
	/*cout<<n<<"\n";
	for(int i=0;i<=2*n;i++) cout<<i<<" "<<z[i]<<"\n";
	for(int i=0;i<=2*n;i++) cout<<i<<" "<<phi[i]<<"\n";
	cout<<"\n";*/
	int i=0;
	while(i<n && b[n-1-i]==a[i]) i++;
	for(;i>0;i--){
        int j=z[n+1+i],k=phi[2*n-i];
        //cout<<i<<" "<<j<<" "<<k<<"\n";
        if(j+k+i<n || k==0) continue;
        cout<<i-1<<" "<<n-k<<"\n";
        return 0;
	}
	cout<<"-1 -1\n";
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

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

int dig[4]={5,3,2,1};
vector<vector<int>> conv(int x){
    vector<vector<int>> ans(5,vector<int>(4,0));
    int i=0;
    while(x){
        int d=x%10;
        x/=10;
        for(int j=0;j<4;j++) if(d>=dig[j]) ans[i][j]=1,d-=dig[j];
        i++;
    }
    return ans;
}
bool check_move(vector<vector<int>> &y){
    int e=1;
    for(int i=0;i<5;i++,e*=10){
        if(y[i][3]>=2){
            y[i][3]-=2;
            y[i][2]+=1;
            cout<<"D 1, "<<e<<"\n";
            return true;
        }
        if(y[i][2]>=2){
            y[i][2]-=2;
            y[i][1]+=1;
            y[i][3]+=1;
            cout<<"D 2, "<<e<<"\n";
            return true;
        }
        if(y[i][1]>=2){
            y[i][1]-=2;
            y[i][0]+=1;
            y[i][3]+=1;
            cout<<"D 3, "<<e<<"\n";
            return true;
        }
        if(y[i][0]>=2){
            y[i][0]-=2;
            y[i+1][3]+=1;
            cout<<"D 5, "<<e<<"\n";
            return true;
        }
    }
    e=1;
    for(int i=0;i<5;i++,e*=10){
        if(y[i][2]>=1 && y[i][3]>=1){
            y[i][1]+=1;
            y[i][2]-=1;
            y[i][3]-=1;
            cout<<"S 1, "<<e<<"\n";
            return true;
        }
        if(y[i][1]>=1 && y[i][2]>=1){
            y[i][0]+=1;
            y[i][1]-=1;
            y[i][2]-=1;
            cout<<"S 2, "<<e<<"\n";
            return true;
        }
    }
    return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        string s;
        cin>>s;
        if(s=="N"){
            int x;
            cin>>x;
            auto yup=conv(x);
            for(int i=4;i>=0;i--){
                for(int j=0;j<4;j++) cout<<yup[i][j];
                cout<<"\n";
            }
        }else{
            int a,b;
            cin>>a>>b;
            auto ya=conv(a);
            auto yb=conv(b);
            for(int i=0;i<5;i++){
                for(int j=0;j<4;j++) ya[i][j]+=yb[i][j];
            }
            while(check_move(ya));
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

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<complex>
#define mp make_pair
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

const double inf=1e20;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(2) << fixed;
	double cx1,cx2,cy,px1,px2,py;
	while(cin>>cx1>>cx2>>cy && !(cx1==0 && cx2==0 && cy==0)){
        cin>>px1>>px2>>py;
        int n;
        cin>>n;
        vector<double> x1,x2,y;
        for(int i=0;i<n;i++){
            double xx1,xx2,yy;
            cin>>xx1>>xx2>>yy;
            if(yy<=cy && yy>py){
                yy-=py;
                x1.pb(xx1);
                x2.pb(xx2);
                y.pb(yy);
            }
        }
        cy-=py;
        int m=x1.size();
        double ans=0;
        double res=inf;
        map<double,int> xd;
        xd[px1]=0;
        xd[px2]=0;
        for(int i=0;i<m;i++){
            xd[cx1+(x2[i]-cx1)*(cy/(cy-y[i]))]--;
            xd[cx2+(x1[i]-cx2)*(cy/(cy-y[i]))]++;
        }
        int cnt=0;
        map<double,int>::iterator it;
        for(it=xd.begin();it!=xd.end();it++){
            cnt+=it->second;
            if(px1<=it->first && it->first<=px2 && cnt==0){
                res=min(res,it->first);
                ans=max(ans,(it->first)-res);
            }else{
                if(px1<=it->first && it->first<=px2) ans=max(ans,(it->first)-res);
                res=inf;
            }
        }


        if(ans==0){
            cout<<"No View\n";
        }else{
            cout<<ans<<"\n";
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

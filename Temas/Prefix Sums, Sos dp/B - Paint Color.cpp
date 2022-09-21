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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
class rectan{
public:
    int x1,y1,x2,y2;
    rectan(){
        x1=y1=x2=y2=0;
    }
    rectan(int _x1,int _y1,int _x2,int _y2){
        x1=_x1,y1=_y1,x2=_x2,y2=_y2;
    }
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int w,h;
	while(true){
        cin>>w>>h;
        if(w==0 && h==0) break;
        int n;
        cin>>n;
        vector<rectan> r(n);
        vector<int> x,y;
        x.pb(0);
        x.pb(w);
        y.pb(0);
        y.pb(h);
        for(int i=0;i<n;i++){
            cin>>r[i].x1>>r[i].y1>>r[i].x2>>r[i].y2;
            x.pb(r[i].x1);
            x.pb(r[i].x2);
            y.pb(r[i].y1);
            y.pb(r[i].y2);
        }
        sort(all(x));
        x.erase(unique(all(x)),x.end());
        sort(all(y));
        y.erase(unique(all(y)),y.end());
        /*for(int i=0;i<x.size();i++) cout<<x[i]<<" ";
        cout<<"\n";
        for(int i=0;i<y.size();i++) cout<<y[i]<<" ";
        cout<<"\n";*/
        vector<vector<int>> tab(x.size(),vector<int>(y.size(),0));
        vector<vector<bool>> visit(x.size(),vector<bool>(y.size(),false));
        map<int,int> mx,my;
        for(int i=0;i<x.size();i++) mx[x[i]]=i;
        for(int i=0;i<y.size();i++) my[y[i]]=i;
        for(int i=0;i<n;i++){
            tab[mx[r[i].x1]][my[r[i].y1]]++;
            tab[mx[r[i].x1]][my[r[i].y2]]--;
            tab[mx[r[i].x2]][my[r[i].y1]]--;
            tab[mx[r[i].x2]][my[r[i].y2]]++;
        }
        for(int i=0;i<x.size();i++){
            for(int j=1;j<y.size();j++){
                tab[i][j]+=tab[i][j-1];
            }
        }
        for(int j=0;j<y.size();j++){
            for(int i=1;i<x.size();i++){
                tab[i][j]+=tab[i-1][j];
            }
        }
        for(int i=0;i<x.size();i++){
            for(int j=0;j<y.size();j++){
                if(tab[i][j]) visit[i][j]=true;
            }
        }
        auto bfs = [&](pair<int,int> start) -> void {
            queue<pair<int,int>> q;
            q.push(start);
            visit[start.first][start.second]=true;
            while(!q.empty()){
                pair<int,int> now=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    pair<int,int> next={now.first+dx[i],now.second+dy[i]};
                    if(next.first>=0 && next.first<x.size()-1 && next.second>=0 && next.second<y.size()-1 && !visit[next.first][next.second]){
                        q.push(next);
                        visit[next.first][next.second]=true;
                    }
                }
            }
        };
        int ans=0;
        for(int i=0;i<x.size()-1;i++){
            for(int j=0;j<y.size()-1;j++){
                if(visit[i][j]) continue;
                bfs({i,j});
                ans++;
            }
        }
        cout<<ans<<"\n";
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

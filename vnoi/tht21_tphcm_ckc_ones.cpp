#include "bits/stdc++.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;
    vector < vector < bool > >A(N+1, vector < bool > (M+1));
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++){
            char x; cin >> x;
            A[i][j] = x == '1';
        }

    if(N > 300){
        int Question; cin >> Question;
        while(Question--){
            int type; cin >> type;
            if(type == 1){
                int u,id; cin >> u >> id;
                A[u][id] = A[u][id] != true;
            }else{
                int x,y,count = 0; cin >> x >> y;
                for(int i = 1; i <= M; i++)count += A[x][i] != A[y][i];
                cout << count << "\n";
            }
        }
    }else{
        vector < vector < int > > Count (N+1, vector < int > (N+1,0));
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                for(int l = 1; l <= M; l++)Count[i][j] += A[i][l] != A[j][l];
                
        int Question; cin >> Question;
        while(Question--){
            int type; cin >> type;
            if(type == 1){
                int u,id; cin >> u >> id;
                A[u][id] = A[u][id] != true;
                for(int i = 1; i <= N; i++)
                if(i != u){
                    Count[i][u] += (A[i][id] != A[u][id] ? 1 : -1);
                    Count[u][i] += (A[i][id] != A[u][id] ? 1 : -1);
                }
            }else {
                int x,y; cin >> x >> y;
                cout << Count[x][y] << "\n";
            }
        }

    }
    return 0;
}
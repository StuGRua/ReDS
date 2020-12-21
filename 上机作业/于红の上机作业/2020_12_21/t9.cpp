#include <iostream>
#include <vector>
#include <string.h> 
using namespace std;
/*
Mark代表每个结点的状态，-1代表还没被访问，0代表正在被访问，1代表访问结束
如果一个状态为“0”的结点，与他相连的结点状态也为0的话就代表有环,这个可以用dfs实现
*/
vector<int> vec[1200];
int Mark[1200];
bool flag;//标记是否有环
 
void dfs(int x){
    if(flag){//如果有环就返回，否则继续搜索
        return;
    }
    Mark[x] = 0;//x正在被访问，状态为0
    for(int i = 0 ; i < vec[x].size() ; i++){
        if(Mark[vec[x][i]] == -1){
        //与x相连的结点状态也为-1，代表还未被访问，则继续搜索
            dfs(vec[x][i]);
        } else if(Mark[vec[x][i]] == 0){
        //与x相连的结点状态也为0，代表有环，返回
            flag = true;
            return;
        }
    }
    Mark[x] = 1;//对x的访问结束
}
 
int main(){
    memset(Mark, -1, sizeof(Mark));
    int n , m;
    cin >> n >> m;//n个结点，m条边
    for(int i = 0 ; i < m ; i++){//建立邻接表
        int u,v;
        cin >> u >> v;
        vec[u].push_back(v);
    }
    flag = false;
    dfs(1);
    if(flag){
        cout<<" have "<<endl;
    } else {
        cout << " not have" <<endl;
    }
    return 0;
}
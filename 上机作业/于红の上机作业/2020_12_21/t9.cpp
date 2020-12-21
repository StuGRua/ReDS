#include <iostream>
#include <vector>
#include <string.h> 
using namespace std;
/*
Mark����ÿ������״̬��-1����û�����ʣ�0�������ڱ����ʣ�1������ʽ���
���һ��״̬Ϊ��0���Ľ�㣬���������Ľ��״̬ҲΪ0�Ļ��ʹ����л�,���������dfsʵ��
*/
vector<int> vec[1200];
int Mark[1200];
bool flag;//����Ƿ��л�
 
void dfs(int x){
    if(flag){//����л��ͷ��أ������������
        return;
    }
    Mark[x] = 0;//x���ڱ����ʣ�״̬Ϊ0
    for(int i = 0 ; i < vec[x].size() ; i++){
        if(Mark[vec[x][i]] == -1){
        //��x�����Ľ��״̬ҲΪ-1������δ�����ʣ����������
            dfs(vec[x][i]);
        } else if(Mark[vec[x][i]] == 0){
        //��x�����Ľ��״̬ҲΪ0�������л�������
            flag = true;
            return;
        }
    }
    Mark[x] = 1;//��x�ķ��ʽ���
}
 
int main(){
    memset(Mark, -1, sizeof(Mark));
    int n , m;
    cin >> n >> m;//n����㣬m����
    for(int i = 0 ; i < m ; i++){//�����ڽӱ�
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
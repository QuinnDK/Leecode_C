#include<iostream>
#include<vector>
#include<queue>
using namespace  std;

struct TreeNode{
    int Val;
    TreeNode *Left;
    TreeNode *Right;
    TreeNode(int x):Val(x),Left(nullptr),Right(nullptr) {}
};

TreeNode* Construct_tree(vector<int> &vec){
    vector<TreeNode*> VecTree(vec.size(),nullptr);

    TreeNode* root=nullptr;
    for(int i=0;i<vec.size();i++){
        TreeNode* Node=nullptr;
        if(vec[i]!=-1){
            Node=new TreeNode(vec[i]);
            VecTree[i]=Node;
            if(i==0){
                root=Node;
            }
        }
    }
    for(int i=0;i*2+2<vec.size();i++){
        if(VecTree[i]!=nullptr){
            VecTree[i]->Left=VecTree[i*2+1];
            VecTree[i]->Right=VecTree[i*2+2];
        }
    }
    return root;
}
//打印
void Print_Tree(TreeNode* root){
    queue<TreeNode*> que;
    if(root!=nullptr){
        que.push(root);
    }
    vector<vector<int> > result;
    while(!que.empty()){
        int size=que.size();
        vector<int> vec;
        for(int i=0;i<size;i++){
            TreeNode* node=que.front();
            que.pop();
            if(node!=nullptr){
                vec.push_back(node->Val);
                que.push(node->Left);
                que.push(node->Right);
            }else{
                vec.push_back(-1);
            }
        }
        result.push_back(vec);
    }
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        //cout<<endl;
    }
}
int main(){
    vector<int> vec = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* root = Construct_tree(vec);
    Print_Tree(root);
}

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
    public:
       int data;
       Node* left;
       Node* right;
    
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;

    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root -> left = buildTree(preorder)    ;//Left
    root -> right = buildTree(preorder);//Right

   return root;
}

//preorder DFS
void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<< root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//inorder DFS
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//postOrder DFS
void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//Level Order
void levelOrder(Node* root){
    queue<Node*> q;

    q.push(root);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        cout<<curr->data <<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout << endl;
}

//Line Wise Level Order with printing in different line
void levelOrderLine(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }

        cout<<curr->data <<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout << endl;
}


int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);
    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;

    preOrder(root);
    cout<<endl;

    inorder(root);  
    cout<<endl;

    postOrder(root);
    cout<<endl;

    levelOrder(root);

    levelOrderLine(root);
    return 0;
}
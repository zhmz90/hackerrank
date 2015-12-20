#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

typedef struct node{
    int data;
    node *left;
    node *right;
}node;
typedef struct Node{
    node* data;
    Node *next;
}Node;

void inorder(node *root){
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


void swap_depth(node *root,int tree_depth, int target_depth){
//swap all the nodes who are at depth dp
    node *tmp;
    if (tree_depth == target_depth){
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return;
    }

    if (root->left != NULL)
        swap_depth(root->left, tree_depth+1, target_depth);
    if (root->right != NULL)
        swap_depth(root->right, tree_depth+1, target_depth);
}

void swap_tree(node *root, int k, int depth){
    for (int i=1;i <= depth;i++){
        if (i*k <= depth)
            swap_depth(root, 1,i*k);
        else
            break;
    }
}
int depth_of_tree(node *root){
    if (root == NULL)
        return 0;
    int depth_left=0,depth_right=0;
    if (root->left != NULL)
        depth_left = depth_of_tree(root->left);
    if (root->right != NULL)
        depth_right = depth_of_tree(root->right);

    int dp;
    if (depth_left>depth_right)
        dp = depth_left;
    else
        dp = depth_right;

    return dp+1;
}

int main(){
    int N;
    cin>>N;
    node *root,*left,*right;
    root = new node;
    root->data = 1;
    root->left = NULL;
    root->right = NULL;
    int l,r;

    Node *head,*tail,*tmp;
    head = new Node;
    head->data = root;
    tail = head;
    head->next = NULL;
    while ( N-->=1 ){
        cin>>l>>r;
        if (l != -1){
            left = new node;
            left->data = l;
            left->left = NULL;
            left->right = NULL;
            head->data->left = left;

            tmp = new Node;
            tmp->data = left;
            tmp->next = NULL;
            tail->next=tmp;

            tail = tail->next;
        }
        if (r != -1){
            right = new node;
            right->data = r;
            right->left = NULL;
            right->right = NULL;
            head->data->right = right;

            tmp = new Node;
            tmp->data = right;
            tmp->next = NULL;
            tail->next = tmp;

            tail = tail->next;
        }
        head = head->next;
    }

    //swap
    int depth = depth_of_tree(root);
//    cout<<"depht is "<<depth<<endl;
//    return 0;
    int T;
    cin>>T;
    int k;
    while (T-->=1){
        cin>>k;
        swap_tree(root, k, depth);
        inorder(root);
        cout<<endl;
    }

    return 0;
}

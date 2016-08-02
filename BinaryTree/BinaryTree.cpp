#include<iostream>
#include<algorithm>
using namespace std;

class node
{
    public:
        int data;
        class connections{
        public:
            node *right_child;
            node *left_child;
        };
        connections links;
        node* newNode(int val){
            node *temp=new node;
            temp->data=val;
            temp->links.left_child=temp->links.right_child=NULL;
            return temp;
        }
};

/*
    This makes a binary tree from an inorder and preorder.
    Similar implementation for inorder and postorder.
    Note, it is yet to deal with the problem if values are equal.
*/

node temp_node_generator;

node* construct_binary_tree(int n,int preorder[],int preorder_start,int preorder_end,int inorder[],int inorder_start,int inorder_end){
    if(preorder_end>=n || preorder_start>preorder_end || inorder_start>inorder_end || inorder_end>=n)
        return NULL;
    if(preorder_start==preorder_end){
        node *temp=temp_node_generator.newNode(preorder[preorder_start]);
        return temp;
    }
    else{
        int inorder_pos;
        for(int j=inorder_start;j<=inorder_end;j++){
            if(inorder[j]==preorder[preorder_start])
                inorder_pos=j;
        }
        node *temp=temp_node_generator.newNode(preorder[preorder_start]);
        temp->links.left_child=construct_binary_tree(n,preorder,preorder_start+1,preorder_start+inorder_pos-inorder_start,inorder,inorder_start,inorder_pos-1);
        temp->links.right_child=construct_binary_tree(n,preorder,preorder_start+inorder_pos+1-inorder_start,preorder_end,inorder,inorder_pos+1,inorder_end);
        return temp;
    }
}

//Traversal for inorder and preorder is similar in design.

void traversal_preorder(node *tree){
    if(tree==NULL)
        return;
    else{
        cout<<tree->data<<" ";
        traversal_preorder(tree->links.left_child);
        traversal_preorder(tree->links.right_child);
    }
}

int count_nodes(node *tree){
    if(tree==NULL)
        return 0;
    else{
        return 1+count_nodes(tree->links.left_child)+count_nodes(tree->links.right_child);
    }

}

int max_height(node *tree){
    if(tree==NULL)
        return 0;
    else{
        return 1+max(max_height(tree->links.left_child),max_height(tree->links.right_child));
    }
}



int main(){
    node *root,*probe;
    root=NULL;
    int n;
    cin>>n;
    int inorder[n];
    int preorder[n];
    for(int i=0;i<n;i++)
        cin>>inorder[i];
    for(int i=0;i<n;i++)
        cin>>preorder[i];
    root=construct_binary_tree(n,preorder,0,n-1,inorder,0,n-1);
    traversal_preorder(root);
    cout<<endl;
    cout<<count_nodes(root)<<endl;
    cout<<max_height(root)<<endl;
    return 0;
}

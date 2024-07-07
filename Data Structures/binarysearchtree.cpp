#include<iostream>
#include<algorithm>
#include<queue>
#define SIZE 1000

using namespace std;

struct bst{
	bst* Lchild;
	int data;
	bst* Rchild;
};

bst* root, *temp;

bst* GetNode(int n){
	bst* temp = new bst();
	temp->data = n;
	temp->Lchild=NULL;
	temp->Rchild=NULL;
	return temp;
}

bst* insert(bst* node ,int n){
    if(node == NULL){
        node = GetNode(n);
    }else if(node->data>=n){
        node->Lchild = insert(node->Lchild,n);
    }else if(node->data<n){
        node->Rchild = insert(node->Rchild,n);
    }
    return node;
}

void Inorder_rec(bst* ptr){
        if(ptr!=NULL){ 
            Inorder_rec(ptr->Lchild);
		    cout << ptr->data << " ";
            Inorder_rec(ptr->Rchild);
        }
}

bool search(bst*node,int x){
    if(node==NULL) return false;
    else if(node->data>x){
        node = node->Lchild;
        return search(node,x);
    }else if(node->data<x){
        node = node->Rchild;
        return search(node,x);
    }else return true;
}

bst* find(bst*node,int x){
    if(node==NULL) return NULL;
    else if(node->data>x){
        node = node->Lchild;
        return find(node,x);
    }else if(node->data<x){
        node = node->Rchild;
        return find(node,x);
    }else return node;
}

int max(bst* node){
    if(node==NULL){
        cout << "The tree is empty" << endl;
        return -1;
    }
    while(node->Rchild!=NULL){
        node = node->Rchild;
    }
    return node->data;
}

bst* max_node(bst* node){
    if(node==NULL){
        cout << "The tree is empty" << endl;
        return NULL;
    }
    while(node->Rchild!=NULL){
        node = node->Rchild;
    }
    return node;
}

int min(bst* node){
    if(node==NULL){
        cout << "The tree is empty" << endl;
        return -1;
    }
    while(node->Lchild!=NULL){
        node = node->Lchild;
    }
    return node->data;
}

bst* min_node(bst* node){
    if(node==NULL){
        cout << "The tree is empty" << endl;
        return NULL;
    }
    while(node->Lchild!=NULL){
        node = node->Lchild;
    }
    return node;
}

int min_rec(bst* node){
    if(node==NULL){
        cout << "The tree is empty" << endl;
        return -1;
    }
    if(node->Lchild!=NULL){
        return min_rec(node->Lchild);
    }else{
        return node->data;
    }
}

int max_rec(bst* node){
    if(node==NULL){
        cout << "The tree is empty" << endl;
        return -1;
    }
    if(node->Rchild!=NULL){
        return max_rec(node->Rchild);
    }else{
        return node->data;
    }
}

int find_height(bst* node){
    if(node==NULL){
        return -1;
    }
    return std::max(find_height(node->Lchild),find_height(node->Lchild)) + 1;
}

void level_order_traversal(bst* node){ //breadth first traversal
    if(node==NULL) return;
    queue<bst*>q;
    q.push(node);
    while (!q.empty())
    {
        bst* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->Lchild) q.push(temp->Lchild);
        if(temp->Rchild) q.push(temp->Rchild);
    }
    
}
//method 1 to check bt is bst
// bool IsSubtreelesser(bst* root,int value){
//     if(root==NULL) return true;
//     if(root->data <= value && IsSubtreelesser(root->Lchild,value) && IsSubtreelesser(root->Rchild,value))
//         return true;
//     else
//         return false;
// }

// bool IsSubtreeGreater(bst* root,int value){
//     if(root==NULL) return true;
//     if(root->data > value && IsSubtreeGreater(root->Lchild,value) && IsSubtreeGreater(root->Rchild,value))
//         return true;
//     else
//         return false;
// }

// bool IsBinarysearch(bst* root){
//     if(root==NULL) return true;
//     if(IsSubtreelesser(root->Lchild,root->data) && IsSubtreeGreater(root->Rchild,root->data) && IsBinarysearch(root->Lchild) && IsBinarysearch(root->Rchild))
//         return true;
//     else
//         return false;
// }

//method 2 to check bt is bst


bool IsBSTutil(bst* root, int minvalue,int maxvalue){
    if(root==NULL) return true;
    if(root->data > minvalue  && root->data < maxvalue && IsBSTutil(root->Lchild,minvalue,root->data) && IsBSTutil(root->Rchild,root->data,maxvalue))
        return true;
    else
        return false;
}

bool IsBinarysearch(bst* root){
    return IsBSTutil(root , INT_MIN, INT_MAX);
}

bst* Delete(bst* root, int data){
    if(root==NULL) return root;
    else if(data > root->data) root->Rchild = Delete(root->Rchild,data);
    else if(data < root->data) root->Lchild = Delete(root->Lchild,data);
    else{
        if(root->Rchild == NULL && root->Lchild == NULL){
            delete root;
            root = NULL;
        }
        else if(root->Lchild == NULL){
            bst* temp = root;
            root = root ->Rchild;
        }
        else if(root->Rchild == NULL){
            bst* temp = root;
            root = root->Lchild;
        }else {
            root->data = min_rec(root->Rchild);
            root->Rchild = Delete(root->Rchild,root->data);
        }
    }
    return root;
}



bst* inorder_succesor(bst* root, int data){
    bst* current = find(root,data);
    if(current==NULL) return NULL;
    if(current->Rchild!=NULL){
        return min_node(current->Rchild);
    }else{
        bst* successor = NULL;
        bst* ancestor = root;
        while(ancestor!=current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor  = ancestor->Lchild;
            }else 
                ancestor = ancestor->Rchild;
        }
        return successor;
    }
}

bst* inorder_predecessor(bst* root, int data){
    bst* current = find(root,data);
    if(current==NULL) return NULL;
    if(current->Lchild!=NULL){
        return max_node(current->Lchild);
    }else{
        bst* predecessor = NULL;
        bst* ancestor = root;
        while(ancestor!=current){
            if(current->data > ancestor->data){
                predecessor = ancestor;
                ancestor  = ancestor->Rchild;
            }else 
                ancestor = ancestor->Lchild;
        }
        return predecessor;
    }
}





int main(){
    root = NULL;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,12);
    root = insert(root,11);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8);
    root = insert(root,17);
    root = insert(root,27);
    root = insert(root,16);
    root = insert(root,6);
    Inorder_rec(root);
    cout << endl;
    int num;
    cout<<"Enter the number you want to search: ";
    cin >> num;
    if(search(root,num)){
        cout << "found the number" <<endl;
    }else{
        cout << "Not found" << endl;
    }
    if(max(root)!=-1)
        cout <<"The max element in the tree is "<< max(root) <<endl;
    if(min(root)!=-1)
        cout <<"The min element in the tree is "<< min(root) <<endl;
    if(max_rec(root)!=-1)
        cout <<"The max element in the tree is "<< max_rec(root) <<endl;
    if(min_rec(root)!=-1)
        cout <<"The min element in the tree is "<< min_rec(root) <<endl;
    cout << "Heigth of the tree : " << find_height(root) << endl;
    cout << "Breadth order traveral: ";
    level_order_traversal(root);
    cout << endl;
    if(IsBinarysearch(root))
        cout<<"The binary tree is binarysearchtree" << endl;
    else
        cout<<"Not binarysearchtree" << endl;
    root = Delete(root,25);
    Inorder_rec(root);
    bst* temp = inorder_succesor(root,12);
    if(temp!=NULL)
        cout <<"\nInorder succesor of 12 is "<< temp->data << endl;
    temp = inorder_predecessor(root,12);
    if(temp!=NULL)
        cout <<"\nInorder Predecessor of 12 is "<< temp->data << endl;
}
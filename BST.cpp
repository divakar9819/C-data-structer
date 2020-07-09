#include<bits/stdc++.h>
using namespace std;

class node
{
public :
    node *lchild;
    int data;
    node *rchild;
};

class BST
{
private:
    node *root;
public:
    BST(){root = nullptr ; }
    node* getRoot(){return root ;}
    void insertBST(int key);
    void Inorder(node *p);
    node*searchBST(int key);
    node* recursiveInsertBST(node *p , int key);
    node* recursiveSearchBST(node *p , int key);
    node* deleteBST(node *p , int value);
    int Height(node *p);
    node* InPre(node *p);
    node* InSucc(node *p);

};


//Insert in BST
void BST::insertBST(int key)
{
    node *t = root;
    node   *p, *r;

    if(t==nullptr){
        t = new node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        root = t;
        return ;
    }

    while(t!=nullptr){
        r = t;
        if(key == t->data){
                cout<<"Duplicate value in BST is not possible"<<endl;
                return ;

        }
        else if(key < t->data){
            t = t->lchild;
        }
        else {
            t = t->rchild;
        }
    }

    p = new node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;
    if(key < r->data){
        r->lchild = p;
    }
    else {
        r->rchild = p;
    }
}


//Traversal in BST
void BST::Inorder(node *p)
{
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

//Searching in BST
node *BST::searchBST(int key)
{
    node *p = root;
    while(p!=nullptr){
            if(p->data == key){
                return p;
            }
            else if(p->data > key){
                p = p->lchild;
            }
            else {
                p = p->rchild;
            }

    }

    return nullptr;
}

//Recursive Insert Function

node* BST::recursiveInsertBST(node * p , int key)
{
    node *t;
    if(p==nullptr){
        t = new node ;
        t->lchild = nullptr;
        t->rchild = nullptr;
        p = t;
        return p;
    }
     if(p->data > key ){
        p->lchild = recursiveInsertBST(p->lchild , key);
    }
    else if(p->data < key){
        p->rchild = recursiveInsertBST(p->rchild , key);
    }
    return p;
}

//Recursive traverse

node* BST::recursiveSearchBST(node *p , int key)
{
    if(p==nullptr){
        return nullptr;
    }
    if(p->data == key){
        return p;
    }
    else if(p->data > key ){
        return recursiveSearchBST(p->lchild , key);
    }
    else {
        return recursiveSearchBST(p->rchild , key);
    }

}

//height of BST
 int BST::Height(node *p)
 {
     int x , y;
     if(p==nullptr){
        return 0;
     }

     x = Height(p->lchild);
     y = Height(p->rchild);
     return x>y ? x+1 : y+1;

 }


//delete bst
node* BST::deleteBST(node *p , int value)
{
    node *q;
    if(p==nullptr){
        return nullptr;
    }
    if(p->lchild==nullptr && p->rchild==nullptr){
        if(p==root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if(value < p->data){
        p->lchild = deleteBST(p->lchild , value);
    }
    else if(value > p->data){
        p->rchild = deleteBST(p->rchild , value);
    }
    else {
        if(Height(p->lchild) > Height(p->rchild)){
                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = deleteBST(p->lchild , q->data);
        }
        else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = deleteBST(p->rchild , q->data);
        }
    }
    return p;
}



 node* BST::InPre(node *p)
 {
     while(p!=nullptr && p->rchild!=nullptr){
        p = p->rchild;
     }
     return p;
 }

 node* BST::InSucc(node *p)
 {
     while(p!=nullptr && p->lchild!=nullptr){
        p = p->lchild;
     }
     return p;
 }

//main function
int main()
{
    BST bst;

    bst.insertBST(8);
    bst.insertBST(6);
    bst.insertBST(5);
    bst.insertBST(12);
    bst.insertBST(11);
    bst.insertBST(10);


    bst.Inorder(bst.getRoot());

    cout<<endl;
    node *temp = bst.searchBST(5);
    if(temp!=nullptr){
        cout<<temp->data<<"  Item is found"<<endl;
    }
    else {
        cout<<"Item is not found"<<endl;
    }

    cout<<endl;
    node *temp1 = bst.recursiveSearchBST(bst.getRoot(), 10);
    if(temp1!=nullptr){
        cout<<temp1->data<<"  Item is found"<<endl;
    }
    else {
        cout<<"Item is not found"<<endl;
    }

    cout<<bst.Height(bst.getRoot())<<endl;
    bst.deleteBST(bst.getRoot(), 10);
    bst.deleteBST(bst.getRoot(), 8);
    bst.Inorder(bst.getRoot());


    return 0;
}

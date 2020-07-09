#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    node *lchild;
    int data;
    node *rchild;
};

//class for queue
class Queue
{
private :
    int qsize;
    int qfront;
    int qrear;
    node **Q;
public:
    Queue(int qsize);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(node *x);
    node*dequeue();

};

//create an empty queue
Queue::Queue(int qsize)
{
    this->qsize = qsize;
    qfront = -1;
    qrear = -1;
    Q = new node* [qsize];
}

Queue:: ~Queue()
{
    delete [] Q;
}

bool Queue::isEmpty()
{
    if(qrear==qfront){
        return true;
    }
    else {
        return false;
    }
}

bool Queue::isFull()
{
    if(qrear== qsize-1){
        return true;
    }
    else {
        return false;
    }
}


//push the node in queue
void Queue::enqueue(node *x)
{
    if(isFull()){
        cout<<"Queue overflow"<<endl;
    }
    else{
        qrear++;
        Q[qrear] = x;
    }
}


//delete node from queue
node* Queue:: dequeue()
{
    node *x = nullptr;
    if( isEmpty()){
        cout<<"Queue is underflow"<<endl;
    }
    else {
            qfront++;
            x = Q[qfront];
    }
     return x;
}

node *root = new node;


//create a  Binary tree
void createTree()
{
    node *p;
    node *t;
    int x;
    Queue q(10);
    cout<<"Enter the root value : "<<flush;
    cin>>x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);
    while(!(q.isEmpty())){
        p = q.dequeue();

        cout<<"Enter left child value of "<<p->data<<" : " <<flush;
        cin>>x;
        if(x!=-1){
            t = new node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        cout<<"Enter right child value of "<<p->data<<" : "<<flush;
        cin>>x;
        if(x!=-1){
            t = new node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Preorder(node *p)
{
    if(p){
        cout<<p->data<<" , "<<flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(node *p)
{
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" , "<<flush;
        Inorder(p->rchild);
    }
}

void Postorder(node *p)
{
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" , "<<flush;
        }
}

int main()
{
    createTree();
    cout<<"Preorder Trvversal "<<endl;
    Preorder(root);
    cout<<endl;
    cout<<"Inorder Trvversal "<<endl;
    Inorder(root);
    cout<<endl;
    cout<<"Postorder Trvversal "<<endl;
    Postorder(root);
    return 0;
}





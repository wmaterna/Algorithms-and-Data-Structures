#include <iostream>
#include <queue>
using namespace std;
typedef int Telement;
struct Node
{
    Telement info;
    Node * left;
    Node * right;
};
typedef Node *PNode;

class BinaryTree{
protected:
    PNode T;
public:
    BinaryTree();
    ~BinaryTree();
    PNode PARENT(PNode n, PNode T);
    PNode PARENT1(PNode n,PNode T);
    PNode LEFT_CHILD(PNode n);
    PNode RIGHT_CHILD(PNode n);
    Telement GetLabel(PNode n);
    PNode BuildTree1(int m, queue<int> &numbers);
    void BuildTree(int m, queue<int> &numbers);
    PNode ROOT();
    void MAKENULL(PNode p);
    void PreOrder(PNode t);
    void InOrder(PNode t);
    void PostOrder(PNode t);
};
BinaryTree::BinaryTree()
{T=NULL;}
BinaryTree::~BinaryTree()
{MAKENULL(T);}
void BinaryTree::MAKENULL(PNode p){
if (p!=NULL)
{
    if (p->left!=NULL) MAKENULL(p->left);
    if (p->right!=NULL) MAKENULL(p->right);
    delete p;
    p=NULL;
}
}
PNode BinaryTree::ROOT(){
    return T;
}
PNode BinaryTree::PARENT(PNode n, PNode T){
    if (n==T)
        return NULL;
    return PARENT1(n,T);
}
PNode BinaryTree::PARENT1(PNode n ,PNode T){
    if ((T->left==n) || (T->right==n))
        return T;
    PNode tmp1=NULL;
    PNode tmp2=NULL;
    if (T->left!=NULL)
        tmp1=PARENT1(n,T->left);
    if (T->right!=NULL)
        tmp2=PARENT1(n,T->right);
    return (tmp1!=NULL)?tmp1 :tmp2;
}
PNode BinaryTree::LEFT_CHILD(PNode n){ //zmienic{
    return n->left;
}
PNode BinaryTree::RIGHT_CHILD(PNode n){ //zmienic{
    //PNode tmp=PARENT(n,T);
    //if ((tmp->left)==n) return tmp->right;
    //else return NULL;
    return n->right;
}
Telement BinaryTree::GetLabel(PNode n){
    if (n!=NULL)
		return n->info;
	else
		return NULL;
}



PNode BinaryTree::BuildTree1(int n, queue<int> &numbers){
    if (n==0) return 0;
    int nl, np;
    Telement x;
    PNode tmp;
    nl=n/ 2;
    np= n-nl-1;
    tmp=new Node;
    tmp->info=numbers.front();
    cout << numbers.front() << ", nl: " << nl << ", np: " << np << endl;
    numbers.pop();
    tmp->left=BuildTree1(nl, numbers);
    tmp->right=BuildTree1(np, numbers);
    return tmp;
}
// kolokwium: listy, stody, kolejki, drzewa
void BinaryTree::BuildTree(int n, queue<int> &numbers){
	T = BuildTree1(n, numbers);
}

void PreOrder(PNode t){
    if (t!= NULL) {
        cout << t->info;
        PreOrder(t->left);
        PreOrder(t->right);
    }
}
void InOrder(PNode t){
    if (t!= NULL) {
        InOrder(t->left);
        cout << t->info;
        InOrder(t->right);
    }
}
void PostOrder(PNode t){
    if (t!= NULL) {
        PostOrder(t->left);
        PostOrder(t->right);
        cout << t->info;
    }
}
int main(){
    int wezly;
    PNode tmp;
    wezly = 9;
    queue<int> numbers;// = new queue<int>;
    for(int i = 0; i < wezly; i++) {
    	numbers.push(i+1);
    }
    
    BinaryTree tree;
    tree.BuildTree(wezly, numbers);
    printf("%d\n",tree.GetLabel(tree.LEFT_CHILD(tree.ROOT())));
    printf("%d\n",tree.GetLabel(tree.RIGHT_CHILD(tree.ROOT())));
    printf("%d\n",tree.GetLabel(tree.PARENT(tree.RIGHT_CHILD(tree.LEFT_CHILD(tree.ROOT())),tree.ROOT())));
    printf("%d\n",tree.GetLabel(tree.PARENT(tree.LEFT_CHILD(tree.ROOT()),tree.ROOT())));

    PreOrder(tree.ROOT());
    cout<<endl;
    InOrder(tree.ROOT());
    cout<<endl;
    PostOrder(tree.ROOT());
    cout<<endl;
    return 0;
}







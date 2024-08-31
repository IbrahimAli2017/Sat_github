#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;
class Node{
public:
    int value;
    Node* left=NULL;
    Node* right=NULL;
};
class BST{
Node* root = NULL;
public:
    void push(int value){
        Node* n = new Node();
        n->value = value;
        if(root==NULL){
            root = n;
            return;
        }
        Node* parent;
        Node* p = root;
        while(p!=NULL){
            parent = p;
            if(p->value==value)return;
            if(value>p->value){
                p = p->right;
            }else{
                p = p->left;
            }
        }
        if(value>parent->value){
            parent->right = n;
        }else{
            parent->left = n;
        }

    }
    void BFS(){
        queue<Node*>items;
        items.push(root);
        while(items.size()>0){
            Node* first = items.front();
            cout<<first->value<<endl;
            if(first->left!=NULL){
                items.push(first->left);
            }
            if(first->right!=NULL){
                items.push(first->right);
            }
            items.pop();
        }
    }

    void print(){
        DFS(root);
    }
    void DFS(Node* p){ //inorder
        if(p==NULL)return;
        DFS(p->left);
        cout<<p->value<<endl;
        DFS(p->right);
    }
    void remove(int value){
        Node* parent =NULL;
        Node* p = root;
        while(p!=NULL){
            if(p->value = value)break;
            parent = p;
            if(value>p->value){
                p = p->right;
            }else{
                p = p->left;
            }
        }
        if(p==NULL)return;
        if(p->left==NULL&&p->right==NULL){
            delete p;
            if(value>parent->value){
                parent->right = NULL;
            }else{
                parent->left = NULL;
            }
        }
        else if(p->right==NULL){
            Node* child = p->left;
            delete p;
            if(value>parent->value){
                parent->right = child;
            }else{
                parent->left = child;
            }
        }

        else if(p->left==NULL){
            Node* child = p->right;
            delete p;
            if(value>parent->value){
                parent->right = child;
            }else{
                parent->left = child;
            }
        }
        else{
            Node* temp = p->left;
            while(temp->right!=NULL){
                    parent = temp;
                temp = temp->right;
            }
            p->value = temp->value;
            parent->right = temp->left;
        }
    }
};
int main()
{

   /* map<int,string> myMap;
    pair<int,string> p(10,"ibrahim");
    myMap.insert(p);
    myMap[5] = "ahmed";
    myMap[15] = "Omar";
    cout<<myMap[5]<<endl;*/
    /*
    set<int>tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(40);
    tree.insert(35);
    tree.insert(45);
    tree.insert(60);
    //tree.erase(50);
    set<int>::iterator p;
    p= tree.begin();
    while(p!=tree.end()){
        cout<<*p<<endl;
        p++;
    }*/

    return 0;
}

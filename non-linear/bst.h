#include <iostream>
using namespace std;

struct Node {
    int key;
    int data;
    Node *left;
    Node *right;
}
class BST {
    private:
        Node *root;
    public:
        BST():root{nullptr} {};
        void insert(int key, int data){
            if(root == nullptr){
                root = new Node;
                root->key = key;
                root->data = data;
                root->left = nullptr;
                root->right = nullptr;
            }
            else{
                Node *current = root;
                while(current != nullptr){
                    if(key < current->key){
                        if(current->left == nullptr){//
                            current->left = new Node;
                            current->left->key = key;
                            current->left->data = data;
                            current->left->left = nullptr;
                            current->left->right = nullptr;
                            break;
                        }
                        else{
                            current = current->left;// go left
                        }
                    }
                    else{
                        if(current->right == nullptr){// go right
                            current->right = new Node;
                            current->right->key = key;
                            current->right->data = data;
                            current->right->left = nullptr;
                            current->right->right = nullptr;
                            break;
                        }
                        else{
                            current = current->right;//
                        }
                    }
                }
            }
        };
        Node* search(int key){
            Node *current = root;
            while(current != nullptr){
                if(key == current->key){
                    return current;
                }
                else if(key < current->key){
                    current = current->left;
                }
                else{
                    current = current->right;
                }
            }
            return nullptr;
        };
        Node* searchParent(int key){
            Node *current = root;
            Node *parent = nullptr;
            while(current != nullptr){
                if(key == current->key){
                    return parent;
                }
                else if(key < current->key){
                    parent = current;
                    current = current->left;
                }
                else{
                    parent = current;
                    current = current->right;
                }
            }
            return nullptr;
        };
        }
        void inOrderTraverse(){
            
        };

        }
        void remove(int key){
            Node* del = search(key);
            Node* parent = searchParent(key);   
            if(del == nullptr){
                cout<<"Key not found"<<endl;
                return;
            }
            else{
                if(del->left=NULL&&del->right=NULL){//no children
                    if(parent->left==del){
                        parent->left=nullptr;
                    }
                    else{
                        parent->right=nullptr;
                    }
                } else if(del->left!=NULL&&del-right!=NULL){//two children
                    Node* temp=del->right;//find smallest node in right subtree
                    while(temp->left!=NULL){//go all the way left
                        temp=temp->left;//smallest node in right subtree
                    }
                    del->key=temp->key;
                    del->data=temp->data;//copy data from smallest node in right subtree to node to be deleted
                    if(temp->right!=NULL){//if smallest node in right subtree has a right child
                        temp->key=temp->right->key;
                        temp->data=temp->right->data; 
                        temp->right=NULL;
                    }
                    else{//if smallest node in right subtree has no children
                            if(parent->left==temp){
                                parent->left=NULL;
                            }
                            else{
                                parent->right=NULL;
                            }
                        }
                    }
                }else{//one child
                    if(del->left!=NULL){//if left child
                        if(parent->left==del){//if node to be deleted is left child of parent
                            parent->left=del->left;//set parent's left child to node's left child
                        }
                        else{
                            parent->right=del->left;//set parent's right child to node's left child
                        }
                    }
                    else{//if right child
                        if(parent->left==del){//if node to be deleted is left child of parent
                            parent->left=del->right;
                        }
                        else{
                            parent->right=del->right;
                        }
                    }
                }
            }
        }
    
  


};
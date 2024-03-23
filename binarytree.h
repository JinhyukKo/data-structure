#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

class BinaryTree{
    Node* root;

    public:
    BinaryTree():root{NULL}{};
    ~BinaryTree(){
        delete root;
    };
    void insert(int data){
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        if(root == NULL){
            root = newNode;
        }else{
            Node* current = root;
            Node* parent = NULL;
            while(current != NULL){
                parent = current;
                if(data < current->data){
                    current = current->left;
                }else{
                    current = current->right;
                }
            }
            if(data < parent->data){
                parent->left = newNode;
            }else{
                parent->right = newNode;
            }
        }
    };
    void remove(int data){
        Node* current = root;
        Node* parent = NULL;
        while(current != NULL && current->data != data){
            parent = current;
            if(data < current->data){
                current = current->left;
            }else{
                current = current->right;
            }
        }
        if(current == NULL){
            cout << "Data not found" << endl;
        }else if(current->left == NULL && current->right == NULL){
            if(current == root){
                root = NULL;
            }else if(parent->left == current){
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }
            delete current;
        }else if(current->left != NULL && current->right == NULL){
            if(current == root){
                root = current->left;
            }else if(parent->left == current){
                parent->left = current->left;
            }else{
                parent->right = current->left;
            }
            delete current;
        }else if(current->left == NULL && current->right != NULL){
            if(current == root){
                root = current->right;
            }else if(parent->left == current){
                parent->left = current->right;
            }else{
                parent->right = current->right;
            }
            delete current;
        }else{
            Node* successor = current->right;
            while(successor->left != NULL){
                successor = successor->left;
            }
            int temp = successor->data;
            remove(successor->data);
            current->data = temp;
        }
    };
    


};
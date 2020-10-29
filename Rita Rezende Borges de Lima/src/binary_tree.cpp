#include "./headers/binary_tree.hpp"
#include "./headers/node.hpp"
#include <iostream>
#include<cstring>

BinaryTree::BinaryTree(){
    this->root = nullptr;
}

void BinaryTree::recursive_insert(char *value, Node *node){
    Node *aux;
    
    if(node->is_bigger_than_value(value)){
        if(node->leftChild == nullptr){
            aux = new Node(value);
            node->leftChild = aux;
        } 
        else
            this->recursive_insert(value, node->leftChild);         
    } 
    else {
        if(node->rightChild == nullptr){
            aux = new Node(value);
            node->rightChild = aux;
        }
        else
            this->recursive_insert(value, node->rightChild);
    }
}

void BinaryTree::insert(char *value){
    if(this->root == nullptr){
        this->root = new Node(value);
    } else {
        this->recursive_insert(value, this->root);
    }
}

// Node *BinaryTree::predecessor(Node* &node, Node* &r){
//     Node *s = r->right_most_child(), *aux = node; // S é o antecessor
//     s->parent->rightChild = s->leftChild; //Como s vai substituir outro elemento seu filho esquerdo tem q ser adicionado no seu pai
//     if(s->left_child_exists()){
//         s->leftChild->parent = s->parent; 
//     }
//     s->leftChild = node->leftChild;
//     s->rightChild = node->rightChild;
//     s->parent = node->parent;
//     return s;
//     delete aux;
// }

void BinaryTree::predecessor(Node* node, Node* &r){
    if(r->right_child_exists()){
        this->predecessor(node, r->rightChild);
        return;
    }
    node->value = r->value;
    node = r;
    r = r->leftChild;
    delete node;
}

void BinaryTree::remove_node(Node* &node, char *value){
    
    Node *aux;
    if(node == nullptr) return ;
    if(node->is_bigger_than_value(value)){ 
        return remove_node(node->leftChild, value);
    } else if(node->is_smaller_than_value(value)) {
        return remove_node(node->rightChild, value);
    } else {
        if(!node->right_child_exists()){
            aux = node;
            if(node->left_child_exists()){
                node = node->leftChild;
            } else {
                node = nullptr;
            }
            free(aux);
        }
        else if(!node->left_child_exists()){
            aux = node;
            if(node->right_child_exists()){
                node = node->rightChild;
            } else{
                node = nullptr;
            }
            free(aux);

        } else {
            this->predecessor(node, node->leftChild);
        }   

    }
}

void BinaryTree::substitute(char *old_value, char *new_value){
        
    this->remove_node(this->root, old_value);  
    this->insert(new_value);
}


int BinaryTree::recursive_encrypt(char *to_encrypt, Node *n, int* pos){
    
    int encrypted;
    
    if(n == nullptr)
        return -1;
    else if(strcmp(n->value, to_encrypt) == 0){
        return *pos;
    } 
    
    if(n->leftChild != nullptr){
        *pos = *pos + 1;
        encrypted = this->recursive_encrypt(to_encrypt, n->leftChild,  pos);
        if(encrypted != -1) 
            return encrypted;
    }
    
    if(n->rightChild != nullptr){
        *pos = *pos + 1;
        encrypted = this->recursive_encrypt(to_encrypt, n->rightChild, pos);
        if(encrypted != -1) 
            return encrypted;
    }

    return -1;
    
}

int BinaryTree::encrypt(char *to_encrypt){
    int pos = 1;
    return this->recursive_encrypt(to_encrypt, this->root, &pos);
}


char * BinaryTree::recursive_decrypt(int to_decrypt, Node *n,  int *pos){

    char *decrypted;

    if(n == nullptr) 
        return nullptr;
    else if(*pos == to_decrypt){
        return n->value;
    }
    if(n->leftChild != nullptr){
        *pos = *pos + 1;
        decrypted = this->recursive_decrypt(to_decrypt, n->leftChild, pos);
        if(decrypted != nullptr)
            return decrypted;
    }

    if(n->rightChild != nullptr){
        *pos = *pos + 1;
        decrypted = this->recursive_decrypt(to_decrypt, n->rightChild, pos);
        if(decrypted != nullptr)
            return decrypted;
    }

    return nullptr;
}

char * BinaryTree::decrypt(int to_decrypt){
    int pos = 1;
    return this->recursive_decrypt(to_decrypt, this->root, &pos);
}

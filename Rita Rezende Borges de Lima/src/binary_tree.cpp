#include "./headers/binary_tree.hpp"
#include "./headers/node.hpp"
#include <iostream>
#include<cstring>

BinaryTree::BinaryTree(){
    this->root = NULL;
}

void BinaryTree::recursive_insert(char *value, Node *node){
    
    if(node->is_bigger_then_value(value)){
        if(node->leftChild == NULL)
            node->leftChild = new Node(value);
        else
            this->recursive_insert(value, node->leftChild);         
    } 
    else {
        if(node->rightChild == NULL)
            node->rightChild = new Node(value);
        else
            this->recursive_insert(value, node->rightChild);
    }
}

void BinaryTree::insert(char *value){
    if(this->root == NULL)
        this->root = new Node(value);
    else
        this->recursive_insert(value, this->root);
}

Node *BinaryTree::search(char *query, Node *node){
    if(node != NULL){
        if(strcmp(node->value,query) == 0)
            return node;
        
        else if(node->is_bigger_then_value(query))
            return this->search(query, node->leftChild);
        
        else 
            return this->search(query, node->rightChild);
        
    }
    return NULL;
}

void BinaryTree::substitute(char *old_value, char *new_value){
    Node *n = this->search(old_value, this->root);
    
    if(n != NULL)
        n->value = new_value;
    
}

int BinaryTree::recursive_encrypt(char *to_encrypt, Node *n, int* pos){
    
    int encrypted;
    
    if(n == NULL)
        return -1;
    else if(strcmp(n->value, to_encrypt) == 0){
        return *pos;
    } 
    
    if(n->leftChild != NULL){
        *pos = *pos + 1;
        encrypted = this->recursive_encrypt(to_encrypt, n->leftChild,  pos);
        if(encrypted != -1) 
            return encrypted;
    }
    
    if(n->rightChild != NULL){
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

    if(n == NULL) 
        return NULL;
    else if(*pos == to_decrypt){
        return n->value;
    }
    if(n->leftChild != NULL){
        *pos = *pos + 1;
        decrypted = this->recursive_decrypt(to_decrypt, n->leftChild, pos);
        if(decrypted != NULL)
            return decrypted;
    }

    if(n->rightChild != NULL){
        *pos = *pos + 1;
        decrypted = this->recursive_decrypt(to_decrypt, n->rightChild, pos);
        if(decrypted != NULL)
            return decrypted;
    }

    return NULL;
}

char * BinaryTree::decrypt(int to_decrypt){
    int pos = 1;
    return this->recursive_decrypt(to_decrypt, this->root, &pos);
}

void BinaryTree::print_tree(Node *n){
    if(n == NULL) return;
    printf("%s\n", n->value);
    print_tree(n->leftChild);
    print_tree(n->rightChild);
}
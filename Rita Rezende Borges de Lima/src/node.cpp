#include "./headers/node.hpp"
#include <string.h>

Node::Node(char *value){
    this->value = value;
    this->leftChild = nullptr;
    this->rightChild = nullptr;    
}

int Node::is_bigger_than_value(char *word){
        
    if(this->node_contains_key(word)) return 0;
    
    for(int i = 0; i < (int)strlen(word) && i < (int)strlen(this->value); i++){
        if((int) word[i] < (int) this->value[i]) return 1;
        if((int) word[i] > (int) this->value[i]) return 0;
    }

    if(strlen(word) < strlen(value)) return 1;
    return 0;
}

int Node::is_smaller_than_value(char *word){
        
    if(this->node_contains_key(word)) return 0;

    for(int i = 0; i < (int)strlen(word) && i < (int)strlen(this->value); i++){
        if((int) word[i] < (int) this->value[i]) return 0;
        if((int) word[i] > (int) this->value[i]) return 1;
    }

    if(strlen(word) < strlen(value)) return 0;
    return 1;
}

int Node::node_contains_key(char *word){
    return strcmp(word, this->value) == 0;
}

int Node::left_child_exists(){
    return this->leftChild != NULL;
}

int Node::right_child_exists(){
    return this->rightChild != NULL;
}

Node *Node::right_most_child(){
    Node *p;
    for(p = this; p->right_child_exists(); p = p->rightChild);

    return p;
}
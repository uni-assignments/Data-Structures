#include "./headers/node.hpp"
#include <string.h>

Node::Node(char *value){
    this->value = value;
}

int Node::is_bigger_then_value(char *word){
        
    for(int i = 0; i < (int)strlen(word) && i < (int)strlen(this->value); i++){
        if((int) word[i] < (int) this->value[i]) return 1;
        if((int) word[i] > (int) this->value[i]) return 0;
    }

    if(strlen(word) < strlen(value)) return 1;
    return 0;
}

int Node::left_child_exists(){
    return this->leftChild != NULL;
}

int Node::right_child_exists(){
    return this->rightChild != NULL;
}

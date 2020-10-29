#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "./node.hpp"

class BinaryTree {
    
    public:
        BinaryTree();
        
        void insert(char *value);
        void substitute(char *old_value, char *new_value);
        int encrypt(char *to_encrypt);
        char *decrypt(int to_decrypt);
        
    private:
        void recursive_insert(char *value, Node *n);    
        void predecessor(Node* node, Node* &right);
        void remove_node(Node* &node, char *value);
        int recursive_encrypt(char *to_encrypt, Node *n, int *pos);
        char *recursive_decrypt(int to_decrypt, Node *n,  int *pos);

        Node *root; 
};

#endif

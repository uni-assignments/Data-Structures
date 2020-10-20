#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "./node.hpp"

class BinaryTree {
    
    public:
        BinaryTree();

        Node *get_root(){return root;};
        
        void recursive_insert(char *value, Node *n);        
        void insert(char *value);
        
        Node *search(char *value, Node *node);
        void substitute(char *old_value, char *new_value);
        
        int recursive_encrypt(char *to_encrypt, Node *n, int *pos);
        int encrypt(char *to_encrypt);
        
        char *recursive_decrypt(int to_decrypt, Node *n,  int *pos);
        char *decrypt(int to_decrypt);

        void print_tree(Node *n);
        
    private:
        Node *root; 
};

#endif

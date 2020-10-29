#ifndef NODE_H
#define NODE_H

class Node {
    
    public:
        Node(char *value);
        
        int is_bigger_than_value(char *word);
        int is_smaller_than_value(char *word);
        int left_child_exists();
        int right_child_exists();
        int node_contains_key(char *values);
        Node *right_most_child();

    
    protected:
        char *value;
        Node *leftChild;
        Node *rightChild;

    friend class BinaryTree;
};

#endif
#ifndef NODE_H
#define NODE_H

class Node {
    
    public:
        Node(char *value);
        
        int is_bigger_then_value(char *word);
        int left_child_exists();
        int right_child_exists();
        int node_contains_key(char **values, int amount_words);
    
    private:
        char *value;
        Node *leftChild;
        Node *rightChild;

    friend class BinaryTree;
};

#endif
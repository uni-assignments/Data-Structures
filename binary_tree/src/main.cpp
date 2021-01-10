#include "./headers/binary_tree.hpp"
#include <cstdlib>  
#include <cstdio>
#include<iostream>

void operation_insert(BinaryTree *tree){
    char *new_word;
    
    scanf("%ms", &new_word);
    tree->insert(new_word);

}

void operation_encrypt(BinaryTree *tree){
    int amount_words, encrypted;
    char *words_to_encrypt;

    scanf("%d", &amount_words);
    
    for(int i = 0; i < amount_words; i++){
        scanf(" %ms", &words_to_encrypt);
        encrypted = tree->encrypt(words_to_encrypt);
        printf("%d ", encrypted);
    }
    printf("\n");

}

void operation_decrypt(BinaryTree *tree){
    int amount_numbers, numbers_to_decrypt;
    char *words_decrypted;

    scanf("%d", &amount_numbers);
    
    for (int i = 0; i < amount_numbers; i++){
        scanf(" %d", &numbers_to_decrypt);
        words_decrypted = tree->decrypt(numbers_to_decrypt);
        printf("%s ", words_decrypted);
    }
    printf("\n");
}

void operation_substitute(BinaryTree *tree){
    char *new_word, *old_word;
    scanf("%ms %ms", &old_word, &new_word);
    tree->substitute(old_word, new_word);
}

int main(){
    char op = ' ';
    
    BinaryTree *tree = new BinaryTree();
    
    while(scanf("%c", &op) != EOF){
        switch (op){
            case 'i': operation_insert(tree);
                break;    
            case 'e': operation_encrypt(tree);                
                break; 
            case 's': operation_substitute(tree);
                break;
            case 'd': operation_decrypt(tree);
                break;
            default:
                break;
        }
    }
    delete tree;
    return 0;   
}

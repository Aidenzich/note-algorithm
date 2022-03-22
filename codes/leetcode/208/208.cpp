// 208. Implement Trie (Prefix Tree) https://leetcode.com/problems/implement-trie-prefix-tree/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Trie {
public:
    // Children Trie array
    Trie* child[26]{};
    char value;
    bool hyphenation = false;
    void insert(string word) {
        Trie* current = this;
        for (char c : word){
            c -= 'a';   // convert char to position: 0~25
            if (!current->child[c]){
                current->child[c] = new Trie();
            }
            current = current->child[c]; // to next child
        }
        current->hyphenation = true;
    }
    
    bool search(string word) {
        Trie* current = this;        
        for (char c: word){            
            c -= 'a';
            if (!current->child[c]){
                return false;
            }
            current = current->child[c];
            
        }
        if (current->hyphenation == true){
                return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* current = this;
        for (char c:prefix){
            c -= 'a';
            if (!current->child[c]){
                return false;
            }
            current = current->child[c];
        }
        return true;
    }
};



int main(){
    Trie* obj = new Trie();
    obj->insert("z");
    // bool search_result = obj->search("apple");
    // cout << search_result;
    // int abc[5] = {1, 2, 3, 4, 5};
    // char a = 'a';
    // char b = 'b';
    // cout << a-b << "\n";
    // cout << abc[-1] << "\n";
    return 0;
}
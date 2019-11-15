#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#define _rep(i, a, b) for(int i = (a); i < (b); ++i)

using namespace std;
const int MXN = 1e5;

class TrieNode {
public:
  TrieNode* children[26];
  bool hasWord;
  string word;
  int id, num = 0;
  int cnt[MXN];
  TrieNode() {
    _rep(i, 0, 26) children[i] = NULL;
    hasWord = false;
    id = num++;    
    cnt[id] = 0;
  }

  void addWord(char* word, TrieNode* root) {
    TrieNode* p = root;
    //int sz = word.size();
    for(int i = 0; word[i]; ++i) {
      int next = word[i] - 'a';
      // cout << next << endl;    
      if (p->children[next] == NULL) {
        p->children[next] = new TrieNode();      
      }
      p = p->children[next];
      cnt[p->id]++;    
    }
    p->word = word;
    p->hasWord = true;           
  }

  bool query(char* word, TrieNode* root) {
    TrieNode* p = root;
    for (int i = 0; word[i]; ++i) {
      int next = word[i] - 'a';    
      if (p->children[next] == NULL) return false;
      p = p->children[next];    
    }
    return true;    
  }
} trie;

int main() {
  TrieNode* root = new TrieNode();
  //char ch[] = "china";
  trie.addWord("china", root);
  trie.addWord("chinese", root);
  trie.addWord("children", root);
  trie.addWord("check", root);
  cout << trie.query("ch", root) << endl;
  cout << trie.query("chi", root) << endl;
  cout << trie.query("chin", root) << endl;
  cout << trie.query("china", root) << endl;
  cout << trie.query("beijing", root) << endl;
  return 0;
}
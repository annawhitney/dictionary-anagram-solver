#include "cuttable_trie.h"

#include <fstream>
#include <iostream>

CuttableTrie::CuttableTrie() : root(new node()) {};

void CuttableTrie::Insert(const std::string& word) {
  auto cur = root.get();

  // iterate through string inserting nodes
  for (auto i : word) {
    // insert node if doesn't exist
    auto check = cur->children.insert({i, nullptr});

    // if the node was inserted
    if (check.second) {
      // create a new node for that character
      check.first->second.reset(new trie_node());
    }

    // descend to next level of trie
    cur = cur->children[i].get();
  }

  // designate end of word
  cur->end = true;
}

void CuttableTrie::LoadFromFile(const std::string& filename) {
  string line;
  ifstream f (filename);

  if (f.is_open()) {
    while (getline(f, line)) {
      Insert(line);
    }
  }
}

// Restrict trie to subset of letters.
void CuttableTrie::CutIfNotIn(const std::string& letters_to_keep) {
  auto cur = root.get();


}

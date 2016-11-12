#ifndef CUTTABLE_TRIE_H_
#define CUTTABLE_TRIE_H_

#include <unordered_map>
#include <string>

struct node {
  bool end = false;
  std::unordered_map<char, std::unique_ptr<node>> children;
};

class CuttableTrie {
  public:
    void LoadFromFile(const std::string& filename);
    void Insert(const std::string& word);
    void CutIfNotIn(const std::string& letters_to_keep);
    std::string PickAWord(void);
    CuttableTrie();

  private:
    std::unique_ptr<node> root;
};

#endif // CUTTABLE_TRIE_H_

#include <string>
#include <vector>
#include <unordered_map>

class TrieNode {
public:
    bool isWord;
    std::unordered_map<char, TrieNode*> children;
    TrieNode() : isWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }
    ~Trie() { clear(root); }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end())
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isWord = true;
    }

    std::vector<std::string> findCompletions(const std::string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end())
                return std::vector<std::string>();
            node = node->children[c];
        }
        return findWords(node, prefix);
    }

private:
    std::vector<std::string> findWords(TrieNode* node, const std::string& prefix) {
        std::vector<std::string> words;
        if (node->isWord) words.push_back(prefix);
        for (auto& kv : node->children) {
            char c = kv.first;
            TrieNode* child = kv.second;
            std::vector<std::string> childWords = findWords(child, prefix + c);
            words.insert(words.end(), childWords.begin(), childWords.end());
        }
        return words;
    }

    void clear(TrieNode* node) {
        for (auto& kv : node->children)
            clear(kv.second);
        delete node;
    }
};

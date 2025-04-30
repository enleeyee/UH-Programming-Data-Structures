#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <vector>

struct TreeNode {
    std::string symbols;
    int frequency;
    TreeNode *parent, *left, *right;

    TreeNode(std::string let, int fq = 1, TreeNode *par = nullptr, TreeNode *lft = nullptr, TreeNode *rt = nullptr);
};

class Huffman {
private:
    std::vector<TreeNode*> working;
    std::vector<std::string> codes;
    TreeNode* root;

    void buildTable(std::string symbol);
    TreeNode* removeMin();
    void generateCodes(TreeNode* root, std::string encoding);
    void freeTree(TreeNode* node);

public:
    Huffman();
    ~Huffman();

    void buildTree(const std::string& message);
    void printCodes() const;
    std::string encodeMessage(const std::string& message) const;
    std::string decodeMessage(const std::string& encoded) const;
};

#endif

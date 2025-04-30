#include "Huffman.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

TreeNode::TreeNode(std::string let, int fq, TreeNode *par, TreeNode *lft, TreeNode *rt)
    : symbols(let), frequency(fq), parent(par), left(lft), right(rt) {}

Huffman::Huffman() : root(nullptr) {}

Huffman::~Huffman() {
    freeTree(root);
}

void Huffman::freeTree(TreeNode* node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }
}

void Huffman::buildTable(std::string symbol) {
    for (auto& node : working) {
        if (node->symbols == symbol) {
            node->frequency++;
            return;
        }
    }
    working.push_back(new TreeNode(symbol));
}

TreeNode* Huffman::removeMin() {
    int index = 0;
    for (size_t i = 0; i < working.size(); ++i) {
        if ((working[i]->frequency < working[index]->frequency) ||
            (working[i]->frequency == working[index]->frequency && working[i]->symbols < working[index]->symbols)) {
            index = i;
        }
    }
    TreeNode* temp = working[index];
    working.erase(working.begin() + index);
    return temp;
}

void Huffman::generateCodes(TreeNode* node, std::string encoding) {
    if (!node->left) {
        std::stringstream ss;
        ss << "'" << node->symbols << "' " << encoding;
        codes.push_back(ss.str());
        return;
    }
    generateCodes(node->left, encoding + "0");
    generateCodes(node->right, encoding + "1");
}

void Huffman::buildTree(const std::string& message) {
    working.clear();
    codes.clear();
    root = nullptr;

    for (char ch : message) {
        std::string temp(1, toupper(ch));
        buildTable(temp);
    }

    while (working.size() > 1) {
        TreeNode* left = removeMin();
        TreeNode* right = removeMin();
        TreeNode* merged = new TreeNode(left->symbols + right->symbols,
                                        left->frequency + right->frequency,
                                        nullptr, left, right);
        working.push_back(merged);
    }

    root = working[0];
    generateCodes(root, "");
    std::sort(codes.begin(), codes.end());
}

void Huffman::printCodes() const {
    std::cout << "Huffman Code:\n";
    for (const std::string& line : codes) {
        std::cout << line << '\n';
    }
}

std::string Huffman::encodeMessage(const std::string& message) const {
    std::string encoded;

    for (char letter : message) {
        for (const std::string& code : codes) {
            if (toupper(letter) == code[1]) {
                encoded += code.substr(4);
                break;
            }
        }
    }

    return encoded;
}

std::string Huffman::decodeMessage(const std::string& encoded) const {
    std::string decoded;
    TreeNode* current = root;

    for (char bit : encoded) {
        if (!current) break;

        if (bit == '0')
            current = current->left;
        else if (bit == '1')
            current = current->right;

        if (current && !current->left && !current->right) {
            decoded += current->symbols;
            current = root;
        }
    }

    return decoded;
}

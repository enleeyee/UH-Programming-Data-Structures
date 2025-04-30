#include <iostream>
#include "Huffman.h"

int main() {
    std::string message = "This is his message";

    Huffman huff;
    huff.buildTree(message);
    huff.printCodes();
    
    std::string encoded = huff.encodeMessage(message);
    std::cout << "\nEncoded binary: " << encoded << std::endl;

    std::string decoded = huff.decodeMessage(encoded);
    std::cout << "Decoded message: " << decoded << std::endl;

    return 0;
}

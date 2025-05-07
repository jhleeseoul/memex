#include "indexer.hpp"
#include "utils.hpp"
#include "tokenizer.hpp"
#include <iostream>

void buildIndex(const std::string& directory, InvertedIndex& index) {
    std::vector<std::string> files = listTextFiles(directory);

    std::cout << "[+] Found " << files.size() << " files to index.\n";

    for (const std::string& filepath : files) {
        std::string content = readFile(filepath);
        if (content.empty()) {
            std::cerr << "[!] Failed to read: " << filepath << "\n";
            continue;
        }

        std::vector<std::string> tokens = tokenize(content);
        if (tokens.empty()) continue;

        index.addDocument(filepath, tokens);

        std::cout << "  Indexed: " << filepath << " (" << tokens.size() << " tokens)\n";
    }

    std::cout << "[✓] Indexing complete.\n";
}

#include <iostream>
#include <string>

#include "inverted_index.hpp"
#include "indexer.hpp"
#include "query_engine.hpp"

const std::string INDEX_FILE = "index.json";

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage:\n";
        std::cout << "  memex index <directory>\n";
        std::cout << "  memex search \"<query>\"\n";
        return 1;
    }

    std::string command = argv[1];
    InvertedIndex index;

    if (command == "index") {
        std::string directory = argv[2];
        buildIndex(directory, index);
        index.saveToFile(INDEX_FILE);
        std::cout << "[✓] Index built and saved to " << INDEX_FILE << "\n";
    } else if (command == "search") {
        std::cout << "[?] Loading index from " << INDEX_FILE << "...";
        index.loadFromFile(INDEX_FILE);
        std::string query = argv[2];
        searchQuery(query, index);
    } else {
        std::cerr << "[!] Unknown command: " << command << "\n";
        return 1;
    }

    return 0;
}

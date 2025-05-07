#ifndef INDEXER_HPP
#define INDEXER_HPP

#include <string>
#include "inverted_index.hpp"

// 디렉토리를 색인하고 InvertedIndex를 생성
void buildIndex(const std::string& directory, InvertedIndex& index);

#endif // INDEXER_HPP

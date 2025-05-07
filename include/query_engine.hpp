#ifndef QUERY_ENGINE_HPP
#define QUERY_ENGINE_HPP

#include <string>
#include "inverted_index.hpp"

// 사용자 질의를 받아서 상위 문서들을 출력
void searchQuery(const std::string& query, const InvertedIndex& index);

#endif // QUERY_ENGINE_HPP

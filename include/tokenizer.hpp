#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>

// 텍스트 → 토큰 벡터로 분리 (소문자화 + 특수문자 제거 포함)
std::vector<std::string> tokenize(const std::string& text);

// 불용어 제거할 단어 리스트 (선택적으로 확장 가능)
bool isStopWord(const std::string& word);

#endif // TOKENIZER_HPP

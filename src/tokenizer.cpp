#include "tokenizer.hpp"
#include <cctype>
#include <sstream>
#include <unordered_set>
#include <algorithm>

static const std::unordered_set<std::string> stopWords = {
    "the", "is", "at", "on", "in", "and", "or", "of", "a", "to", "an"
};

bool isStopWord(const std::string& word) {
    return stopWords.count(word) > 0;
}

// 문자열 정제: 소문자화 + 특수문자 제거
std::string clean(const std::string& input) {
    std::string result;
    for (char ch : input) {
        if (std::isalnum(ch) || ch == ' ') {
            result += std::tolower(ch);
        } else {
            result += ' ';
        }
    }
    return result;
}

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::string cleaned = clean(text);
    std::istringstream iss(cleaned);
    std::string word;

    while (iss >> word) {
        if (!isStopWord(word) && word.length() >= 2) {
            tokens.push_back(word);
        }
    }
    return tokens;
}

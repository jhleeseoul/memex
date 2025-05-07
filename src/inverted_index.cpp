#include "inverted_index.hpp"
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>  // 헤더만 있는 JSON 라이브러리 사용

using json = nlohmann::json;

void InvertedIndex::saveToFile(const std::string& path) const {
    json j;

    // 색인 저장
    for (const auto& [term, postings] : index) {
        for (const auto& post : postings) {
            j["index"][term].push_back({
                {"filename", post.filename},
                {"termFrequency", post.termFrequency}
            });
        }
    }

    // 문서별 토큰 수 저장
    j["docTokenCounts"] = docTokenCounts;
    j["docFrequencies"] = docFrequencies;

    // 저장
    std::ofstream out(path);
    out << j.dump(2);  // 예쁘게 저장
    out.close();
}

void InvertedIndex::loadFromFile(const std::string& path) {
    std::ifstream in(path);
    if (!in.is_open()) {
        std::cerr << "[!] Failed to load index from " << path << "\n";
        return;
    }

    json j;
    in >> j;

    // 색인 불러오기
    for (auto& [term, postings] : j["index"].items()) {
        for (auto& p : postings) {
            index[term].push_back({
                p["filename"],
                p["termFrequency"]
            });
            docSeen[p["filename"]] = true;
        }
    }

    docTokenCounts = j["docTokenCounts"].get<std::map<std::string, int>>();
    docFrequencies = j["docFrequencies"].get<std::map<std::string, int>>();
}


void InvertedIndex::addDocument(const std::string& filename, const std::vector<std::string>& tokens) {
    std::unordered_map<std::string, int> termFreqs;
    std::unordered_set<std::string> uniqueTerms;

    // 단어별 빈도수 계산
    for (const std::string& token : tokens) {
        termFreqs[token]++;
        uniqueTerms.insert(token);
    }

    // 색인 업데이트
    for (const auto& [term, freq] : termFreqs) {
        index[term].push_back({filename, freq});
    }

    // 문서의 토큰 수 저장 (TF 계산용)
    docTokenCounts[filename] = tokens.size();

    // 각 단어의 문서 등장 횟수 증가 (IDF 계산용)
    for (const auto& term : uniqueTerms) {
        docFrequencies[term]++;
    }

    // 중복 방지용 문서 등록
    docSeen[filename] = true;
}

std::vector<Posting> InvertedIndex::query(const std::string& term) const {
    auto it = index.find(term);
    if (it != index.end()) {
        return it->second;
    } else {
        return {};
    }
}

std::vector<std::string> InvertedIndex::getAllTerms() const {
    std::vector<std::string> terms;
    for (const auto& [term, _] : index) {
        terms.push_back(term);
    }
    return terms;
}

void InvertedIndex::registerDocTokenCount(const std::string& filename, int tokenCount) {
    docTokenCounts[filename] = tokenCount;
}

int InvertedIndex::getDocumentCount() const {
    return docSeen.size();
}

int InvertedIndex::getTokenCount(const std::string& filename) const {
    auto it = docTokenCounts.find(filename);
    if (it != docTokenCounts.end()) {
        return it->second;
    } else {
        return 0;
    }
}

int InvertedIndex::getDocumentFrequency(const std::string& term) const {
    auto it = docFrequencies.find(term);
    if (it != docFrequencies.end()) {
        return it->second;
    } else {
        return 0;
    }
}

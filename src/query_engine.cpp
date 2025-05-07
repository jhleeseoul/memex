#include "query_engine.hpp"
#include "tokenizer.hpp"
#include <unordered_map>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <iomanip>

void searchQuery(const std::string& query, const InvertedIndex& index) {
    std::vector<std::string> queryTerms = tokenize(query);
    if (queryTerms.empty()) {
        std::cout << "[!] No valid keywords found in query.\n";
        return;
    }

    std::unordered_map<std::string, double> docScores;

    int totalDocs = index.getDocumentCount();

    for (const std::string& term : queryTerms) {
        auto postings = index.query(term);
        int df = index.getDocumentFrequency(term);

        if (df == 0) continue;

        double idf = std::log((double)(totalDocs + 1) / (df + 1));  // smooth IDF

        for (const auto& post : postings) {
            int tf = post.termFrequency;
            int docTokenCount = index.getTokenCount(post.filename);
            double tfNorm = (double)tf / docTokenCount;
            double tfidf = tfNorm * idf;

            docScores[post.filename] += tfidf;
        }
    }

    if (docScores.empty()) {
        std::cout << "[!] No matching documents found.\n";
        return;
    }

    // 정렬
    std::vector<std::pair<std::string, double>> rankedResults(docScores.begin(), docScores.end());
    std::sort(rankedResults.begin(), rankedResults.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second;
              });

    // 출력
    std::cout << "\n[🔍] Top results:\n";
    int rank = 1;
    for (const auto& [filename, score] : rankedResults) {
        std::cout << std::setw(2) << rank++ << ". " << filename
                  << "  (score: " << std::fixed << std::setprecision(4) << score << ")\n";
        if (rank > 10) break;
    }
}

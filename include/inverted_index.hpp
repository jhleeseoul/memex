#ifndef INVERTED_INDEX_HPP
#define INVERTED_INDEX_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <map>

// 문서 하나에 대한 정보
struct Posting {
    std::string filename;
    int termFrequency;  // 단어가 해당 문서에 등장한 횟수
};

// Inverted Index 클래스
class InvertedIndex {
public:
    // 단어 추가 (색인 시 호출)
    void addDocument(const std::string& filename, const std::vector<std::string>& tokens);

    // index 파일 저장 & 로드
    void saveToFile(const std::string& path) const;
    void loadFromFile(const std::string& path);


    // 단어 → 문서 목록 질의
    std::vector<Posting> query(const std::string& term) const;

    // 전체 단어 목록 반환
    std::vector<std::string> getAllTerms() const;

    // 특정 문서의 토큰 수 저장 (TF 계산용)
    void registerDocTokenCount(const std::string& filename, int tokenCount);

    // TF-IDF 계산을 위한 보조 데이터
    int getDocumentCount() const;
    int getTokenCount(const std::string& filename) const;
    int getDocumentFrequency(const std::string& term) const;

private:
    std::unordered_map<std::string, std::vector<Posting>> index;
    std::map<std::string, int> docTokenCounts;      // filename → 총 토큰 수
    std::map<std::string, int> docFrequencies;      // term → 등장한 문서 수
    std::unordered_map<std::string, bool> docSeen;  // 중복 방지를 위한 문서 집합
};

#endif // INVERTED_INDEX_HPP

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

// 파일 전체 텍스트 읽기
std::string readFile(const std::string& filepath);

// 지정 디렉토리 아래의 모든 파일 경로 재귀적으로 수집
std::vector<std::string> listTextFiles(const std::string& directory);

// 처리할 파일 확장자 목록 필터
bool isTextFile(const std::string& filename);

#endif // UTILS_HPP

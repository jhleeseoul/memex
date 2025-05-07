#include "utils.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

// 파일에서 텍스트 읽기
std::string readFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) return "";

    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

// 우리가 색인할 텍스트 파일 확장자 목록
static const std::vector<std::string> allowedExtensions = {
    ".txt", ".md", ".cpp", ".h", ".py", ".java"
};

bool isTextFile(const std::string& filename) {
    for (const std::string& ext : allowedExtensions) {
        if (filename.size() >= ext.size() &&
            filename.substr(filename.size() - ext.size()) == ext) {
            return true;
        }
    }
    return false;
}

// 디렉토리 재귀 순회
std::vector<std::string> listTextFiles(const std::string& directory) {
    std::vector<std::string> files;
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            std::string path = entry.path().string();
            if (isTextFile(path)) {
                files.push_back(path);
            }
        }
    }
    return files;
}

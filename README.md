# 🧠 Memex – 나만의 로컬 지식 검색기

> **문서 안 내용까지** 인덱싱해서, **자연어처럼 질의하면 관련 문서를 찾아주는** 로컬 기반 검색기입니다.  
> 오프라인에서 동작하는 **개인 검색 엔진**을 목표로 구현했습니다.

---

## 🚀 기능 요약

- ✅ `.txt`, `.md`, `.cpp`, `.py`, `.java` 등 파일 내용 색인
- ✅ 디렉토리 재귀 순회 후 전체 문서 인덱싱
- ✅ 전처리/불용어 제거된 텍스트 토큰화
- ✅ TF-IDF 기반 유사도 계산으로 정렬된 검색 결과
- ✅ 오프라인 동작 (GPT/인터넷 없이 사용 가능)
- ✅ CLI 기반 사용

---

## 📦 기술 스택

- **언어**: C++17
- **자료구조**: Inverted Index (단어 → 문서 목록)
- **알고리즘**: TF-IDF, Cosine Scoring
- **구성**: 모듈화된 헤더/소스 구조
- **표준 라이브러리**: `<filesystem>`, `<unordered_map>`, `<cmath>` 등

---

## 📁 프로젝트 구조

```
memex/
├── src/                # 핵심 구현 파일
├── include/            # 각 컴포넌트 헤더
├── test/               # 유닛 테스트
├── data/               # 색인 데이터 (선택)
└── README.md
```

---

## ⚙️ 빌드 방법

### 🔧 요구사항

- g++ 9 이상 (C++17 지원)
- Linux 환경 (추천: WSL, Ubuntu)
- CMake 없이도 동작

### 🧪 컴파일 명령어

```bash
g++ -std=c++17 src/*.cpp -o memex
```

### 💡 WSL 설치 & 세팅 가이드

```bash
# WSL 설치
wsl --install

# Ubuntu 진입 후 필수 도구 설치
sudo apt update
sudo apt install g++ make build-essential
```

---

## 🧪 실행 예시

### 인덱싱 (디렉토리 지정)

```bash
./memex index ./notes
```

### 검색

```bash
./memex search "memory leak detection"
```

### 결과 예시

```
[🔍] Top results:
 1. ./notes/cpp_memory.md (score: 0.7234)
 2. ./dev/debug_tips.txt (score: 0.5182)
```

---

## 🧠 구현 동기

GPT 없이도 정보를 똑똑하게 찾을 수 있는 **검색 시스템의 원리**를 직접 체험하는 것이 목적이었습니다.
로컬에서 내가 가진 정보들을 결정론적으로 검색하는 방식을 공부하고 구현하였습니다.

---

## 🏗️ 학습한 내용

- 텍스트 전처리, 불용어 제거, 소문자화 등 NLP 기초
- Inverted Index 구현
- TF-IDF 유사도 기반 질의 엔진 설계
- 모듈 기반 C++ 프로젝트 구조 설계
- CLI 도구 아키텍처 설계 및 구현

---

## ✅ 향후 확장 아이디어

- PDF 파서 추가 (`libpoppler`)
- 색인 저장/불러오기 (`index.json`)
- 임베딩 기반 의미 검색 (OpenAI / BERT 등)
- TUI 또는 GUI 추가 (`ncurses`, `Qt`)

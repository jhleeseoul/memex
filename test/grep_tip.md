# Tips for grep_tip.md
## Useful `grep` Commands

- **Search for a specific string in files:**
    ```bash
    grep "search_term" filename
    ```

- **Recursive search in directories:**
    ```bash
    grep -r "search_term" directory/
    ```

- **Case-insensitive search:**
    ```bash
    grep -i "search_term" filename
    ```

- **Show line numbers with matches:**
    ```bash
    grep -n "search_term" filename
    ```

- **Search for whole words only:**
    ```bash
    grep -w "search_term" filename
    ```

- **Count the number of matches:**
    ```bash
    grep -c "search_term" filename
    ```

- **Invert match (exclude lines with the term):**
    ```bash
    grep -v "search_term" filename
    ```

- **Use regular expressions:**
    ```bash
    grep -E "regex_pattern" filename
    ```
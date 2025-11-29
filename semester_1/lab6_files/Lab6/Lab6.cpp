#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool is_empty(std::ifstream& file) {
    return file.peek() == EOF;
}

bool is_palindrome(const std::string& str, size_t start, size_t end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
std::vector<std::string> readLines(const std::string& filename) {
    std::ifstream input{ filename };

    if (!input.is_open()) {
        throw ("Error! Cannot open file");
    }
    if (is_empty(input)) {
        throw ("File is empty!");
    }
    std::vector<std::string> lines;
    std::string line;
    while (getline(input, line)) {
        lines.push_back(line);
    }
    input.close();
    return lines;
}
std::string findLongestPalindrome(const std::string& line) {
    if (line.empty()) {
        return "";
    }
    size_t max_length = 1;
    size_t start_index = 0;
    size_t n = line.length();
    bool found_palindrome = false;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (j - i + 1 > max_length && is_palindrome(line, i, j)) {
                max_length = j - i + 1;
                start_index = i;
                found_palindrome = true;
            }
        }
    }
        if (!found_palindrome) {
            return "";
        
    }
    return line.substr(start_index, max_length);
}
size_t process_line(const std::string & line) {
    std::string longest_palindrome = findLongestPalindrome(line);
    return longest_palindrome.length();
}

size_t find_max_palindrome_length(const std::vector<std::string>& lines) {
    size_t max = 0;
    for (size_t i = 0; i < lines.size(); ++i) {
        size_t currlength = process_line(lines[i]);
        if (currlength > max) {
           max = currlength;
        }
    }
    return max;
}
std::vector<std::string> find_lines_with_max_palindrome(const std::vector<std::string>& lines, size_t max_length) {
    std::vector<std::string> result;
    size_t count = 0;
    for (size_t i = 0; i < lines.size(); ++i) {
        size_t curr_length = process_line(lines[i]);
        if (curr_length == max_length) {
            if (count >= 10) {
                return result;
            }
            else {
                count++;
                result.push_back(lines[i]);
            }
        }
    }
    return result;
}

void print_result(const std::vector<std::string>& result, const int& max_length) {
     std::cout << "Max palindrome length: " << max_length << '\n';
     std::cout << "Result: " << '\n';
     for (size_t i = 0; i < result.size(); ++i) {
           std::cout << i + 1 << ". " << result[i] << '\n';
     }
}
int main() {
    const std::string filename{ "input.txt" };
    try {
        std::vector<std::string> lines = readLines(filename);
        size_t max_length = find_max_palindrome_length(lines);
        if (max_length == 0) {
            throw ("There are no palindroms!");
        }
        std::vector<std::string> result = find_lines_with_max_palindrome(lines, max_length);
        print_result(result, max_length);
    }
    catch (const char* msg) {
        std::cout << msg << '\n';
    }
    return 0;
}



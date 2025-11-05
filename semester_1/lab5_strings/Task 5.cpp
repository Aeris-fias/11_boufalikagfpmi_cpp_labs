#include <iostream>
#include <string>
#include <cctype>
#include <vector>
 //функция проверки слова на палиндром
bool isPalindrome(const std::string& word) {
	if (word.empty())
		return false;
	int left = 0;
	int right = word.length() - 1;
	while (left < right) {
		if (word[left] != word[right]) {
			return false;
		}
		++left;
		--right;
	}
	return true;
}
//функция извлечения слов
std::vector<std::string> extractWords(const std::string& str) {
	std::vector<std::string> words;
	std::string currentWord;
	for (char c : str) {
		if (std::isalnum(c)) {
			currentWord += c;
		}
		else {
			if (!currentWord.empty()) {
				words.push_back(currentWord);
				currentWord.clear();
			}
		}
	}
	if (!currentWord.empty()) {
		words.push_back(currentWord);
	}
	return words;
}
int main() {
	std::string input;
	std::cout << " Enter the string: \n";
	std::getline(std::cin, input);
	std::vector<std::string> words = extractWords(input);
	std::vector<std::string> palindromes;
	size_t maxLength = 0;
	for (const std::string& word : words) {
		if (isPalindrome(word)) {
			if (word.length() > maxLength) {
				maxLength = word.length();
				palindromes.clear();
				palindromes.push_back(word);
			}
			else if (word.length() == maxLength) {
				palindromes.push_back(word);
			}
		}
	}
	std::string result;
	for (size_t i = 0; i < palindromes.size(); ++i) {
		if (i > 0) {
			result += ", ";
		}
		result += palindromes[i];
	}

	if (result.empty()) {
		std::cout << "There are no palindromes" << std::endl;
	}
	else {
		std::cout << "The longest palindrome(s): " << result << std::endl;
		std::cout << "Lenght: " << maxLength << std::endl;
	}

	return 0;

}



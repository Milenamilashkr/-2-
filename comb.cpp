/* ЗАДАНИЕ 31 Переставить буквы слова «ПАСТУХИ» так, чтобы как гласные, так и согласные шли в алфавитном порядке. */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isValid(const string& s) {
    string vowels = "АИУ";
    string consonants = "ПСТХ";

    string extractedVowels = "";
    string extractedConsonants = "";

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        bool isVowel = false;
        for (int j = 0; j < vowels.length(); ++j) {
            if (c == vowels[j]) {
                isVowel = true;
                break;
            }
        }
        if (isVowel) {
            extractedVowels += c;
        }
        else {
            bool isConsonant = false;
            for (int j = 0; j < consonants.length(); ++j) {
                if (c == consonants[j]) {
                    isConsonant = true;
                    break;
                }
            }
            if (isConsonant) {
                extractedConsonants += c;
            }
        }
    }

    string sortedVowels = extractedVowels;
    string sortedConsonants = extractedConsonants;

    sort(sortedVowels.begin(), sortedVowels.end());
    sort(sortedConsonants.begin(), sortedConsonants.end());
    return (extractedVowels == sortedVowels) && (extractedConsonants == sortedConsonants);
}

int validPermutationCount = 0; 

void generatePermutations(string& word, int k, int* dop, char* p) {
    int n = 7;
    int m = 7;
    if (k == n) {
        string permutation(p, n);
        if (isValid(permutation)) {
            cout << permutation << endl;
            validPermutationCount++; 
        }
        return;
    }

    char letters[] = { 'П', 'А', 'С', 'Т', 'У', 'Х', 'И' };
    for (int y = 0; y < m; ++y) {
        int count = 0;
        for (char c : word) {
            if (c == letters[y]) {
                count++;
            }
        }
        int used = 0;
        for (int i = 0; i < k; i++) {
            if (p[i] == letters[y]) {
                used++;
            }
        }
        if (used < count) {
            p[k] = letters[y];
            generatePermutations(word, k + 1, dop, p);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    string word = "ПАСТУХИ";
    int n = 7;
    char* p = new char[n];
    int dop[7] = { 1, 1, 1, 1, 1, 1, 1 };

    cout << "Слова, в которых гласные и согласные идут в алфавитном порядке:" << endl;

    generatePermutations(word, 0, dop, p);

    cout << "Всего найдено слов: " << validPermutationCount << endl; 

    delete[] p;
    return 0;
}


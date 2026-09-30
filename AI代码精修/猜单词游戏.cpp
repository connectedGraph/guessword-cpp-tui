#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <sstream>  // 用于自定义数字转字符串函数
#include "word_database.cpp"
using namespace std;
string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
    
}
// 打印当前已猜字母状态 __ 
void printCurrentGuess(const vector<char>& currentGuess) {
    for (size_t i = 0; i < currentGuess.size(); ++i) {  
        if (currentGuess[i] == 0)
            cout << '_' << ' ';
        else
            cout << currentGuess[i] << ' ';
    }
    cout << endl;
}

// 将数字转换为对应的英文单词（1-20）
string numberToWord(int number) {
    switch(number) {
        case 1:  return "one";
        case 2:  return "two";
        case 3:  return "three";
        case 4:  return "four";
        case 5:  return "five";
        case 6:  return "six";
        case 7:  return "seven";
        case 8:  return "eight";
        case 9:  return "nine";
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
        case 20: return "twenty";
        default: return intToString(number);  // 用自定义函数替换to_string
    }
}

// 随机索引
int generateRandomIndex(int maxIndex) {
    return rand() % maxIndex;
}

// 验证输入字母是否有效
bool isValidInput(char input) {
    return isalpha(input) != 0;
}

int main() {
    srand(time(NULL));
    cout << "Word Guessing Game\n\n";
    int playAgain;
    
    do {
        int wrongGuesses = 0;
        int randomIndex = generateRandomIndex(4448);
        string targetWord = Eng[randomIndex];
        int wordLength = targetWord.length();
        int maxWrongGuesses;
        int remainingLetters = wordLength;
        
        cout << "The word has " << numberToWord(wordLength) << " letters\n\n";
        cout << "Please enter the maximum number of wrong guesses: ";
        cin >> maxWrongGuesses;
        
        vector<char> currentGuess(wordLength, 0);
        
        while (remainingLetters > 0 && wrongGuesses <= maxWrongGuesses) {
            cout << "\nCurrent guessed letters: ";
            printCurrentGuess(currentGuess);
            
            char userInput;
            do {
                cout << "Please input a letter: ";
                cin >> userInput;
                userInput = tolower(userInput);
                
                if (!isValidInput(userInput)) {
                    cout << "Invalid input! Please enter a letter.\n";
                }
            } while (!isValidInput(userInput));
            
            bool isCorrect = false;
            for (int i = 0; i < wordLength; ++i) {
                if (currentGuess[i] == 0 && tolower(targetWord[i]) == userInput) {
                    currentGuess[i] = targetWord[i];
                    remainingLetters--;
                    isCorrect = true;
                }
            }
            
            if (!isCorrect) {
                wrongGuesses++;
                cout << "Wrong guess! " << (maxWrongGuesses - wrongGuesses) 
                     << " chances left.\n";
            }
            
            system("cls");
        }
        
        if (remainingLetters == 0) {
            cout << "\nCongratulations!! The word is \"" << targetWord << "\"!\n";
            cout << "You made " << wrongGuesses << " wrong guesses!\n\n";
        } else {
            cout << "\nGame Over. The word is \"" << targetWord << "\"!\n\n";
        }
        
        cout << "Its Chinese translation is: " << Ch[randomIndex] << "\n\n";
        cout << "If you want to play again, please enter 1: ";
        cin >> playAgain;
        system("cls");
        
    } while (playAgain == 1);

    return 0;
}


#include <iostream>
#include <map>
#include <string>

std::map<char, int> romanToArabicMap;
std::map<int, std::string> arabicToRomanMap;

void initializeMaps() {
    romanToArabicMap['I'] = 1;
    romanToArabicMap['V'] = 5;
    romanToArabicMap['X'] = 10;
    romanToArabicMap['L'] = 50;
    romanToArabicMap['C'] = 100;
    romanToArabicMap['D'] = 500;
    romanToArabicMap['M'] = 1000;

    arabicToRomanMap[1] = "I";
    arabicToRomanMap[5] = "V";
    arabicToRomanMap[10] = "X";
    arabicToRomanMap[50] = "L";
    arabicToRomanMap[100] = "C";
    arabicToRomanMap[500] = "D";
    arabicToRomanMap[1000] = "M";
}

int convertRomanToArabic(const std::string& romanNumeral) {
    int result = 0;
    int prevValue = 0;

    for (char c : romanNumeral) {
        int currValue = romanToArabicMap[c];
        result += currValue;

        if (prevValue < currValue) {
            result = result - (2 * prevValue);
        }

        prevValue = currValue;
    }

    return result;
}

std::string convertArabicToRoman(int arabicValue) {
    std::map<int, std::string> arabicToRomanMap;
    romanToArabicMap['I'] = 1;
    romanToArabicMap['V'] = 5;
    romanToArabicMap['X'] = 10;
    romanToArabicMap['L'] = 50;
    romanToArabicMap['C'] = 100;
    romanToArabicMap['D'] = 500;
    romanToArabicMap['M'] = 1000;

    int result = 0;
    int current = 0, prev = 0;
std::string number = std::to_string(arabicValue);
    for (int i = 0; i < number.length(); i++) {
        prev = current;
        current = romanToArabicMap[number[i]];
        result += current;
        if (prev < current) {
            result -= 2 * prev;
        }
    }

    std::cout << result;
    return 0;
}

int main() {
    initializeMaps();
    setlocale(LC_ALL, "RUS");

    std::string type, num;
    std::cout << "Введите тип числа (roman или arabic): ";
    std::cin >> type;
    int arabicValue; 

    if (type == "roman") {
        std::cout << "Введите римское число: ";
        std::cin >> num;

        int arabicValue = convertRomanToArabic(num);
        if (arabicValue != 0) {
            std::cout << "Арабское число: " << arabicValue << std::endl;
        } else {
            std::cout << "Неправильное римское число" << std::endl;
        }
    } else if (type == "arabic") {
        std::cout << "Введите арабское число: ";
        std::cin >> arabicValue;

       std::string romanNumeral = convertArabicToRoman(arabicValue);
        std::cout << "Римское число: " << romanNumeral << std::endl;
    } else {
        std::cout << "Неверный ввод, используйте арабский или римский" << std::endl;
        return 1;
    }
    return 0;
}

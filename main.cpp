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

    arabicToRomanMap[1000] = "M";
    arabicToRomanMap[900] = "CM";
    arabicToRomanMap[500] = "D";
    arabicToRomanMap[400] = "CD";
    arabicToRomanMap[100] = "C";
    arabicToRomanMap[90] = "XC";
    arabicToRomanMap[50] = "L";
    arabicToRomanMap[40] = "XL";
    arabicToRomanMap[10] = "X";
    arabicToRomanMap[9] = "IX";
    arabicToRomanMap[5] = "V";
    arabicToRomanMap[4] = "IV";
    arabicToRomanMap[1] = "I";
}

// 529 % 10 == 9 IX iter 1 53 % 10 2 50 - 30 = 20 != 10 XXX 5 % 10 = 5 3 5 * 10 * 10 D DXXX map[iter] - map[iter - 2] > map[iter - 2] == map[iter - 2] n раз 

int convertRomanToArabic(const std::string& romanNumeral) {
    int result = 0;
    int prevValue = 0;

    for (char c : romanNumeral) {
        int currValue = romanToArabicMap[c];

        if (prevValue < currValue) {
            result -= 2 * prevValue;
        }

        result += currValue;
        prevValue = currValue;
    }

    return result;
}

std::string convertArabicToRoman(int arabicValue) {
    std::string romanNumeral;

    for (auto it = arabicToRomanMap.rbegin(); it != arabicToRomanMap.rend(); ++it) {
        while (arabicValue >= it->first) {
            romanNumeral += it->second;
            arabicValue -= it->first;
        }
    }

    return romanNumeral;
}

int main() {
    initializeMaps();
    setlocale(LC_ALL, "RUS");

    std::string type, num;
    std::cout << "Введите числа (roman или arabic): ";
    std::cin >> type;
    int arabicValue;

    if (type == "roman") {
        std::cout << "Введите римское число: ";
        std::cin >> num;

        int arabicValue = convertRomanToArabic(num);
        if (arabicValue != 0) {
            std::cout << "Арабское число: " << arabicValue << std::endl;
        }
        else {
            std::cout << "Неправильное римское число" << std::endl;
        }
    }
    else if (type == "arabic") {
        std::cout << "Введите арабское число: ";
        std::cin >> arabicValue;

        std::string romanNumeral = convertArabicToRoman(arabicValue);
        std::cout << "Римское число: " << romanNumeral << std::endl;
    }
    else {
        std::cout << "Неверный ввод, используйте арабский или римский" << std::endl;
        return 1;
    }
    return 0;
}

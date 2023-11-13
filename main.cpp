#include <iostream>
#include <map>
#include <string>

std::map<std::string, int> romanToArabicMap;
std::map<int, std::string> arabicToRomanMap;

void initializeMaps()
{
    std::string romanNumerals[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X" };
    int arabicNumerals[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int i = 0; i < 10; ++i)
{
    romanToArabicMap[romanNumerals[i]] = arabicNumerals[i];
    arabicToRomanMap[arabicNumerals[i]] = romanNumerals[i];
}
}

int convertRomanToArabic(const std::string& romanNumeral)
{
    auto it = romanToArabicMap.find(romanNumeral);
    if (it != romanToArabicMap.end())
{
    return it->second;
}

    std::cerr << "неправильное римское число" << std::endl;
    return -1;
}

std::string convertArabicToRoman(int arabicNumeral)
{
    auto it = arabicToRomanMap.find(arabicNumeral);
    if (it != arabicToRomanMap.end())
{
    return it->second;
}

    std::cerr << "неправильное арабское число" << arabicNumeral << std::endl;
    return "";
}

int main()
{
    initializeMaps();
    setlocale(LC_ALL, "RUS");
    std::string type, num;
    std::cout << "введите ваше число (roman или arabic): ";
    std::cin >> type;

if (type[0] == 'r')
{
    std::cout << "введите римское число: ";
    std::cin >> num;

    int arabicValue = convertRomanToArabic(num);
if (arabicValue != -1)
{
            std::cout << "арабское число: " << arabicValue << std::endl;
}
}
else if (type[0] == 'a')
{
    int arabicValue;
    std::cout << "введите арабское число: ";
    std::cin >> arabicValue;

    std::string romanNumeral = convertArabicToRoman(arabicValue);
    if (!romanNumeral.empty())
{
            std::cout << "римское число: " << romanNumeral << std::endl;
}
}
else
{
    std::cerr << "неверный ввод, используйте арабский или римский" << std::endl;
    return 1;
}

    return 0;
}

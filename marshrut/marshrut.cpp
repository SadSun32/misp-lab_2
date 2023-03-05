#include "marshrut.h"
#include <algorithm>
#include <iostream>
using namespace std;
marshrut::marshrut(int key)
{
    marshrut::key = key;
}
string marshrut::transform(string stroka)
{
    stroka = getValidText(stroka);
    string temp;
    string final;
    while (!(stroka.empty())) {
        for (int i = 0; i < key; i++) {
            if (!(stroka.empty())) {
                temp.push_back(stroka[0]);
                stroka.erase(0, 1);
            }
        }
        reverse(temp.begin(), temp.end());
        final += temp;
        temp = "";
    }
    return final;
    return 0;
}
string marshrut::getValidText(string stroka)
{
    string alphaUpper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string alphaLower = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    string temp;
    string temp2;
    if (stroka.empty())
        throw cipher_error("Пустая строка");
    for (auto c:stroka)
        if (alphaUpper.find(c) != string::npos || alphaLower.find(c) !=
            string::npos)
            temp.push_back(c);
    if (temp.empty())
        throw cipher_error("Пустая строка");
    for (auto c:temp) {
        if (alphaLower.find(c) != string::npos)
            temp2.push_back(alphaUpper[alphaLower.find(c)]);
        if (alphaUpper.find(c) != string::npos)
            temp2.push_back(c);
    }
    return temp2;
}

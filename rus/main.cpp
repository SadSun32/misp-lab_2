#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include "Windows.h"
using namespace std;
int main(int argc, char **argv)
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 string key;
 string text;
 unsigned op;
 cout<<"Шифровщик готов. Введите ключ: ";
 cin>>key;
 // if (!isValid(key)) {
 // cerr<<"ключ неверен\n";
 // return 1;
 // }
 // cout<<"Ключ загружен\n";
 try {
 modAlphaCipher cipher(key);
 do {
 cout<<"Шифровщик готов. Введите операцию (0-выход, 1-
зашифровать, 2-расшифровать): ";
 cin>>op;
 if (op > 2) {
 cout<<"Неверная операция\n";
 } else if (op >0) {
 cout<<"Шифровщик готов. Введите текст: ";
 cin>>text;
 // if (isValid(text)) {
 if (op==1) {
 cout<<"Зашифрованный текст:
"<<cipher.encrypt(text)<<endl;
 } else {
 cout<<"Расшифрованный текст:
"<<cipher.decrypt(text)<<endl;
 }
 // } else {
 // cout<<"Операция отклонена: некорректный текст\n";
 // }
 }
 } while (op!=0);
 } catch(const cipher_error& e) {
 cerr << "Ошибка: " << e.what() << endl;
 exit(EXIT_FAILURE);
 }
 return 0;
}

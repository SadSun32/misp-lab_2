#pragma once
#include <string>
#include <stdexcept>
using namespace std;
class marshrut
{
private:
    int key;
    string getValidText(string stroka);
public:
    marshrut()=delete;
    marshrut(int key);
    string transform(string stroka);
};
class cipher_error: public invalid_argument
{
public:
    explicit cipher_error (const string& what_arg):
        invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        invalid_argument(what_arg) {}
};

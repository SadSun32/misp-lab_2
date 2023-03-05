#include "modAlphaCipher.h"
modAlphaCipher::modAlphaCipher(const std::string& skey)
{
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(getValidKey(skey));
}
std::string modAlphaCipher::encrypt(const std::string& open_text)
{
    std::vector<int> work = convert(getValidOpenText(open_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
std::string modAlphaCipher::decrypt(const std::string& cipher_text)
{
    std::vector<int> work = convert(getValidCipherText(cipher_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) %
                  alphaNum.size();
    }
    return convert(work);
}
inline std::vector<int> modAlphaCipher::convert(const std::string& s)
{
    std::vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline std::string modAlphaCipher::convert(const std::vector<int>& v)
{
    std::string result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
std::string modAlphaCipher::getValidKey(const std::string& s)
{
    std::string alphaUpper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::string alphaLower = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    if (s.empty())
        throw cipher_error("Пустой ключ");
    std::string tmp(s);
    for (auto& c:tmp) {
        if (alphaUpper.find(c) == std::string::npos &&
            alphaLower.find(c) == std::string::npos)
            throw cipher_error("Неверный ключ");
        if (alphaLower.find(c) != std::string::npos)
            c = alphaUpper[alphaLower.find(c)];
    }
    return tmp;
}
inline std::string modAlphaCipher::getValidOpenText(const std::string&
        open_text)
{
    std::string alphaUpper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::string alphaLower = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    std::string tmp;
    for (auto c:open_text) {
        if (alphaUpper.find(c) != std::string::npos ||
            alphaLower.find(c) != std::string::npos) {
            if (alphaLower.find(c) != std::string::npos)
                tmp.push_back(alphaUpper[alphaLower.find(c)]);
            else
                tmp.push_back(c);
        }
    }
    if (tmp.empty())
        throw cipher_error("Пустой текст");
    return tmp;
}
inline std::string modAlphaCipher::getValidCipherText(const std::string&
        cipher_text)
{
    std::string alphaUpper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::string alphaLower = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    std::string tmp;
    for (auto c:cipher_text) {
        if (alphaUpper.find(c) != std::string::npos ||
            alphaLower.find(c) != std::string::npos) {
            if (alphaLower.find(c) != std::string::npos)
                tmp.push_back(alphaUpper[alphaLower.find(c)]);
            else
                tmp.push_back(c);
        }
    }
    if (tmp.empty())
        throw cipher_error("Пустой текст");
    return tmp;
}

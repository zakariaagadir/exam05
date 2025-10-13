#include "bigint.hpp"



std::string addition(const bigint& obj1, const bigint& obj2)
{
    std::string str1 = reverse(obj1.getStr());
    std::string str2 = reverse(obj2.getStr());
    std::string result;
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    if (len1 > len2)
    {
        int deff = len1 - len2;
        while (deff > 0)
        {
            str2.push_back('0');
            deff--;
        }
    } else if (len2 > len1)
    {
        int deff = len2 - len1;
        while (deff > 0)
        {
            str1.push_back('0');
            deff--;
        }
    }
    int digit1;
    int digit2;
    int buffer = 0;
    size_t len = str1.length();
    for(size_t i = 0; i < len; i++)
    {
        int res = str1[i] + str2[i] + buffer - '0';
        if (res > 9)
        {
            buffer = res/10;
            result.push_back((res%10) + '0');
        } else
        {
            buffer = 0;
            result.push_back((res%10) + '0');
        }
    }
    if (buffer !=0)
    {
            result.push_back(buffer + '0');
            buffer = 0;
    }
    return (reverse(result));
}

bigint& bigint::operator=(const operator& other)
{
    if (this != &other)
    {
        this->str = other.getStr();

    }
    return (*this);
}
std::string reverse(const std::string& str)
{
    std::string revStr;
    for (size_t i = str.length(); i > 0; i--)
    {
        revStr.push_back(str[i-1]);
    }
    return (revStr);
}


bigint bigint::operator+(const bigint& other)
{
    bigint buffer;
    buffer.str = addition (this->str, other.str);
    return (buffer);
}


bigint bigint::operator<<(unsigned int n) const
{
    bigint temp = *this;
    temp->str.insert(temp.str.end(), n, '0');
    return (temp);
}



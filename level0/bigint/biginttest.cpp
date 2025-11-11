#include "biginttest.hpp"


bigint::bigint()
{
    this->str = "0";
}
bigint::bigint(unsigned int other)
{
    std::stringstream ss;
    ss << other;
    str = ss.str();
}
bigint::bigint(const std::string& other)
{
    str= other;
}
bigint& bigint::operator=(const bigint& other)
{
    if (this != & other)
    {
        str = other.str;
    }
    return(*this);
}
bigint::~bigint()
{

}

std::string bigint::getString()
{
    return(str);
}


std::string revers(std::string other)
{
    if (other.empty())
        return(other);
    std::string reversed;
    for(int i = (other.length() - 1); i >= 0; i-- )
    {
        reversed.push_back(other[i]);
    }
    return(reversed);
}

std::string addition(bigint obj1, bigint obj2)
{
    std::string str1 = revers(obj1.getString());
    std::string str2 = revers(obj2.getString());
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    if(len1 > len2)
    {
        int diff = len1 - len2;
        while(diff > 0)
        {
            str2.push_back('0');
            diff--;
        }
    } else if(len2 > len1)
    {
        int diff = len2 - len1;
        while(diff > 0)
        {
            str1.push_back('0');
            diff--;
        }
    }
    int carry = 0;
    int digit1;
    int digit2;
    std::string result;
    size_t len = str1.length();
    for(size_t i = 0; i < len; i++)
    {
        digit1 = str1[i] - '0';
        digit2 = str2[i] - '0';
        int add = digit1 + digit2 + carry;
        if (add > 9)
        {
            carry = add / 10;
            result.push_back((add%10) + '0');
        } else{
            carry = 0;
            result.push_back((add%10) + '0');
        }
    }
    if (carry!=0)
    {
        result.push_back((carry%10) + '0');
        carry = 0;
    }
    return (revers(result));
}

bigint bigint::operator+(const bigint& other) const
{
    bigint test;
    test.str = addition(*this, other);
    return(test);
}
bigint& bigint::operator+=(const bigint& other)
{
    str = addition(*this, other);
    return(*this);
}
bigint& bigint::operator++()
{
    bigint test(1);
    str = addition(*this, test);
    return(*this);
}

bigint bigint::operator++(int)
{
    bigint test(1);
    bigint test1;
    test1 = *this;
    str = addition(*this, test);
    return(test1);
}

bigint bigint::operator<<(unsigned int other)
{
    str.erase(str.length()- other, other);
    return(*this);
}

unsigned int toUnsigned(std::string other)
{
    unsigned int test;
    std::stringstream ss(other);
    ss >> test;
    return(test);
}

bigint bigint::operator<<(const bigint& other)
{
    unsigned int other1 = toUnsigned(other.str);
    str.erase(str.length()- other1, other1);
    return(*this);
}
bigint& bigint::operator<<=(unsigned int other)
{
    str.erase(str.length()- other, other);
    return(*this);
}
bigint& bigint::operator>>=(unsigned int other)
{
    str.insert(str.end(), other , '0');
    return(*this);
}

bigint& bigint::operator>>=(const bigint& other)
{
    unsigned int other1 = toUnsigned(other.str);
    str.insert(str.end(), other1 , '0');
    return(*this);
}

bool bigint::operator<(const bigint& other) const
{
    if (str.length() < other.str.length())
        return(true);
    else if (str.length() > other.str.length())
        return(false);
    for(size_t i = 0; i < str.length(); i++)
    {
        if (str[i] < other.str[i])
            return(true);
        else if (str[i] > other.str[i])
            return(false);
    }
    return (false);
}
bool bigint::operator>(const bigint& other) const
{
    if (str.length() > other.str.length())
        return(true);
    else if (str.length() < other.str.length())
        return(false);
    for(size_t i = 0; i < str.length(); i++)
    {
        if (str[i] > other.str[i])
            return(true);
        else if (str[i] < other.str[i])
            return(false);
    }
    return (false);
}
bool bigint::operator==(const bigint& other) const
{
    if (str.length() != other.str.length())
        return(false);

    for(size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != other.str[i])
            return(false);
    }
    return (true);
}
bool bigint::operator!=(const bigint& other) const
{
    return (!(*this == other));
}
bool bigint::operator<=(const bigint& other) const
{
    if (str.length() < other.str.length())
        return(true);
    else if (str.length() > other.str.length())
        return(false);
    for(size_t i = 0; i < str.length(); i++)
    {
        if (str[i] < other.str[i])
            return(true);
        else if (str[i] > other.str[i])
            return(false);
    }
    return (true);
}
bool bigint::operator>=(const bigint& other) const
{
    if (str.length() > other.str.length())
        return(true);
    else if (str.length() < other.str.length())
        return(false);
    for(size_t i = 0; i < str.length(); i++)
    {
        if (str[i] > other.str[i])
            return(true);
        else if (str[i] < other.str[i])
            return(false);
    }
    return (true);
}


std::ostream& operator<<(std::ostream &os,  bigint other)
{
    os << other.getString();
    return (os);
}
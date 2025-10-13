#ifndef BIGINT
#define BIGINT

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>


class bigint
{
    private:
        std::string str;
    public:
        bigint();
        bigint(unsigned int num);
        bigint(const bigint& source);
        std::string getStr()const;
        bigint& operator=(const bigint & source);
        bigint operator+(const bigint & source);
        bigint& operator+=(const bigint & source);
        bigint& operator++();
        bigint operator++(int);
        //chift withe num
        bigint operator<<(unsigned int n) const;
        bigint operator>>(unsigned int n) const;
        bigint& operator>>=(unsigned int n);
        bigint& operator>>=(unsigned int n);
        //shift withe object
        bigint operator<<(const bigint& other) const; 
        bigint operator>>(const bigint& other) const; 
        bigint& operator<<=(const bigint& other); 
        bigint& operator>>=(const bigint& other); 

        // ==, !=, <, >, <=, >=
        bool operator==(const bigint& nother) const;
        bool operator!=(const bigint& nother) const;
        bool operator<(const bigint& nother) const;
        bool operator>(const bigint& nother) const;
        bool operator<=(const bigint& nother) const;
        bool operator>=(const bigint& nother) const;
        //~bigint

};

std::ostream& operator<<(std::ostream output, const bigint& obj);
#endif














#endif

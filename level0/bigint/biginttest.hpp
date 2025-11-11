#pragma once 
#include <iostream>
#include <string>
#include <sstream>

class bigint {
    private:
        std::string str;
    public:
        bigint();
        bigint(const unsigned int other);
        bigint(const std::string& other);
        bigint& operator=(const bigint& other);
        ~bigint();
        
        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);
        bigint& operator++();
        bigint operator++(int);
        ///
        bigint operator<<(unsigned int other);
        bigint operator<<(const bigint& other);
        bigint& operator<<=(unsigned int other);
        bigint& operator>>=(unsigned int other);
        bigint& operator>>=(const bigint& other);
        //////
        bool operator<(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        std::string getString();


};


std::ostream& operator<<(std::ostream &os, bigint other);



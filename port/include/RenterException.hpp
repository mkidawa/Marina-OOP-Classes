//
// Created by pobi on 17.01.19.
//

#ifndef POBIMARINA_RENTEREXCEPTION_HPP
#define POBIMARINA_RENTEREXCEPTION_HPP


#include <iostream>

class RenterException: public std::logic_error{
public:
    RenterException(std::string s);
};


#endif //POBIMARINA_RENTEREXCEPTION_HPP

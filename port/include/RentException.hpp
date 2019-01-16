//
// Created by pobi on 16.01.19.
//

#ifndef POBIMARINA_RENTEXCEPTION_HPP
#define POBIMARINA_RENTEXCEPTION_HPP

#include <iostream>

class RentException: public std::logic_error{
public:
    RentException(std::string s);
};


#endif //POBIMARINA_RENTEXCEPTION_HPP

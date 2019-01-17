//
// Created by pobi on 16.01.19.
//

#include <iostream>
#include "RentException.hpp"

using namespace std;

RentException::RentException(string s):
        logic_error(s)
{}
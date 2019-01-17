//
// Created by pobi on 17.01.19.
//

#include <iostream>
#include "RenterException.hpp"

using namespace std;

RenterException::RenterException(string s):
        logic_error(s)
{}
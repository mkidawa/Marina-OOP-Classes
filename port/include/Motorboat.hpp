//
// Created by pobi on 11.01.19.
//

#ifndef PORT_MOTORBOAT_HPP
#define PORT_MOTORBOAT_HPP

#include "RenterType.hpp"

class Motorboat : public RenterType {
    double length; //dystynktywna cecha dla motorówek - długość kadłuba
public:
    Motorboat(int crew, double factor, double length);
    virtual ~Motorboat();
    double realPrice();
    double getLength() const;

};


#endif //PORT_MOTORBOAT_HPP

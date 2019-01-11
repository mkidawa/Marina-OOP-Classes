//
// Created by pobi on 11.01.19.
//

#include "Motorboat.hpp"

Motorboat::Motorboat(int crew, double factor, double length) : RenterType(crew, factor), length(length) {}

Motorboat::~Motorboat() {

}

double Motorboat::getLength() const {
    return length;
}

double Motorboat::realPrice() {
    return(30+((getCrew()*10)+(getLength()*10))*getFactor()); //bazowa cena (30) + (załoga *10 zł + dlugosc*10)*tajemniczy factor
}
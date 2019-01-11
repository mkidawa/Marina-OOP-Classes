//
// Created by pobi on 11.01.19.
//

#include "Yacht.hpp"

Yacht::Yacht(int crew, double factor, int mast) : RenterType(crew, factor), mast(mast) {}

Yacht::~Yacht() {}

int Yacht::getMast() const {
    return mast;
}

double Yacht::realPrice() {
    return(30+((getCrew()*10)+(getMast()*7.5))*getFactor()); //bazowa cena (30) + (załoga *10 zł + maszty*7.5)*tajemniczy factor
}

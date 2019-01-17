//
// Created by pobi on 11.01.19.
//

#ifndef PORT_YACHT_HPP
#define PORT_YACHT_HPP

#include <memory>
#include "RenterType.hpp"

class Yacht : public RenterType {
    int mast; //dystynktywna cecha dla jachtów - ilość masztów
public:
    Yacht(int crew, double factor, int mast);
    Yacht();
    virtual ~Yacht();
    double realPrice();
    int getMast() const;
};
typedef std::shared_ptr<Yacht>Yacht_ptr;

#endif //PORT_YACHT_HPP

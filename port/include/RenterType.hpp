//
// Created by pobi on 11.01.19.
//

#ifndef PORT_RENTERTYPE_HPP
#define PORT_RENTERTYPE_HPP


class RenterType {
    int crew;
    double factor;
public:
    virtual ~RenterType() {};
    RenterType(int crew, double factor) : crew(crew), factor(factor) {};
    virtual double realPrice()=0;

    int getCrew() const {
        return crew;
    }

    double getFactor() const {
        return factor;
    }

};


#endif //PORT_RENTERTYPE_HPP

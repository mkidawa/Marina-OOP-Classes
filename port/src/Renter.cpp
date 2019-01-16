//
// Created by pobi on 15.01.19.
//

#include <iostream>
#include <boost/uuid/random_generator.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "Renter.hpp"
#include "RenterType.hpp"
#include "Yacht.hpp"
#include "Motorboat.hpp"

using namespace std;

Renter::Renter(string name, string country):
        name(name),
        country(country){
        UUID = boost::uuids::random_generator()();
        innerRenter = nullptr;
        }

Renter::Renter(std::string name, std::string country, RenterType_ptr R):
        name(name),
        country(country){
        UUID = boost::uuids::random_generator()();
        innerRenter = R;
}

Renter::Renter(){
    UUID = boost::uuids::random_generator()();
}

Renter::Renter(const Renter& R):
        name(R.name),
        country(R.country),
        innerRenter(R.innerRenter){
        UUID = boost::uuids::random_generator()();
}

double Renter::get_realPrice(){
    return innerRenter->realPrice();
}

std::string Renter::get_info(){
    stringstream info;
    info << name + ' ' + country;
    return info.str();
}

boost::uuids::uuid Renter::getUUID(){
    return UUID;
}

void Renter::operator=(const Renter& R){
    name = R.name;
    country = R.country;
    innerRenter = R.innerRenter;
}

const string &Renter::getName() const {
    return name;
}

const string &Renter::getCountry() const {
    return country;
}

Renter::~Renter(){
}

const RenterType_ptr &Renter::getInnerRenter() const {
    return innerRenter;
}

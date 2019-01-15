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

using namespace std;

Renter::Renter(string name, string country):
        name(name),
        country(country){
        UUID = boost::uuids::random_generator()();
        innerRenter = RenterType_ptr(new Yacht());
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

boost::uuids::uuid Renter::get_uuid(){
    return UUID;
}

void Renter::operator=(const Renter& R){
    name = R.name;
    country = R.country;
    innerRenter = R.innerRenter;
}

string Renter::get_name(){
    return name;
}

string Renter::get_country(){
    return country;
}

Renter::~Renter(){
}


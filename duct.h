//
// Created by garvet on 15.04.18.
//

#ifndef COAT_OF_ARMS_DUCT_H
#define COAT_OF_ARMS_DUCT_H

#include <iostream>
#include <vector>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

class Duct {
    std::vector<std::string> list;
public:
    Duct() = delete;
    Duct(std::string file_name);
    ~Duct() = default;
    friend std::ostream &operator<<(std::ostream &os, const Duct &duct);
    unsigned long get_size() const;
    std::string get_value(int number) const;
};

#endif //COAT_OF_ARMS_DUCT_H

//
// Created by garvet on 15.04.18.
//

#include "duct.h"

Duct::Duct(std::string file_name) {
    std::ifstream file(file_name);
    if (!file) {
        std::cerr << "Невозможно открыть файл: \"" << file_name << "\"" << std::endl;
    }
    else if (this == nullptr) {
        std::cerr << "Операция невозможна, отсутствует объект.\n" << std::endl;
    }
    else {
        boost::property_tree::ptree duct_tree;
        boost::property_tree::read_xml(file_name, duct_tree);
        for (boost::property_tree::ptree::value_type &iterator : duct_tree) {
            std::string str = duct_tree.get<std::string>(iterator.first, "");
            if (!str.empty())
                list.push_back(str);
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Duct &duct) {
    for (int i = 0; i < duct.list.size(); i++) {
        os << i+1 << "." << duct.list[i] << std::endl;
    }
    return os;
}

unsigned long Duct::get_size() const {
    return list.size();
}

std::string Duct::get_value(int number) const {
    if ((number >= 0) && (number < list.size()))
        return list[number];
    std::cerr << "Индекс за пределом массива\n" << std::endl;
    return "";
}

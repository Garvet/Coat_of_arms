//
// Created by garvet on 10.04.18.
//

#ifndef COAT_OF_ARMS_BLAZON_H
#define COAT_OF_ARMS_BLAZON_H

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <fstream>

class Blazon_builder;
class Blazon {
    std::string name;
    unsigned int color;
    int motto;
    int shape_shield;
    int left_shield_holder;
    int right_shield_holder;
    int ground;
    int order;
    int crown;
public:
    Blazon();
    ~Blazon() = default;
    Blazon &operator=(const Blazon &blazon);
    void save ();
    void load (std::string file_name);
    friend std::ostream &operator<<(std::ostream &os, const Blazon &blazon);

    void setName(const std::string &name);
    void setColor(unsigned int color);
    void setMotto(int motto);
    void setShape_shield(int shape_shield);
    void setLeft_shield_holder(int left_shield_holder);
    void setRight_shield_holder(int right_shield_holder);
    void setGround(int ground);
    void setOrder(int order);
    void setCrown(int crown);

    const std::string &getName() const;
    unsigned int getColor() const;
    int getMotto() const;
    int getShape_shield() const;
    int getLeft_shield_holder() const;
    int getRight_shield_holder() const;
    int getGround() const;
    int getOrder() const;
    int getCrown() const;

};
#include "blazon_builder.h"

#endif //COAT_OF_ARMS_BLAZON_H

//
// Created by garvet on 18.04.18.
//

#ifndef COAT_OF_ARMS_BLAZON_BUILDER_H
#define COAT_OF_ARMS_BLAZON_BUILDER_H

#include "blazon.h"
#include "duct.h"

static Duct duct_motto("motto.xml");
static Duct duct_shape_shield("shape_shield.xml");
static Duct duct_shield_holder("shield_holder.xml");
static Duct duct_ground("ground.xml");
static Duct duct_order("order.xml");
static Duct duct_crown("crown.xml");

class Blazon_builder {
    std::unique_ptr<Blazon> blazon;
    int option_duct(std::string type, const Duct &duct);
public:
    Blazon_builder();
    ~Blazon_builder() = default;

    Blazon_builder& name();
    Blazon_builder& color();
    Blazon_builder& motto();
    Blazon_builder& shape_shield();
    Blazon_builder& left_shield_holder();
    Blazon_builder& right_shield_holder();
    Blazon_builder& ground();
    Blazon_builder& order();
    Blazon_builder& crown();

    void output(Blazon &blazon);
};

#endif //COAT_OF_ARMS_BLAZON_BUILDER_H

//
// Created by garvet on 18.04.18.
//

#include "blazon.h"

Blazon::Blazon(): name(""), color(0), motto(-1), shape_shield(0), left_shield_holder(-1),
                  right_shield_holder(-1), ground(-1), order(-1), crown(-1) {}

Blazon &Blazon::operator=(const Blazon &blazon) {
    name=blazon.name;
    color=blazon.color;
    motto=blazon.motto;
    shape_shield=blazon.shape_shield;
    left_shield_holder=blazon.left_shield_holder;
    right_shield_holder=blazon.right_shield_holder;
    ground=blazon.ground;
    order=blazon.order;
    crown=blazon.crown;
    return *this;
}

void Blazon::save() {
    if (this == nullptr) {
        std::cerr << "Операция невозможна, отсутствует объект.\n" << std::endl;
        return;
    }
    if (name.empty()) {
        std::cerr << "Ошибка записи: объект повреждён, отсутствует имя";
        return;
    }
    boost::property_tree::ptree blazon_tree;

    blazon_tree.put("blazon", "");
    blazon_tree.put("blazon.name", name);
    blazon_tree.put("blazon.color", color);
    blazon_tree.put("blazon.motto", motto);
    blazon_tree.put("blazon.shape_shield", shape_shield);
    blazon_tree.put("blazon.left_shield_holder", left_shield_holder);
    blazon_tree.put("blazon.right_shield_holder", right_shield_holder);
    blazon_tree.put("blazon.ground", ground);
    blazon_tree.put("blazon.order", order);
    blazon_tree.put("blazon.crown", crown);
    boost::property_tree::write_xml((name + ".xml"), blazon_tree);
}

void Blazon::load(std::string file_name) {
    std::ifstream file(file_name);
    if (!file) {
        std::cerr << "Невозможно открыть файл: \"" << file_name << "\".\n" << std::endl;
        return;
    }
    if (this == nullptr) {
        std::cerr << "Операция невозможна, отсутствует объект.\n" << std::endl;
        return;
    }
    boost::property_tree::ptree blazon_tree;
    boost::property_tree::read_xml(file_name, blazon_tree);
    boost::property_tree::ptree::value_type &tree = blazon_tree.front();
    if(tree.first == "blazon") {
        name = blazon_tree.get<std::string>("blazon.name", "");
        color = blazon_tree.get<unsigned int>("blazon.color", 0xFFFF);
        motto = blazon_tree.get<int>("blazon.motto", -1);
        shape_shield = blazon_tree.get<int>("blazon.shape_shield", -1);
        left_shield_holder = blazon_tree.get<int>("blazon.left_shield_holder", -1);
        right_shield_holder = blazon_tree.get<int>("blazon.right_shield_holder", -1);
        ground = blazon_tree.get<int>("blazon.ground", -1);
        order = blazon_tree.get<int>("blazon.order", -1);
        crown = blazon_tree.get<int>("blazon.crown", -1);
    }
    if((name.empty()) || (color == 0xFFFF) || (motto == -1) || (shape_shield == -1) || (left_shield_holder == -1)
       || (right_shield_holder == -1) || (ground == -1) || (order == -1) || (crown == -1)) {
            std::cerr << "Операция невозможна, файл не полный / повреждён.\n" << std::endl;
            return;
    }
}

std::ostream &operator<<(std::ostream &os, const Blazon &blazon) {
    if (&blazon == nullptr) {
        std::cerr << "Операция невозможна, отсутствует объект.\n" << std::endl;
        return os;
    }
    if (blazon.name.empty()) {
        std::cerr << "Ошибка записи: объект повреждён, отсутствует имя";
        return os;
    }

    os << "Название: " << blazon.name << std::endl;
    os << "Состав цвета: \n\tКрасный: " << ((blazon.color & 0xFF0000) >> 16)
       << "\n\tЗалёный: " << ((blazon.color & 0x00FF00) >> 8)
       <<"\n\tСиний:   " << (blazon.color & 0x0000FF) << std::endl;
    if (blazon.motto != -1)
        os << "Девиз: \"" << duct_motto.get_value(blazon.motto) << "\"" << std::endl;
    os << "Щит - " << duct_shape_shield.get_value(blazon.shape_shield) << std::endl;
    if (blazon.left_shield_holder != -1)
        os << "Слева щит держит " << duct_shield_holder.get_value(blazon.left_shield_holder) << std::endl;
    if (blazon.right_shield_holder != -1)
        os << "Справа щит держит " << duct_shield_holder.get_value(blazon.right_shield_holder) << std::endl;
    if (blazon.ground != -1)
        os << duct_ground.get_value(blazon.ground) << " - почва для герба" << std::endl;
    if (blazon.order != -1)
        os << "Герб входит в " << duct_order.get_value(blazon.order) << std::endl;
    if (blazon.crown != -1)
        os << "На гербе находится " << duct_crown.get_value(blazon.crown) << std::endl;

    return os;
}

void Blazon::setName(const std::string &name) {
    Blazon::name = name;
}

void Blazon::setColor(unsigned int color) {
    Blazon::color = color;
}

void Blazon::setMotto(int motto) {
    Blazon::motto = motto;
}

void Blazon::setShape_shield(int shape_shield) {
    Blazon::shape_shield = shape_shield;
}

void Blazon::setLeft_shield_holder(int left_shield_holder) {
    Blazon::left_shield_holder = left_shield_holder;
}

void Blazon::setRight_shield_holder(int right_shield_holder) {
    Blazon::right_shield_holder = right_shield_holder;
}

void Blazon::setGround(int ground) {
    Blazon::ground = ground;
}

void Blazon::setOrder(int order) {
    Blazon::order = order;
}

void Blazon::setCrown(int crown) {
    Blazon::crown = crown;
}

const std::string &Blazon::getName() const {
    return name;
}

unsigned int Blazon::getColor() const {
    return color;
}

int Blazon::getMotto() const {
    return motto;
}

int Blazon::getShape_shield() const {
    return shape_shield;
}

int Blazon::getLeft_shield_holder() const {
    return left_shield_holder;
}

int Blazon::getRight_shield_holder() const {
    return right_shield_holder;
}

int Blazon::getGround() const {
    return ground;
}

int Blazon::getOrder() const {
    return order;
}

int Blazon::getCrown() const {
    return crown;
}
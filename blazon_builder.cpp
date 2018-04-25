//
// Created by garvet on 18.04.18.
//

#include "blazon_builder.h"

Blazon_builder::Blazon_builder(): blazon(new Blazon) {}

Blazon_builder &Blazon_builder::name() {
    std::string name;
    std::cout << "Введите название герба:";
    std::getline(std::cin, name);
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cout << "Указано неверное название.\n";
        std::cout << "Введите название герба:";
        std::getline(std::cin, name);
    }
    blazon->setName(name);
    return *this;
}

Blazon_builder &Blazon_builder::color() {
    unsigned int colorRGB[3] = {0,0,0};
    std::string type[3] = {"красного","зелёного","синего"};
    for (int i = 0; i < 3; ++i) {
        std::cout << "Введите количество " << type[i] << " цвета (от 0 до 255): ";
        std::cin >> colorRGB[i];
        while ((colorRGB[i] <= 0) || (colorRGB[i] > 255)) {
            std::cout << "Указано неверное число.\n";
            std::cout << "Введите количество " << type[i] << " цвета (от 0 до 255): ";
            std::cin >> colorRGB[i];
        }
    }
    blazon->setColor((colorRGB[0] << 16) | (colorRGB[1] << 8) | colorRGB[2]);
    return *this;
}

Blazon_builder &Blazon_builder::motto() {
    blazon->setMotto(option_duct("варианты девизов", duct_motto));
    return *this;
}

Blazon_builder &Blazon_builder::shape_shield() {
    blazon->setShape_shield(option_duct("варианты формы щита", duct_shape_shield));
    return *this;
}

Blazon_builder &Blazon_builder::left_shield_holder() {
    blazon->setLeft_shield_holder(option_duct("варианты левого щитодержателя", duct_shield_holder));
    return *this;
}

Blazon_builder &Blazon_builder::right_shield_holder() {
    blazon->setRight_shield_holder(option_duct("варианты правого щитодержателя", duct_shield_holder));
    return *this;
}

Blazon_builder &Blazon_builder::ground() {
    blazon->setGround(option_duct("варианты почвы", duct_ground));
    return *this;
}

Blazon_builder &Blazon_builder::order() {
    blazon->setOrder(option_duct("ордены", duct_order));
    return *this;
}

Blazon_builder &Blazon_builder::crown() {
    blazon->setCrown(option_duct("варианты короны", duct_crown));
    return *this;
}

int Blazon_builder::option_duct(std::string type, const Duct &duct) {
    int number=-1;
    std::cout << "Возможные " << type << ":\n" << duct << "Выберите вариант:";
    std::cin >> number;
    while (((number-1) < 0) || ((number-1) >= duct.get_size())){
        std::cout << "Выберите вариант:";
        std::cin >> number;
    }
    return (number-1);
}

void Blazon_builder::output(Blazon &newBlazon){
    if ((this == nullptr) || (&newBlazon == nullptr)) {
        std::cerr << "Ошибка, отсутствует объект.\n" << std::endl;
        return;
    }
    newBlazon.setName (blazon->getName());
    newBlazon.setColor (blazon->getColor());
    newBlazon.setMotto (blazon->getMotto());
    newBlazon.setShape_shield (blazon->getShape_shield());
    newBlazon.setLeft_shield_holder (blazon->getLeft_shield_holder());
    newBlazon.setRight_shield_holder (blazon->getRight_shield_holder());
    newBlazon.setGround (blazon->getGround());
    newBlazon.setOrder (blazon->getOrder());
    newBlazon.setCrown (blazon->getCrown());
}

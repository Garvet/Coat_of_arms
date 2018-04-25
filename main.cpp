#include <iostream>
#include <vector>
#include <string>
#include "blazon.h"

int main() {
    bool not_exit = true;
    while(not_exit) {
        Blazon blazon;
        Blazon_builder builder_blazon;
        bool var[6] = {false, false, false, false, false, false};
        std::cout << "Введите 0, если \"нет\", или 1, если \"да\"." << std::endl <<"Будет ли у вашего герба девиз?" << std::endl;
        std::cin >> var[0];

        std::cout << "А щитодержатели?" << std::endl;
        std::cin >> var[1];
        if (var[1]) {
            int amt_shield_holder = 0;
            std::cout << "Сколько их будет? (1 или 2)" << std::endl;
            std::cin >> amt_shield_holder;
            if ((--amt_shield_holder) == 0){
                var[2] = false;
                std::cout << "А с какой стороны он будет стоять? (0 - слева, 1 - справа)" << std::endl;
                std::cin >> var[3];
            }
            else
                var[2] = true;
        }
        std::cout << "Будет ли герб относиться к ордену?" << std::endl;
        std::cin >> var[4];
        std::cout << "А будет ли на гербе находиться корона?" << std::endl;
        std::cin >> var[5];

        builder_blazon.name().color().shape_shield();
        if(var[0]) builder_blazon.motto();
        if(var[1] && var[2]) builder_blazon.left_shield_holder().right_shield_holder().ground();
        if(var[1] && !var[2] && !var[3]) builder_blazon.left_shield_holder().ground();
        if(var[1] && !var[2] && var[3]) builder_blazon.right_shield_holder().ground();
        if(var[4]) builder_blazon.order();
        if(var[5]) builder_blazon.crown();

        builder_blazon.output(blazon);
        std::cout << std::endl << blazon;
        blazon.save();

        std::cout << std::endl  << "Герб сохранён, желаете создать ещё один? (0 - \"нет\", 1 - \"да\")" << std::endl;
        std::cin >> not_exit;
    }
    return 0;
}
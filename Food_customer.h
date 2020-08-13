//
// Created by Wills Ekanem on 2020-07-24.
//

#ifndef ZAMONHOTELBOOKINGCPP_FOOD_CUSTOMER_H
#define ZAMONHOTELBOOKINGCPP_FOOD_CUSTOMER_H

#include "Room.h"

using namespace std;

class Food_customer {
public:
    int room_number;
    string food;
    double price;

    Food_customer(int roomNumber, string food, double price);

    int getRoomNumber() const;

    void setRoomNumber(int roomNumber);

    const string &getFood() const;

    void setFood(const string &food);

    double getPrice() const;

    void setPrice(double price);

};


#endif //ZAMONHOTELBOOKINGCPP_FOOD_CUSTOMER_H

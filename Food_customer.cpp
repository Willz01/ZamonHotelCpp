//
// Created by Wills Ekanem on 2020-07-24.
//

#include "Food_customer.h"

#include <utility>


Food_customer::Food_customer(int roomNumber, string food, double price) : room_number(roomNumber), food(std::move(food)),
                                                                                 price(price) {}

int Food_customer::getRoomNumber() const {
    return room_number;
}

void Food_customer::setRoomNumber(int roomNumber) {
    room_number = roomNumber;
}

const string &Food_customer::getFood() const {
    return food;
}

void Food_customer::setFood(const string &food) {
    Food_customer::food = food;
}

double Food_customer::getPrice() const {
    return price;
}

void Food_customer::setPrice(double price) {
    Food_customer::price = price;
}

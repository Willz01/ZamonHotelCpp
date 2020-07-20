//
// Created by Wills Ekanem on 2020-07-20.
//

#include "Room_feature.h"

#include <utility>

Room_feature::Room_feature(Room room, double length, double width, int numberOfChairs, int numberOfBeds,
                           int numberOfTables) : room(std::move(room)), length(length), width(width),
                                                 number_of_chairs(numberOfChairs), number_of_beds(numberOfBeds),
                                                 number_of_tables(numberOfTables) {}

const Room &Room_feature::getRoom() const {
    return room;
}

void Room_feature::setRoom(const Room &room) {
    Room_feature::room = room;
}

double Room_feature::getLength() const {
    return length;
}

void Room_feature::setLength(double length) {
    Room_feature::length = length;
}

double Room_feature::getWidth() const {
    return width;
}

void Room_feature::setWidth(double width) {
    Room_feature::width = width;
}

int Room_feature::getNumberOfChairs() const {
    return number_of_chairs;
}

void Room_feature::setNumberOfChairs(int numberOfChairs) {
    number_of_chairs = numberOfChairs;
}

int Room_feature::getNumberOfBeds() const {
    return number_of_beds;
}

void Room_feature::setNumberOfBeds(int numberOfBeds) {
    number_of_beds = numberOfBeds;
}

int Room_feature::getNumberOfTables() const {
    return number_of_tables;
}

void Room_feature::setNumberOfTables(int numberOfTables) {
    number_of_tables = numberOfTables;
}

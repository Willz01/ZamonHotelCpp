//
// Created by Wills Ekanem on 2020-07-19.
//

#include "Room.h"

#include <utility>

Room::Room(int roomNo, std::string occupant, std::string type, double charge, bool availability,
           int period) : room_no(roomNo), occupant(std::move(occupant)), type(std::move(type)), charge(charge), availability(availability),
                         period(period) {}

int Room::getRoomNo() const {
    return room_no;
}

void Room::setRoomNo(int roomNo) {
    room_no = roomNo;
}

const std::string &Room::getOccupant() const {
    return occupant;
}

void Room::setOccupant(const std::string &occupant) {
    Room::occupant = occupant;
}

const std::string &Room::getType() const {
    return type;
}

void Room::setType(const std::string &type) {
    Room::type = type;
}

double Room::getCharge() const {
    return charge;
}

void Room::setCharge(double charge) {
    Room::charge = charge;
}

bool Room::isAvailability() const {
    return availability;
}

void Room::setAvailability(bool availability) {
    Room::availability = availability;
}

int Room::getPeriod() const {
    return period;
}

void Room::setPeriod(int period) {
    Room::period = period;
}

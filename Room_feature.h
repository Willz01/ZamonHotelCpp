//
// Created by Wills Ekanem on 2020-07-20.
//

#ifndef ZAMONHOTELBOOKINGCPP_ROOM_FEATURE_H
#define ZAMONHOTELBOOKINGCPP_ROOM_FEATURE_H

#include "Room.h"


class Room_feature {
public:
    Room room;
    double length{};
    double width{};
    int number_of_chairs;
    int number_of_beds;
    int number_of_tables;

    Room_feature(Room room, double length, double width, int numberOfChairs, int numberOfBeds,
                 int numberOfTables);

    const Room &getRoom() const;

    void setRoom(const Room &room);

    double getLength() const;

    void setLength(double length);

    double getWidth() const;

    void setWidth(double width);

    int getNumberOfChairs() const;

    void setNumberOfChairs(int numberOfChairs);

    int getNumberOfBeds() const;

    void setNumberOfBeds(int numberOfBeds);

    int getNumberOfTables() const;

    void setNumberOfTables(int numberOfTables);
};


#endif //ZAMONHOTELBOOKINGCPP_ROOM_FEATURE_H

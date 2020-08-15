//
// Created by Wills Ekanem on 2020-07-19.
//

#ifndef ZAMONHOTELBOOKINGCPP_ROOM_H
#define ZAMONHOTELBOOKINGCPP_ROOM_H


#include <string>

class Room {
private:
    int room_no;
public:
    std::__1::string occupant;
    std::__1::string type;
    double charge;
    bool availability;
    int period;

    Room(int roomNo, std::string occupant, std::string type, double charge, bool availability,
         int period);

    int getRoomNo() const;

    void setRoomNo(int roomNo);

    const std::string &getOccupant() const;

    void setOccupant(const std::string &occupant);

    const std::string &getType() const;

    void setType(const std::string &type);

    double getCharge() const;

    void setCharge(double charge);

    bool isAvailability() const;

    void setAvailability(bool availability);

    int getPeriod() const;

    void setPeriod(int period);

};


#endif //ZAMONHOTELBOOKINGCPP_ROOM_H

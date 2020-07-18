//
// Created by Wills Ekanem on 2020-07-18.
//

#ifndef ZAMONHOTELBOOKINGCPP_ROOM_H
#define ZAMONHOTELBOOKINGCPP_ROOM_H

using namespace std;

class Room {
private:
    int room_no;
public:
    string occupant;
    string type;
    double charge;
    bool availability;
    int period;

    Room(int roomNo, string occupant, string type, double charge, bool availability, int period);

    int getRoomNo() const;

    void setRoomNo(int roomNo);

    const string &getOccupant() const;

    void setOccupant(const string &occupant);

    const string &getType() const;

    void setType(const string &type);

    double getCharge() const;

    void setCharge(double charge);

    bool isAvailability() const;

    void setAvailability(bool availability);

    int getPeriod() const;

    void setPeriod(int period);

};


#endif //ZAMONHOTELBOOKINGCPP_ROOM_H

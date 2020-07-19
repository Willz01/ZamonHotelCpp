//
// Created by Wills Ekanem on 2020-07-19.
//

#ifndef ZAMONHOTELBOOKINGCPP_CUSTOMER_H
#define ZAMONHOTELBOOKINGCPP_CUSTOMER_H

using namespace std;

class Customer {
private:
    int ID;
    int room_number;
public:
    string name;
    int age;
    string address;
    string email;
    int phone_number;

    Customer(int id, int roomNumber, string name, int age, string address, string email,
             int phoneNumber);

    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    int getAge() const;

    void setAge(int age);

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getEmail() const;

    void setEmail(const string &email);

    int getPhoneNumber() const;

    void setPhoneNumber(int phoneNumber);

    int getRoomNumber() const;

    void setRoomNumber(int roomNumber);


};


#endif //ZAMONHOTELBOOKINGCPP_CUSTOMER_H

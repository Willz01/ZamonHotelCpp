//
// Created by Wills Ekanem on 2020-07-19.
//

#include "Customer.h"

#include <utility>

int Customer::getId() const {
    return ID;
}

void Customer::setId(int id) {
    ID = id;
}

const string &Customer::getName() const {
    return name;
}

void Customer::setName(const string &name) {
    Customer::name = name;
}

int Customer::getAge() const {
    return age;
}

void Customer::setAge(int age) {
    Customer::age = age;
}

const string &Customer::getAddress() const {
    return address;
}

void Customer::setAddress(const string &address) {
    Customer::address = address;
}

const string &Customer::getEmail() const {
    return email;
}

void Customer::setEmail(const string &email) {
    Customer::email = email;
}

int Customer::getPhoneNumber() const {
    return phone_number;
}

void Customer::setPhoneNumber(int phoneNumber) {
    phone_number = phoneNumber;
}

Customer::Customer(int id, int roomNumber, string name, int age, string address, string email,
                   int phoneNumber) : ID(id), room_number(roomNumber), name(std::move(name)), age(age), address(std::move(address)),
                                      email(std::move(email)), phone_number(phoneNumber) {}

int Customer::getRoomNumber() const {
    return room_number;
}

void Customer::setRoomNumber(int roomNumber) {
    room_number = roomNumber;
}

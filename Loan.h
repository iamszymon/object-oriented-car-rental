#ifndef LOAN_H
#define LOAN_H

#include <iostream>
#include <ctime>

#include "Client.h"
#include "Vehicle.h"

class Loan
{

private:
    int _id;
    time_t _startDateTime;
    time_t _endDateTime;

    Vehicle *_car;
    Client *_client;

public:
    Loan(int id, time_t startDateTime, time_t endDateTime, Vehicle *car, Client *client);

    int id() const;
    time_t startDateTime() const;
    time_t endDateTime() const;
    Vehicle *car() const;
    Client *client() const;

    void print();
};

#endif // LOAN_H

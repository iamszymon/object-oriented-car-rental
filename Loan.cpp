#include "Loan.h"

Loan::Loan(int id, time_t startDateTime, time_t endDateTime, Vehicle *car, Client *client)
{
    _id = id;
    _startDateTime = startDateTime;
    _endDateTime = endDateTime;

    _car = car;
    _client = client;
}


int Loan::id() const
{
    return _id;
}


time_t Loan::startDateTime() const
{
    return _startDateTime;
}

time_t Loan::endDateTime() const
{
    return _endDateTime;
}

Vehicle *Loan::car() const
{
    return _car;
}

Client *Loan::client() const
{
    return _client;
}

void Loan::print()
{
    std::cout << "\n\tLoan data:" <<
                 "\n\t\tID: " << _id <<
                 "\n\t\tLoan start date: " << ctime(&_startDateTime) <<
                 "\n\t\tLoan end date: " << ctime(&_endDateTime) <<
                 "\n\t\tCar: " << _car->id() <<
                 "\n\t\tClient: " << _client->id() << "\n";
}


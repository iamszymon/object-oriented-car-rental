#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

#include "Vehicle.h"
#include "Client.h"
#include "Loan.h"

class Branch
{
private:
    int _branchId;
    std::string _city;
    std::string _address;
    std::vector<Vehicle*> _vehicles;
    std::vector<Client*> _clients;
    std::vector<Loan*> _loans;

    int countCurrentLoans(int clientId);
    int countCurrentLoans(int clientId, int vehicleType);

    bool checkIsCarRented(int carId);

public:
    Branch(int branchId, std::string city, std::string address );
    ~Branch();

    int countClients();
    int countCars();
    int countLoans();
    int countCurrentLoans();

    bool addClient(Client *client);
    bool removeClient(int id);

    bool addCar(Vehicle *car);
    bool removeCar(int id);

    bool addLoan(int clientId, int carId, int daysOrHours = -1);

    void printAllCars();

    void printAllClients();

    void printAllLoans();
    void printClientsLoans(int id);

    int branchId() const;

    std::string city() const;
    void setCity(const std::string &city);

    std::string address() const;
    void setAddress(const std::string &address);

    friend class CarRental;
};

#endif // BRANCH_H

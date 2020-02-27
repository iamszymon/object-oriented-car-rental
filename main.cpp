#include <iostream>
#include <ctime>
//#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_MODULE Hello
//#include <boost/test/unit_test.hpp>

#include "CarRental.h"
#include "LuxuriousCar.h"
#include "OrdinaryCar.h"

void loadDemoData(CarRental &cRental);

int main()
{

    CarRental carRental("Onion Rentals");

    loadDemoData(carRental);


    return 0;
}


void loadDemoData(CarRental &cRental)
{

    std::vector<Branch*> branches;

    branches.push_back(new Branch(100, "Warsaw", "Chodakowska 7"));
    branches.push_back(new Branch(101, "Katowice", "Koksowa 113"));
    branches.push_back(new Branch(102, "Cracow", "Wawelska 11"));

    for(auto const& branch : branches) {
        branch->addClient(new Client(1, 2, 3, true));
        branch->addClient(new Client(2, 2, 3, true));
        branch->addClient(new Client(3, 2, 3, false));
        branch->addClient(new Client(4, 2, 3, false));
        branch->addClient(new Client(5, 2, 8, true));
        branch->addClient(new Client(6, 1, 4, true));
        branch->addClient(new Client(7, 1, 6, true));
        branch->addClient(new Client(8, 1, 5, true));
        branch->addClient(new Client(9, 2, 3, true));
        branch->addClient(new Client(10, 2, 2, true));
        branch->addClient(new Client(11, 2, 3, true));
        branch->addClient(new Client(12, 1, 12, true));
        branch->addClient(new Client(13, 2, 2, true));
        branch->addClient(new Client(14, 2, 1, true));

        if(branch->branchId()==100) {
            branch->addCar(new LuxuriousCar(1, "Mercedes", "C klasse", 2018, 219.99));
            branch->addCar(new LuxuriousCar(2, "Lincoln", "K", 1986, 519.99));
            branch->addCar(new LuxuriousCar(3, "Bentley", "Continental"));

            branch->addCar(new OrdinaryCar(4, "Volkswagen", "Polo"));
            branch->addCar(new OrdinaryCar(5, "Mercedes", "B klasse", 2016, 69.33));
            branch->addCar(new OrdinaryCar(6, "Ford", "Focus"));
            branch->addCar(new OrdinaryCar(7, "Kia", "Ceed"));
            branch->addCar(new OrdinaryCar(8, "Volkswagen", "Passat"));
            branch->addCar(new OrdinaryCar(9, "Toyota", "Yaris"));
            branch->addCar(new OrdinaryCar(10, "Volkswagen", "Golf"));
            branch->addCar(new OrdinaryCar(11, "Opel", "Frontera"));

            branch->addLoan(1,1,5);
            branch->addLoan(1,2,3);
            branch->addLoan(13,3,5);
            branch->addLoan(4,4,40);
            branch->addLoan(7,8,11);
            branch->addLoan(8,9,5);
            branch->addLoan(8,10,2);

        } else {
            branch->addCar(new LuxuriousCar(1, "Lincoln", "Continental", 1990, 919.99));

            branch->addCar(new OrdinaryCar(2, "Volkswagen", "Polo"));
            branch->addCar(new OrdinaryCar(3, "Mercedes", "B klasse", 2016, 69.33));

            branch->addLoan(1,1,5);
            branch->addLoan(2,2,3);
            branch->addLoan(13,3,5);
        }


        cRental.addBranch(branch);

        branch->printAllCars();
        branch->printAllClients();
        branch->printAllLoans();
    }







}

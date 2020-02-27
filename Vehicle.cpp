#include "Vehicle.h"


Vehicle::Vehicle(int id, std::string brand, std::string model, int year, double priceOfHire, int km_done, std::string transmission, bool technicalCondition, double priceOfRepair)
{
    _id = id;
    _brand = brand;
    _model = model;
    _year = year;
    _priceOfHire = priceOfHire;
    _kmDone = km_done;
    _transmission = transmission;
    _technicalCondition = technicalCondition;
    _priceOfRepair = priceOfRepair;
}


std::string Vehicle::brand() const
{
    return _brand;
}

std::string Vehicle::model() const
{
    return _model;
}

int Vehicle::year() const
{
    return _year;
}

double Vehicle::priceOfHire() const
{
    return _priceOfHire;
}

void Vehicle::setPriceOfHire(double priceOfHire)
{
    _priceOfHire = priceOfHire;
}

int Vehicle::kmDone() const
{
    return _kmDone;
}

void Vehicle::setKmDone(int kmDone)
{
    _kmDone = kmDone;
}

std::string Vehicle::transmission() const
{
    return _transmission;
}

void Vehicle::setTransmission(const std::string &transmission)
{
    _transmission = transmission;
}

bool Vehicle::technicalCondition() const
{
    return _technicalCondition;
}

void Vehicle::setTechnicalCondition(bool technicalCondition)
{
    _technicalCondition = technicalCondition;
}

double Vehicle::priceOfRepair() const
{
    return _priceOfRepair;
}

void Vehicle::setPriceOfRepair(double priceOfRepair)
{
    _priceOfRepair = priceOfRepair;
}


int Vehicle::id() const
{
    return _id;
}

int Vehicle::type() const
{
    return _type;
}

void Vehicle::print()
{
    std::cout << "\tCar data:" <<
                 "\n\t\tID: " << _id <<
                 "\n\t\tBrand: " << _brand <<
                 "\n\t\tModel: " << _model <<
                 "\n\t\tProduction year: " << _year <<
                 "\n\t\tHire pirce:" << _priceOfHire <<
                 "\n\t\tKilometers done: " << _kmDone <<
                 "\n\t\tTransmission: " << _transmission <<
                 "\n\t\tTechnical condition: " << _technicalCondition <<
                 "\n\t\tRepair price year: " << _priceOfRepair << "\n";
}


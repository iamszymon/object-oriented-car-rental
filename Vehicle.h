#ifndef CAR_H
#define CAR_H

#include <iostream>

class Vehicle
{
protected:
    int _id;
    std::string _brand;
    std::string _model;
    int _year;
    double _priceOfHire;
    int _kmDone;
    std::string _transmission;
    bool _technicalCondition;
    double _priceOfRepair;

    int _type; // 1 - ordinary car, 2 - luxury car

public:
    Vehicle(int id,
            std::string brand,
            std::string model,
            int year = 2012,
            double priceOfHire = 50.55,
            int km_done = 100000,
            std::string transmission = "manual",
            bool technicalCondition = true,
            double priceOfRepair = 299.99);



    int id() const;
    std::string brand() const;
    std::string model() const;
    int year() const;

    double priceOfHire() const;
    void setPriceOfHire(double priceOfHire);

    int kmDone() const;
    void setKmDone(int kmDone);

    std::string transmission() const;
    void setTransmission(const std::string &transmission);

    bool technicalCondition() const;
    void setTechnicalCondition(bool technicalCondition);

    double priceOfRepair() const;
    void setPriceOfRepair(double priceOfRepair);

    int type() const;

    void print();
};

#endif // CAR_H

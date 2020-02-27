#ifndef ORDINARYCAR_H
#define ORDINARYCAR_H

#include <iostream>
#include "Vehicle.h"

class OrdinaryCar : public Vehicle
{
private:
    bool _air_conditioning;
    bool _radio;

public:
    OrdinaryCar(int id,
                std::string brand,
                std::string model,
                int year = 2012,
                double priceOfHire = 50.55,
                bool air_conditioning = true,
                bool radio = true,
                int km_done = 100000,
                std::string transmission = "manual",
                bool technicalCondition = true,
                double priceOfRepair = 299.99);

    ~OrdinaryCar();

    bool air_conditioning() const;
    void setAir_conditioning(bool air_conditioning);
    bool radio() const;
    void setRadio(bool radio);

    void print();
};

#endif // ORDINARYCAR_H

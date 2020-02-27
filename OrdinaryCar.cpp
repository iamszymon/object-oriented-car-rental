#include "OrdinaryCar.h"

OrdinaryCar::OrdinaryCar(int id,
                         std::string brand,
                         std::string model,
                         int year,
                         double priceOfHire,
                         bool air_conditioning,
                         bool radio,
                         int km_done,
                         std::string transmission,
                         bool technicalCondition,
                         double priceOfRepair)
    : Vehicle (id, brand, model, year, priceOfHire, km_done, transmission, technicalCondition, priceOfRepair)
{
    _type = 1;
    _air_conditioning = air_conditioning;
    _radio = radio;
}

bool OrdinaryCar::radio() const
{
    return _radio;
}

void OrdinaryCar::setRadio(bool radio)
{
    _radio = radio;
}

bool OrdinaryCar::air_conditioning() const
{
    return _air_conditioning;
}

void OrdinaryCar::setAir_conditioning(bool air_conditioning)
{
    _air_conditioning = air_conditioning;
}

void OrdinaryCar::print()
{
    std::cout << "\tCar data:" <<
                 "\n\t\tType: Ordinary car"<<
                 "\n\t\tID: " << _id <<
                 "\n\t\tBrand: " << _brand <<
                 "\n\t\tModel: " << _model <<
                 "\n\t\tProduction year: " << _year <<
                 "\n\t\tHire pirce:" << _priceOfHire <<
                 "\n\t\tKilometers done: " << _kmDone <<
                 "\n\t\tTransmission: " << _transmission <<
                 "\n\t\tTechnical condition: " << _technicalCondition <<
                 "\n\t\tRepair price year: " << _priceOfRepair <<
                 "\n\t\tRadio: " << _radio <<
                 "\n\t\tAir conditioning: " << _air_conditioning << "\n";
}


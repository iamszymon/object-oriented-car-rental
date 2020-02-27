#include "LuxuriousCar.h"

LuxuriousCar::LuxuriousCar(int id,
                           std::string brand,
                           std::string model,
                           int year,
                           double priceOfHire,
                           bool leather_seats,
                           bool chauffeur,
                            bool system_to_recognise_road_signs,
                            bool road_camera,
                            int km_done,
                            std::string transmission,
                            bool technicalCondition,
                            double priceOfRepair)
    : Vehicle (id, brand, model, year, priceOfHire, km_done, transmission, technicalCondition, priceOfRepair)
{
    _type = 2;
    _leather_seats = leather_seats;
    _chauffeur = chauffeur;
    _system_to_recognise_road_signs = system_to_recognise_road_signs;
    _road_camera = road_camera;
}

bool LuxuriousCar::leather_seats() const
{
    return _leather_seats;
}

void LuxuriousCar::setLeather_seats(bool leather_seats)
{
    _leather_seats = leather_seats;
}

bool LuxuriousCar::chauffeur() const
{
    return _chauffeur;
}

void LuxuriousCar::setChauffeur(bool chauffeur)
{
    _chauffeur = chauffeur;
}

bool LuxuriousCar::system_to_recognise_road_signs() const
{
    return _system_to_recognise_road_signs;
}

void LuxuriousCar::setSystem_to_recognise_road_signs(bool system_to_recognise_road_signs)
{
    _system_to_recognise_road_signs = system_to_recognise_road_signs;
}

bool LuxuriousCar::road_camera() const
{
    return _road_camera;
}

void LuxuriousCar::setRoad_camera(bool road_camera)
{
    _road_camera = road_camera;
}

void LuxuriousCar::print()
{
    std::cout << "\tCar data:" <<
                 "\n\t\tType: Luxurious car"<<
                 "\n\t\tID: " << _id <<
                 "\n\t\tBrand: " << _brand <<
                 "\n\t\tModel: " << _model <<
                 "\n\t\tProduction year: " << _year <<
                 "\n\t\tHire pirce:" << _priceOfHire <<
                 "\n\t\tKilometers done: " << _kmDone <<
                 "\n\t\tTransmission: " << _transmission <<
                 "\n\t\tTechnical condition: " << _technicalCondition <<
                 "\n\t\tRepair price year: " << _priceOfRepair <<
                 "\n\t\tLeather seats: " << _leather_seats <<
                 "\n\t\tRoad signs recognize system: " << _system_to_recognise_road_signs <<
                 "\n\t\tRoad camera: " << _road_camera <<
                 "\n\t\tChauffeur " << _chauffeur << "\n";
}

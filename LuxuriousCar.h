#ifndef LUXURIOUSCAR_H
#define LUXURIOUSCAR_H

#include <iostream>
#include "Vehicle.h"

class LuxuriousCar : public Vehicle
{
private:
    bool _leather_seats;
    bool _chauffeur;
    bool _system_to_recognise_road_signs;
    bool _road_camera;

public:
    LuxuriousCar(int id,
                std::string brand,
                std::string model,
                int year = 2015,
                double priceOfHire = 77.55,
                bool leather_seats = true,
                bool chauffeur = true,
                bool system_to_recognise_road_signs = true,
                bool road_camera = true,
                int km_done = 40000,
                std::string transmission = "automatic",
                bool technicalCondition = true,
                double priceOfRepair = 599.99);

    bool leather_seats() const;
    void setLeather_seats(bool leather_seats);

    bool chauffeur() const;
    void setChauffeur(bool chauffeur);

    bool system_to_recognise_road_signs() const;
    void setSystem_to_recognise_road_signs(bool system_to_recognise_road_signs);

    bool road_camera() const;
    void setRoad_camera(bool road_camera);

    void print();
};

#endif // LUXURIOUSCAR_H

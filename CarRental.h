#ifndef CARRENTAL_H
#define CARRENTAL_H

#include <iostream>
#include "Branch.h"

class CarRental
{

private:
    std::string _name;
    std::vector<Branch*> _branches;

public:
    CarRental(std::string name);

    bool addBranch(Branch *branch);

};

#endif // CARRENTAL_H

#include "CarRental.h"


CarRental::CarRental(std::string name)
{
    _name = name;
}

bool CarRental::addBranch(Branch *branch)
{
    if(branch->branchId() <100 && branch->branchId()>999) {
        std::cout << "\n\tBranch ID must be a 3-digit number\n";
        return false;
    }

    _branches.push_back(branch);

    return true;
}

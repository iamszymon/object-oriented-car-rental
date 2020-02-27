#include "Client.h"

Client::Client(int id, int limit, int licenceYears, bool licence)
{
    _id = id;
    _limit = limit;
    _licenceYears = licenceYears;
    _licence = licence;
}

int Client::limit() const
{
    return _limit;
}

void Client::setLimit(int limit)
{
    _limit = limit;
}

int Client::licenceYears() const
{
    return _licenceYears;
}

void Client::setLicenceYears(int licenseYears)
{
    _licenceYears = licenseYears;
}

bool Client::licence() const
{
    return _licence;
}

void Client::setLicence(bool licence)
{
    _licence = licence;
}

void Client::print()
{
    std::cout << "\tClient data:" <<
                 "\n\t\tID: " << _id <<
                 "\n\t\tLimit of loans: " << _limit <<
                 "\n\t\tValid licence: " << _licence <<
                 "\n\t\tLicence years: " << _licenceYears << "\n";
}



int Client::id() const
{
    return _id;
}


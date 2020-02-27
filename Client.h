#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class Client {
private:
    int _id;
    int _limit;//limit of rentals for client (2 by default)
    int _licenceYears;// 4 by default
    bool _licence;//true by default
public:

    ~Client();
    Client(int id, int limit = 2, int licenceYears = 4, bool licence = true);

    int id() const;

    int limit() const;
    void setLimit(int limit);

    int licenceYears() const;
    void setLicenceYears(int licenseYears);

    bool licence() const;
    void setLicence(bool licence);

    void print();
};

#endif // CLIENT_H

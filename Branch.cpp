#include "Branch.h"

Branch::Branch(int branchId, std::string city, std::string address)
{
    _branchId = branchId;
    _city = city;
    _address = address;
}

int Branch::countClients()
{
    return _clients.size();
}

int Branch::countCars()
{
    return _vehicles.size();
}

int Branch::countLoans() {
    return _loans.size();
}

int Branch::countCurrentLoans() {

    int counter = 0;

    time_t now = time(nullptr);

    for (auto const& loan : _loans)
    {

        if (difftime(now, loan->endDateTime()) > 0 )
        {
            ++counter;
        }
    }
    return counter;
}

int Branch::branchId() const
{
    return _branchId;
}

std::string Branch::city() const
{
    return _city;
}

void Branch::setCity(const std::string &city)
{
    _city = city;
}

std::string Branch::address() const
{
    return _address;
}

void Branch::setAddress(const std::string &address)
{
    _address = address;
}

int Branch::countCurrentLoans(int clientId)
{
    int counter = 0;

    for (auto const& loan : _loans)
    {

        if (loan->client()->id() == clientId )
        {
            ++counter;
        }
    }
    return counter;
}

int Branch::countCurrentLoans(int clientId, int vehicleType)
{
    int counter = 0;

    for (auto const& loan : _loans)
    {

        if (loan->client()->id() == clientId && loan->car()->type() == vehicleType)
        {
            ++counter;
        }
    }
    return counter;
}

bool Branch::checkIsCarRented(int carId)
{
    time_t now = time(nullptr);

    for (auto const& loan : _loans)
    {

        if (difftime(now, loan->endDateTime()) < 0 && loan->car()->id() == carId)
        {
            return true;
        }
    }
    return false;
}



bool Branch::addClient(Client *client)
{

    //check if limit is set to more than 2, if yes ask CEO for permission
    if(client->limit()>2) {

        int permission = -1;

        while(permission==-1) {
            std::cout << "\n\tYou want to add client with limit bigger than 2, ask CEO for permission(1 - yes, 0 - no_: ";
            std::cin >> permission;

            switch(permission) {
            case 0:
                std::cout << "OK bye bye\n";
                return false;
            case 1:
                std::cout << "All right\n";
                break;
            default:
                permission = -1;
                break;
            }
        }
    }



    for(auto const& tmpClient : _clients)
    {
        if(tmpClient->id() == client->id())  {
            return false;
        }
    }

    _clients.push_back(client);
    return true;
}

bool Branch::removeClient(int id)
{
    int position = 0;
    bool exists = false;

    for(auto const& tmpClient : _clients)
    {
        if(tmpClient->id() == id)  {
            exists = true;
        }
        if(!exists) {
            ++position;
        }
    }

    if(!exists) {
        return exists;
    }

    _clients.erase(_clients.begin()+position);

    return exists;
}

bool Branch::addCar(Vehicle *car)
{
    //check if maximum count of cars on the branch is exceed
    if(countCars()>=100) {
        return false;
    }

    //check if car is produced before 2010
    if(car->year()<2010) {
        return false;
    }

    for(auto const& tmpCar : _vehicles)
    {
        if(tmpCar->id() == car->id())  {
            return false;
        }
    }

    _vehicles.push_back(car);
    return true;
}

bool Branch::removeCar(int id)
{
    int position = 0;
    bool exists = false;

    for(auto const& tmpCar : _vehicles)
    {
        if(tmpCar->id() == id)  {
            exists = true;
        }
        if(!exists) {
            ++position;
        }
    }


    if(!exists) {
        return exists;
    }

    if(checkIsCarRented(id)) {
        return false;
    }

    _vehicles.erase(_vehicles.begin()+position);

    return exists;
}

bool Branch::addLoan(int clientId, int carId, int daysOrHours)
{
    bool exists = false;

    Vehicle *tmpVehicle= nullptr;
    Client *tmpCustomer= nullptr;

    time_t now = time(nullptr);
    tm *later = localtime(&now);

    //check if client specified by ID exists
    for(auto const& tmpClient : _clients)
    {
        if(tmpClient->id() == clientId)  {
            exists = true;
            tmpCustomer = tmpClient;
        }
    }

    if(!exists) {
        return false;
    }

    exists = false;

    //check if car specified by ID exists
    for(auto const& tmpCar : _vehicles)
    {
        if(tmpCar->id() == carId)  {
            exists = true;
            tmpVehicle = tmpCar;
        }
    }

    if(!exists) {
        return false;
    }


    //check validity of client's licence
    if(!tmpCustomer->licence()) {
        return false;
    }

    //check if car is luxurious and client has dribing licence for more than 5 years
    if(tmpVehicle->type()==2 && tmpCustomer->licenceYears()<5) {
        return false;
    }

    //check client's limit
    if(countCurrentLoans(clientId)>=tmpCustomer->limit())  {
        return false;
    }

    //client can't loan two different types of cars
    if(countCurrentLoans(clientId, 1) > 0 && countCurrentLoans(clientId, 2) > 0 ) {
        return false;
    }

    //check if car is in good technical condition
    if(!tmpVehicle->technicalCondition()) {
        return false;
    }

    //check if car is actually rented
    if(checkIsCarRented(carId)) {
        return false;
    }

    std::cout << "\n\tSelected car is ";
    int howMuch = daysOrHours;
    if(tmpVehicle->type()==1) {

        std::cout << "ordinary, so it is rent for days. Type in amount of days: ";
        if(howMuch<0)
            std::cin >> howMuch;

        if(howMuch < 2) {
            std::cout << "\n\tOrdinary car can't be rented for less than 2 days";
            return false;
        }

        later->tm_mday= howMuch + later->tm_mday;
        //add days to loan end date
    } else {

        std::cout << "luxurious, so it is rent for hours. Type in amount of hours: ";
        if(howMuch<0)
            std::cin >> howMuch;

        if(howMuch > 24) {
            std::cout << "\n\tLuxorious car can't be rented for more than 24 hours";
            return false;
        }

        later->tm_hour= howMuch + later->tm_hour;
        //add hours to loan end date
    }

    int loanId = -1;
    if(_loans.empty()) {
        loanId = 1;
    } else {
        loanId = _loans.back()->id()+1;
    }

    Loan *newLoan = new Loan(loanId, now, mktime(later), tmpVehicle, tmpCustomer);

    _loans.push_back(newLoan);

    return true;
}

void Branch::printAllCars()
{
    for(auto const& tmpCar : _vehicles)
    {
        tmpCar->print();
    }
}

void Branch::printAllClients()
{
    for(auto const& tmpClient : _clients)
    {
        tmpClient->print();
    }
}

void Branch::printAllLoans()
{
    for(auto const& tmpLoan : _loans)
    {
        tmpLoan->print();
    }
}

void Branch::printClientsLoans(int id)
{
    if(countCurrentLoans(id) == 0) {
        std::cout << "\n\t\tClient didn't rent any cars\n";
    }

    for(auto const& tmpLoan : _loans)
    {
        if(tmpLoan->id() == id) {
            tmpLoan->print();
        }
    }
}

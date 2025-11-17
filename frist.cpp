#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    string vehicleID;
    string manufacturer;
    string model;
    int year;

    static int totalVehicles;

public:
    Vehicle()
    {
        vehicleID = "N/A";
        manufacturer = "N/A";
        model = "N/A";
        year = 0;
        totalVehicles++;
    }

    Vehicle(string id, string mfg, string mdl, int yr)
    {
        vehicleID = id;
        manufacturer = mfg;
        model = mdl;
        year = yr;
        totalVehicles++;
    }

    ~Vehicle()
    {
    }

    void setVehicleID(string id)        { vehicleID = id; }
    void setManufacturer(string mfg)    { manufacturer = mfg; }
    void setModel(string mdl)           { model = mdl; }
    void setYear(int yr)                { year = yr; }

    string getVehicleID() const         { return vehicleID; }
    string getManufacturer() const      { return manufacturer; }
    string getModel() const             { return model; }
    int getYear() const                 { return year; }


    static int getTotalVehicles()
    {
        return totalVehicles;
    }

    void showDetails() const
    {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;


int main()
{
    Vehicle v1;
    Vehicle v2("V102", "Honda", "City", 2022);

    cout << "Total Vehicles Created: "
         << Vehicle::getTotalVehicles() << endl;

    cout << "\nVehicle 1 Details:\n";
    v1.showDetails();

    cout << "\nVehicle 2 Details:\n";
    v2.showDetails();

    return 0;
}

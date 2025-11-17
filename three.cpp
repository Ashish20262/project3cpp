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

public:
    Vehicle()
    {
        vehicleID = "N/A";
        manufacturer = "N/A";
        model = "N/A";
        year = 0;
    }

    Vehicle(string id, string mfg, string mdl, int yr)
    {
        vehicleID = id;
        manufacturer = mfg;
        model = mdl;
        year = yr;
    }

    void setVehicleID(string id)      { vehicleID = id; }
    void setManufacturer(string mfg)  { manufacturer = mfg; }
    void setModel(string mdl)         { model = mdl; }
    void setYear(int yr)              { year = yr; }

    string getVehicleID() const  { return vehicleID; }
    string getManufacturer() const { return manufacturer; }
    string getModel() const { return model; }
    int getYear() const { return year; }

    void show()
    {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};


class VehicleRegistry
{
private:
    Vehicle list[100];   
    int count;           

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle(const Vehicle &v)
    {
        if (count < 100)
        {
            list[count] = v;
            count++;
            cout << "Vehicle added successfully.\n";
        }
        else
        {
            cout << "Registry is full! Cannot add more vehicles.\n";
        }
    }

    void displayAll()
    {
        if (count == 0)
        {
            cout << "No vehicles in the registry.\n";
            return;
        }

        cout << "--- Vehicle Registry ---\n";
        for (int i = 0; i < count; i++)
        {
            cout << "\nVehicle " << (i + 1) << ":\n";
            list[i].show();
        }
    }

    void searchByID(string id)
    {
        for (int i = 0; i < count; i++)
        {
            if (list[i].getVehicleID() == id)
            {
                cout << "\nVehicle Found:\n";
                list[i].show();
                return;
            }
        }
        cout << "No vehicle found with ID: " << id << endl;
    }
};


int main()
{
    VehicleRegistry reg;

    Vehicle v1("V101", "Honda", "City", 2022);
    Vehicle v2("V102", "Tesla", "Model S", 2023);

    reg.addVehicle(v1);
    reg.addVehicle(v2);

    cout << "\nDisplaying All Vehicles:\n";
    reg.displayAll();

    cout << "\nSearching for V102:\n";
    reg.searchByID("V102");

    cout << "\nSearching for V999:\n";
    reg.searchByID("V999");

    return 0;
}

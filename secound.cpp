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

    ~Vehicle() {}

    void setVehicleID(string id)         { vehicleID = id; }
    void setManufacturer(string mfg)     { manufacturer = mfg; }
    void setModel(string mdl)            { model = mdl; }
    void setYear(int yr)                 { year = yr; }

    string getVehicleID() const          { return vehicleID; }
    string getManufacturer() const       { return manufacturer; }
    string getModel() const              { return model; }
    int    getYear() const               { return year; }

    static int getTotalVehicles()        { return totalVehicles; }

    void show()
    {
        cout << "VehicleID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;


class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car() : Vehicle()
    {
        fuelType = "Unknown";
    }

    Car(string id, string mfg, string mdl, int yr, string fuel)
        : Vehicle(id, mfg, mdl, yr)
    {
        fuelType = fuel;
    }

    void setFuelType(string fuel) { fuelType = fuel; }
    string getFuelType() const    { return fuelType; }

    void showCar()
    {
        show();
        cout << "Fuel Type: " << fuelType << endl;
    }
};


class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    ElectricCar() : Car()
    {
        batteryCapacity = 0;
    }

    ElectricCar(string id, string mfg, string mdl, int yr, string fuel, int capacity)
        : Car(id, mfg, mdl, yr, fuel)
    {
        batteryCapacity = capacity;
    }

    void setBattery(int cap) { batteryCapacity = cap; }
    int getBattery() const   { return batteryCapacity; }

    void showElectric()
    {
        showCar();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};


class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }

    Aircraft(int range)
    {
        flightRange = range;
    }

    void setRange(int r) { flightRange = r; }
    int getRange() const { return flightRange; }

    void showAircraft()
    {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};


class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar() : Car(), Aircraft() {}

    FlyingCar(string id, string mfg, string mdl, int yr,
              string fuel, int range)
        : Car(id, mfg, mdl, yr, fuel),
          Aircraft(range)
    {}

    void showFlyingCar()
    {
        Car::showCar();
        Aircraft::showAircraft();
    }
};


class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar() : ElectricCar()
    {
        topSpeed = 0;
    }

    SportsCar(string id, string mfg, string mdl, int yr,
              string fuel, int battery, int speed)
        : ElectricCar(id, mfg, mdl, yr, fuel, battery)
    {
        topSpeed = speed;
    }

    void setTopSpeed(int ts) { topSpeed = ts; }
    int getTopSpeed() const  { return topSpeed; }

    void showSports()
    {
        showElectric();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};


class Sedan : public Car
{
public:
    Sedan() : Car() {}

    Sedan(string id, string mfg, string mdl, int yr, string fuel)
        : Car(id, mfg, mdl, yr, fuel)
    {}

    void showSedan()
    {
        showCar();
        cout << "Type: Sedan" << endl;
    }
};


class SUV : public Car
{
public:
    SUV() : Car() {}

    SUV(string id, string mfg, string mdl, int yr, string fuel)
        : Car(id, mfg, mdl, yr, fuel)
    {}

    void showSUV()
    {
        showCar();
        cout << "Type: SUV" << endl;
    }
};


int main()
{
    SportsCar s("SC01", "Tesla", "Roadster", 2024, "Electric", 200, 400);
    s.showSports();


    FlyingCar f("FC01", "SkyDrive", "X2", 2025, "Hybrid", 300);
    f.showFlyingCar();


    Sedan sd("SD01", "Honda", "City", 2023, "Petrol");
    sd.showSedan();


    SUV su("SUV01", "Toyota", "Fortuner", 2022, "Diesel");
    su.showSUV();

    return 0;
}

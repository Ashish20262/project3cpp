#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
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

    // Getters
    string getVehicleID() const { return vehicleID; }

    void show()
    {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};


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

    ElectricCar(string id, string mfg, string mdl, int yr, string fuel, int cap)
        : Car(id, mfg, mdl, yr, fuel)
    {
        batteryCapacity = cap;
    }

    void showElectric()
    {
        showCar();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
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

    void showSports()
    {
        showElectric();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
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
        cout << "Type: Sedan\n";
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
        cout << "Type: SUV\n";
    }
};


class VehicleRegistry
{
private:
    Vehicle* vehicles[100];  
       int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle(Vehicle* v)
    {
        if (count < 100)
        {
            vehicles[count] = v;
            count++;
            cout << "Vehicle added successfully!\n";
        }
        else
        {
            cout << "Registry full!\n";
        }
    }

    void displayAll()
    {
        if (count == 0)
        {
            cout << "No vehicles added.\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << "\n--- Vehicle " << (i + 1) << " ---\n";
            vehicles[i]->show();
        }
    }

    void searchByID(string id)
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "\nVehicle Found:\n";
                vehicles[i]->show();
                return;
            }
        }

        cout << "Vehicle not found!\n";
    }
};


int main()
{
    VehicleRegistry registry;

    while (true)
    {
        int choice;
        cout << "\n========== VEHICLE MENU ==========\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search Vehicle by ID\n";
        cout << "4. Exit\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nSelect Vehicle Type:\n";
            cout << "1. Car\n";
            cout << "2. Electric Car\n";
            cout << "3. Sports Car\n";
            cout << "4. Sedan\n";
            cout << "5. SUV\n";
            cout << "6. Flying Car\n";
            cout << "Enter: ";

            int type;
            cin >> type;

            string id, mfg, mdl, fuel;
            int yr, battery, speed, range;

            cout << "Vehicle ID: ";
            cin >> id;
            cout << "Manufacturer: ";
            cin >> mfg;
            cout << "Model: ";
            cin >> mdl;
            cout << "Year: ";
            cin >> yr;

            if (type == 1)
            {
                cout << "Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new Car(id, mfg, mdl, yr, fuel));
            }
            else if (type == 2)
            {
                cout << "Fuel Type: ";
                cin >> fuel;
                cout << "Battery Capacity: ";
                cin >> battery;
                registry.addVehicle(new ElectricCar(id, mfg, mdl, yr, fuel, battery));
            }
            else if (type == 3)
            {
                cout << "Fuel Type: ";
                cin >> fuel;
                cout << "Battery Capacity: ";
                cin >> battery;
                cout << "Top Speed: ";
                cin >> speed;
                registry.addVehicle(new SportsCar(id, mfg, mdl, yr, fuel, battery, speed));
            }
            else if (type == 4)
            {
                cout << "Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new Sedan(id, mfg, mdl, yr, fuel));
            }
            else if (type == 5)
            {
                cout << "Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new SUV(id, mfg, mdl, yr, fuel));
            }
            else if (type == 6)
            {
                cout << "Fuel Type: ";
                cin >> fuel;
                cout << "Flight Range: ";
                cin >> range;
                registry.addVehicle(new FlyingCar(id, mfg, mdl, yr, fuel, range));
            }
            else
            {
                cout << "Invalid type!\n";
            }
        }
        else if (choice == 2)
        {
            registry.displayAll();
        }
        else if (choice == 3)
        {
            string id;
            cout << "Enter ID: ";
            cin >> id;
            registry.searchByID(id);
        }
        else if (choice == 4)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

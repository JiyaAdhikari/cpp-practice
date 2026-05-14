#include <iostream>
#include <vector>
using namespace std;

class Time {

public:
    int hours;
    int minutes;
    int seconds;

    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }
};

// Class for City

class City {
private:
    string name;
    int utcOffset;

public:
    City() {
        name = "Unknown";
        utcOffset = 0;
    }

    City(string n, int offset) {
        name = n;
        utcOffset = offset;
    }

    string getName() {
        return name;
    }

    int getOffset() {
        return utcOffset;
    }

    void setCity(string n, int offset) {
        name = n;
        utcOffset = offset;
    }

    void displayCity() {
        cout << "City: " << name;
        cout << " | UTC Offset: " << utcOffset << endl;
    }
};

class WorldClock {
    
private:
    vector<City> cities;

public:
    void loadDefaultCities() {
        cities.push_back(City("Delhi", 5));
        cities.push_back(City("London", 0));
        cities.push_back(City("New York", -5));
        cities.push_back(City("Tokyo", 9));
        cities.push_back(City("Sydney", 10));
        cities.push_back(City("Dubai", 4));
        cities.push_back(City("Moscow", 3));
        cities.push_back(City("Beijing", 8));
    }

    void displayAllCities() {
        cout << "\nAVAILABLE CITIES:\n";

        for (int i = 0; i < cities.size(); i++) {
            cout << i + 1 << ". ";
            cities[i].displayCity();
        }
    }

    Time getBaseTime() {
        int h, m, s;

        cout << "Enter Base Time\n";

        cout << "Enter hours: ";
        cin >> h;

        cout << "Enter minutes: ";
        cin >> m;

        cout << "Enter seconds: ";
        cin >> s;

        return Time(h, m, s);
    }

    Time normalizeTime(Time t) {

        while (t.seconds >= 60) {
            t.seconds -= 60;
            t.minutes++;
        }

        while (t.minutes >= 60) {
            t.minutes -= 60;
            t.hours++;
        }

        while (t.hours >= 24) {
            t.hours -= 24;
        }

        while (t.hours < 0) {
            t.hours += 24;
        }

        return t;
    }

    Time calculateCityTime(Time base, int offset) {
        Time result = base;
        result.hours += offset;

        return normalizeTime(result);
    }

    void displayTime(Time t) {

        if (t.hours < 10)
            cout << "0";

        cout << t.hours << ":";

        if (t.minutes < 10)
            cout << "0";

        cout << t.minutes << ":";

        if (t.seconds < 10)
            cout << "0";

        cout << t.seconds << endl;
    }

    void showWorldClock() {

        displayAllCities();

        int choice;

        cout << "\nSelect City Number: ";
        cin >> choice;

        if (choice < 1 || choice > cities.size()) {
            cout << "Invalid choice!" << endl;
            return;
        }

        Time base = getBaseTime();

        City selected = cities[choice - 1];

        Time cityTime = calculateCityTime(base, selected.getOffset());

        cout << "\nTime in " << selected.getName() << " = ";

        displayTime(cityTime);
    }

    void compareCities() {

        displayAllCities();

        int c1, c2;

        cout << "\nSelect First City: ";
        cin >> c1;

        cout << "Select Second City: ";
        cin >> c2;

        if (c1 < 1 || c2 < 1 || c1 > cities.size() || c2 > cities.size()) {
            cout << "Invalid selection!" << endl;
            return;
        }

        City city1 = cities[c1 - 1];
        City city2 = cities[c2 - 1];

        Time base = getBaseTime();

        Time t1 = calculateCityTime(base, city1.getOffset());
        Time t2 = calculateCityTime(base, city2.getOffset());

        cout << "\nTime in " << city1.getName() << " = ";
        displayTime(t1);

        cout << "Time in " << city2.getName() << " = ";
        displayTime(t2);

        int diff = city1.getOffset() - city2.getOffset();

        cout << "\nTime Difference = " << diff << " hours" << endl;
    }

    void addCity() {

        string name;
        int offset;

        cout << "Enter City Name: ";
        cin >> name;

        cout << "Enter UTC Offset: ";
        cin >> offset;

        City newCity(name, offset);

        cities.push_back(newCity);

        cout << "City Added Successfully!" << endl;
    }

    void deleteCity() {

        displayAllCities();

        int choice;

        cout << "\nEnter city number to delete: ";
        cin >> choice;

        if (choice < 1 || choice > cities.size()) {
            cout << "Invalid choice!" << endl;
            return;
        }

        cities.erase(cities.begin() + (choice - 1));

        cout << "City removed successfully!" << endl;
    }

    void searchCity() {

        string name;

        cout << "\nEnter city name to search: ";
        cin >> name;

        for (int i = 0; i < cities.size(); i++) {

            if (cities[i].getName() == name) {

                cout << "City Found!" << endl;

                cities[i].displayCity();

                return;
            }
        }

        cout << "City not found!" << endl;
    }

    void menu() {

        int choice;

        do {

            cout << "\nSMART WORLD CLOCK\n";
            cout << "1. Show World Clock\n";
            cout << "2. Compare Time Zones\n";
            cout << "3. Add New City\n";
            cout << "4. View All Cities\n";
            cout << "5. Delete City\n";
            cout << "6. Search City\n";
            cout << "7. Exit\n";

            cout << "Enter Choice: ";
            cin >> choice;

            switch (choice) {

            case 1:
                showWorldClock();
                break;

            case 2:
                compareCities();
                break;

            case 3:
                addCity();
                break;

            case 4:
                displayAllCities();
                break;

            case 5:
                deleteCity();
                break;

            case 6:
                searchCity();
                break;

            case 7:
                cout << "Exiting Program" << endl;
                break;

            default:
                cout << "Invalid Option!" << endl;
            }

        } while (choice != 7);
    }
};

int main() {

    WorldClock app;

    app.loadDefaultCities();

    app.menu();

    return 0;
}
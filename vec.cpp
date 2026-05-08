#include <iostream>
using namespace std;

class Student {
    int roll;
    char *name;

public:
    Student(int r, const char *n) {
        roll = r;
        name = new char[20];
        int i = 0;
        while(n[i] != '\0') {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
    }

    int getRoll() { return roll; }

    void display() {
        cout << "Roll No: " << roll << ", Name: " << name << endl;
    }

    ~Student() {
        delete[] name;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student **s = new Student*[n];
    int rolls[50];

    for(int i = 0; i < n; i++) {
        int r;
        char nm[20];

        cout << "Enter roll number for student " << i+1 << ": ";
        cin >> r;

        // uniqueness check
        for(int j = 0; j < i; j++) {
            if(rolls[j] == r) {
                cout << "Duplicate roll number. Enter again: ";
                cin >> r;
            }
        }
        rolls[i] = r;

        cout << "Enter name: ";
        cin >> nm;

        s[i] = new Student(r, nm);
    }

    cout << "--- Student Directory ---\n";
    for(int i = 0; i < n; i++)
        s[i]->display();

    int key;
    cout << "Enter roll number to search: ";
    cin >> key;

    for(int i = 0; i < n; i++) {
        if(s[i]->getRoll() == key) {
            cout << "Student Found:\n";
            s[i]->display();
        }
    }

    for(int i = 0; i < n; i++)
        delete s[i];
    delete[] s;

    cout << "All memory released. Program ended safely.\n";
    return 0;
}

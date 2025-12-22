#include <iostream>
using namespace std;

struct Patient {
    int id;
    int heartRate;
    int steps;
};

int main() {
    Patient patients[3] = {
        {1, 72, 5000},
        {2, 88, 3000},
        {3, 65, 7000}
    };

    cout << "Patient Health Data:\n";
    for (int i = 0; i < 3; i++)
        cout << "ID: " << patients[i].id
             << " HR: " << patients[i].heartRate
             << " Steps: " << patients[i].steps << endl;

    return 0;
}

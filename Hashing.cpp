#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> participants;

    participants[101] = "Alice";
    participants[102] = "Bob";
    participants[103] = "Charlie";

    cout << "Participant Records:\n";
    for (auto &p : participants)
        cout << "ID: " << p.first << " Name: " << p.second << endl;

    return 0;
}

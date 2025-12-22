#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class WasteLookup {
private:
    unordered_map<string, int> wasteTable; // key = "hub:wasteType", value = quantity
public:
    void addWaste(const string& hub, const string& type, int qty) {
        string key = hub + ":" + type;
        wasteTable[key] += qty;
    }

    int getWaste(const string& hub, const string& type) {
        string key = hub + ":" + type;
        return wasteTable[key];
    }

    void printWaste() {
        cout << "Waste Lookup Table:\n";
        for (auto& entry : wasteTable) {
            cout << entry.first << " -> " << entry.second << " units\n";
        }
    }
};

int main() {
    WasteLookup lookup;
    lookup.addWaste("Hub0", "Biogas", 50);
    lookup.addWaste("Hub1", "Compost", 30);
    lookup.addWaste("Hub2", "Recyclables", 40);
    lookup.addWaste("Hub3", "Hazardous", 10);

    lookup.printWaste();

    cout << "Quantity of Biogas at Hub0: " << lookup.getWaste("Hub0", "Biogas") << endl;

    return 0;
}

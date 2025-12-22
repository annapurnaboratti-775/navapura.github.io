#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class SensorHashTable {
private:
    unordered_map<string, double> table; // key = "nodeID:sensorType", value = reading
public:
    void addSensorData(const string& node, const string& type, double value) {
        string key = node + ":" + type;
        table[key] = value;
    }

    double getSensorData(const string& node, const string& type) {
        string key = node + ":" + type;
        if (table.find(key) != table.end()) return table[key];
        return -1; // not found
    }

    void printAllData() {
        cout << "Sensor Data Table:\n";
        for (auto& entry : table) {
            cout << entry.first << " -> " << entry.second << endl;
        }
    }
};

int main() {
    SensorHashTable sensors;
    sensors.addSensorData("Node0", "FlowRate", 12.5);
    sensors.addSensorData("Node1", "Contamination", 0.03);
    sensors.addSensorData("Node2", "FlowRate", 15.0);
    sensors.addSensorData("Node3", "Contamination", 0.05);

    sensors.printAllData();
    cout << "Flow rate at Node2: " << sensors.getSensorData("Node2", "FlowRate") << endl;

    return 0;
}


#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> workshops;

    workshops.push("Digital Literacy");
    workshops.push("Online Safety");
    workshops.push("E-Governance Training");

    cout << "Workshop Schedule:\n";
    while (!workshops.empty()) {
        cout << "Conducting: " << workshops.front() << endl;
        workshops.pop();
    }
    return 0;
}

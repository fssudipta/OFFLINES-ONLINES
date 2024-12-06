#include <iostream>
#include <queue>
#include <string>

using namespace std;

class OfficerQueue {
public:
    queue<int> q;

    void enqueue(int customerId) {
        q.push(customerId);
    }

    int dequeue() {
        if (q.empty()) {
            return -1;
        }
        int front = q.front();
        q.pop();
        return front;
    }

    int size() {
        return q.size();
    }
};

int main() {
    OfficerQueue officerB, officerC, managerA;

    string command;
    char person;
    int customerId;
    while (cin >> command) {
        if (command == "terminate") {
            break;
        }

        if (command == "enter") {
            cin >> customerId;
            if (officerB.size() <= officerC.size()) {
                officerB.enqueue(customerId);
                cout << "Customer " << customerId << " enters queue B" << endl;
            } else {
                officerC.enqueue(customerId);
                cout << "Customer " << customerId << " enters queue C" << endl;
            }
        } else if (command == "approve") {
            cin >> person;
            if (person == 'B') {
                customerId = officerB.dequeue();
                if (customerId != -1) {
                    managerA.enqueue(customerId);
                    cout << "Customer " << customerId << " enters queue A" << endl;
                } else {
                    cout << "Queue B was already empty" << endl;
                }
            } else if (person == 'C') {
                customerId = officerC.dequeue();
                if (customerId != -1) {
                    managerA.enqueue(customerId);
                    cout << "Customer " << customerId << " enters queue A" << endl;
                } else {
                    cout << "Queue C was already empty" << endl;
                }
            } else if (person == 'A') {
                customerId = managerA.dequeue();
                if (customerId != -1) {
                    cout << "Customer " << customerId << " gets the loan" << endl;
                } else {
                    cout << "Queue A was already empty" << endl;
                }
            }
        } else if (command == "reject") {
            cin >> person;
            if (person == 'B') {
                customerId = officerB.dequeue();
                if (customerId != -1) {
                    if (officerB.size() <= officerC.size()) {
                        officerC.enqueue(customerId);
                        cout << "Customer " << customerId << " enters queue C" << endl;
                    } else {
                        officerB.enqueue(customerId);
                        cout << "Customer " << customerId << " enters queue B" << endl;
                    }
                } else {
                    cout << "Queue B was already empty" << endl;
                }
            } else if (person == 'C') {
                customerId = officerC.dequeue();
                if (customerId != -1) {
                    if (officerB.size() <= officerC.size()) {
                        officerC.enqueue(customerId);
                        cout << "Customer " << customerId << " enters queue C" << endl;
                    } else {
                        officerB.enqueue(customerId);
                        cout << "Customer " << customerId << " enters queue B" << endl;
                    }
                } else {
                    cout << "Queue C was already empty" << endl;
                }
            }
        }
    }

    return 0;
}

#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Struct to represent a patient
struct Patient {
    string name;
    int age;
    int severity;       // Higher means more critical
    int arrivalOrder;   // Used to break ties when severity is the same
};

// Comparator for priority_queue (higher severity first, then earlier arrival)
struct Compare {
    bool operator()(const Patient& a, const Patient& b) {
        if (a.severity == b.severity)
            return a.arrivalOrder > b.arrivalOrder; // earlier arrival first
        return a.severity < b.severity;             // higher severity first
    }
};

int main() {
    // Priority queue to manage patients based on severity and arrival order
    priority_queue<Patient, vector<Patient>, Compare> pq;
    int order = 0;  // Used to assign unique arrival order to each patient

    while (true) {
        cout << "1. Register Patient  2. Start Treatment  3. Exit\nSelect: ";
        int menu;
        cin >> menu;

        if (menu == 1) {
            // Register a new patient
            string name;
            int age, severity;
            cout << "Enter name, age, severity: ";
            cin >> name >> age >> severity;

            Patient p = {name, age, severity, order++};
            pq.push(p);
        }
        else if (menu == 2) {
            // Start treating the next patient
            if (!pq.empty()) {
                Patient top = pq.top();
                cout << "Now treating: " << top.name 
                     << " (Severity: " << top.severity << ")" << endl;
                pq.pop();
            } else {
                cout << "No patients in queue." << endl;
            }
        }
        else if (menu == 3) {
            // Exit the program
            cout << "Shutting down system." << endl;
            break;
        }
        else {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}

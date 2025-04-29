#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Structure to store student information
struct Student {
    string name;
    int id;
    int score;
};

int main() {
    vector<Student> students;

    while (true) {
        cout << "1. Register Student\n"
             << "2. Show All Students\n"
             << "3. Search by ID\n"
             << "4. Exit\n"
             << "Select: ";

        int input;
        cin >> input;

        if (input == 1) {
            // Register a new student
            string name;
            int id, score;
            cin >> name >> id >> score;

            // Check for duplicate ID
            bool found = false;
            for (const auto& s : students) {
                if (s.id == id) {
                    cout << "ID already exists." << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                students.push_back({name, id, score});
            }
        }
        else if (input == 2) {
            // Print all student information
            for (const auto& s : students) {
                cout << "Name: " << s.name
                     << ", ID: " << s.id
                     << ", Score: " << s.score << endl;
            }
        }
        else if (input == 3) {
            // Search student by ID
            int targetId;
            cin >> targetId;

            bool found = false;
            for (const auto& s : students) {
                if (s.id == targetId) {
                    cout << "Name: " << s.name
                         << ", Score: " << s.score << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found." << endl;
            }
        }
        else if (input == 4) {
            // Before exit, calculate average score (if any)
            if (!students.empty()) {
                float sum = 0;
                for (const auto& s : students) {
                    sum += s.score;
                }
                float avg = sum / students.size();
                cout << "Average score: " << avg << endl;
            }
            cout << "Program terminated." << endl;
            break;
        }
        else {
            cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}

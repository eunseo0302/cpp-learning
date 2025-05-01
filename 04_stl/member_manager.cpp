#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class representing a member
class Member {
public:
    string name;
    int age;
    string job;

    Member(const string& name, int age, const string& job) {
        this->name = name;
        this->age = age;
        this->job = job;
    }

    Member(const Member& other) {
        name = other.name;
        age = other.age;
        job = other.job;
    }
};

int main() {
    vector<Member> members;

    while (true) {
        // Menu
        cout << "\n1. Register member\n2. Search by name\n3. Print all members\n4. Filter by job\n5. Statistics\n6. Exit" << endl;
        int input;
        cin >> input;
        cin.ignore(); // Remove trailing newline

        if (input == 1) {
            // Register new member
            string name, job;
            int age;

            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter age: ";
            cin >> age;
            cin.ignore();  // remove newline after age
            cout << "Enter job: ";
            getline(cin, job);

            bool found = false;
            for (auto& m : members) {
                if (m.name == name) {
                    cout << "Name already exists. What would you like to do?" << endl;
                    cout << "1. Overwrite\n2. Cancel" << endl;
                    int menu;
                    cin >> menu;
                    cin.ignore();
                    if (menu == 1) {
                        m = Member(name, age, job);
                        found = true;
                    }
                    break;
                }
            }

            if (!found) {
                members.push_back(Member{name, age, job});
            }

        } else if (input == 2) {
            // Search by name
            string name;
            cout << "Enter name to search: ";
            getline(cin, name);

            bool found = false;
            for (const auto& m : members) {
                if (m.name == name) {
                    cout << "Name: " << m.name << ", Age: " << m.age << ", Job: " << m.job << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "No member found with that name." << endl;
            }

        } else if (input == 3) {
            // Print all members
            for (const auto& m : members) {
                cout << "Name: " << m.name << ", Age: " << m.age << ", Job: " << m.job << endl;
            }

        } else if (input == 4) {
            // Filter by job
            string targetJob;
            cout << "Enter job to filter: ";
            getline(cin, targetJob);

            for (const auto& m : members) {
                if (m.job == targetJob) {
                    cout << "Name: " << m.name << ", Age: " << m.age << ", Job: " << m.job << endl;
                }
            }

        } else if (input == 5) {
            // Show statistics
            float totalAge = 0;
            for (const auto& m : members) {
                totalAge += m.age;
            }
            cout << "Total members: " << members.size() << endl;
            if (!members.empty()) {
                cout << "Average age: " << totalAge / members.size() << endl;
            }

        } else if (input == 6) {
            // Exit
            cout << "Program exited." << endl;
            break;
        } else {
            cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}

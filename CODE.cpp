#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

struct Task {
    string name;
    double timeSpent;
};

int main() {

    vector<Task> tasks;
    int choice;

    while (true) {

        cout << "\n------ Productivity Tracker ------\n";
        cout << "1. Start New Task\n";
        cout << "2. Show Daily Report\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {

            Task t;
            cout << "Enter task name: ";
            cin >> t.name;

            cout << "Task started...\n";

            time_t start = time(0);

            cout << "Press 1 to stop the task: ";
            int stop;
            cin >> stop;

            time_t end = time(0);

            t.timeSpent = difftime(end, start) / 60.0;

            tasks.push_back(t);

            cout << "Task stopped.\n";
            cout << "Time spent: " << t.timeSpent << " minutes\n";

        }

        else if (choice == 2) {

            cout << "\n------ Daily Report ------\n";

            for (int i = 0; i < tasks.size(); i++) {
                cout << tasks[i].name << " : "
                     << tasks[i].timeSpent
                     << " minutes\n";
            }

        }

        else if (choice == 3) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}

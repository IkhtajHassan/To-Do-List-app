#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoList {
private:
    vector<string> tasks;

public:
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << "Task added!" << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
        } else {
            cout << "To-Do List:" << endl;
            for (int i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". " << tasks[i] << endl;
            }
        }
    }

    void deleteTask(int taskNumber) {
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
};

int main() {
    ToDoList myList;
    int choice, taskNumber;
    string task;

    do {
        cout << "\nTo-Do List Menu\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                cout << "Enter the task: ";
                getline(cin, task);
                myList.addTask(task);
                break;

            case 2:
                myList.viewTasks();
                break;

            case 3:
                cout << "Enter task number to delete: ";
                cin >> taskNumber;
                myList.deleteTask(taskNumber);
                break;

            case 4:
                cout << "Exiting the program...\n";
                break;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


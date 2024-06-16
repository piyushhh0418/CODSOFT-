#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure of tasks
struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

void addTask(vector<Task>& tasks, const string& description) {
    tasks.emplace_back(description);
}

void viewTasks(const vector<Task>& tasks) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].isCompleted ? "x" : " ") << "] " << tasks[i].description << "\n";
    }
}

void markTaskAsCompleted(vector<Task>& tasks, size_t index) {
    if (index < tasks.size()) {
        tasks[index].isCompleted = true;
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(vector<Task>& tasks, size_t index) {
    if (index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    } else {
        cout << "Invalid task number.\n";
    }
}

void showMenu() {
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    vector<Task> tasks;
    int choice;
    string description;
    size_t index;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); // Clear the buffer
                getline(cin, description);
                addTask(tasks, description);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                markTaskAsCompleted(tasks, index - 1);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> index;
                removeTask(tasks, index - 1);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
}


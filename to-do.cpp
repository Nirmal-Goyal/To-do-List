#include <bits/stdc++.h>
using namespace std;

const int MAX_TASKS = 10;
string tasks[MAX_TASKS];
int taskCount = 0;

void addTask();
void viewTasks();
void deleteTask();

int main() {
    int choice;
    do {
        cout << "\n=== TO-DO-LIST ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: deleteTask(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void addTask() {
    if (taskCount < MAX_TASKS) {
        cout << "Enter task: ";
        getline(cin, tasks[taskCount]);
        taskCount++;
        cout << "Task added successfully!\n";
    } else {
        cout << "Task list is full!\n";
    }
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "No tasks available.\n";
    } else {
        cout << "\nYour Tasks:\n";
        for (int i = 0; i < taskCount; i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

void deleteTask() {
    if (taskCount == 0) {
        cout << "No tasks to delete.\n";
        return;
    }
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > taskCount) {
        cout << "Invalid task number!\n";
        return;
    }
    for (int i = index - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    cout << "Task deleted successfully!\n";
}

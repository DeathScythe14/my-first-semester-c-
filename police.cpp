#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

// Global variables for admin credentials
string adminUsername = "";
string adminPassword = "";

// Data structures for Criminal and FIR records
struct Criminal {
    int id;
    string name;
    int age;
    string crimeHistory;
};

struct FIR {
    int firNumber;
    string crimeDetails;
    string suspectInfo;
    string status; // e.g., "Open", "Closed", "Under Investigation"
};

vector<Criminal> criminals;
vector<FIR> firs;

// Function prototypes
void createAdminAccount();
bool adminLogin();
void adminMenu();
void criminalRecordModule();
void firModule();
void reportsModule();
void saveDataToFile();
void loadDataFromFile();

// Utility functions
void clearScreen() {
    system("cls || clear");
}

void pressEnterToContinue() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Main function
int main() {
    loadDataFromFile();
    int choice;
    do {
        clearScreen();
        cout << "=== Police FIR Management System ===\n";
        cout << "1. Create Admin Account\n";
        cout << "2. Admin Login\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAdminAccount();
                break;
            case 2:
                if (adminLogin()) {
                    adminMenu();
                } else {
                    cout << "Login failed. Please try again.\n";
                    pressEnterToContinue();
                }
                break;
            case 0:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                pressEnterToContinue();
        }
    } while (choice != 0);

    saveDataToFile();
    return 0;
}

// Admin Account Creation
void createAdminAccount() {
    clearScreen();
    cout << "=== Create Admin Account ===\n";
    cout << "Enter a username: ";
    cin >> adminUsername;
    cout << "Enter a password: ";
    cin >> adminPassword;
    cout << "Admin account created successfully!\n";
    pressEnterToContinue();
}

// Admin Login
bool adminLogin() {
    clearScreen();
    string username, password;
    cout << "=== Admin Login ===\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == adminUsername && password == adminPassword) {
        cout << "Login successful!\n";
        pressEnterToContinue();
        return true;
    } else {
        return false;
    }
}

// Admin Menu
void adminMenu() {
    int choice;
    do {
        clearScreen();
        cout << "=== Admin Menu ===\n";
        cout << "1. Criminal Record\n";
        cout << "2. FIR\n";
        cout << "3. Reports\n";
        cout << "0. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                criminalRecordModule();
                break;
            case 2:
                firModule();
                break;
            case 3:
                reportsModule();
                break;
            case 0:
                cout << "Logging out...\n";
                pressEnterToContinue();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                pressEnterToContinue();
        }
    } while (choice != 0);
}

// Criminal Record Module
void criminalRecordModule() {
    int choice;
    do {
        clearScreen();
        cout << "=== Criminal Record Module ===\n";
        cout << "1. Add Criminal Record\n";
        cout << "2. Update Criminal Record\n";
        cout << "3. Delete Criminal Record\n";
        cout << "4. Search for Criminal Record\n";
        cout << "5. Generate Criminal Record Report\n";
        cout << "0. Back to Admin Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Criminal criminal;
                cout << "Enter Criminal ID: ";
                cin >> criminal.id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, criminal.name);
                cout << "Enter Age: ";
                cin >> criminal.age;
                cout << "Enter Crime History: ";
                cin.ignore();
                getline(cin, criminal.crimeHistory);
                criminals.push_back(criminal);
                cout << "Criminal record added successfully!\n";
                pressEnterToContinue();
                break;
            }
            case 2: {
                int id;
                cout << "Enter Criminal ID to update: ";
                cin >> id;
                for (auto& criminal : criminals) {
                    if (criminal.id == id) {
                        cout << "Enter new Name: ";
                        cin.ignore();
                        getline(cin, criminal.name);
                        cout << "Enter new Age: ";
                        cin >> criminal.age;
                        cout << "Enter new Crime History: ";
                        cin.ignore();
                        getline(cin, criminal.crimeHistory);
                        cout << "Criminal record updated successfully!\n";
                        pressEnterToContinue();
                        return;
                    }
                }
                cout << "Criminal ID not found.\n";
                pressEnterToContinue();
                break;
            }
            case 3: {
                int id;
                cout << "Enter Criminal ID to delete: ";
                cin >> id;
                for (auto it = criminals.begin(); it != criminals.end(); ++it) {
                    if (it->id == id) {
                        criminals.erase(it);
                        cout << "Criminal record deleted successfully!\n";
                        pressEnterToContinue();
                        return;
                    }
                }
                cout << "Criminal ID not found.\n";
                pressEnterToContinue();
                break;
            }
            case 4: {
                int id;
                cout << "Enter Criminal ID to search: ";
                cin >> id;
                for (const auto& criminal : criminals) {
                    if (criminal.id == id) {
                        cout << "ID: " << criminal.id << "\n";
                        cout << "Name: " << criminal.name << "\n";
                        cout << "Age: " << criminal.age << "\n";
                        cout << "Crime History: " << criminal.crimeHistory << "\n";
                        pressEnterToContinue();
                        return;
                    }
                }
                cout << "Criminal ID not found.\n";
                pressEnterToContinue();
                break;
            }
            case 5: {
                cout << "=== Criminal Record Report ===\n";
                for (const auto& criminal : criminals) {
                    cout << "ID: " << criminal.id << "\n";
                    cout << "Name: " << criminal.name << "\n";
                    cout << "Age: " << criminal.age << "\n";
                    cout << "Crime History: " << criminal.crimeHistory << "\n";
                    cout << "-------------------------\n";
                }
                pressEnterToContinue();
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                pressEnterToContinue();
        }
    } while (choice != 0);
}

// FIR Module
void firModule() {
    int choice;
    do {
        clearScreen();
        cout << "=== FIR Module ===\n";
        cout << "1. Issue FIR\n";
        cout << "2. Update FIR\n";
        cout << "3. Change FIR Status\n";
        cout << "0. Back to Admin Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                FIR fir;
                cout << "Enter FIR Number: ";
                cin >> fir.firNumber;
                cout << "Enter Crime Details: ";
                cin.ignore();
                getline(cin, fir.crimeDetails);
                cout << "Enter Suspect Information: ";
                getline(cin, fir.suspectInfo);
                fir.status = "Open";
                firs.push_back(fir);
                cout << "FIR issued successfully!\n";
                pressEnterToContinue();
                break;
            }
            case 2: {
                int firNumber;
                cout << "Enter FIR Number to update: ";
                cin >> firNumber;
                for (auto& fir : firs) {
                    if (fir.firNumber == firNumber) {
                        cout << "Enter new Crime Details: ";
                        cin.ignore();
                        getline(cin, fir.crimeDetails);
                        cout << "Enter new Suspect Information: ";
                        getline(cin, fir.suspectInfo);
                        cout << "FIR updated successfully!\n";
                        pressEnterToContinue();
                        return;
                    }
                }
                cout << "FIR Number not found.\n";
                pressEnterToContinue();
                break;
            }
            case 3: {
                int firNumber;
                cout << "Enter FIR Number to change status: ";
                cin >> firNumber;
                for (auto& fir : firs) {
                    if (fir.firNumber == firNumber) {
                        cout << "Current Status: " << fir.status << "\n";
                        cout << "Enter new Status (Open/Closed/Under Investigation): ";
                        cin.ignore();
                        getline(cin, fir.status);
                        cout << "FIR status updated successfully!\n";
                        pressEnterToContinue();
                        return;
                    }
                }
                cout << "FIR Number not found.\n";
                pressEnterToContinue();
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                pressEnterToContinue();
        }
    } while (choice != 0);
}

// Reports Module
void reportsModule() {
    int choice;
    do {
        clearScreen();
        cout << "=== Reports Module ===\n";
        cout << "1. Generate FIR Report\n";
        cout << "2. Generate Criminal Report\n";
        cout << "0. Back to Admin Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "=== FIR Report ===\n";
                for (const auto& fir : firs) {
                    cout << "FIR Number: " << fir.firNumber << "\n";
                    cout << "Crime Details: " << fir.crimeDetails << "\n";
                    cout << "Suspect Information: " << fir.suspectInfo << "\n";
                    cout << "Status: " << fir.status << "\n";
                    cout << "-------------------------\n";
                }
                pressEnterToContinue();
                break;
            }
            case 2: {
                cout << "=== Criminal Report ===\n";
                for (const auto& criminal : criminals) {
                    cout << "ID: " << criminal.id << "\n";
                    cout << "Name: " << criminal.name << "\n";
                    cout << "Age: " << criminal.age << "\n";
                    cout << "Crime History: " << criminal.crimeHistory << "\n";
                    cout << "-------------------------\n";
                }
                pressEnterToContinue();
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                pressEnterToContinue();
        }
    } while (choice != 0);
}

// File Management
void saveDataToFile() {
    ofstream outFile("data.txt");
    if (outFile.is_open()) {
        // Save admin credentials
        outFile << adminUsername << "\n" << adminPassword << "\n";

        // Save criminal records
        outFile << criminals.size() << "\n";
        for (const auto& criminal : criminals) {
            outFile << criminal.id << "\n" << criminal.name << "\n" << criminal.age << "\n" << criminal.crimeHistory << "\n";
        }

        // Save FIR records
        outFile << firs.size() << "\n";
        for (const auto& fir : firs) {
            outFile << fir.firNumber << "\n" << fir.crimeDetails << "\n" << fir.suspectInfo << "\n" << fir.status << "\n";
        }

        outFile.close();
    } else {
        cout << "Error saving data to file.\n";
    }
}

void loadDataFromFile() {
    ifstream inFile("data.txt");
    if (inFile.is_open()) {
        // Load admin credentials
        getline(inFile, adminUsername);
        getline(inFile, adminPassword);

        // Load criminal records
        int criminalCount;
        inFile >> criminalCount;
        inFile.ignore();
        for (int i = 0; i < criminalCount; i++) {
            Criminal criminal;
            inFile >> criminal.id;
            inFile.ignore();
            getline(inFile, criminal.name);
            inFile >> criminal.age;
            inFile.ignore();
            getline(inFile, criminal.crimeHistory);
            criminals.push_back(criminal);
        }

        // Load FIR records
        int firCount;
        inFile >> firCount;
        inFile.ignore();
        for (int i = 0; i < firCount; i++) {
            FIR fir;
            inFile >> fir.firNumber;
            inFile.ignore();
            getline(inFile, fir.crimeDetails);
            getline(inFile, fir.suspectInfo);
            getline(inFile, fir.status);
            firs.push_back(fir);
        }

        inFile.close();
    } else {
        cout << "No existing data found. Starting with a fresh system.\n";
    }
}

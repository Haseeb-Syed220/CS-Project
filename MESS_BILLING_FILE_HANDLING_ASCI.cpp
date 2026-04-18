#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printASCIIArt() {
    cout << R"(
███╗   ███╗███████╗███████╗███████╗    ██████╗ ██╗██╗     ██╗     ██╗███╗   ██╗ ██████╗     ███████╗██╗   ██╗███████╗████████╗███████╗███╗   ███╗
████╗ ████║██╔════╝██╔════╝██╔════╝    ██╔══██╗██║██║     ██║     ██║████╗  ██║██╔════╝     ██╔════╝╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔════╝████╗ ████║
██╔████╔██║█████╗  ███████╗███████╗    ██████╔╝██║██║     ██║     ██║██╔██╗ ██║██║  ███╗    ███████╗ ╚████╔╝ ███████╗   ██║   █████╗  ██╔████╔██║
██║╚██╔╝██║██╔══╝  ╚════██║╚════██║    ██╔══██╗██║██║     ██║     ██║██║╚██╗██║██║   ██║    ╚════██║  ╚██╔╝  ╚════██║   ██║   ██╔══╝  ██║╚██╔╝██║
██║ ╚═╝ ██║███████╗███████║███████║    ██████╔╝██║███████╗███████╗██║██║ ╚████║╚██████╔╝    ███████║   ██║   ███████║   ██║   ███████╗██║ ╚═╝ ██║
╚═╝     ╚═╝╚══════╝╚══════╝╚══════╝    ╚═════╝ ╚═╝╚══════╝╚══════╝╚═╝╚═╝  ╚═══╝ ╚═════╝     ╚══════╝   ╚═╝   ╚══════╝   ╚═╝   ╚══════╝╚═╝     ╚═╝
    )" << endl;
}

// Global student data
string name[100];
int reg_no[100];
unsigned int password[100];
int bill[100];
bool check_io[100];  // true = mess access granted
int n = 0;           // total students

// Global menu data
string menuItems[21];
int priceItems[21];
int m = 0;  // total menu items

string weekDays[7];  // day names set by menuFunction
bool messOpen = false;  // tracks whether mess is open or closed

// --- File I/O ---

void saveStudents() {
    ofstream outFile("students.txt");
    for (int i = 0; i < n; i++)
        outFile << reg_no[i] << " " << name[i] << " " << password[i] << " " << bill[i] << " " << check_io[i] << endl;
    outFile.close();
}

void loadStudents() {
    ifstream inFile("students.txt");
    if (!inFile) {
        // File doesn't exist — create it with one default student
        ofstream newFile("students.txt");
        newFile << "1001 Ali 1234 0 1" << endl;
        newFile.close();
        // Load the default we just wrote
        reg_no[0] = 1001;
        name[0]     = "Ali";
        password[0] = 1234;
        bill[0]     = 0;
        check_io[0] = true;
        n = 1;
        cout << "students.txt not found. Created with default student (Reg: 1001, Pass: 1234)." << endl;
        return;
    }
    while (n < 100 && inFile >> reg_no[n])
        inFile >> name[n] >> password[n] >> bill[n] >> check_io[n], n++;
    inFile.close();
}

void saveMenu() {
    ofstream outFile("menu.txt");
    for (int i = 0; i < m; i++)
        outFile << menuItems[i] << " " << priceItems[i] << endl;
    outFile.close();
}

void loadMenu() {
    ifstream inFile("menu.txt");
    if (!inFile) {
        // File doesn't exist — create it with 3 default items
        ofstream newFile("menu.txt");
        newFile << "Rice 50"   << endl;
        newFile << "Dal 30"    << endl;
        newFile << "Chicken 120" << endl;
        newFile.close();
        // Load the defaults we just wrote
        menuItems[0] = "Rice";      priceItems[0] = 50;
        menuItems[1] = "Dal";       priceItems[1] = 30;
        menuItems[2] = "Chicken";   priceItems[2] = 120;
        m = 3;
        cout << "menu.txt not found. Created with default menu items." << endl;
        return;
    }
    while (m < 21 && inFile >> menuItems[m])
        inFile >> priceItems[m], m++;
    inFile.close();
}

void saveBills() {
    ofstream outFile("bills.txt");
    for (int i = 0; i < n; i++)
        outFile << reg_no[i] << " " << bill[i] << endl;
    outFile.close();
}

void loadBills() {
    ifstream inFile("bills.txt");
    if (!inFile) {
        // File doesn't exist — create it with 0 bill for each loaded student
        ofstream newFile("bills.txt");
        for (int i = 0; i < n; i++)
            newFile << reg_no[i] << " 0" << endl;
        newFile.close();
        cout << "bills.txt not found. Created with zero bills for all students." << endl;
        return;
    }
    int reg;
    while (inFile >> reg) {
        for (int i = 0; i < n; i++) {
            if (reg_no[i] == reg) { inFile >> bill[i]; break; }
        }
    }
    inFile.close();
}

// --- Utilities ---

int getDaysInMonth(int month) {
    if (month == 2) return 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    else return 31;
}

// --- Menu ---

// Sets weekly menu; writes into global menuItems/priceItems via caller copy
void menuFunction(string day[], int &v, string menu[], int price[], int &m, int &dayNum, int &month, int &year) {
    m = 0;
    for (int i = 0; i < 7; i++) {
        cout << "Enter the name of the day : ";
        cin >> day[i];
        for (int j = 0; j < 3; j++) {
            cout << "Enter the name of dish " << j + 1 << ": ";
            cin >> menu[m];
            cout << "Enter the price for " << menu[m] << ": ";
            cin >> price[m];
            m++;
        }
        cout << "Menu for " << day[i] << " (" << dayNum << "/" << month << "/" << year << ")" << endl;
        dayNum++;
        if (dayNum > getDaysInMonth(month)) {
            dayNum = 1;
            month++;
            if (month > 12) { month = 1; year++; }
        }
    }
    cout << "Menu for the week has been set successfully!" << endl;
}

void changeMenu() {
    char action;
    cout << "Menu Management:" << endl;
    cout << "1. Display Menu" << endl;
    cout << "2. Add Food Item" << endl;
    cout << "3. Remove Food Item" << endl;
    cout << "4. Set Weekly Menu" << endl;
    cout << "Enter your choice: ";
    cin >> action;

    if (action == '1') {
        if (m == 0) {
            cout << "No items available in the menu." << endl;
        } else {
            cout << "Current Menu:" << endl;
            for (int i = 0; i < m; i++)  // flat list; day-based display needs saved day names
                cout << i + 1 << ". " << menuItems[i] << " - Price: " << priceItems[i] << endl;
        }
    } else if (action == '2') {
        if (m < 21) {
            cout << "Enter the name of the new food item: ";
            cin >> menuItems[m];
            cout << "Enter the price of the new food item: ";
            cin >> priceItems[m];
            m++;
            cout << "Food item added successfully!" << endl;
        } else {
            cout << "Menu is full, can't add more items." << endl;
        }
    } else if (action == '3') {
        int itemToRemove;
        cout << "Enter the number of the food item to remove: ";
        cin >> itemToRemove;
        if (itemToRemove < 1 || itemToRemove > m) {
            cout << "Invalid item number!" << endl;
        } else {
            for (int i = itemToRemove - 1; i < m - 1; i++) {
                menuItems[i] = menuItems[i + 1];
                priceItems[i] = priceItems[i + 1];
            }
            m--;
            cout << "Food item removed successfully!" << endl;
        }
    } else if (action == '4') {
        string day[7];
        string menu[21];  // fixed: must hold 7 days x 3 dishes = 21 items
        int price[21];    // fixed: same reason
        int v = 0;
        int dayNum = 1, month = 1, year = 2024;

        menuFunction(day, v, menu, price, m, dayNum, month, year);

        // Copy results into globals so menu persists beyond this scope
        for (int i = 0; i < 7; i++) weekDays[i] = day[i];
        for (int i = 0; i < m; i++) {
            menuItems[i] = menu[i];
            priceItems[i] = price[i];
        }
    } else {
        cout << "Invalid choice!" << endl;
    }
}

// --- Student Management ---

void addStudent() {
    if (n >= 100) { cout << "Student limit reached!" << endl; return; }  // bounds check
    cout << "Enter student name: ";
    cin >> name[n];
    cout << "Enter registration number: ";
    cin >> reg_no[n];
    cout << "Enter password: ";
    cin >> password[n];
    bill[n] = 0;
    check_io[n] = true;
    n++;
    cout << "Student added successfully!" << endl;
}

void removeStudent() {
    int check_r;
    cout << "Enter registration number of student to remove: ";
    cin >> check_r;
    for (int i = 0; i < n; i++) {
        if (reg_no[i] == check_r) {
            for (int j = i; j < n - 1; j++) {
                reg_no[j] = reg_no[j + 1];
                name[j] = name[j + 1];
                password[j] = password[j + 1];
                bill[j] = bill[j + 1];
                check_io[j] = check_io[j + 1];
            }
            n--;
            cout << "Student removed successfully!" << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void checkStudentProfile() {
    int check_r;
    cout << "Enter student registration number: ";
    cin >> check_r;
    for (int i = 0; i < n; i++) {
        if (reg_no[i] == check_r) {
            cout << "Name: " << name[i] << endl;
            cout << "Registration Number: " << reg_no[i] << endl;
            cout << "Bill: " << bill[i] << endl;
            cout << "Mess Access: " << (check_io[i] ? "Granted" : "Denied") << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void toggleMessAccess() {
    int check_r;
    string action;
    cout << "Enter registration number to toggle access: ";
    cin >> check_r;
    for (int i = 0; i < n; i++) {
        if (reg_no[i] == check_r) {
            cout << "Enter 'IN' to grant access or 'OUT' to deny: ";
            cin >> action;
            if (action == "IN")       { check_io[i] = true;  cout << "Access granted!" << endl; }
            else if (action == "OUT") { check_io[i] = false; cout << "Access denied!"  << endl; }
            else cout << "Invalid option!" << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

// --- Billing ---

void printBill() {
    char choice;
    cout << "Enter 'S' to print a single bill or 'A' to print all bills: ";
    cin >> choice;
    if (choice == 'S') {
        int check_r;
        cout << "Enter registration number: ";
        cin >> check_r;
        for (int i = 0; i < n; i++) {
            if (reg_no[i] == check_r) {
                cout << "Bill for " << name[i] << ": " << bill[i] << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    } else if (choice == 'A') {
        for (int i = 0; i < n; i++)
            cout << "Bill for " << name[i] << " (" << reg_no[i] << "): " << bill[i] << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
}

void confirmBillPayment() {
    int check_r;
    cout << "Enter registration number to confirm payment: ";
    cin >> check_r;
    for (int i = 0; i < n; i++) {
        if (reg_no[i] == check_r) {
            bill[i] = 0;
            cout << "Payment confirmed for " << name[i] << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

// --- Mess State ---

void openMess()  { messOpen = true;  cout << "Mess is now OPEN!"   << endl; }
void closeMess() { messOpen = false; cout << "Mess is now CLOSED!" << endl; }

// --- Main ---

int main() {
    printASCIIArt();

    // Load persisted data on startup
    loadStudents();
    loadMenu();
    loadBills();

    char userType;
    int check_p;

    cout << "Welcome to the Mess Billing System!" << endl;
    cout << "------------------------------------" << endl;

    cout << "Enter the password to start: ";
    cin >> check_p;

    if (check_p != 12345) {  // system-level password check
        cout << "Invalid system password!" << endl;
        return 0;
    }

    do {
        cout << "\nEnter 'S' for Student, 'M' for Manager, or 'X' to exit: ";
        cin >> userType;

        if (userType == 'S') {
            int studentReg;
            cout << "Enter your registration number: ";
            cin >> studentReg;

            bool studentFound = false;
            for (int i = 0; i < n; i++) {
                if (reg_no[i] == studentReg) {
                    // Verify student password
                    unsigned int enteredPass;
                    cout << "Enter your password: ";
                    cin >> enteredPass;
                    if (password[i] != enteredPass) {
                        cout << "Wrong password!" << endl;
                        break;
                    }
                    // Enforce mess access before showing menu
                    if (!check_io[i]) {
                        cout << "Mess access denied!" << endl;
                        break;
                    }
                    cout << "Today's menu:" << endl;
                    for (int k = 0; k < m; k++)  // fixed: renamed k to avoid shadowing outer i
                        cout << menuItems[k] << " - Price: " << priceItems[k] << endl;
                    studentFound = true;
                    break;
                }
            }
            if (!studentFound) cout << "Student not found!" << endl;

        } else if (userType == 'M') {
            cout << "Enter the manager password: ";
            cin >> check_p;

            if (check_p == 54321) {
                char choice;
                cout << "\nManager Menu:\n";
                cout << "1. Add Student\n";
                cout << "2. Remove Student\n";
                cout << "3. Print Bill (Single/All)\n";
                cout << "4. Change Menu\n";
                cout << "5. Open Mess\n";
                cout << "6. Close Mess\n";
                cout << "7. Check Student Profile\n";
                cout << "8. Confirm Bill Payment\n";
                cout << "9. Toggle Mess Access for a Student\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case '1': addStudent();          break;
                    case '2': removeStudent();       break;
                    case '3': printBill();           break;
                    case '4': changeMenu();          break;
                    case '5': openMess();            break;
                    case '6': closeMess();           break;
                    case '7': checkStudentProfile(); break;
                    case '8': confirmBillPayment();  break;
                    case '9': toggleMessAccess();    break;
                    default:  cout << "Invalid choice!" << endl; break;
                }
                // Persist all changes to disk after every manager action
                saveStudents();
                saveMenu();
                saveBills();

            } else {
                cout << "Invalid password." << endl;
            }

        } else if (userType == 'X') {
            cout << "Exiting system. Goodbye!" << endl;
            break;  // explicit exit
        } else {
            cout << "Invalid input!" << endl;
        }

    } while (userType != 'X');  // loop until explicit exit

    return 0;
}
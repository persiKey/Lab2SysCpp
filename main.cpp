#include <iostream>
#include "UserInterface.hpp"


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int displayMenu();

int main(int argc, char **argv)
{
    Database employeeDB;
    UserInterface Ui(&employeeDB);

    bool done = false;
    while (!done)
    {
        int selection = displayMenu();
        switch (selection)
        {
        case 1:
            Ui.doAdd();
            break;
        case 2:
            Ui.doFine();
            break;
        case 3:
            Ui.doPromote();
            break;
        case 4:
            employeeDB.displayAll();
            break;
        case 5:
            Ui.doListDuties();
            break;
        case 6:
            Ui.doListRequirements();
            break;
        case 0:
            done = true;
            break;
        default:
            cerr << "Unknown command." << endl;
        }
    }
}


int displayMenu()
{
    int selection;
    cout << endl;
    cout << "Roles Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Add a new role" << endl;
    cout << "2) Decrease the role wage" << endl;
    cout << "3) Increase the role wage" << endl;
    cout << "4) List all roles" << endl;
    cout << "5) List all duties of the role" << endl;
    cout << "6) List all requirements of the role" << endl;
    cout << "0) Quit" << endl;
    cout << endl;

    cout << "---> ";
    cin >> selection;
    return selection;
}
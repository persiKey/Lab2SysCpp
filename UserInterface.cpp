#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.hpp"

using namespace std;
using namespace Records;

int displayMenu();
void doAdd(Database &inDB);
void doListDuties(Database &inDB);
void doListRequirements(Database &inDB);
void doFine(Database &inDB);
void doPromote(Database &inDB);


int main(int argc, char **argv)
{
    Database employeeDB;
    bool done = false;
    while (!done)
    {
        int selection = displayMenu();
        switch (selection)
        {
        case 1:
            doAdd(employeeDB);
            break;
        case 2:
            doFine(employeeDB);
            break;
        case 3:
            doPromote(employeeDB);
            break;
        case 4:
            employeeDB.displayAll();
            break;
        case 5:
            doListDuties(employeeDB);
            break;
        case 6:
            doListRequirements(employeeDB);
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
void doAdd(Database &inDB)
{
    int roleCode;
    string roleName;
    float roleWage;
    cout << "Role code? ";
    cin >> roleCode;
    cout << "Role name? ";
    cin >> roleName;
    cout << "Role wage? ";
    cin >> roleWage;
    try
    {
        inDB.addRole(roleCode, roleName, roleWage);
    }
    catch (std::exception& ex)
    {
        cerr << "Unable to add new role!" << endl;
    }
}

void doListDuties(Database &inDB)
{
    int roleCode;
    cout << "Role code? ";
    cin >> roleCode;
    try
    {
        const Role &rl = inDB.getRole(roleCode);

        cout << "Employee's " << roleCode << " duties: " << endl;
        for (const auto& d : rl.getDuties())
            cout << '\t' << d << '\n'; 
    }
    catch (std::exception& ex)
    {
        cerr << "Unable to find employee!" << endl;
    }
}
void doListRequirements(Database &inDB)
{
    int roleCode;
    cout << "Role code? ";
    cin >> roleCode;
    try
    {
        const Role &rl = inDB.getRole(roleCode);

        cout << "Employee's " << roleCode << " requirements: " << endl;
        for (const auto& rq: rl.getRequirements())
            cout << '\t' << rq << '\n'; 
    }
    catch (std::exception& ex)
    {
        cerr << "Unable to find employee!" << endl;
    }
}

void doFine(Database &inDB)
{
    int roleCode;
    int delta;
    cout << "Role code? ";
    cin >> roleCode;
    cout << "Role fine? ";
    cin >> delta;
    try
    {
        Role &rl = inDB.getRole(roleCode);

        int oldWage = rl.getWage();
        int newWage = oldWage - delta;

        if(newWage < 0)
        { 
            cerr << "Wage cannot be negative!\n";
            return;
        }

        rl.setWage(newWage);

        cout << "Fined Role " << roleCode << " from " << oldWage << " to " << newWage << endl;
    }
    catch (std::exception& ex)
    {
        cerr << "Unable to find employee!" << endl;
    }   
}

void doPromote(Database &inDB)
{
    int roleCode;
    int delta;
    cout << "Role code? ";
    cin >> roleCode;
    cout << "Role promotion? ";
    cin >> delta;
    try
    {
        Role &rl = inDB.getRole(roleCode);

        int oldWage = rl.getWage();
        int newWage = oldWage + delta;
        rl.setWage(newWage);

        cout << "Promoted Role " << roleCode << " from " << oldWage << " to " << newWage << endl;
    }
    catch (std::exception& ex)
    {
        cerr << "Unable to find employee!" << endl;
    }       
}

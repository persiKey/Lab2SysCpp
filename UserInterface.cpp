#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.hpp"
#include "UserInterface.hpp"

using namespace std;
using namespace Records;



UserInterface::UserInterface(Records::Database* targetDB) : inDB(targetDB)
{
}

UserInterface::~UserInterface()
{
}


void UserInterface::doAdd()
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
    
    if(roleWage < 0)
    {
        cerr << "Wage cannot be negative!" << endl;
        cerr << "Unable to add new role!" << endl;
    }
    try
    {
        inDB->addRole(roleCode, roleName, roleWage);
    }
    catch (std::exception& ex)
    {
        cerr << "Unable to add new role!" << endl;
    }
}

void UserInterface::doListDuties()
{
    int roleCode;
    cout << "Role code? ";
    cin >> roleCode;
    try
    {
        const Role &rl = inDB->getRole(roleCode);

        cout << "Employee's " << roleCode << " duties: " << endl;
        for (const auto& d : rl.getDuties())
            cout << '\t' << d << '\n'; 
    }
    catch (std::exception& ex)
    {
        cerr << "Unable to find employee!" << endl;
    }
}
void UserInterface::doListRequirements()
{
    int roleCode;
    cout << "Role code? ";
    cin >> roleCode;
    try
    {
        const Role &rl = inDB->getRole(roleCode);

        cout << "Employee's " << roleCode << " requirements: " << endl;
        for (const auto& rq: rl.getRequirements())
            cout << '\t' << rq << '\n'; 
    }
    catch (std::exception& ex)
    {
        cerr << "Unable to find employee!" << endl;
    }
}

void UserInterface::doFine()
{
    int roleCode;
    int delta;
    cout << "Role code? ";
    cin >> roleCode;
    cout << "Role fine? ";
    cin >> delta;
    try
    {
        Role &rl = inDB->getRole(roleCode);

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

void UserInterface::doPromote()
{
    int roleCode;
    int delta;
    cout << "Role code? ";
    cin >> roleCode;
    cout << "Role promotion? ";
    cin >> delta;
    try
    {
        Role &rl = inDB->getRole(roleCode);

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

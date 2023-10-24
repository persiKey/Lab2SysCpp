#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.hpp"
#include <algorithm>

using namespace std;

namespace Records
{
    Database::Database()
    {
        mNextSlot = 0;
        mNextRoleNumber = kFirstRoleNumber;
    }
    Database::~Database()
    {
    }
    Role &Database::addRole(int roleCode, std::string roleName, float roleWage)
    {
        if (mNextSlot >= kMaxRoles)
        {
            cerr << "There is no more room to add the new Rolee!" << endl;
            throw exception();
        }
        
        if(std::find_if(mRoles,mRoles + mNextSlot,
        [roleCode](const Role& role)
        { return roleCode == role.getCode(); } ) != (mRoles + mNextSlot))
        {
            cerr << "There is a role with the same code" << endl;
            throw exception();           
        }
        Role &theRole = mRoles[mNextSlot++];
        theRole.setCode(roleCode);
        theRole.setName(roleName);
        theRole.setWage(roleWage);
        return theRole;
    }
    Role &Database::getRole(int roleCode)
    {
        for (int i = 0; i < mNextSlot; i++)
        {
            if (mRoles[i].getCode() == roleCode)
            {
                return mRoles[i];
            }
        }
        cerr << "No Role with Role number " << roleCode << endl;
        throw exception();
    }

    void Database::displayAll()
    {
        for (int i = 0; i < mNextSlot; i++)
        {
            cout << mRoles[i] << '\n';       
        }
    }
}
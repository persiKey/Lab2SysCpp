#pragma once

#include <iostream>
#include "radio.hpp"

namespace Records {
    const int kMaxRoles = 100;
    const int kFirstRoleNumber = 1000;
    
    class Database
    {
    public:
        Database();
        ~Database();
        Role& addRole(int roleCode, std::string roleName, float roleWage);
        Role& getRole(int roleCode);
        void displayAll();
        void displayAllDuties(int roleCode);
        void displayAllRequirements(int roleCode);
    protected:
        Role mRoles[kMaxRoles];
        int mNextSlot;
        int mNextRoleNumber;
    };
}
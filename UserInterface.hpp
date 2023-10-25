#pragma once

#include "Database.hpp"

using namespace Records;

class UserInterface
{
private:
    Records::Database *inDB;
public:
    UserInterface(Records::Database* targetDB);
    ~UserInterface();
    void doAdd();
    void doListDuties();
    void doListRequirements();
    void doFine();
    void doPromote();

};


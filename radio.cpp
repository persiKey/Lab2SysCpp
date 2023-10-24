#include "radio.hpp"
#include <algorithm>

Role::Role(/* args */)
{
    //std::cout << "ctor\n";
}

Role::~Role()
{
     //std::cout << "dtor\n";
}

std::ostream &operator<<(std::ostream &out, const Role &r)
{
    out << "Code: " << r.code << '\n';
    out << "Name: " << r.name << '\n';
    out << "Wage: " << r.wage << '\n';
    out << "Duties:\n";
    for (const auto &d : r.duties)
        out << '\t' << d << '\n';
    out << "Requirements:\n";
    for (const auto &rq : r.requirements)
        out << '\t' << rq << '\n';
    
    return out;
}



void Role::setCode(int newCode)
{
    code = newCode;
}

int Role::getCode() const
{
    return code;
}

void Role::setName(const string& newName)
{
    name = newName;
}

string Role::getName() const
{
    return name;
}

void Role::setWage(int newWage)
{
    wage = newWage;
}

float Role::getWage() const
{
    return wage;
}

bool Role::addDuty(const string &duty)
{
    if(duty.empty())
        return false;

    if(hasDuty(duty))
        return false;
    
    duties.push_back(duty);
    return true;
}

bool Role::removeDuty(const string &duty)
{
    auto findRes = std::find(duties.begin(), duties.end(), duty);
    if( findRes == duties.end() )
        return false;
    
    duties.erase(findRes);
    return true;
}

bool Role::hasDuty(const string &duty) const
{
    auto findRes = std::find(duties.begin(), duties.end(), duty);
    return findRes != duties.end();
}

vector<string> Role::getDuties() const
{
    return duties;
}

bool Role::addRequirement(const string &requirement)
{
    if(requirements.empty())
        return false;

    if(hasDuty(requirement))
        return false;
    
    requirements.push_back(requirement);
    return true;
}

bool Role::removeRequirement(const string &requirement)
{
    auto findRes = std::find(requirements.begin(), requirements.end(), requirement);
    if( findRes == requirements.end() )
        return false;
    
    requirements.erase(findRes);
    return true;
}

bool Role::hasRequirement(const string &requirement) const
{
    auto findRes = std::find(requirements.begin(), requirements.end(), requirement);
    return findRes != requirements.end();
}

vector<string> Role::getRequirements() const
{
    return requirements;
}

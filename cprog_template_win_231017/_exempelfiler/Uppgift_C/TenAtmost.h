#ifndef TENATMOST_H
#define TENATMOST_H

#include <string>
#include <stdexcept>

class  TenAtMost
{
private:
    static int objectCount;
    std::string name;   
public:
     TenAtMost(std::string name);
    //~ TenAtMost();
    std::string getName()const;
};

#endif

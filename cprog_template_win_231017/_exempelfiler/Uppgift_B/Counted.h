#ifndef COUNTED_H
#define COUNTED_H

#include <string>

class Counted {
public:
    Counted(std::string d);
    ~Counted();
    Counted(const Counted& other);
    std::string get() const;
    int getCount();

private:
    static int count;
    std::string data;
};

#endif // COUNTED_H
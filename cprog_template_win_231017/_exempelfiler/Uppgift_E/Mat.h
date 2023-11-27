#ifndef MAT_H
#define MAT_H

#include<string>

class Mat
{
private:
    int weight;
    int sweetness;
public:
    virtual int CalculateNutrientContent() const=0;
    virtual ~Mat() = default;
    int getWeight() const;
protected:
    Mat(int weight, int sweetness);
};

    

#endif
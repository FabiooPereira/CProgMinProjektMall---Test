class Vector
{
private:
    int size;
    int* data;
public:
    
    //Konstruktor
    Vector(int n): size(n), data(new int[size]){};
    //copy-konstruktor
    Vector(const Vector &other): size(other.size), data(new int[other.size]){
        for(int i = 0; i< size; i++){
            data[i] = other.data[i];  
        }
    }
    //destruktor
    ~Vector(){
        delete[] data;
    };
    //tilldelningsoperator
    Vector &operator=(const Vector &other){
        if(this != &other){
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    // överlaggrad indexeringsoperator
    int &operator[](int index){
        return data[index];
    }
};

 
#include <iostream>
#include <cstring>
using namespace std;

class Overcoat {
    char* type;
    int sizeType;
    char* name;
    int sizeName;
    int price;

public:
    Overcoat() : type{ nullptr }, sizeType{ 0 }, name{ nullptr }, sizeName{ 0 }, price{ 0 } {}

    Overcoat(const char* type, const int sizeType, const char* name, const int sizeName, const int price)
        : type{ new char[sizeType + 1] }, sizeType{ sizeType },
        name{ new char[sizeName + 1] }, sizeName{ sizeName }, price{ price }
    {
        strcpy_s(this->type, sizeType + 1, type);
        strcpy_s(this->name, sizeName + 1, name);
    }

    ~Overcoat() {
        delete[] type;
        delete[] name;
    }

    Overcoat(const Overcoat& other)
        : type{ new char[other.sizeType + 1] }, sizeType{ other.sizeType },
        name{ new char[other.sizeName + 1] }, sizeName{ other.sizeName }, price{ other.price }
    {
        strcpy_s(this->type, sizeType + 1, other.type);
        strcpy_s(this->name, sizeName + 1, other.name);
    }
    Overcoat(Overcoat&& moved) {
        type = moved.type;
        moved.type = nullptr;
        sizeType = moved.sizeType;
        name = moved.name;
        moved.name = nullptr;
        sizeName = moved.sizeName;
        price = moved.price;
        moved.sizeType = 0;
        moved.sizeName = 0;
        moved.price = 0;
    }

    Overcoat& operator=(const Overcoat& other) {
        if (this == &other)
            return *this;

        delete[] type;
        delete[] name;

        type = new char[other.sizeType + 1];
        sizeType = other.sizeType;
        strcpy_s(type, sizeType + 1, other.type);

        name = new char[other.sizeName + 1];
        sizeName = other.sizeName;
        strcpy_s(name, sizeName + 1, other.name);

        price = other.price;

        return *this;
    }

    friend bool operator==(const Overcoat& overcoat1, const Overcoat& overcoat2) {
        return strcmp(overcoat1.type, overcoat2.type) == 0;
    }

    friend bool operator>(const Overcoat& overcoat1, const Overcoat& overcoat2) {
        return overcoat1.price > overcoat2.price;
    }
};

int main() {
    Overcoat overcoat1{ "Куртка", 6, "ООО", 3, 100000 };
    Overcoat overcoat2{ "Куртка", 6, "ООО", 3, 150000 };

    cout << "Равенство: " << (overcoat1 == overcoat2) << endl;
    cout << "Сравнение цен: " << (overcoat1 > overcoat2) << endl;

    Overcoat overcoat3 = overcoat2;

    return 0;
}

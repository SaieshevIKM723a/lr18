#include <iostream>

using namespace std;

class ComplexNumber {
private:
    double realPart;
    double imaginaryPart;

public:
    ComplexNumber(double realPart, double imaginaryPart) {
        this->realPart = realPart;
        this->imaginaryPart = imaginaryPart;
    }

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    bool operator==(const ComplexNumber& other) const {
        return (realPart == other.realPart) && (imaginaryPart == other.imaginaryPart);
    }

    bool operator<(const ComplexNumber& other) const {
        return (realPart < other.realPart) || ((realPart == other.realPart) && (imaginaryPart < other.imaginaryPart));
    }

    bool operator>(const ComplexNumber& other) const {
        return (realPart > other.realPart) || ((realPart == other.realPart) && (imaginaryPart > other.imaginaryPart));
    }

    ComplexNumber& operator=(const ComplexNumber& other) {
        if (this != &other) {
            realPart = other.realPart;
            imaginaryPart = other.imaginaryPart;
        }
        return *this;
    }

    double getRealPart() const {
        return realPart;
    }

    double getImaginaryPart() const {
        return imaginaryPart;
    }
};

int main() {
    ComplexNumber num1(3.0, 4.0);
    ComplexNumber num2(2.0, -5.0);

    ComplexNumber sum = num1 + num2;
    cout << "Sum: " << sum.getRealPart() << " + " << sum.getImaginaryPart() << "i" << endl;

    if (num1 == num2) {
        cout << "Numbers are equal" << endl;
    }
    else if (num1 < num2) {
        cout << "First number is less than the second number" << endl;
    }
    else if (num1 > num2) {
        cout << "First number is greater than the second number" << endl;
    }

    ComplexNumber num3(0.0, 0.0);
    num3 = num1;
    cout << "Assigned value: " << num3.getRealPart() << " + " << num3.getImaginaryPart() << "i" << endl;

    return 0;
}

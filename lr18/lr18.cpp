#include <iostream>

using namespace std;

class Complex {
private:
    double real; 
    double imaginary; 

public:
  
    Complex() : real(0), imaginary(0) {}
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    Complex& operator+(const Complex& other) {
        Complex result(real + other.real, imaginary + other.imaginary);
        return result;
    }

    bool operator==(const Complex& other) const {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    bool operator<(const Complex& other) const {
        if (real < other.real) {
            return true;
        }
        else if (real == other.real) {
            return imaginary < other.imaginary;
        }
        else {
            return false;
        }
    }

    Complex& operator=(const Complex& other) {
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Complex& complex) {
        out << complex.real << " + " << complex.imaginary << "i";
        return out;
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);

    Complex sum = c1 + c2;
    cout << "c1 + c2 = " << sum << endl; 

    cout << "c1 == c2: " << (c1 == c2) << endl; 
    cout << "c1 < c2: " << (c1 < c2) << endl; 

    c1 = c2;
    cout << "c1 after assignment c2: " << c1 << endl; 

    return 0;
}

#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class Fraction {
public:
    double dividend;
    double divisor;
    static int countOfFractions;
    Fraction(int dividend, int divisor) {
        this->dividend = dividend / gcd(dividend, divisor);
        this->divisor = divisor / gcd(dividend, divisor);
        countOfFractions++;
    }
    static int gcd(int n, int m) {
        while (m)
        {
            int temp = m;
            m = n % m;
            n = temp;
        }
        return n;
    }
    Fraction* operator + (Fraction n) {
        return this->doubleAsFraction(this->toDouble() + n.toDouble());
    }
    Fraction* operator - (Fraction n) {
        return this->doubleAsFraction(this->toDouble() - n.toDouble());
    }
    Fraction* operator * (Fraction n) {
        return this->doubleAsFraction(this->toDouble() * n.toDouble());
    }
    Fraction* operator / (Fraction n) {
        return this->doubleAsFraction(this->toDouble() / n.toDouble());
    }
    static void printAsFraction(double decimal_fraction) {
        Fraction* fraction = doubleAsFraction(decimal_fraction);
        cout << fraction->dividend << "/" << fraction->divisor << endl;
    }
    static void printAsFraction(char* decimal_fraction) {
        double n = stod(decimal_fraction);
        printAsFraction(n);
    }
    void print() {
        cout << dividend << "/" << divisor << endl;
    }
private:
    double toDouble() {
        return dividend / divisor;
    }
    static Fraction* doubleAsFraction(double number) {
        double intVal = floor(number);
        double fVal = number - intVal;
        const long pVal = pow(10, 9);
        long long gcdVal
            = gcd(round(fVal * pVal), pVal);
        long long num
            = round(fVal * pVal) / gcdVal;
        long long deno = pVal / gcdVal;
        return new Fraction((intVal * deno) + num, deno);
    }
};
int Fraction::countOfFractions = 0;
int main()
{
    setlocale(LC_ALL, "Rus");

    Fraction* fraction1 = new Fraction(1, 4);
    Fraction* fraction2 = new Fraction(5, 25);
    string str = "2,5";
    char fraction3[10];
    strcpy(fraction3, str.c_str());
    Fraction* fraction5 = *fraction1 + *fraction2;
    Fraction* fraction6 = *fraction1 * *fraction2;
    Fraction* fraction7 = *fraction1 - *fraction2;
    Fraction* fraction8 = *fraction1 / *fraction2;

    fraction1->print();
    fraction2->print();
    Fraction::printAsFraction(fraction3);
    fraction5->print();
    fraction6->print();
    fraction7->print();
    fraction8->print();
    cout << Fraction::gcd(45, 564) << endl;
    cout << Fraction::countOfFractions << endl;
}
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>

class Polynomial
{
    public:
        int degree = 0;
        std::vector<float> coef;
        Polynomial();
        virtual ~Polynomial();
        void set_degree(int);
        void define();
        void display();

        Polynomial operator!();
        Polynomial operator/(const Polynomial&);
        Polynomial operator%(const Polynomial&);
        Polynomial operator*(const Polynomial&);
        Polynomial operator~();
        Polynomial operator+(const Polynomial&);
        Polynomial operator-(const Polynomial&);

    protected:
    private:
};

#endif // POLYNOMIAL_H

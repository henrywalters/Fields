#include "Polynomial.h"
#include <iostream>

Polynomial::Polynomial()
{
    //ctor
}

Polynomial::~Polynomial()
{
    //dtor
}


Polynomial Polynomial::operator~()
{
    Polynomial out;
    out.set_degree(degree);
    std::vector<float> vec;

    for (int i = degree; i >= 0; i--)
    {
        vec.push_back(coef[i]);
    }
    out.coef = vec;

    return out;
}

void Polynomial::set_degree(int deg)
{
    degree = deg;
}
void Polynomial::define()
{
    for (int i = 0; i <= degree; i++)
    {
        std::cout << "coefficient at x^" << i << " : ";
        float input;
        std::cin >> input;
        coef.push_back(input);
    }

}
void Polynomial::display()
{
    std::cout << "\n\n";
    for (int i = degree; i >= 0; i--)
    {
        if (i == 0)
        {
            std::cout << coef[i];
        }
        else
        {
            std::cout << coef[i] << "x^" << i << " + ";
        }
    }
    std::cout << "\n\n";
}

Polynomial Polynomial::operator/(const Polynomial& p)
{
    Polynomial out;
    Polynomial divisor;
    divisor.set_degree(p.degree);

    for (int i = 0; i <= p.degree; i++)
    {
         divisor.coef.push_back(p.coef[i]);
    }

    Polynomial running;
    running.set_degree(degree);
    for (int i = degree ; i >= 0; i--) { running.coef.push_back(coef[i]); }

    out.set_degree(degree - p.degree);

    for (int i = 0; i <= degree - p.degree; i++)
    {
        Polynomial scalar;
        for (int i = 0; i <= degree - p.degree; i++){ scalar.coef.push_back(0);}
        scalar.coef[degree - p.degree - i] = (running.coef[i]/p.coef[p.degree]);
        scalar.set_degree(degree - p.degree);


        running = ~running;
        out.coef.push_back(scalar.coef[degree - p.degree - i]);
        Polynomial test;
        scalar.display();
        running.display();
        test = divisor*scalar;
        test.display();
        running = running-test;

        running = ~running;
    }
    out = ~out;
    return out;
}
Polynomial Polynomial::operator*(const Polynomial& p)
{
    Polynomial out;
    out.set_degree(degree + p.degree);
    std::vector<float> cos;
    for (int i = 0; i <= (degree + p.degree); i++)
    {
        cos.push_back(0);

    }

    for (int i = 0; i <= degree; i++)
    {
        for (int j = 0; j <= p.degree; j ++)
        {

            cos[i + j] += (coef[i] *p.coef[j]);
        }
    }
    out.coef = cos;
    return out;
}
Polynomial Polynomial::operator+(const Polynomial& p)
{
    Polynomial out;
    if (degree > p.degree)
    {
        out.set_degree(degree);
    }
    else { out.set_degree(p.degree); }
    for (int i = 0; i <= out.degree; i++)
    {
        if (i <= degree && i <= p.degree)
        {
            out.coef.push_back(coef[i] + p.coef[i]);
        }
        else if (i <= degree && i > p.degree)
        {
            out.coef.push_back(coef[i]);
        }
        else if (i > degree && i <= p.degree)
        {
            out.coef.push_back(p.coef[i]);
        }
        else
        {

        }
    }
    return out;
}
Polynomial Polynomial::operator-(const Polynomial& p)
{
    Polynomial out;
    if (degree > p.degree)
    {
        out.set_degree(degree);
    }
    else { out.set_degree(p.degree); }
    for (int i = 0; i <= out.degree; i++)
    {
        if (i <= degree && i <= p.degree)
        {
            out.coef.push_back(coef[i] - p.coef[i]);
        }
        else if (i <= degree && i > p.degree)
        {
            out.coef.push_back(coef[i]);
        }
        else if (i > degree && i <= p.degree)
        {
            out.coef.push_back(-1 * p.coef[i]);
        }
        else
        {

        }
    }
    return out;
}

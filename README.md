# Fields

#Introduction
Fields is a set of c++ classes that will allow for easy use and display of mathematical fields and other objects. It will be a work in progress and any suggestions will gladly be implemented. Also feel free to contribute :)

#Polynomials 
Define a polynomial element in the following way:

Polynomial poly1;
poly1.set_degree(4); // note any positive integer degree will work
poly1.define(); // manually input the poly
poly1.display(); //shows poly in the form ax^4 + bx^3 + cx^2 + dx^1 +e

Let x, y, z be polynomials, then the following binary operations hold:
z = x + y; z = x - y; z = x * y; z = x / y; z = x % y; If at any time you need to flip the order of a polynomial (which is useful in construction within the class) you may say x = ~x;


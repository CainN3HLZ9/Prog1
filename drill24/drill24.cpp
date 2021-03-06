#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <complex>
#include <numeric>
#include "./Matrix.h"
#include "./MatrixIO.h"

using Numeric_lib::Matrix;

void sqrt_out()
{
    int val;
    std::cin >> val;
    if (val < 0)
        std::cout << "no square root\n";
    else
        std::cout << sqrt(val) << '\n';
}

int main()
try {
    std::cout << "Drill 1:\n"
              << "char: " << sizeof(char) << '\n'
              << "short: " << sizeof(short) << '\n'
              << "int: " << sizeof(int) << '\n'
              << "long: " << sizeof(long) << '\n'
              << "float: " << sizeof(float) << '\n'
              << "double: " << sizeof(double) << '\n'
              << "int*: " << sizeof(int*) << '\n'
              << "double*: " << sizeof(double*) << "\n\n";

    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    std::cout << "Drill 2:\n"
              << "Matrix<int>(10): " << sizeof(a) << '\n'
              << "Matrix<int>(100): " << sizeof(b) << '\n'
              << "Matrix<double>(10): " << sizeof(c) << '\n'
              << "Matrix<int,2>(10,10): " << sizeof(d) << '\n'
              << "Matrix<int,3>(10,10,10): " << sizeof(e) << "\n\n";

    std::cout << "Drill3:\n"
              << "Matrix<int>(10): " << a.size() << '\n'
              << "Matrix<int>(100): " << b.size() << '\n'
              << "Matrix<double>(10): " << c.size() << '\n'
              << "Matrix<int,2>(10,10): " << d.size() << '\n'
              << "Matrix<int,3>(10,10,10): " << e.size() << "\n\n";

    std::cout << "Drill 4:\n";
    std::cout << "Vigyen be inteket négyzetgyök számoláshoz:\n";
    for (int i = 0; i < 5; ++i)
        sqrt_out();
    std::cout << "Drill 5:\n";
    std::cout << "Vigyen be 10 float típusú elemet a mátrixba:\n";
    const int entries = 10;

    Matrix<double> md(entries);
    for (int i = 0; i < entries; ++i)
        std::cin >> md[i];

    std::cout << md << '\n';
    std::cout << "Drill 6:\n";
    std::cout << "N és M érték megadása: ";
    int m, n;
    std::cin >> m >> n;
    std::cout << '\n';

    Matrix<double,2> mult_table(m,n);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            mult_table(i,j) = i == 0 || j == 0 ? i + j : i * j;

    for (int i = 0; i < mult_table.dim1(); ++i) {
        for (int j = 0; j < mult_table.dim2(); ++j)
            std::cout << std::setw(5) << mult_table(i,j);
        std::cout << '\n';
    }
    std::cout << "Drill 7:\n";
    std::cout << "Vigyen be 10 komplex számot:\n";
    Matrix<std::complex<double>> mcd (10);
    for (int i = 0; i < mcd.size(); ++i) {
        std::cin >> mcd[i];
    }

    std::cout << "Total: "
              << std::accumulate(mcd.data(), mcd.data() + mcd.size(),
                      std::complex<double>{})
              << '\n';
    std::cout << "Drill 8:\n";
    std::cout << "Vigyen be 6 int típusú változót a 2x3-as mátrixba:\n";
    Matrix<int,2> mm (2,3);
    for (int i = 0; i < mm.dim1(); ++i)
        for (int j = 0; j < mm.dim2(); ++j)
            std::cin >> mm[i][j];

    std::cout << mm << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

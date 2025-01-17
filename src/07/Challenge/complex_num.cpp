#include "complex_num.h"

complex_num::complex_num(double r, double i){
    // Write your code here
    real = r;
    imaginary = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    // Write your code here

    z.real = real + w.real;
    z.imaginary = imaginary + w.imaginary;

    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    // Write your code here

    z.real = real - w.real;
    z.imaginary = imaginary - w.imaginary;

    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    // Write your code here

    z.real = (real * w.real) - (imaginary * w.imaginary);
    z.imaginary = (real * w.imaginary) + (imaginary * w.real);

    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    // Write your code here

    z.real = ((real * w.real) + (imaginary * w.imaginary)) / ((w.real * w.real) + (w.imaginary * w.imaginary));
    return z;
}

void complex_num::print(std::ostream &os){
    // Write your code here
    if (imaginary >= 0.0) {
        os << real << " + i" << imaginary;
    } else {
        os << real << " - i" << imaginary * -1;
    }

    os << std::flush;
     
}
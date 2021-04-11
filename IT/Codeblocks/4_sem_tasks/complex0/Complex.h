class Complex {
    double re, im;
public:
    Complex (double Re = 0, double Im = 0) : re(Re), im(Im) {
    }

    /// return Complex&, not Complex --> no constructor call
    Complex& operator = (const Complex & z) {
        re = z.re;
        im = z.im;
        return *this;
    }

    double Re () const {
        return re;
    }

    double Im () const {
        return im;
    }


    const Complex& operator + () const {
        return *this;
    }
    Complex operator - () const {
        return Complex(-re, -im);
    }

    /// it's friend function ---> can use x.re instead of x.Re()
    friend Complex operator + (Complex x, const Complex & y);
    friend Complex operator - (Complex x, const Complex & y);

    friend Complex operator * (Complex x, const Complex & y);
    friend Complex operator / (Complex x, const Complex & y);
    friend Complex operator * (Complex x, double p);
    friend Complex operator / (Complex x, double p);

    /// here it's better to return reference to &this, not copy
    Complex& operator += (const Complex & y) {
        re += y.re;
        im += y.im;
        return *this;
    }

    Complex& operator -= (const Complex & y) {
        re -= y.re;
        im -= y.im;
        return *this;
    }

    Complex& operator *= (double p) {
        re *= p;
        im *= p;
        return *this;
    }

    Complex& operator *= (const Complex & y) {
        double a = re * y.re - im * y.im;
        double b = re * y.im + im * y.re;
        re = a;
        im = b;
        return *this;
    }

    Complex& operator /= (double p) {
        if (p) {
            re /= p;
            im /= p;
        }
        return *this;
    }

    Complex& operator /= (const Complex & y) {
        double a = re * y.re + im * y.im;
        double b = im * y.re - re * y.im;
        double frac = y.re * y.re + y.im * y.im;
        if (frac) {
            re = a / frac;
            im = b / frac;
        }
        return *this;
    }

    friend std::istream& operator >> (std::istream &is, Complex &c);
    friend std::ostream& operator << (std::ostream &os, const Complex &c);
};


Complex operator + (Complex x, const Complex & y) {
    return x += y;
}

Complex operator - (Complex x, const Complex & y) {
    return x -= y;
}

/// here it's more efficient to define a separate function for double type
/// ---> no constructors, no casting from double to Complex
/// !! double p !!   not  "const double& p" ---> easy, efficient
Complex operator * (Complex x, double p) {
    return x *= p;
}

Complex operator * (Complex x, const Complex & y) {
    return x *= y;
}

Complex operator / (Complex x, double p) {
    return x /= p;
}

Complex operator / (Complex x, const Complex & y) {
    return x /= y;
}

std::istream& operator >> (std::istream &is, Complex &c) {
    double re = 0, im = 0;
    char i;
    if (is >> re) {
        if (is >> im) {
            if (!(is >> i && i == 'i'))
                is.setstate(std::ios_base::failbit);
        }
    }
    //c.re = re; c.im = im;
    c = Complex(re , im);
    return is;
}

std::ostream& operator << (std::ostream &os, const Complex &c) {
    os << c.Re() << std::showpos << c.Im() << "i" << std::noshowpos;
    return os;
}

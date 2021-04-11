#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <cstring>
/// In programmer's responsibility:
/// - remember about Vector sizes (he can change it as he wants at any time)
/// - remember about Vector's aim (what variable responses)
/// -

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <exception>
#include <stdexcept>
/// T is used instead of real type
template <class T>
class Vector {
private:
    unsigned N;          /// available for user
    unsigned real_size;  /// real size in memory
    T *a;

public:

    Vector(unsigned n = 0) : N(n), real_size(n), a(new T[N]()) {
    }
    Vector(const Vector < T > & x) {
        /// constructor --> intialization --> new object
        /// --> don't need delete [] a;
        N = x.N;
        real_size = x.N;
        a = new T[N];
        for (unsigned i = 0; i < N; ++i) {
            a[i] = x[i];
        }
    }


    void push(const T& x) {
        /// if we use all allocated memory
        if (N == real_size) {
            ++real_size;
            T *b = new T[N+1];
            for (unsigned i = 0; i < N; ++i)
                b[i] = a[i];
            delete [] a;
            b[N] = x;
            a = b;
        } else {
            /// if we use only part of it
            a[N] = x;
        }
        ++N;
    }
    /// insertion in sorted vector
    unsigned insert(const T& x) {
        unsigned i, index;
        if (N == real_size) {
            ++real_size;
            T *b = new T[N+1];
            for (i = 0, index = 0; i < N && a[i] < x; ++i, ++index) {
                b[i] = a[i];
            }
            b[i] = x;
            for (; i < N; ++i) {
                b[i + 1] = a[i];
            }
            delete [] a;
            a = b;
        } else {
            for (i = 0, index = 0; i < N && a[i] < x; ++i, ++index);
            for (i = N; i > index; --i) {
                a[i] = a[i - 1];
            }
            a[index] = x;
        }
        ++N;
        return index;
    }
    void insert(const T& x, const unsigned index) {
        if (index > N) {
            throw std::invalid_argument("");
        }
        unsigned i;
        if (N == real_size) {
            ++real_size;
            T *b = new T[N+1];
            for (i = 0; i < index; ++i) {
                b[i] = a[i];
            }
            b[i] = x;
            for (; i < N; ++i) {
                b[i + 1] = a[i];
            }
            delete [] a;
            a = b;
        } else {
            for (i = N; i > index; --i) {
                a[i] = a[i - 1];
            }
            a[index] = x;
        }
        ++N;
    }


    unsigned size() const;
    unsigned resize(unsigned new_size) {
        if (new_size <= real_size) {
            for (unsigned i = N; i < new_size; ++i) {
                a[i] = T();
            }
            N = new_size;
            return N;
        }

        /// new_size > real_size >= N
        T* b = new T[new_size]();
        for (unsigned i = 0; i < N; ++i) {
            b[i] = a[i];
        }
        delete [] a;
        a = b;
        N = new_size;
        real_size = new_size;
        return N;
    }


    unsigned find(const T& x) const {
        /// find first appearance
        unsigned index;
        for (index = 0; index < N && a[index] != x; ++index);
        if (index == N) {
            return -1;
        }
        return index;
    }
    T& operator[](unsigned index) const {
        if (index >= N) {
            throw std::invalid_argument("Wrong index in operator [] const");
        }
        return a[index];
    }
    T& operator[](unsigned index) {
        if (index >= N) {
            throw std::invalid_argument("Wrong index in operator []");
        }
        return a[index];
    }


    Vector<T>& operator = (const Vector < T > & x);
    Vector<T>& operator = (const std::vector < T > & x);
    bool operator == (const Vector < T > & x);
    bool operator == (const std::vector < T > & x);
    bool operator != (const Vector < T > & x);
    bool operator != (const std::vector < T > & x);


    friend Vector<T> operator + (Vector < T > x, const Vector < T > & y) {
        return x += y;
    }
    friend Vector<T> operator - (Vector < T > x, const Vector < T > & y) {
        return x -= y;
    }
    friend Vector<T> operator * (Vector < T > x, double p) {
        return x *= p;
    }
    friend Vector<T> operator / (Vector < T > x, double p) {
        return x /= p;
    }
    Vector<T>& operator += (const Vector < T > & y) {
        if (N == y.N) {
            for (unsigned i = 0; i < N; ++i) {
                a[i] += y[i];
            }
        }
        return *this;
    }
    Vector<T>& operator -= (const Vector < T > & y) {
        if (N == y.N) {
            for (unsigned i = 0; i < N; ++i) {
                a[i] -= y[i];
            }
        }
        return *this;
    }
    Vector<T>& operator *= (double p) {
        for (unsigned i = 0; i < N; ++i) {
            a[i] *= p;
        }
        return *this;
    }
    Vector<T>& operator /= (double p) {
        for (unsigned i = 0; i < N; ++i) {
            a[i] /= p;
        }
        return *this;
    }


    friend std::istream& operator >> (std::istream& in, Vector < T > & x) {
        int n;
        in >> n;
        if (n < 0) {
            cerr << "Wrong vector size" << endl;
            return in;
        }
        x.resize(n);
        for (unsigned i = 0; i < x.N; ++i) {
            in >> x[i];
        }
        return in;
    }
    friend std::ostream& operator << (std::ostream& out, const Vector < T > & x) {
        out << "size of vector : " << x.N << endl;
        out << "vector : ";
        for (unsigned i = 0; i < x.N; ++i) {
            out << x[i] << " ";
        }
        return out;
    }


    T pop() {
        /*if (N > 0) {
            T *b = new T[N-1];
            for (unsigned i = 0; i < N - 1; ++i)
                b[i] = a[i];
            delete [] a;
            a = b;
            --N;
        }*/
        /// we don't actually need free memory here
        /// it will be done in
        /// pop/=/~Vector/insert/resize/etc...
        if (N == 0) {
            throw std::runtime_error("Pop from empty vector");
        }
        --N;
        return a[N];
        //runtime_error("");
    }
    T erase(const unsigned& index) {
        if (N == 0 || index >= N) {
            throw std::runtime_error("Erase from empty vector");
        }
        T result;
        result = a[index];
        for (unsigned i = index; i < N - 1; ++i) {
            a[i] = a[i+1];
        }
        --N;
        return result;
    }
    void clear() {
        //delete [] a;
        //a = new T[0];
        N = 0;
    }
    ~Vector() {
        ///cout << "Destructor" << endl;
        delete [] a;
        /// it is bad if (a != NULL)
        /// but a is local variable ---> when destructor is called
        /// it means that object "dies" ---> "a" dies too
        //a = NULL;
        //N = 0;
        //real_size = 0;
    }
};

/// small --> inline
/// definition out of class --> write "template"
/// note: Vector<T>, not Vector
template <class T>
inline unsigned Vector<T>::size() const {
    return N;
}

template <class T>
Vector<T>& Vector<T>::operator = (const Vector < T > & x) {
    if (N != x.N) {
        this->resize(x.N);
    }
    for (unsigned i = 0; i < N; ++i) {
        a[i] = x[i];
    }
    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator = (const std::vector < T > & x) {
    if (N != x.size()) {
        this->resize(x.size());
    }
    for (unsigned i = 0; i < N; ++i) {
        a[i] = x[i];
    }
    return *this;
}

template <class T>
bool Vector<T>::operator == (const Vector < T > & x) {
    if (N != x.N) {
        return false;
    }
    for (unsigned i = 0; i < N; ++i) {
        if (a[i] != x[i]) {
            return false;
        }
    }
    return true;
}

template <class T>
bool Vector<T>::operator == (const std::vector < T > & x) {
    if (N != x.size()) {
        return false;
    }
    for (unsigned i = 0; i < N; ++i) {
        if (a[i] != x[i]) {
            return false;
        }
    }
    return true;
}

template <class T>
bool Vector<T>::operator != (const Vector < T > & x) {
    return !(*this == x);
}

template <class T>
bool Vector<T>::operator != (const std::vector < T > & x) {
    return !(*this == x);
}

template<typename T>
std::ostream& operator << (std::ostream& out, const std::vector < T > & x) {
    out << "size of vector : " << x.size() << endl;
    out << "vector : ";
    for (unsigned i = 0; i < x.size(); ++i) {
        out << x[i] << " ";
    }
    return out;
}


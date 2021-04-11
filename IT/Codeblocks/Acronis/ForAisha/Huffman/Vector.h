/// Vector class realisation


/// T is used instead of real type
template <class T>
class Vector {
private:
    unsigned N;
    T *a;

public:
    Vector() {
        N = 0;
        a = new T[N];
    }

    Vector(int n) {
        N = (n >= 0) ? n : 0;
        a = new T[N];
    }

    void push(const T& x) {
        T *b = new T[N+1];
        for (unsigned i = 0; i < N; ++i)
            b[i] = a[i];
        b[N] = x;
        delete [] a;
        a = b;
        ++N;
    }

    void pop() {
        if (N > 0) {
            T *b = new T[N-1];
            for (unsigned i = 0; i < N - 1; ++i)
                b[i] = a[i];
            delete [] a;
            a = b;
            --N;
        }
    }

    unsigned insert(const T& x) {
        T *b = new T[N+1];
        for (unsigned i = 0; i < N; ++i)
            b[i] = a[i];
        b[N] = x;
        delete [] a;
        unsigned index;
        for (index = N; index && b[index] < b[index-1]; --index) {
            std::swap(b[index], b[index-1]);
        }
        a = b;
        ++N;
        return index;
    }

    void insert(const T& x, const unsigned& index) {
        T *b = new T[N+1];
        for (unsigned i = 0; i <= N; ++i) {
            if (i < index)
                b[i] = a[i];
            if (i == index)
                b[i] = x;
            if (i > index)
                b[i] = a[i-1];
        }
        delete [] a;
        a = b;
        ++N;
    }

    unsigned find(const T& x) const {
        /// find first appearance
        for (unsigned index = 0; index < N; ++index) {
            if (a[index] == x) {
                return index;
            }
        }
        return -1;
    }

    void erase(const unsigned& index) {
        if (N && 0 <= index && index < N) {
            T *b = new T[N-1];
            for (unsigned i = 0; i < N - 1; ++i) {
                if (i < index) {
                    b[i] = a[i];
                } else {
                    b[i] = a[i+1];
                }
            }
            delete [] a;
            a = b;
            --N;
        }
    }

    ~Vector() {
        delete [] a;
        /// it is bad if (a != NULL)
        //a = NULL;
        N = 0;
    }

    void clear() {
        delete [] a;
        a = new T[0];
        N = 0;
    }

    T& operator[](int index) const {
        return a[index];
    }

    unsigned size() const;
};

template <class T> /// method is out of class definition --> need to write method template
unsigned Vector<T>::size() const {
    return N;
} /// note: Array<T>, not Array


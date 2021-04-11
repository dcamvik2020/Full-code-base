template<typename T, unsigned N>
class Array {
public:
    const unsigned size = N; /// const size
    T arr[N];           /// not dinamicly allocated memory

    T& operator [] (unsigned i) {
        return arr[i % N];
    }
};

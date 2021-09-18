
#define f(a, b) a##b
#define g(a) #a
#define h(a) g(a)

//#define r(a) #(h(a)) /// invalid way of using #

int main() {
  int a, b;
  g(f(a, b));
  h(f(a, b));

  /// r(f(a, b)); /// CE ...
}

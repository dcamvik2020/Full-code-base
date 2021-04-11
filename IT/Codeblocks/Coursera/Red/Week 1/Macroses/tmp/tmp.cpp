
#define f(a, b) a##b
#define g(a) #a
#define h(a) g(a)

int main() {
  int a, b;
  g(f(a, b));
  h(f(a, b));
}

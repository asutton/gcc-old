// { dg-do compile }
// { dg-options "-std=c++2a" }

// Test basic expression requirements

// req13.C

template<class T, class...Args>
concept Constructible =
  requires(Args&&...args) {
    T {((Args&&)(args))...};
    new T{((Args&&)(args))...};
  };

template<typename T>
  requires Constructible<T> 
struct A { };

A<int> a;

// req19.C

struct B
{
  template <class T> 
  void f(T t) requires requires (T tt) { tt; }
  { }
};

int main()
{
  B().f(42);
}

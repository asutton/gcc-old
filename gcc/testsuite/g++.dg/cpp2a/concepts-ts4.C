// { dg-do compile }
// { dg-options "-std=c++2a -fconcepts-ts" }

// Basic tests for introduction syntax.

template<typename T>
concept True = true;

template<typename T>
concept False = false;

True{T} void f1(T) { }
False{T} void f2(T) { }

void driver()
{
  f1(0);
  f2(0); // { dg-error "cannot call function" }
}

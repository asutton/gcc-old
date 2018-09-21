// PR c++/66834
// { dg-options "-std=c++2a" }

template <class From, class To>
concept ExplicitlyConvertible =
  requires (From&& f) {
    static_cast<To>((From&&)f);
  };

template <class T, class... Args>
concept Constructible =
  ExplicitlyConvertible<Args..., T> ||
  requires (Args&&... args) {
    T{((Args&&)(args))...};
  };

template <class T, class...Args>
constexpr bool constructible() { return false; }

template<typename T, typename... Args>
  requires Constructible<T, Args...>
constexpr bool constructible() { return false; }

int main() {}

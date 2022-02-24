#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <string>

namespace wrap_example {

class Greeting {
 public:
  std::string name = "";

  Greeting(){};
  Greeting(const std::string& s) : name(s) {}

  /// Print a greeting and optionally add name
  void sayHello() const;

  /// An example of declaring a simple pointer type
  void takeAPointer(const double* d) const {}

  /**
   * Example of optional parameter.
   * For Pybind, we use nullptr which gets typecast to None.
   */
  void printOptional(boost::optional<std::string> s = boost::none) const {
    if (s) {
      std::cout << *s << std::endl;
    }
  }

  /// Print a farewell with a shared pointer
  void sayGoodbye(boost::shared_ptr<Greeting> x) const;

  Greeting operator+(const Greeting& other) const {
    return Greeting(this->name + " " + other.name);
  }
};

template <typename T, typename R>
R CoolFunction(const T& s) {
  std::cout << "Cool function says " << s << std::endl;
  R ret;
  return ret;
}

enum Pet { Dog = 0, Cat, Hamster = 2, Goldfish = 3 };

}  // namespace wrap_example

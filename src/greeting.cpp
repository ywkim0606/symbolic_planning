#include "greeting.h"

namespace wrap_example {

/// Print a greeting
void Greeting::sayHello() const {
  std::cout << "Hello from C++!" << (name.empty() ? "" : " " + name)
            << std::endl;
}

/// Print a farewell
void Greeting::sayGoodbye(boost::shared_ptr<Greeting> x) const {
  std::cout << "Goodbye, from robot " << x->name << std::endl;
}

};  // namespace wrap_example

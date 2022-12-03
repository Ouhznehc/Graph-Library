#include <string>
using namespace std;

#include <Exceptions/NegativeCycleException.h>

NegativeCycleException::NegativeCycleException(const string &s) : message(s) {}

string NegativeCycleException::GetMessage() const {
  return message;
}

ostream &operator<<(ostream &os, const NegativeCycleException &e) {
  return os << e.GetMessage();
}


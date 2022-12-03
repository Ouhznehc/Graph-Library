#ifndef NEGATIVE_CYCLE_EXCEPTION
#define NEGATIVE_CYCLE_EXCEPTION

#include <iostream>
#include <exception>
#include <string>
#include "GLException.h"

class NegativeCycleException : public GLException
{
 protected:
  std::string message;
 public:
  explicit NegativeCycleException(const std::string &s);
  virtual std::string GetMessage() const;
};

std::ostream &operator<<(std::ostream &os, const NegativeCycleException &e);

#endif
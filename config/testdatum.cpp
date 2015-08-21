#include <map>
#include <iostream>
#include <stdexcept>
#include "MinVRDatum.h"
#include "MinVRDatumFactory.h"

int main() {
  // suppose this is the "singleton" instance for the MinVRDatumFactory
  // (this is an example! Singletons are not implemented like this!)
  MinVRDatumFactory *factory = new MinVRDatumFactory;
  factory->RegisterMinVRDatum(MVRFLOAT, CreateMinVRDatumDouble);
  factory->RegisterMinVRDatum(MVRINT, CreateMinVRDatumInt);

  int i = 14;
  double f = 3.1415926;
  MinVRDatum* s1 = factory->CreateMinVRDatum(MVRINT, &i, std::string("ralph"));
  MinVRDatum* s2 = factory->CreateMinVRDatum(MVRFLOAT, &f, std::string("henry"));
  s1->doSomething();
  s2->doSomething();
  // will throw an error
  try {
    MinVRDatum* s3 = factory->CreateMinVRDatum(-1, &f, std::string("lloyd"));
    s3->doSomething();
  } catch(const std::exception& e) {
    std::cout<<"caught exception: "<<e.what()<<std::endl;
  }
  return 0;
}
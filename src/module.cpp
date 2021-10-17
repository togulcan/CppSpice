/// Implementation of the sample library module.
///
#include "CppSpice/module.hpp"

using CppSpice::SampleClass;


int SampleClass::add(int x) const
{
    return CppSpice::add(num, x);
}


int CppSpice::add(int x, int y)
{
    return x + y;
}

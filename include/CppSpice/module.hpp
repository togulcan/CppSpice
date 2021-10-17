/// Interface for the sample library module.
///
/// @file
#ifndef CPPSPICE_MODULE_HPP
#define CPPSPICE_MODULE_HPP


namespace CppSpice
{
    /// Sample class.
    ///
    class SampleClass
    {
    public:
        /// Construct a SampleClass object.
        ///
        /// @param num any integer value
        SampleClass(int num=0) : num{num} {}
        
        /// Add a number.
        ///
        /// @param x any integer value
        /// @returns the sum of num and x.
        int add(int x) const;
        
    private:
        const int num;
    };
    
    /// Sample function.
    ///
    /// @param x any integer value
    /// @param y any integer value
    /// @returns the sum of x and y
    int add(int x, int y);
}

#endif  // CPPSPICE_MODULE_HPP 

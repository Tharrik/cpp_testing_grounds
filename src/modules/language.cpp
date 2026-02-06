#include <modules/language.hpp>

#include <stdexcept>
#include <iostream>

void language::noexceptSpecifiers()
{
    // noexcept specifiers are used to indicate that a function does not throw exceptions. This can help the compiler optimize code and can also be used for better error handling.
    // This is a promise that the function will not throw exceptions, is not enforced neither at compile time nor at runtime, but it is a convention that should be followed by the programmer.

    class Aux
    {
        int i;

    public:
        Aux(int i) : i(i)
        {}

        void Foo() noexcept
        {
            // This function is guaranteed not to throw exceptions.
            std::cout << "noexcept Foo" << std::endl;
            throw std::runtime_error("This will cause std::terminate to be called.");
        }
    };

    Aux aux(5);

    // The noexcept operator can be used to check if a function is declared as noexcept.
    // It does not check if the function actually throws exceptions at runtime, but rather if it is declared with the noexcept specifier.
    // Also, it does not invoke the function, so it will not cause std::terminate to be called even if the function throws an exception.
    // This is used for functions whose implementation is not visible at the point of the call, such as template functions or functions in a different translation unit (like libraries).
    bool isNoexcept = noexcept(aux.Foo());
    if(isNoexcept)
    {
        // Since aux.Foo() is declared as noexcept, we can call it without worrying about exceptions.
        // However, since aux.Foo() actually throws an exception, this will cause std::terminate to be called.
        // So noexcept is a promise (by convention) that the function will not throw exceptions, but it does not enforce this at runtime.
        aux.Foo();
    }
    else
    {
        // If the function is not declared as noexcept, we should handle exceptions properly.
        // Again, this is used for functions whose implementation is not visible at the point of the call, so we cannot determine if they throw exceptions or not.
        try
        {
            aux.Foo();
        }
        catch(const std::exception& e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
}
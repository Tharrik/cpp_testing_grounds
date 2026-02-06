#include <modules/memory.hpp>

#include <iostream>

void memory::referenceVsPointer()
{
    // We can use references or pointers to refer to an objetc in C++.
    // References are safer and easier to use than pointers, but they cannot be null and they cannot be reseated to refer to a different object after they are initialized.
    // Pointers can be null and can be reseated to refer to a different object, but they require more care to avoid issues like dangling pointers or memory leaks.

    class Aux {
    private:
        int i;
    public:
        Aux(int i) : i(i) {}

        static void Foo(Aux& ref)
        {
            // When we pass an object by reference, we are passing a reference to the original object, so any changes made to the reference will affect the original object.
            // Also, the reference itself is not an object, so it does not have its own address in memory.
            // If we try to take the address of the reference, we will get the address of the original object, not the reference itself.
            std::cout << "Reference address: " << &ref << std::endl;
        }
    };

    Aux aux(5);

    // These two lines will print the same address, because the reference is just an alias for the original object.
    std::cout << "Object address: " << &aux << std::endl;
    Aux::Foo(aux);
}

void memory::objectPersistence()
{
    // In C++, the lifetime of an object is determined by its storage duration.
    // Objects can have automatic storage duration (local variables), dynamic storage duration (allocated with new), or static storage duration (global variables or static local variables).
    // Every time a function is called, a new stack frame is created for that function, and all local variables are allocated on that stack frame.
    // When the function returns, the stack frame is destroyed, and all local variables are also destroyed.
    // If we return a reference or a pointer to a local variable from a function, we will end up with a dangling reference or pointer, because the local variable will be destroyed when the function

    // This class does not allow to directly create an object of type Number, but it provides static methods to create objects of type Number either by value or by pointer.
    class Number {
    public:
        int i;
    private:
        Number(int i) : i(i) {
            std::cout << "Constructor called" << std::endl;
        }
        Number(const Number& other) : i(other.i) {
            std::cout << "Copy constructor called" << std::endl;
        }
        Number(Number&& other) = delete; // No need to implement move constructor for this class, but we can delete it to prevent its use.
        
    public:
        static Number Create()
        {
            // This will create a temporary object of type Number, and return it by value.
            // When the object is returned it will be copied to the caller, so the original object created in this function will be destroyed at the end of this function, but the copy will persist in the caller.
            return Number(10);
        }

        // static Number& CreateRef()
        // {
        //     // This will create a temporary object of type Number, and return it by reference.
        //     // When the object is returned, it will be a reference to the original object created in this function,
        //     // so when the function returns, the original object will be destroyed, leaving the reference dangling.
        //     // So unless we want to return a reference to an object that was created outside of this function, we should not return a reference to a local variable.
        //     return Number(10);
        // }

        static Number* CreatePtr()
        {
            // This will create a new object of type Number on the heap, and return a pointer to it.
            // The object created on the heap will persist until we delete it, so the pointer returned by this function will not be dangling,
            // as long as we remember to delete the object when we are done with it to avoid memory leaks.
            return new Number(10);
        }
    };

    class Aux {
    public:
        Number* ptr;
    public:
        Aux() : ptr(nullptr) {}
        
        void setNumber()
        {
            // Asume that Number is a class that we cannot modify, and we want to store a pointer to Number in Aux
            // We cannot create an object of type Number directly in Aux because its constructor is private,
            // so we have to use the static methods provided by Number to create objects of type Number.

            // This will not work because the object created by Create() will be destroyed at the end of this function, leaving ptr dangling.
            // Also, C++17 does not allow returning a reference to a local variable, so we cannot return a reference from Create() either.
            // This will fail to compile.
            // ptr = &Number::Create();

            // This will work because the object created by CreatePtr() will persist until we delete it, so ptr will not be dangling.
            ptr = Number::CreatePtr();
        }
    };

    Aux aux;
    aux.setNumber();
}

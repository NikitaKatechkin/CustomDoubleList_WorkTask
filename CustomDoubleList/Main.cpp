#include <iostream>

#include "CustomDoubleList.h"

int main()
{
    CustomDoubleList<int> test;

    test.PushFront(26);
    
    std::cout << test.Front() << std::endl;
    std::cout << test.Back() << std::endl;
    
    test.PushBack(25);
    
    std::cout << test.Front() << std::endl;
    std::cout << test.Back() << std::endl;

    std::cout << test.GetSize() << std::endl;
    
    test.Insert(1, 27);

    std::cout << test.Front() << std::endl;
    std::cout << test.Back() << std::endl;

    test.Insert(1, 27);
    
    std::cout << test.Front() << std::endl;
    std::cout << test.Back() << std::endl;

    test.Remove(1);

    std::cout << test.Front() << std::endl;
    std::cout << test.Back() << std::endl;
    
    test.PopFront();
    
    std::cout << test.Front() << std::endl;
    std::cout << test.Back() << std::endl;

    test.PopBack();

    std::cout << test.Front() << std::endl;
    std::cout << test.Back() << std::endl;
    
    test.Clear();

    return 0;
}

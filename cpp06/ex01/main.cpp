#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data myData = {1, 3};
    Data* ptr = &myData;
    std::cout << "============= Printing Content ==========\n";
    std::cout << "myData id: " << myData.id << " and value: " << myData.value << std::endl;
    std::cout << "ptr id: " << ptr->id << " and value: " << ptr->value << std::endl;
    std::cout << "ptr : " << ptr << std::endl;
    
    std::cout << "============= Serializing ==========\n";
    uintptr_t serialized =  Serializer::serialize(ptr);
    std::cout << "============= Printing Serialized ==========\n";
    std::cout << "serialized : " <<  serialized << std::endl;
    std::cout << "serialized in hex: 0x" << std::hex << serialized << std::endl;
    
    
    std::cout << "============= deSerializing ==========\n";
    Data * deserialized =  Serializer::deserialize(serialized);
    std::cout << "============= Printing deSerialized ==========\n";
    std::cout << "deserialized: " <<  deserialized << std::endl;

    std::cout << "============= Printing Content ==========\n";
    std::cout << "desrialized data's id: " << deserialized->id << " and value: " << deserialized->value << std::endl;
    
    std::cout << "============= comparing the pointers ==========\n";
    if ( ptr == deserialized)
        std::cout << " SUCCESS : Original pointer == deserialized pointer " << std::endl;
    else  
        std::cout << " FAILURE : Original pointer != deserialized pointer " << std::endl;
}
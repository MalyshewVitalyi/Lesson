#include <iostream>
#include <stdexcept>

class smart_array 
{
private:
    int* data;      
    size_t size;    
    size_t capacity; 

public:
    
    smart_array(size_t initial_capacity)
        : size(0), capacity(initial_capacity)
    {
        if (initial_capacity == 0) 
        {
            throw std::invalid_argument("Capacity must be greater than 0.");
        }
        data = new int[capacity];  
    }

    ~smart_array() 
    {
        delete[] data; 
    }

    void add_element(int element) 
    {
        if (size >= capacity) 
        {
            
            capacity *= 2; 
            int* new_data = new int[capacity];
            for (size_t i = 0; i < size; ++i) 
            {
                new_data[i] = data[i]; 
            }
            delete[] data; 
            data = new_data; 
        }
        data[size++] = element; 
    }

    int get_element(size_t index) const 
    {
        if (index >= size) 
        {
            throw std::out_of_range("Index out of range.");
        }
        return data[index]; 
    }
};

int main() 
{
    try 
    {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl; 
    }
    catch (const std::exception& ex) 
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
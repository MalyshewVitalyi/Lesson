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

        smart_array() 
    {
        delete[] data; 
    }

    
        smart_array(const smart_array& other)
        : size(other.size), capacity(other.capacity) 
    {
        data = new int[capacity]; 
        for (size_t i = 0; i < size; ++i) 
        {
            data[i] = other.data[i]; 
        }
    }

    
    smart_array& operator=(const smart_array& other) 
    {
        if (this != &other)
        { 
            delete[] data; 

            size = other.size;
            capacity = other.capacity;
            data = new int[capacity]; 
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = other.data[i]; 
            }
        }
        return *this;
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

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array; 

        for (size_t i = 0; i < 2; ++i) 
        {
            std::cout << arr.get_element(i) << std::endl; 
        }
    }
    catch (const std::exception& ex) 
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
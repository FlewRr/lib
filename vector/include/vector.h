#ifndef VECTOR_INCLUDE_VECTOR_H_20240407
#define VECTOR_INCLUDE_VECTOR_H_20240407

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector{
private:
    size_t size_, capacity;
    T* arr;
public:
    Vector(T arr_[], size_t size){
        if (size <= 0)
            throw std::invalid_argument("Negative size\n");

        size_ = size;
        capacity = size_ * 2;
        arr = new T[capacity];

        std::copy(arr_, arr_ + size_, arr);
    }

    Vector(){
        size_ = 0;
        capacity = 0;
        arr = new T[capacity];
    }

    ~Vector(){
        delete[] arr;
    }
    
    Vector(const Vector& other){
        size_ = other.size_;
        capacity = other.capacity;
        arr = new T[capacity];

        std::copy(other.arr, other.arr + other.size_, arr);
    }

    Vector(Vector&& other) noexcept{
        size_ = std::move(other.size_);
        capacity = std::move(other.capacity);
        arr = std::move(other.arr);

        other.size_ = 0;
        other.capacity = 0;
        other.arr = nullptr;
    }

    Vector& operator=(const Vector& other){
        Vector<T> new_other(other);
        std::swap(size_, new_other.size_);
        std::swap(arr, new_other.arr);
        std::swap(capacity, new_other.capacity);
        
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept{
        std::swap(arr, other.arr);
        std::swap(size_, other.size_);
        std::swap(capacity, other.capacity);

        return *this;
    }

    T& operator[](size_t index) const{
        if (index >= size_ || index < 0)
            throw std::invalid_argument("Index is out of bounds\n");

        return arr[index];
    }
    
    int size() const noexcept{
        return size_;
    }
    // size_t new_size ловит terminate called after throwing an instance of 'std::bad_array_new_length'
    void resize(int new_size){
        if (new_size <= 0)
            throw std::invalid_argument("Index is out of bounds\n");

        reserve(new_size);
        size_ = new_size;
    }

    void reserve(int new_capacity) noexcept{
        if (new_capacity <= capacity) return;

        T* new_arr = new T[new_capacity];
        
        for (int i = 0; i < size_; ++i)
            new_arr[i] = arr[i];
        
        delete[] arr;

        arr = new_arr;
        capacity = new_capacity;
    }

    void insert(T element, unsigned int pos){
        if (pos >= size_ || pos < 0)
            throw std::invalid_argument("Index is out of bounds\n");

        if (size_ + 1 > capacity)
            reserve(2*size_);

        int tmp2 = arr[pos];
        for (int i = pos; i < size_ + 1; ++i){
            int tmp1 = arr[i+1];
            arr[i+1] = tmp2;
            tmp2 = tmp1;
        }
        arr[pos] = element;
    }

    void push_back(const T& element) noexcept{
        if (size_ == 0)
            reserve(2);
        else if (size_ == capacity)
            reserve(2 * size_);

        arr[size_] = element;
        size_++;
    }
};

#endif

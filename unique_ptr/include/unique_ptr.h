#ifndef UNIQUE_PTR_INCLUDE_UNIQUEPTR_H_20240407
#define UNIQUE_PTR_INCLUDE_UNIQUEPTR_H_20240407

#include <memory>

template<class T, class Deleter=std::default_delete<T>>
class Unique_ptr {
    T* data;
    Deleter deleter;
public:
    Unique_ptr(T* data_, Deleter deleter_): data(data_), deleter(std::forward<Deleter>(deleter_)){
    }

    Unique_ptr(T* data_): data(data_){
    }
    Unique_ptr(): data(nullptr){
    }

    ~Unique_ptr(){
        reset();
    }

    Unique_ptr(const Unique_ptr& other) = delete;
    Unique_ptr& operator=(const Unique_ptr& other) = delete;

    Unique_ptr(Unique_ptr&& other) noexcept : data(nullptr) {
        other.swap(*this);
    };

    Unique_ptr& operator=(Unique_ptr&& other) noexcept{
        other.swap(*this);
        return *this;
    }

    T* operator->() const {
        return data;
    }

    T& operator*() const {
        return *data;
    }

    T* get() const {
        return data;
    }

    Deleter get_deleter() const{
        return deleter;
    }

    T* release() noexcept {
        T* result = nullptr;
        std::swap(result, data);
        return result;
    }

    void swap(Unique_ptr& other) noexcept{
        std::swap(data, other.data);
        std::swap(deleter, other.deleter);
    }

    void reset(T* ptr = nullptr){
        T* result = release();

        if(result != nullptr)
            deleter(result);

        data = ptr;
    }   
};

#endif
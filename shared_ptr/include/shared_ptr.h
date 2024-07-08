#ifndef SHAREDPTR_INCLUDE_SHAREDPTR_H_20240807
#define SHAREDPTR_INCLUDE_SHAREDPTR_H_20240807

#include <memory>

template<class T, class Deleter=std::default_delete<T>> class Shared_ptr{
    T* data;
    size_t* use_count;
    Deleter deleter;
public:
    constexpr Shared_ptr() noexcept : data(nullptr), use_count(nullptr) {
    }
    
    constexpr Shared_ptr(std::nullptr_t) noexcept : data(nullptr), use_count(nullptr){
    }

    explicit Shared_ptr(T* ptr): data(ptr), use_count(new size_t(1)){
    }

    Shared_ptr(T* ptr, Deleter deleter_): data(ptr), use_count(new size_t(1)), deleter(std::forward<Deleter>(deleter_)){
    }

    ~Shared_ptr(){
        if (data != nullptr)
            reset();
    }


    Shared_ptr(const Shared_ptr& other): data(other.data), use_count(other.use_count){
        if (data)
            ++*use_count;
    }

    Shared_ptr& operator=(const Shared_ptr& other){
        Shared_ptr<T> tmp(other);
        std::swap(data, tmp.data);
        std::swap(use_count, tmp.use_count);

        if (data)
            ++*use_count;

        other.reset();

        return *this;
    }

    Shared_ptr(Shared_ptr&& other) noexcept {
        data = nullptr;
        use_count = nullptr;
        std::swap(data, other.data);
        std::swap(use_count, other.use_count);

        other.reset();
    }

    Shared_ptr& operator=(Shared_ptr&& other) noexcept{
        std::swap(data, other.data);
        std::swap(use_count, other.use_count);

        other.reset();
        return *this;
    }

    T& operator*() const{
        return *data;
    }

    T* operator->() const{
        return data;
    }

    void reset(){
        if (use_count == nullptr || data == nullptr){
            delete use_count;
            return;
        }
            
        --*use_count;

        if (*use_count == 0){
            deleter(data);
            delete use_count;
        }
        data = nullptr;
    }

    void reset(T* ptr){ 
        reset();

        data = ptr;
        use_count = new size_t(1);
    }

    size_t count() const{
        return *use_count;
    }

    T* get() const{
        return data;
    }

    Deleter get_deleter() const {
        return deleter;
    }
};
#endif

#pragma once
#include <algorithm>

namespace psv {
template<typename T>
class vector {
    public:
    vector() : _data(nullptr), _size(), _capacity() {}
    vector(vector&& other) noexcept;
    ~vector() = default;

    // Copy
    vector(const vector& other);
    vector& operator=(vector other);

    // Mutate
    void push_back(T value);
    // emplace_back is a variadic template function that allows you to construct
    // an object in place. This is useful when you want to avoid copying or moving
    // an object.
    // Note that this is not a perfect implementation, as it does not support
    // initializer lists.
    template<typename... Args>
    void emplace_back(Args&&... args);
    void pop_back();
    void clear();

    // Access
    T& operator[](int index);
    T& front();
    T& back();

    int size() const;
    int capacity() const;

    friend void swap(vector<T>& first, vector<T>& second) {
        // std::swap is one of the few STL functions that is (relatively) easy to read:
        /* clang implementation:
        template <class _Tp>
        inline _LIBCPP_INLINE_VISIBILITY __swap_result_t<_Tp> _LIBCPP_CONSTEXPR_AFTER_CXX17 swap(_Tp& __x, _Tp& __y)
            _NOEXCEPT_(is_nothrow_move_constructible<_Tp>::value&& is_nothrow_move_assignable<_Tp>::value) {
          _Tp __t(_VSTD::move(__x));
          __x = _VSTD::move(__y);
          __y = _VSTD::move(__t);
        }
         */
        std::swap(first._data, second._data);
        std::swap(first._size, second._size);
        std::swap(first._capacity, second._capacity);
    }
private:
    T* _data;
    int _size{};
    int _capacity{};
};

    // This implementation doubles the capacity of the CustomVector when it is full;
    // however, you may want to consider a different strategy. (Think When??)
    template<typename T>
    void vector<T>::push_back(T value) {
        if (_size == _capacity) {
            _capacity = _capacity == 0 ? 1 : _capacity * 2;
            T* new_data = new T[_capacity];
            // Copy memory methods:
//             memcpy(new_data, _data, _size * sizeof(T));
//            for (int i = 0; i < _size; ++i) {
//                new_data[i] = _data[i];
//            }
            // std::copy is generally best
            std::copy(_data, _data + _size, new_data);
            delete[] _data;
            _data = new_data;
        }
        _data[_size] = value;
        ++_size;
    }

    template<typename T>
    template<typename... Args>
    void vector<T>::emplace_back(Args&&... args) {
        if (_size == _capacity) {
            _capacity = _capacity == 0 ? 1 : _capacity * 2;
            T* new_data = new T[_capacity];
            std::copy(_data, _data + _size, new_data);
            delete[] _data;
            _data = new_data;
        }
        _data[_size] = T(std::forward<Args>(args)...);
        ++_size;
    }


    template<typename T>
    vector<T>::vector(vector const &other) {
        swap(*this, other);

        return *this;
    }

    template<typename T>
    vector<T>& vector<T>::operator=(vector other) {
        swap(*this, other);

        return *this;
    }

    template<typename T>
    vector<T>::vector(vector &&other) noexcept {
        swap(*this, other);
    }

    template<typename T>
    void vector<T>::pop_back() {
        if (_size > 0) {
            --_size;
        }
    }

    template<typename T>
    void vector<T>::clear() {
        _size = 0;
    }


    // Access
    template<typename T>
    T& vector<T>::operator[](int index) {
        if(index < 0 || index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    template<typename T>
    T& vector<T>::front() {
        if (_size == 0) {
            throw std::out_of_range("Index out of range");
        }
        return _data[0];
    }

    template<typename T>
    T& vector<T>::back() {
        if (_size == 0) {
            throw std::out_of_range("Index out of range");
        }
        return _data[_size - 1];
    }

    template<typename T>
    int vector<T>::size() const {
        return _size;
    }

    template<typename T>
    int vector<T>::capacity() const {
        return _capacity;
    }



} // namespace psv


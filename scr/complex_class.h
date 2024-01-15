#pragma once

#include <iostream>
#include <cmath>
#include <type_traits>

template<typename T>
class Complex {
private:
    T real_part;
    T imaginary_part;
public:
    Complex(T r = T(0), T i = T(0));

    Complex operator+(const Complex &other) const;

    Complex operator-(const Complex &other) const;

    Complex operator*(const Complex &other) const;

    Complex operator/(const Complex &other) const;

    Complex operator^(double power) const;

    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const Complex<U> &obj);

    bool operator<(const Complex &other) const;

    bool operator>(const Complex &other) const;

    bool operator==(const Complex &other) const;

    bool operator!=(const Complex &other) const;

    bool operator<(T other) const;

    bool operator>(T other) const;

    bool operator==(T other) const;

    bool operator!=(T other) const;

    T get_length() const;

    T get_real_part() const;

    T get_imaginary_part() const;

    void set_real_part(T r);

    void set_imaginary_part(T i);
};

template<typename T>
Complex<T>::Complex(T r, T i) : real_part(r), imaginary_part(i)
{
    static_assert(std::is_arithmetic<T>::value, "T must be numeric type");
}

template<typename T>
Complex<T> Complex<T>::operator+(const Complex &other) const {
    Complex result;
    result.real_part = this->real_part + other.real_part;
    result.imaginary_part = this->imaginary_part + other.imaginary_part;
    return result;
}

template<typename T>
Complex<T> Complex<T>::operator-(const Complex &other) const {
    Complex result;
    result.real_part = this->real_part - other.real_part;
    result.imaginary_part = this->imaginary_part - other.imaginary_part;
    return result;
}

template<typename T>
Complex<T> Complex<T>::operator*(const Complex &other) const {
    Complex result;
    result.real_part = this->real_part * other.real_part - this->imaginary_part * other.imaginary_part;
    result.imaginary_part = this->real_part * other.imaginary_part + other.real_part * this->imaginary_part;
    return result;
}

template<typename T>
Complex<T> Complex<T>::operator/(const Complex &other) const {
    const T eps = T(1e-6);

    T divisor = (other.real_part * other.real_part) + (other.imaginary_part * other.imaginary_part);

    if (std::abs(divisor) < eps) {
        throw std::runtime_error("You can't divide by 0");
    }

    T newReal = ((real_part * other.real_part) + (imaginary_part * other.imaginary_part)) / divisor;
    T newImaginary = ((imaginary_part * other.real_part) - (real_part * other.imaginary_part)) / divisor;
    return Complex<T>(newReal, newImaginary);
}

template<typename T>
Complex<T> Complex<T>::operator^(double power) const {
    double magnitude = std::pow(std::sqrt(real_part * real_part + imaginary_part * imaginary_part), power);
    double angle = std::atan2(imaginary_part, real_part) * power;
    return Complex(magnitude * std::cos(angle), magnitude * std::sin(angle));
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Complex<T> &obj) {
    os << "Complex(" << obj.real_part << "f, " << obj.imaginary_part << "f)";
    return os;
}

template<typename T>
bool Complex<T>::operator<(const Complex &other) const {
    return this->get_length() < other.get_length();
}

template<typename T>
bool Complex<T>::operator>(const Complex &other) const {
    return this->get_length() > other.get_length();
}

template<typename T>
bool Complex<T>::operator==(const Complex &other) const {
    return this->get_length() == other.get_length();
}

template<typename T>
bool Complex<T>::operator!=(const Complex &other) const {
    return this->get_length() != other.get_length();
}

template<typename T>
bool Complex<T>::operator<(T other) const {
    return this->get_length() < other;
}

template<typename T>
bool Complex<T>::operator>(T other) const {
    return this->get_length() > other;
}

template<typename T>
bool Complex<T>::operator==(T other) const {
    return this->get_length() == other;
}

template<typename T>
bool Complex<T>::operator!=(T other) const {
    return this->get_length() != other;
}

template<typename T>
T Complex<T>::get_length() const {
    return sqrt(pow(this->get_real_part(), 2) + pow(this->get_imaginary_part(), 2));
}

template<typename T>
T Complex<T>::get_real_part() const {
    return real_part;
}

template<typename T>
T Complex<T>::get_imaginary_part() const {
    return imaginary_part;
}

template<typename T>
void Complex<T>::set_real_part(T r) {
    this->real_part = r;
}

template<typename T>
void Complex<T>::set_imaginary_part(T i) {
    this->imaginary_part = i;
}


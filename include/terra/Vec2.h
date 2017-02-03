#ifndef TERRA_VEC2_H // -*- C++ -*-
#define TERRA_VEC2_H

class Vec2 {
protected:
    real elt[2];

    inline void copy(const Vec2 &v);

public:
    // Standard constructors
    Vec2(real x = 0, real y = 0) {
        elt[0] = x;
        elt[1] = y;
    }

    Vec2(const Vec2 &v) { copy(v); }

    Vec2(const real *v) {
        elt[0] = v[0];
        elt[1] = v[1];
    }

    Vec2 &clone() const { return *(new Vec2(elt[0], elt[1])); }

    // Access methods
    real &operator()(int i) { return elt[i]; }

    const real &operator()(int i) const { return elt[i]; }

    real &operator[](int i) { return elt[i]; }

    const real &operator[](int i) const { return elt[i]; }

    // Assignment methods
    inline Vec2 &operator=(const Vec2 &v);

    inline Vec2 &operator+=(const Vec2 &v);

    inline Vec2 &operator-=(const Vec2 &v);

    inline Vec2 &operator*=(real s);

    inline Vec2 &operator/=(real s);

    // Arithmetic methods
    inline Vec2 operator+(const Vec2 &v) const;

    inline Vec2 operator-(const Vec2 &v) const;

    inline Vec2 operator-() const;

    inline Vec2 operator*(real s) const;

    inline Vec2 operator/(real s) const;

    inline real operator*(const Vec2 &v) const;

#ifdef _GLIBCXX_IOSTREAM
    // Input/Output methods
    friend std::ostream& operator<<(std::ostream&, const Vec2&);
    friend std::istream& operator>>(std::istream&, Vec2&);
#endif

    // Additional vector methods
    inline real length();

    inline real norm();

    inline real norm2();

    inline real unitize();

    inline int operator==(const Vec2 &v) const {
        return (*this - v).norm2() < EPS2;
    }
};


inline void Vec2::copy(const Vec2 &v) {
    elt[0] = v.elt[0];
    elt[1] = v.elt[1];
}

inline Vec2 &Vec2::operator=(const Vec2 &v) {
    copy(v);
    return *this;
}

inline Vec2 &Vec2::operator+=(const Vec2 &v) {
    elt[0] += v[0];
    elt[1] += v[1];
    return *this;
}

inline Vec2 &Vec2::operator-=(const Vec2 &v) {
    elt[0] -= v[0];
    elt[1] -= v[1];
    return *this;
}

inline Vec2 &Vec2::operator*=(real s) {
    elt[0] *= s;
    elt[1] *= s;
    return *this;
}

inline Vec2 &Vec2::operator/=(real s) {
    elt[0] /= s;
    elt[1] /= s;
    return *this;
}

///////////////////////

inline Vec2 Vec2::operator+(const Vec2 &v) const {
    Vec2 w(elt[0] + v[0], elt[1] + v[1]);
    return w;
}

inline Vec2 Vec2::operator-(const Vec2 &v) const {
    Vec2 w(elt[0] - v[0], elt[1] - v[1]);
    return w;
}

inline Vec2 Vec2::operator-() const {
    return Vec2(-elt[0], -elt[1]);
}

inline Vec2 Vec2::operator*(real s) const {
    Vec2 w(elt[0] * s, elt[1] * s);
    return w;
}

inline Vec2 Vec2::operator/(real s) const {
    Vec2 w(elt[0] / s, elt[1] / s);
    return w;
}

inline real Vec2::operator*(const Vec2 &v) const {
    return elt[0] * v[0] + elt[1] * v[1];
}

inline real Vec2::length() {
    return norm();
}

inline real Vec2::norm() {
    return sqrt(elt[0] * elt[0] + elt[1] * elt[1]);
}

inline real Vec2::norm2() {
    return elt[0] * elt[0] + elt[1] * elt[1];
}

inline real Vec2::unitize() {
    real l = norm();
    if (l != 1.0)
        (*this) /= l;
    return l;
}

#ifdef _GLIBCXX_IOSTREAM
inline std::ostream& operator<<(std::ostream& out, const Vec2& v)
{
    return out << (char *)"[" << v[0] << (char *)" " << v[1] << (char *)"]";
}

inline std::istream& operator>>(std::istream& in, Vec2& v)
{
    return in >> (char *)"[" >> v[0] >> v[1] >> (char *)"]";
}
#endif


#endif

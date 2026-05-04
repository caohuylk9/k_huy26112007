#include "CVector.h"

CVector::CVector(int n) {
    if (n > 0) a.resize(n, 0.0);
}

int CVector::size() const {
    return static_cast<int>(a.size());
}

double& CVector::operator[](int i) {
    return a[i];
}

const double& CVector::operator[](int i) const {
    return a[i];
}

CVector CVector::operator+(const CVector& v) const {
    CVector kq(static_cast<int>(a.size()));
    for (size_t i = 0; i < a.size(); i++)
        kq.a[i] = a[i] + v.a[i];
    return kq;
}

CVector CVector::operator-(const CVector& v) const {
    CVector kq(static_cast<int>(a.size()));
    for (size_t i = 0; i < a.size(); i++)
        kq.a[i] = a[i] - v.a[i];
    return kq;
}

istream& operator>>(istream& in, CVector& v) {
    for (size_t i = 0; i < v.a.size(); i++)
        in >> v.a[i];
    return in;
}

ostream& operator<<(ostream& out, const CVector& v) {
    out << "(";
    for (size_t i = 0; i < v.a.size(); i++) {
        out << v.a[i] << (i < v.a.size() - 1 ? ", " : "");
    }
    out << ")";
    return out;
}
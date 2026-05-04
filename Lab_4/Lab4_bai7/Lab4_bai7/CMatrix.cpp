#include "CMatrix.h"

CMatrix::CMatrix(int r, int c) : rows(r), cols(c) {
    if (r > 0 && c > 0)
        a.resize(r, vector<double>(c, 0.0));
}

int CMatrix::getRows() const { return rows; }
int CMatrix::getCols() const { return cols; }

vector<double>& CMatrix::operator[](int i) { return a[i]; }
const vector<double>& CMatrix::operator[](int i) const { return a[i]; }

// Cộng Ma trận
CMatrix CMatrix::operator+(const CMatrix& m) const {
    CMatrix kq(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            kq.a[i][j] = a[i][j] + m.a[i][j];
    return kq;
}

// Tích Ma trận * Ma trận
CMatrix CMatrix::operator*(const CMatrix& m) const {
    CMatrix kq(rows, m.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            for (int k = 0; k < cols; k++) {
                kq.a[i][j] += a[i][k] * m.a[k][j];
            }
        }
    }
    return kq;
}

// Tích Ma trận * Vector
CVector CMatrix::operator*(const CVector& v) const {
    CVector kq(rows);
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += a[i][j] * v[j];
        }
        kq[i] = sum;
    }
    return kq;
}

istream& operator>>(istream& in, CMatrix& m) {
    for (int i = 0; i < m.rows; i++)
        for (int j = 0; j < m.cols; j++)
            in >> m.a[i][j];
    return in;
}

ostream& operator<<(ostream& out, const CMatrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++)
            out << m.a[i][j] << "\t";
        out << endl;
    }
    return out;
}
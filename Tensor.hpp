/* 
 * File:   Tensor.hpp
 * Author: kingfisher1337
 *
 * Created on August 26, 2013, 10:56 AM
 */

#ifndef TENSOR_HPP
#define	TENSOR_HPP

#include <cstdlib>

template <typename K>
class Tensor1 {
private:
    K * m;
    size_t n[1];
    size_t nTotal;
public:
    Tensor1(size_t n) {
        this->n[0] = n;
        nTotal = n;
        m = new K[nTotal];
        if (m == 0) {
            this->n[0] = 0;
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    ~Tensor1() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t getSize() const {
        return nTotal;
    }
    size_t getSize(size_t i) const {
        return n[i];
    }
    void resize(size_t n) {
        if (m != 0) {
            delete[] m;
        }
        this->n[0] = n;
        nTotal = n;
        m = new K[nTotal];
        if (m == 0) {
            this->n[0] = 0;
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    K & operator()(size_t i) {
        return m[i];
    }
    const K & operator()(size_t i) const {
        return (*this)(i);
    }
};

template <typename K>
class Tensor2 {
private:
    K * m;
    size_t n[2];
    size_t nTotal;
public:
    Tensor2(size_t m, size_t n) {
        this->n[0] = m;
        this->n[1] = n;
        nTotal = m * n;
        this->m = new K[nTotal];
        if (this->m == 0) {
            this->n[0] = 0;
            this->n[1] = 0;
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    ~Tensor2() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t getSize() const {
        return nTotal;
    }
    size_t getSize(size_t i) const {
        return n[i];
    }
    void resize(size_t m, size_t n) {
        if (m != 0) {
            delete[] m;
        }
        this->n[0] = m;
        this->n[1] = n;
        nTotal = m * n;
        this->m = new K[nTotal];
        if (this->m == 0) {
            this->n[0] = 0;
            this->n[1] = 0;
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    K & operator()(size_t i, size_t j) {
        size_t k = i + j * n[0];
        return m[k];
    }
    const K & operator()(size_t i, size_t j) const {
        return (*this)(i, j);
    }
};

template <typename K>
class Tensor3 {
private:
    K * m;
    size_t n[3];
    size_t nTotal;
public:
    Tensor3(size_t n1, size_t n2, size_t n3) {
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        nTotal = n1 * n2 * n3;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 3);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    ~Tensor3() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t getSize() const {
        return nTotal;
    }
    size_t getSize(size_t i) const {
        return n[i];
    }
    void resize(size_t n1, size_t n2, size_t n3) {
        if (m != 0) {
            delete[] m;
        }
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        nTotal = n1 * n2 * n3;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 3);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i1 + i2 * n[0] + i3 * n[0] * n[1];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3) const {
        return (*this)(i1, i2, i3);
    }
};

template <typename K>
class Tensor4 {
private:
    K * m;
    size_t n[4];
    size_t nTotal;
public:
    Tensor4(size_t n1, size_t n2, size_t n3, size_t n4) {
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        nTotal = n1 * n2 * n3 * n4;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 4);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    ~Tensor4() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t getSize() const {
        return nTotal;
    }
    size_t getSize(size_t i) const {
        return n[i];
    }
    void resize(size_t n1, size_t n2, size_t n3, size_t n4) {
        if (m != 0) {
            delete[] m;
        }
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        nTotal = n1 * n2 * n3 * n4;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 4);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i1 + 
                   i2 * n[0] + 
                   i3 * n[0] * n[1] + 
                   i4 * n[0] * n[1] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4) const {
        return (*this)(i1, i2, i3, i4);
    }
};

template <typename K>
class Tensor5 {
private:
    K * m;
    size_t n[5];
    size_t nTotal;
public:
    Tensor5(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5) {
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        nTotal = n1 * n2 * n3 * n4 * n5;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 5);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    ~Tensor5() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t getSize() const {
        return nTotal;
    }
    size_t getSize(size_t i) const {
        return n[i];
    }
    void resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5) {
        if (m != 0) {
            delete[] m;
        }
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        nTotal = n1 * n2 * n3 * n4 * n5;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 5);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i1 + 
                   i2 * n[0] + 
                   i3 * n[0] * n[1] + 
                   i4 * n[0] * n[1] * n[2] + 
                   i5 * n[0] * n[1] * n[2] * n[3];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) const {
        return (*this)(i1, i2, i3, i4, i5);
    }
};

template <typename K>
class Tensor6 {
private:
    K * m;
    size_t n[6];
    size_t nTotal;
public:
    Tensor6(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6) {
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        this->n[5] = n6;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 6);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    ~Tensor6() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t getSize() const {
        return nTotal;
    }
    size_t getSize(size_t i) const {
        return n[i];
    }
    void resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6) {
        if (m != 0) {
            delete[] m;
        }
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        this->n[5] = n6;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 6);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i1 + 
                   i2 * n[0] + 
                   i3 * n[0] * n[1] + 
                   i4 * n[0] * n[1] * n[2] + 
                   i5 * n[0] * n[1] * n[2] * n[3] + 
                   i6 * n[0] * n[1] * n[2] * n[3] * n[4];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) const {
        return (*this)(i1, i2, i3, i4, i5, i6);
    }
};

template <typename K>
class Tensor7 {
private:
    K * m;
    size_t n[7];
    size_t nTotal;
public:
    Tensor7(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7) {
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        this->n[5] = n6;
        this->n[6] = n7;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 7);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    ~Tensor7() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t getSize() const {
        return nTotal;
    }
    size_t getSize(size_t i) const {
        return n[i];
    }
    void resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7) {
        if (m != 0) {
            delete[] m;
        }
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        this->n[5] = n6;
        this->n[6] = n7;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 7);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) {
        size_t k = i1 + 
                   i2 * n[0] + 
                   i3 * n[0] * n[1] + 
                   i4 * n[0] * n[1] * n[2] + 
                   i5 * n[0] * n[1] * n[2] * n[3] + 
                   i6 * n[0] * n[1] * n[2] * n[3] * n[4] + 
                   i7 * n[0] * n[1] * n[2] * n[3] * n[4] * n[5];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) const {
        return (*this)(i1, i2, i3, i4, i5, i6, i7);
    }
};

template <typename K>
class Tensor8 {
private:
    K * m;
    size_t n[8];
    size_t nTotal;
public:
    Tensor8(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8) {
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        this->n[5] = n6;
        this->n[6] = n7;
        this->n[7] = n8;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 8);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    ~Tensor8() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t getSize() const {
        return nTotal;
    }
    size_t getSize(size_t i) const {
        return n[i];
    }
    void resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8) {
        if (m != 0) {
            delete[] m;
        }
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        this->n[5] = n6;
        this->n[6] = n7;
        this->n[7] = n8;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 8);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8) {
        size_t k = i1 + 
                   i2 * n[0] + 
                   i3 * n[0] * n[1] + 
                   i4 * n[0] * n[1] * n[2] + 
                   i5 * n[0] * n[1] * n[2] * n[3] + 
                   i6 * n[0] * n[1] * n[2] * n[3] * n[4] + 
                   i7 * n[0] * n[1] * n[2] * n[3] * n[4] * n[5] + 
                   i8 * n[0] * n[1] * n[2] * n[3] * n[4] * n[5] * n[6];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8) const {
        return (*this)(i1, i2, i3, i4, i5, i6, i7, i8);
    }
};

template <typename K>
class Tensor9 {
private:
    K * m;
    size_t n[9];
    size_t nTotal;
public:
    Tensor9(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9) {
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        this->n[5] = n6;
        this->n[6] = n7;
        this->n[7] = n8;
        this->n[8] = n9;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 9);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    ~Tensor9() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t getSize() const {
        return nTotal;
    }
    size_t getSize(size_t i) const {
        return n[i];
    }
    void resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9) {
        if (m != 0) {
            delete[] m;
        }
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        this->n[5] = n6;
        this->n[6] = n7;
        this->n[7] = n8;
        this->n[8] = n9;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 9);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9) {
        size_t k = i1 + 
                   i2 * n[0] + 
                   i3 * n[0] * n[1] + 
                   i4 * n[0] * n[1] * n[2] + 
                   i5 * n[0] * n[1] * n[2] * n[3] + 
                   i6 * n[0] * n[1] * n[2] * n[3] * n[4] + 
                   i7 * n[0] * n[1] * n[2] * n[3] * n[4] * n[5] + 
                   i8 * n[0] * n[1] * n[2] * n[3] * n[4] * n[5] * n[6] + 
                   i9 * n[0] * n[1] * n[2] * n[3] * n[4] * n[5] * n[6] * n[7];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9) const {
        return (*this)(i1, i2, i3, i4, i5, i6, i7, i8, i9);
    }
};

template <typename K>
class Tensor10 {
private:
    K * m;
    size_t n[10];
    size_t nTotal;
public:
    Tensor10(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9, size_t n10) {
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        this->n[5] = n6;
        this->n[6] = n7;
        this->n[7] = n8;
        this->n[8] = n9;
        this->n[9] = n10;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9 * n10;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 10);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    ~Tensor10() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t getSize() const {
        return nTotal;
    }
    size_t getSize(size_t i) const {
        return n[i];
    }
    void resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9, size_t n10) {
        if (m != 0) {
            delete[] m;
        }
        this->n[0] = n1;
        this->n[1] = n2;
        this->n[2] = n3;
        this->n[3] = n4;
        this->n[4] = n5;
        this->n[5] = n6;
        this->n[6] = n7;
        this->n[7] = n8;
        this->n[8] = n9;
        this->n[9] = n10;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9 * n10;
        this->m = new K[nTotal];
        if (this->m == 0) {
            memset(this->n, 0, sizeof(n[0]) * 10);
            nTotal = 0;
        } else {
            memset(m, 0, sizeof(nTotal * sizeof(K)));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9, size_t i10) {
        size_t k = i1 + 
                   i2 * n[0] + 
                   i3 * n[0] * n[1] + 
                   i4 * n[0] * n[1] * n[2] + 
                   i5 * n[0] * n[1] * n[2] * n[3] + 
                   i6 * n[0] * n[1] * n[2] * n[3] * n[4] + 
                   i7 * n[0] * n[1] * n[2] * n[3] * n[4] * n[5] + 
                   i8 * n[0] * n[1] * n[2] * n[3] * n[4] * n[5] * n[6] + 
                   i9 * n[0] * n[1] * n[2] * n[3] * n[4] * n[5] * n[6] * n[7] + 
                  i10 * n[0] * n[1] * n[2] * n[3] * n[4] * n[5] * n[6] * n[7] * n[8];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9, size_t i10) const {
        return (*this)(i1, i2, i3, i4, i5, i6, i7, i8, i9, i10);
    }
};

#endif	/* TENSOR_HPP */


#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <cstdlib>
#include <cstring>

template <typename K> class TensorSlice1 {
private:
    K * m;
    size_t n[1];
    size_t nTotal;
public:
    TensorSlice1(K * m, size_t n1), m(m) {
        n[0] = n1;
        nTotal = n1;
    }
    K & operator()(size_t i1) {
        size_t k = i1;
        return m[k];
    }
    const K & operator()(size_t i1) const {
        size_t k = i1;
        return m[k];
    }
};

template <typename K> class TensorSlice2 {
private:
    K * m;
    size_t n[2];
    size_t nTotal;
public:
    TensorSlice2(K * m, size_t n1, size_t n2), m(m) {
        n[0] = n1;
        n[1] = n2;
        nTotal = n1 * n2;
    }
    K & operator()(size_t i1, size_t i2) {
        size_t k = i2 +
                   i1 * n[1];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2) const {
        size_t k = i2 +
                   i1 * n[1];
        return m[k];
    }
    TensorSlice1<K> operator()(size_t i1) {
        size_t k = i1 * n[1];
        return TensorSlice1<K>(&m[k], n2);
    }
};

template <typename K> class TensorSlice3 {
private:
    K * m;
    size_t n[3];
    size_t nTotal;
public:
    TensorSlice3(K * m, size_t n1, size_t n2, size_t n3), m(m) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        nTotal = n1 * n2 * n3;
    }
    K & operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i3 +
                   i2 * n[2] +
                   i1 * n[2] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3) const {
        size_t k = i3 +
                   i2 * n[2] +
                   i1 * n[2] * n[2];
        return m[k];
    }
    TensorSlice2<K> operator()(size_t i1) {
        size_t k = i2 * n[2] +
                   i1 * n[2] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2) {
        size_t k = i1 * n[2] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3);
    }
};

template <typename K> class TensorSlice4 {
private:
    K * m;
    size_t n[4];
    size_t nTotal;
public:
    TensorSlice4(K * m, size_t n1, size_t n2, size_t n3, size_t n4), m(m) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        nTotal = n1 * n2 * n3 * n4;
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i4 +
                   i3 * n[3] +
                   i2 * n[3] * n[3] +
                   i1 * n[3] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4) const {
        size_t k = i4 +
                   i3 * n[3] +
                   i2 * n[3] * n[3] +
                   i1 * n[3] * n[3] * n[2];
        return m[k];
    }
    TensorSlice3<K> operator()(size_t i1) {
        size_t k = i3 * n[3] +
                   i2 * n[3] * n[3] +
                   i1 * n[3] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2) {
        size_t k = i2 * n[3] * n[3] +
                   i1 * n[3] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i1 * n[3] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4);
    }
};

template <typename K> class TensorSlice5 {
private:
    K * m;
    size_t n[5];
    size_t nTotal;
public:
    TensorSlice5(K * m, size_t n1, size_t n2, size_t n3, size_t n4, size_t n5), m(m) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        nTotal = n1 * n2 * n3 * n4 * n5;
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i5 +
                   i4 * n[4] +
                   i3 * n[4] * n[4] +
                   i2 * n[4] * n[4] * n[3] +
                   i1 * n[4] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) const {
        size_t k = i5 +
                   i4 * n[4] +
                   i3 * n[4] * n[4] +
                   i2 * n[4] * n[4] * n[3] +
                   i1 * n[4] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice4<K> operator()(size_t i1) {
        size_t k = i4 * n[4] +
                   i3 * n[4] * n[4] +
                   i2 * n[4] * n[4] * n[3] +
                   i1 * n[4] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2) {
        size_t k = i3 * n[4] * n[4] +
                   i2 * n[4] * n[4] * n[3] +
                   i1 * n[4] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i2 * n[4] * n[4] * n[3] +
                   i1 * n[4] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i1 * n[4] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5);
    }
};

template <typename K> class TensorSlice6 {
private:
    K * m;
    size_t n[6];
    size_t nTotal;
public:
    TensorSlice6(K * m, size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6), m(m) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6;
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i6 +
                   i5 * n[5] +
                   i4 * n[5] * n[5] +
                   i3 * n[5] * n[5] * n[4] +
                   i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) const {
        size_t k = i6 +
                   i5 * n[5] +
                   i4 * n[5] * n[5] +
                   i3 * n[5] * n[5] * n[4] +
                   i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice5<K> operator()(size_t i1) {
        size_t k = i5 * n[5] +
                   i4 * n[5] * n[5] +
                   i3 * n[5] * n[5] * n[4] +
                   i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice5<K>(&m[k], n2, n3, n4, n5, n6);
    }
    TensorSlice4<K> operator()(size_t i1, size_t i2) {
        size_t k = i4 * n[5] * n[5] +
                   i3 * n[5] * n[5] * n[4] +
                   i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5, n6);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i3 * n[5] * n[5] * n[4] +
                   i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5, n6);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5, n6);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5, n6);
    }
};

template <typename K> class TensorSlice7 {
private:
    K * m;
    size_t n[7];
    size_t nTotal;
public:
    TensorSlice7(K * m, size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7), m(m) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7;
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) {
        size_t k = i7 +
                   i6 * n[6] +
                   i5 * n[6] * n[6] +
                   i4 * n[6] * n[6] * n[5] +
                   i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) const {
        size_t k = i7 +
                   i6 * n[6] +
                   i5 * n[6] * n[6] +
                   i4 * n[6] * n[6] * n[5] +
                   i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice6<K> operator()(size_t i1) {
        size_t k = i6 * n[6] +
                   i5 * n[6] * n[6] +
                   i4 * n[6] * n[6] * n[5] +
                   i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice6<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
    TensorSlice5<K> operator()(size_t i1, size_t i2) {
        size_t k = i5 * n[6] * n[6] +
                   i4 * n[6] * n[6] * n[5] +
                   i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice5<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
    TensorSlice4<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i4 * n[6] * n[6] * n[5] +
                   i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
};

template <typename K> class TensorSlice8 {
private:
    K * m;
    size_t n[8];
    size_t nTotal;
public:
    TensorSlice8(K * m, size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8), m(m) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        n[7] = n8;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8;
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8) {
        size_t k = i8 +
                   i7 * n[7] +
                   i6 * n[7] * n[7] +
                   i5 * n[7] * n[7] * n[6] +
                   i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8) const {
        size_t k = i8 +
                   i7 * n[7] +
                   i6 * n[7] * n[7] +
                   i5 * n[7] * n[7] * n[6] +
                   i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice7<K> operator()(size_t i1) {
        size_t k = i7 * n[7] +
                   i6 * n[7] * n[7] +
                   i5 * n[7] * n[7] * n[6] +
                   i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice7<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice6<K> operator()(size_t i1, size_t i2) {
        size_t k = i6 * n[7] * n[7] +
                   i5 * n[7] * n[7] * n[6] +
                   i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice6<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice5<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i5 * n[7] * n[7] * n[6] +
                   i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice5<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice4<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) {
        size_t k = i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
};

template <typename K> class TensorSlice9 {
private:
    K * m;
    size_t n[9];
    size_t nTotal;
public:
    TensorSlice9(K * m, size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9), m(m) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        n[7] = n8;
        n[8] = n9;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9;
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9) {
        size_t k = i9 +
                   i8 * n[8] +
                   i7 * n[8] * n[8] +
                   i6 * n[8] * n[8] * n[7] +
                   i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9) const {
        size_t k = i9 +
                   i8 * n[8] +
                   i7 * n[8] * n[8] +
                   i6 * n[8] * n[8] * n[7] +
                   i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice8<K> operator()(size_t i1) {
        size_t k = i8 * n[8] +
                   i7 * n[8] * n[8] +
                   i6 * n[8] * n[8] * n[7] +
                   i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice8<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice7<K> operator()(size_t i1, size_t i2) {
        size_t k = i7 * n[8] * n[8] +
                   i6 * n[8] * n[8] * n[7] +
                   i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice7<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice6<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i6 * n[8] * n[8] * n[7] +
                   i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice6<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice5<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice5<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice4<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) {
        size_t k = i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8) {
        size_t k = i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
};

template <typename K> class TensorSlice10 {
private:
    K * m;
    size_t n[10];
    size_t nTotal;
public:
    TensorSlice10(K * m, size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9, size_t n10), m(m) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        n[7] = n8;
        n[8] = n9;
        n[9] = n10;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9 * n10;
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9, size_t i10) {
        size_t k = i10 +
                   i9 * n[9] +
                   i8 * n[9] * n[9] +
                   i7 * n[9] * n[9] * n[8] +
                   i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9, size_t i10) const {
        size_t k = i10 +
                   i9 * n[9] +
                   i8 * n[9] * n[9] +
                   i7 * n[9] * n[9] * n[8] +
                   i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice9<K> operator()(size_t i1) {
        size_t k = i9 * n[9] +
                   i8 * n[9] * n[9] +
                   i7 * n[9] * n[9] * n[8] +
                   i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice9<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice8<K> operator()(size_t i1, size_t i2) {
        size_t k = i8 * n[9] * n[9] +
                   i7 * n[9] * n[9] * n[8] +
                   i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice8<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice7<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i7 * n[9] * n[9] * n[8] +
                   i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice7<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice6<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice6<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice5<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice5<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice4<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) {
        size_t k = i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8) {
        size_t k = i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9) {
        size_t k = i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
};

template <typename K> class Tensor1 {
private:
    K * m;
    size_t n[1];
    size_t nTotal;
public:
    Tensor1() : m(0), nTotal(0) {
        memset(n, 0, sizeof(n));
    }
    Tensor1(const Tensor1 & t) {
        memcpy(n, t.n, sizeof(n));
        nTotal = t.nTotal;
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memcpy(m, t.n, nTotal * sizeof(K));
        }
    }
    Tensor1(size_t n1) {
        n[0] = n1;
        nTotal = n1;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    ~Tensor1() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t size() {
        return nTotal;
    }
    size_t size(size_t i) {
        return n[i];
    }
    size_t resize(size_t n1) {
        if (m != 0) {
            delete[] m;
        }
        n[0] = n1;
        nTotal = n1;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    K & operator()(size_t i1) {
        size_t k = i1;
        return m[k];
    }
    const K & operator()(size_t i1) const {
        size_t k = i1;
        return m[k];
    }
};

template <typename K> class Tensor2 {
private:
    K * m;
    size_t n[2];
    size_t nTotal;
public:
    Tensor2() : m(0), nTotal(0) {
        memset(n, 0, sizeof(n));
    }
    Tensor2(const Tensor2 & t) {
        memcpy(n, t.n, sizeof(n));
        nTotal = t.nTotal;
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memcpy(m, t.n, nTotal * sizeof(K));
        }
    }
    Tensor2(size_t n1, size_t n2) {
        n[0] = n1;
        n[1] = n2;
        nTotal = n1 * n2;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    ~Tensor2() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t size() {
        return nTotal;
    }
    size_t size(size_t i) {
        return n[i];
    }
    size_t resize(size_t n1, size_t n2) {
        if (m != 0) {
            delete[] m;
        }
        n[0] = n1;
        n[1] = n2;
        nTotal = n1 * n2;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    K & operator()(size_t i1, size_t i2) {
        size_t k = i2 +
                   i1 * n[1];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2) const {
        size_t k = i2 +
                   i1 * n[1];
        return m[k];
    }
    TensorSlice1<K> operator()(size_t i1) {
        size_t k = i1 * n[1];
        return TensorSlice1<K>(&m[k], n2);
    }
};

template <typename K> class Tensor3 {
private:
    K * m;
    size_t n[3];
    size_t nTotal;
public:
    Tensor3() : m(0), nTotal(0) {
        memset(n, 0, sizeof(n));
    }
    Tensor3(const Tensor3 & t) {
        memcpy(n, t.n, sizeof(n));
        nTotal = t.nTotal;
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memcpy(m, t.n, nTotal * sizeof(K));
        }
    }
    Tensor3(size_t n1, size_t n2, size_t n3) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        nTotal = n1 * n2 * n3;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    ~Tensor3() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t size() {
        return nTotal;
    }
    size_t size(size_t i) {
        return n[i];
    }
    size_t resize(size_t n1, size_t n2, size_t n3) {
        if (m != 0) {
            delete[] m;
        }
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        nTotal = n1 * n2 * n3;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i3 +
                   i2 * n[2] +
                   i1 * n[2] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3) const {
        size_t k = i3 +
                   i2 * n[2] +
                   i1 * n[2] * n[2];
        return m[k];
    }
    TensorSlice2<K> operator()(size_t i1) {
        size_t k = i2 * n[2] +
                   i1 * n[2] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2) {
        size_t k = i1 * n[2] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3);
    }
};

template <typename K> class Tensor4 {
private:
    K * m;
    size_t n[4];
    size_t nTotal;
public:
    Tensor4() : m(0), nTotal(0) {
        memset(n, 0, sizeof(n));
    }
    Tensor4(const Tensor4 & t) {
        memcpy(n, t.n, sizeof(n));
        nTotal = t.nTotal;
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memcpy(m, t.n, nTotal * sizeof(K));
        }
    }
    Tensor4(size_t n1, size_t n2, size_t n3, size_t n4) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        nTotal = n1 * n2 * n3 * n4;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    ~Tensor4() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t size() {
        return nTotal;
    }
    size_t size(size_t i) {
        return n[i];
    }
    size_t resize(size_t n1, size_t n2, size_t n3, size_t n4) {
        if (m != 0) {
            delete[] m;
        }
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        nTotal = n1 * n2 * n3 * n4;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i4 +
                   i3 * n[3] +
                   i2 * n[3] * n[3] +
                   i1 * n[3] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4) const {
        size_t k = i4 +
                   i3 * n[3] +
                   i2 * n[3] * n[3] +
                   i1 * n[3] * n[3] * n[2];
        return m[k];
    }
    TensorSlice3<K> operator()(size_t i1) {
        size_t k = i3 * n[3] +
                   i2 * n[3] * n[3] +
                   i1 * n[3] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2) {
        size_t k = i2 * n[3] * n[3] +
                   i1 * n[3] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i1 * n[3] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4);
    }
};

template <typename K> class Tensor5 {
private:
    K * m;
    size_t n[5];
    size_t nTotal;
public:
    Tensor5() : m(0), nTotal(0) {
        memset(n, 0, sizeof(n));
    }
    Tensor5(const Tensor5 & t) {
        memcpy(n, t.n, sizeof(n));
        nTotal = t.nTotal;
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memcpy(m, t.n, nTotal * sizeof(K));
        }
    }
    Tensor5(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        nTotal = n1 * n2 * n3 * n4 * n5;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    ~Tensor5() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t size() {
        return nTotal;
    }
    size_t size(size_t i) {
        return n[i];
    }
    size_t resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5) {
        if (m != 0) {
            delete[] m;
        }
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        nTotal = n1 * n2 * n3 * n4 * n5;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i5 +
                   i4 * n[4] +
                   i3 * n[4] * n[4] +
                   i2 * n[4] * n[4] * n[3] +
                   i1 * n[4] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) const {
        size_t k = i5 +
                   i4 * n[4] +
                   i3 * n[4] * n[4] +
                   i2 * n[4] * n[4] * n[3] +
                   i1 * n[4] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice4<K> operator()(size_t i1) {
        size_t k = i4 * n[4] +
                   i3 * n[4] * n[4] +
                   i2 * n[4] * n[4] * n[3] +
                   i1 * n[4] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2) {
        size_t k = i3 * n[4] * n[4] +
                   i2 * n[4] * n[4] * n[3] +
                   i1 * n[4] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i2 * n[4] * n[4] * n[3] +
                   i1 * n[4] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i1 * n[4] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5);
    }
};

template <typename K> class Tensor6 {
private:
    K * m;
    size_t n[6];
    size_t nTotal;
public:
    Tensor6() : m(0), nTotal(0) {
        memset(n, 0, sizeof(n));
    }
    Tensor6(const Tensor6 & t) {
        memcpy(n, t.n, sizeof(n));
        nTotal = t.nTotal;
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memcpy(m, t.n, nTotal * sizeof(K));
        }
    }
    Tensor6(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    ~Tensor6() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t size() {
        return nTotal;
    }
    size_t size(size_t i) {
        return n[i];
    }
    size_t resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6) {
        if (m != 0) {
            delete[] m;
        }
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i6 +
                   i5 * n[5] +
                   i4 * n[5] * n[5] +
                   i3 * n[5] * n[5] * n[4] +
                   i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) const {
        size_t k = i6 +
                   i5 * n[5] +
                   i4 * n[5] * n[5] +
                   i3 * n[5] * n[5] * n[4] +
                   i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice5<K> operator()(size_t i1) {
        size_t k = i5 * n[5] +
                   i4 * n[5] * n[5] +
                   i3 * n[5] * n[5] * n[4] +
                   i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice5<K>(&m[k], n2, n3, n4, n5, n6);
    }
    TensorSlice4<K> operator()(size_t i1, size_t i2) {
        size_t k = i4 * n[5] * n[5] +
                   i3 * n[5] * n[5] * n[4] +
                   i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5, n6);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i3 * n[5] * n[5] * n[4] +
                   i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5, n6);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i2 * n[5] * n[5] * n[4] * n[3] +
                   i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5, n6);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i1 * n[5] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5, n6);
    }
};

template <typename K> class Tensor7 {
private:
    K * m;
    size_t n[7];
    size_t nTotal;
public:
    Tensor7() : m(0), nTotal(0) {
        memset(n, 0, sizeof(n));
    }
    Tensor7(const Tensor7 & t) {
        memcpy(n, t.n, sizeof(n));
        nTotal = t.nTotal;
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memcpy(m, t.n, nTotal * sizeof(K));
        }
    }
    Tensor7(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    ~Tensor7() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t size() {
        return nTotal;
    }
    size_t size(size_t i) {
        return n[i];
    }
    size_t resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7) {
        if (m != 0) {
            delete[] m;
        }
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) {
        size_t k = i7 +
                   i6 * n[6] +
                   i5 * n[6] * n[6] +
                   i4 * n[6] * n[6] * n[5] +
                   i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) const {
        size_t k = i7 +
                   i6 * n[6] +
                   i5 * n[6] * n[6] +
                   i4 * n[6] * n[6] * n[5] +
                   i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice6<K> operator()(size_t i1) {
        size_t k = i6 * n[6] +
                   i5 * n[6] * n[6] +
                   i4 * n[6] * n[6] * n[5] +
                   i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice6<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
    TensorSlice5<K> operator()(size_t i1, size_t i2) {
        size_t k = i5 * n[6] * n[6] +
                   i4 * n[6] * n[6] * n[5] +
                   i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice5<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
    TensorSlice4<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i4 * n[6] * n[6] * n[5] +
                   i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i3 * n[6] * n[6] * n[5] * n[4] +
                   i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i2 * n[6] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i1 * n[6] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5, n6, n7);
    }
};

template <typename K> class Tensor8 {
private:
    K * m;
    size_t n[8];
    size_t nTotal;
public:
    Tensor8() : m(0), nTotal(0) {
        memset(n, 0, sizeof(n));
    }
    Tensor8(const Tensor8 & t) {
        memcpy(n, t.n, sizeof(n));
        nTotal = t.nTotal;
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memcpy(m, t.n, nTotal * sizeof(K));
        }
    }
    Tensor8(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        n[7] = n8;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    ~Tensor8() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t size() {
        return nTotal;
    }
    size_t size(size_t i) {
        return n[i];
    }
    size_t resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8) {
        if (m != 0) {
            delete[] m;
        }
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        n[7] = n8;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8) {
        size_t k = i8 +
                   i7 * n[7] +
                   i6 * n[7] * n[7] +
                   i5 * n[7] * n[7] * n[6] +
                   i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8) const {
        size_t k = i8 +
                   i7 * n[7] +
                   i6 * n[7] * n[7] +
                   i5 * n[7] * n[7] * n[6] +
                   i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice7<K> operator()(size_t i1) {
        size_t k = i7 * n[7] +
                   i6 * n[7] * n[7] +
                   i5 * n[7] * n[7] * n[6] +
                   i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice7<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice6<K> operator()(size_t i1, size_t i2) {
        size_t k = i6 * n[7] * n[7] +
                   i5 * n[7] * n[7] * n[6] +
                   i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice6<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice5<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i5 * n[7] * n[7] * n[6] +
                   i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice5<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice4<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i4 * n[7] * n[7] * n[6] * n[5] +
                   i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i3 * n[7] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i2 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) {
        size_t k = i1 * n[7] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5, n6, n7, n8);
    }
};

template <typename K> class Tensor9 {
private:
    K * m;
    size_t n[9];
    size_t nTotal;
public:
    Tensor9() : m(0), nTotal(0) {
        memset(n, 0, sizeof(n));
    }
    Tensor9(const Tensor9 & t) {
        memcpy(n, t.n, sizeof(n));
        nTotal = t.nTotal;
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memcpy(m, t.n, nTotal * sizeof(K));
        }
    }
    Tensor9(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        n[7] = n8;
        n[8] = n9;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    ~Tensor9() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t size() {
        return nTotal;
    }
    size_t size(size_t i) {
        return n[i];
    }
    size_t resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9) {
        if (m != 0) {
            delete[] m;
        }
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        n[7] = n8;
        n[8] = n9;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9) {
        size_t k = i9 +
                   i8 * n[8] +
                   i7 * n[8] * n[8] +
                   i6 * n[8] * n[8] * n[7] +
                   i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9) const {
        size_t k = i9 +
                   i8 * n[8] +
                   i7 * n[8] * n[8] +
                   i6 * n[8] * n[8] * n[7] +
                   i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice8<K> operator()(size_t i1) {
        size_t k = i8 * n[8] +
                   i7 * n[8] * n[8] +
                   i6 * n[8] * n[8] * n[7] +
                   i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice8<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice7<K> operator()(size_t i1, size_t i2) {
        size_t k = i7 * n[8] * n[8] +
                   i6 * n[8] * n[8] * n[7] +
                   i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice7<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice6<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i6 * n[8] * n[8] * n[7] +
                   i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice6<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice5<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i5 * n[8] * n[8] * n[7] * n[6] +
                   i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice5<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice4<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i4 * n[8] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i3 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) {
        size_t k = i2 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8) {
        size_t k = i1 * n[8] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9);
    }
};

template <typename K> class Tensor10 {
private:
    K * m;
    size_t n[10];
    size_t nTotal;
public:
    Tensor10() : m(0), nTotal(0) {
        memset(n, 0, sizeof(n));
    }
    Tensor10(const Tensor10 & t) {
        memcpy(n, t.n, sizeof(n));
        nTotal = t.nTotal;
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memcpy(m, t.n, nTotal * sizeof(K));
        }
    }
    Tensor10(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9, size_t n10) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        n[7] = n8;
        n[8] = n9;
        n[9] = n10;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9 * n10;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    ~Tensor10() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t size() {
        return nTotal;
    }
    size_t size(size_t i) {
        return n[i];
    }
    size_t resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9, size_t n10) {
        if (m != 0) {
            delete[] m;
        }
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        n[7] = n8;
        n[8] = n9;
        n[9] = n10;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9 * n10;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9, size_t i10) {
        size_t k = i10 +
                   i9 * n[9] +
                   i8 * n[9] * n[9] +
                   i7 * n[9] * n[9] * n[8] +
                   i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9, size_t i10) const {
        size_t k = i10 +
                   i9 * n[9] +
                   i8 * n[9] * n[9] +
                   i7 * n[9] * n[9] * n[8] +
                   i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice9<K> operator()(size_t i1) {
        size_t k = i9 * n[9] +
                   i8 * n[9] * n[9] +
                   i7 * n[9] * n[9] * n[8] +
                   i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice9<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice8<K> operator()(size_t i1, size_t i2) {
        size_t k = i8 * n[9] * n[9] +
                   i7 * n[9] * n[9] * n[8] +
                   i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice8<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice7<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i7 * n[9] * n[9] * n[8] +
                   i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice7<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice6<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i6 * n[9] * n[9] * n[8] * n[7] +
                   i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice6<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice5<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i5 * n[9] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice5<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice4<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i4 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) {
        size_t k = i3 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8) {
        size_t k = i2 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9) {
        size_t k = i1 * n[9] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10);
    }
};

template <typename K> class Tensor11 {
private:
    K * m;
    size_t n[11];
    size_t nTotal;
public:
    Tensor11() : m(0), nTotal(0) {
        memset(n, 0, sizeof(n));
    }
    Tensor11(const Tensor11 & t) {
        memcpy(n, t.n, sizeof(n));
        nTotal = t.nTotal;
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memcpy(m, t.n, nTotal * sizeof(K));
        }
    }
    Tensor11(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9, size_t n10, size_t n11) {
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        n[7] = n8;
        n[8] = n9;
        n[9] = n10;
        n[10] = n11;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9 * n10 * n11;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    ~Tensor11() {
        if (m != 0) {
            delete[] m;
        }
    }
    size_t size() {
        return nTotal;
    }
    size_t size(size_t i) {
        return n[i];
    }
    size_t resize(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9, size_t n10, size_t n11) {
        if (m != 0) {
            delete[] m;
        }
        n[0] = n1;
        n[1] = n2;
        n[2] = n3;
        n[3] = n4;
        n[4] = n5;
        n[5] = n6;
        n[6] = n7;
        n[7] = n8;
        n[8] = n9;
        n[9] = n10;
        n[10] = n11;
        nTotal = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9 * n10 * n11;
        m = new K[nTotal];
        if (m == 0) {
            memset(n, 0, sizeof(n));
            nTotal = 0;
        } else {
            memset(m, 0, nTotal * sizeof(K));
        }
    }
    K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9, size_t i10, size_t i11) {
        size_t k = i11 +
                   i10 * n[10] +
                   i9 * n[10] * n[10] +
                   i8 * n[10] * n[10] * n[9] +
                   i7 * n[10] * n[10] * n[9] * n[8] +
                   i6 * n[10] * n[10] * n[9] * n[8] * n[7] +
                   i5 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    const K & operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9, size_t i10, size_t i11) const {
        size_t k = i11 +
                   i10 * n[10] +
                   i9 * n[10] * n[10] +
                   i8 * n[10] * n[10] * n[9] +
                   i7 * n[10] * n[10] * n[9] * n[8] +
                   i6 * n[10] * n[10] * n[9] * n[8] * n[7] +
                   i5 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return m[k];
    }
    TensorSlice10<K> operator()(size_t i1) {
        size_t k = i10 * n[10] +
                   i9 * n[10] * n[10] +
                   i8 * n[10] * n[10] * n[9] +
                   i7 * n[10] * n[10] * n[9] * n[8] +
                   i6 * n[10] * n[10] * n[9] * n[8] * n[7] +
                   i5 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice10<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
    }
    TensorSlice9<K> operator()(size_t i1, size_t i2) {
        size_t k = i9 * n[10] * n[10] +
                   i8 * n[10] * n[10] * n[9] +
                   i7 * n[10] * n[10] * n[9] * n[8] +
                   i6 * n[10] * n[10] * n[9] * n[8] * n[7] +
                   i5 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice9<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
    }
    TensorSlice8<K> operator()(size_t i1, size_t i2, size_t i3) {
        size_t k = i8 * n[10] * n[10] * n[9] +
                   i7 * n[10] * n[10] * n[9] * n[8] +
                   i6 * n[10] * n[10] * n[9] * n[8] * n[7] +
                   i5 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice8<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
    }
    TensorSlice7<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4) {
        size_t k = i7 * n[10] * n[10] * n[9] * n[8] +
                   i6 * n[10] * n[10] * n[9] * n[8] * n[7] +
                   i5 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice7<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
    }
    TensorSlice6<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {
        size_t k = i6 * n[10] * n[10] * n[9] * n[8] * n[7] +
                   i5 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice6<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
    }
    TensorSlice5<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6) {
        size_t k = i5 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] +
                   i4 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice5<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
    }
    TensorSlice4<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7) {
        size_t k = i4 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] +
                   i3 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice4<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
    }
    TensorSlice3<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8) {
        size_t k = i3 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] +
                   i2 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice3<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
    }
    TensorSlice2<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9) {
        size_t k = i2 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] +
                   i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice2<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
    }
    TensorSlice1<K> operator()(size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t i6, size_t i7, size_t i8, size_t i9, size_t i10) {
        size_t k = i1 * n[10] * n[10] * n[9] * n[8] * n[7] * n[6] * n[5] * n[4] * n[3] * n[2];
        return TensorSlice1<K>(&m[k], n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
    }
};

#endif

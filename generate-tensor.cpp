/* 
 * File:   generate-tensor.cpp
 * Author: kingfisher1337
 *
 * Created on September 2, 2013, 9:36 AM
 */

#include <cstdlib>
#include <fstream>
using namespace std;

void printInitCopyN(ostream & o, int rank) {
    for (int j = 1; j <= rank; ++j) {
        o << "        this->n[" << (j-1) << "] = n" << j << ";" << endl;
        o << "        this->b[" << (j-1) << "] = 0;" << endl;
    }
    o << "        this->nTotal = n1";
    for (int j = 2; j <= rank; ++j ) {
        o << " * n" << j;
    }
    o << ";" << endl;
}
void printInitCopyN2(ostream & o, int rank) {
    for (int j = 1; j <= rank; ++j) {
        o << "        this->n[" << (j-1) << "] = n" << j << " - m" << j << " + 1;" << endl;
        o << "        this->b[" << (j-1) << "] = m" << j << ";" << endl;
    }
    o << "        this->nTotal = this->n[0]";
    for (int j = 2; j <= rank; ++j ) {
        o << " * this->n[" << (j-1) << "]";
    }
    o << ";" << endl;
}
void printInit(ostream & o, int rank) {
    printInitCopyN(o, rank);
    o << "        this->m = new K[this->nTotal];" << endl
      << "        if (this->m == 0) {" << endl
      << "            memset(this->n, 0, sizeof(this->n));" << endl
      << "            memset(this->b, 0, sizeof(this->b));" << endl
      << "            this->nTotal = 0;" << endl
      << "        } else {" << endl
      << "            memset(this->m, 0, this->nTotal * sizeof(K));" << endl
      << "        }" << endl;
}
void printInit2(ostream & o, int rank) {
    printInitCopyN2(o, rank);
    o << "        this->m = new K[this->nTotal];" << endl
      << "        if (this->m == 0) {" << endl
      << "            memset(this->n, 0, sizeof(this->n));" << endl
      << "            memset(this->b, 0, sizeof(this->b));" << endl
      << "            this->nTotal = 0;" << endl
      << "        } else {" << endl
      << "            memset(this->m, 0, this->nTotal * sizeof(K));" << endl
      << "        }" << endl;
}
void printClean(ostream & o) {
    o << "        if (this->m != 0) {" << endl
      << "            delete[] this->m;" << endl
      << "            this->m = 0;" << endl
      << "        }" << endl;
}
void printArgList(ostream & o, int rank, const string & basename = "n", bool showType = true) {
    o << (showType ? "int " : "") << basename << "1";
    for (int j = 2; j <= rank; ++j) {
        o << ", " << (showType ? "int " : "") << basename << j;
    }
}
void printArgList2(ostream & o, int rank, const string & basename1 = "m", const string & basename2 = "n", bool showType = true) {
    o << (showType ? "int " : "") << basename1 << "1" << ", "
      << (showType ? "int " : "") << basename2 << "1";
    for (int j = 2; j <= rank; ++j) {
        o << ", " << (showType ? "int " : "") << basename1 << j
          << ", " << (showType ? "int " : "") << basename2 << j;
    }
}
void printIndexMethodBodyIndexCalc(ostream & o, int rank, int dimLimit = -1) {
    if (dimLimit == -1) {
        dimLimit = rank;
    }
    o << "        int k = ";
    for (int j = dimLimit; j >= 1; --j) {
        if (j != dimLimit) {
            o << "                   ";
        }
        o << "(i" << j << "-b[" << (j-1) << "])";
        if (j < dimLimit || rank != dimLimit) {
            o << " * n[" << rank-1 << "]";
        }
        for (int k = rank - 1; k > j; --k) {
            o << " * n[" << k-1 << "]";
        }
        if (j > 1) {
            o << " +" << endl;
        } else {
            o << ";" << endl;
        }
    }
}
void printIndexMethodBody(ostream & o, int rank) {
    printIndexMethodBodyIndexCalc(o, rank);
    o << "        return m[k];" << endl;
}

int main(int argc, char** argv) {

    const int maxRank = 11;
    ofstream o("output/tensor.hpp");
    
    o << "#ifndef TENSOR_HPP" << endl
      << "#define TENSOR_HPP" << endl << endl
      << "#include <cstdlib>" << endl
      << "#include <cstring>" << endl << endl;
    
    for (int i = 1; i <= maxRank; ++i) {
        o << "template <typename K> class TensorBase" << i << " {" << endl
          << "protected:" << endl
          << "    K * m;" << endl
          << "    int n[" << i << "];" << endl
          << "    int b[" << i << "];" << endl
          << "    int nTotal;" << endl
          << "    TensorBase" << i << "() : m(0), nTotal(0) {" << endl
          << "        memset(this->n, 0, sizeof(this->n));" << endl
          << "        memset(this->b, 0, sizeof(this->b));" << endl
          << "    }" << endl
          << "public:" << endl
          << "    TensorBase" << i << "(K * m, ";
        printArgList(o, i);
        o << ") : m(m) {" << endl;
        printInitCopyN(o, i);
        o << "    }" << endl;
        o << "    TensorBase" << i << "(K * m, ";
        printArgList2(o, i);
        o << ") : m(m) {" << endl;
        printInitCopyN2(o, i);
        o << "    }" << endl
          << "    virtual ~TensorBase" << i << "() { }" << endl
          << "    int size() const {" << endl
          << "        return nTotal;" << endl
          << "    }" << endl
          << "    int size(int i) const {" << endl
          << "        return n[i];" << endl
          << "    }" << endl
          << "    int baseIndex(int i) const {" << endl
          << "        return b[i];" << endl
          << "    }" << endl
          << "    K & operator()(";
        printArgList(o, i, "i");
        o << ") {" << endl;
        printIndexMethodBody(o, i);
        o << "    }" << endl
          << "    const K & operator()(";
        printArgList(o, i, "i");
        o << ") const {" << endl;
        printIndexMethodBody(o, i);
        o << "    }" << endl;
        for (int j = 1; j <= i - 1; ++j) {
            o << "    TensorBase" << (i-j) << "<K> operator()(";
            printArgList(o, j, "i");
            o << ") {" << endl;
            printIndexMethodBodyIndexCalc(o, i, j);
            o << "        return TensorBase" << (i-j) << "<K>(&m[k]";
            for (int k = j; k < i; ++k) {
                o << ", b[" << k << "], b[" << k << "]+n[" << k << "]-1";
            }
            o << ");" << endl
              << "    }" << endl;
        }
        o << "    K * getMemory() {" << endl
          << "        return m;" << endl
          << "    }" << endl
          << "};" << endl << endl;
    }
    
    for (int i = 1; i <= maxRank; ++i) {
        o << "template <typename K> class Tensor" << i << " : public TensorBase" << i << "<K> {" << endl
          << "public:" << endl
          << "    Tensor" << i << "() {" << endl
          << "        memset(this->n, 0, sizeof(this->n));" << endl
          << "        memset(this->b, 0, sizeof(this->b));" << endl
          << "    }" << endl
          << "    Tensor" << i << "(const TensorBase" << i << "<K> & t) {" << endl
          << "        memcpy(this->n, t.n, sizeof(this->n));" << endl
          << "        memcpy(this->b, t.b, sizeof(this->b));" << endl
          << "        this->nTotal = t.nTotal;" << endl
          << "        this->m = new K[this->nTotal];" << endl
          << "        if (this->m == 0) {" << endl
          << "            memset(this->n, 0, sizeof(this->n));" << endl
          << "            memset(this->b, 0, sizeof(this->b));" << endl
          << "            this->nTotal = 0;" << endl
          << "        } else {" << endl
          << "            memcpy(this->m, t.m, this->nTotal * sizeof(K));" << endl
          << "        }" << endl
          << "    }" << endl
          << "    Tensor" << i << "(const Tensor" << i << "<K> & t) {" << endl
          << "        memcpy(this->n, t.n, sizeof(this->n));" << endl
          << "        memcpy(this->b, t.b, sizeof(this->b));" << endl
          << "        this->nTotal = t.nTotal;" << endl
          << "        this->m = new K[this->nTotal];" << endl
          << "        if (this->m == 0) {" << endl
          << "            memset(this->n, 0, sizeof(this->n));" << endl
          << "            memset(this->b, 0, sizeof(this->b));" << endl
          << "            this->nTotal = 0;" << endl
          << "        } else {" << endl
          << "            memcpy(this->m, t.m, this->nTotal * sizeof(K));" << endl
          << "        }" << endl
          << "    }" << endl
          << "    Tensor" << i << "(";
        printArgList(o, i);
        o << ") {" << endl;
        printInit(o, i);
        o << "    }" << endl
          << "    Tensor" << i << "(";
        printArgList2(o, i);
        o << ") {" << endl;
        printInit2(o, i);
        o << "    }" << endl
          << "    ~Tensor" << i <<"() {" << endl;
        printClean(o);
        o << "    }" << endl
          << "    void resize(int n1";
        for (int j = 2; j <= i; ++j) {
            o << ", int n" << j;
        }
        o << ") {" << endl;
        printClean(o);
        printInit(o, i);
        o << "    }" << endl
          << "};" << endl << endl;
    }
    
    o << "#endif" << endl << endl;
    
    o.close();    
    return 0;
}

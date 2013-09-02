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
        o << "        n[" << (j-1) << "] = n" << j << ";" << endl;
    }
    o << "        nTotal = n1";
    for (int j = 2; j <= rank; ++j ) {
        o << " * n" << j;
    }
    o << ";" << endl;
}
void printInit(ostream & o, int rank) {
    printInitCopyN(o, rank);
    o << "        m = new K[nTotal];" << endl
      << "        if (m == 0) {" << endl
      << "            memset(n, 0, sizeof(n));" << endl
      << "            nTotal = 0;" << endl
      << "        } else {" << endl
      << "            memset(m, 0, nTotal * sizeof(K));" << endl
      << "        }" << endl;
}
void printClean(ostream & o) {
    o << "        if (m != 0) {" << endl
      << "            delete[] m;" << endl
      << "        }" << endl;
}
void printArgList(ostream & o, int rank, const string & basename = "n", bool showType = true) {
    o << (showType ? "size_t " : "") << basename << "1";
    for (int j = 2; j <= rank; ++j) {
        o << ", " << (showType ? "size_t " : "") << basename << j;
    }
}
void printIndexMethodBodyIndexCalc(ostream & o, int rank, int dimLimit = -1) {
    if (dimLimit == -1) {
        dimLimit = rank;
    }
    o << "        size_t k = ";
    for (int j = dimLimit; j >= 1; --j) {
        if (j != dimLimit) {
            o << "                   ";
        }
        o << "i" << j;
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
    
    for (int i = 1; i <= maxRank - 1; ++i) {
        o << "template <typename K> class TensorSlice" << i << " {" << endl
          << "private:" << endl
          << "    K * m;" << endl
          << "    size_t n[" << i << "];" << endl
          << "    size_t nTotal;" << endl
          << "public:" << endl
          << "    TensorSlice" << i << "(K * m, ";
        printArgList(o, i);
        o << ") : m(m) {" << endl;
        printInitCopyN(o, i);
        o << "    }" << endl
          << "    size_t size() {" << endl
          << "        return nTotal;" << endl
          << "    }" << endl
          << "    size_t size(size_t i) {" << endl
          << "        return n[i];" << endl
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
            o << "    TensorSlice" << (i-j) << "<K> operator()(";
            printArgList(o, j, "i");
            o << ") {" << endl;
            printIndexMethodBodyIndexCalc(o, i, j);
            o << "        return TensorSlice" << (i-j) << "<K>(&m[k]";
            for (int k = j; k < i; ++k) {
                o << ", n[" << k << "]";
            }
            o << ");" << endl
              << "    }" << endl;
        }
        o << "};" << endl << endl;
    }
    
    for (int i = 1; i <= maxRank; ++i) {
        o << "template <typename K> class Tensor" << i << " {" << endl
          << "private:" << endl
          << "    K * m;" << endl
          << "    size_t n[" << i << "];" << endl
          << "    size_t nTotal;" << endl
          << "public:" << endl
          << "    Tensor" << i << "() : m(0), nTotal(0) {" << endl
          << "        memset(n, 0, sizeof(n));" << endl
          << "    }" << endl
          << "    Tensor" << i << "(const Tensor" << i << " & t) {" << endl
          << "        memcpy(n, t.n, sizeof(n));" << endl
          << "        nTotal = t.nTotal;" << endl
          << "        if (m == 0) {" << endl
          << "            memset(n, 0, sizeof(n));" << endl
          << "            nTotal = 0;" << endl
          << "        } else {" << endl
          << "            memcpy(m, t.n, nTotal * sizeof(K));" << endl
          << "        }" << endl
          << "    }" << endl
          << "    Tensor" << i << "(";
        printArgList(o, i);
        o << ") {" << endl;
        printInit(o, i);
        o << "    }" << endl
          << "    ~Tensor" << i <<"() {" << endl;
        printClean(o);
        o << "    }" << endl
          << "    size_t size() {" << endl
          << "        return nTotal;" << endl
          << "    }" << endl
          << "    size_t size(size_t i) {" << endl
          << "        return n[i];" << endl
          << "    }" << endl
          << "    size_t resize(size_t n1";
        for (int j = 2; j <= i; ++j) {
            o << ", size_t n" << j;
        }
        o << ") {" << endl;
        printClean(o);
        printInit(o, i);
        o << "    }" << endl
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
            o << "    TensorSlice" << (i-j) << "<K> operator()(";
            printArgList(o, j, "i");
            o << ") {" << endl;
            printIndexMethodBodyIndexCalc(o, i, j);
            o << "        return TensorSlice" << (i-j) << "<K>(&m[k]";
            for (int k = j; k < i; ++k) {
                o << ", n[" << k << "]";
            }
            o << ");" << endl
              << "    }" << endl;
        }
        o << "};" << endl << endl;
    }
    
    o << "#endif" << endl << endl;
    
    o.close();    
    return 0;
}


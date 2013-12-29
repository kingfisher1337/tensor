tensor
======

this is a small c++ program to generate tensor classes up to an arbitrary rank;
use the file "tensor.hpp" from this repo or compile "generate-tensor.cpp" yourself to generate "tensor.hpp";

examples:

1. simple 1D-array
------------------
Tensor1<double> f(10);
for (int x = 0; x < 10; ++x) {
    f(x) = 5.0 * x;
}

2. arbitrary index range
------------------------
Tensor1<double> f(-10, +10);
for (int x = -10; x <= 10; ++x) {
    f(x) = 5.0 * x;
}

3. multiple indices (non-physicist see wikipedia for the epsilon-tensor or levi-civita-symbol)
-------------------
Tensor3<int> epsilon(1, 3, 1, 3, 1, 3);
// each of the 3 epsilon-indices goes from 1 to 3
for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
        for (int k = 1; k <= 3; ++k) {
            if (i == j || i == k || j == k) {
                epsilon(i, j, k) = 0;
            } else if (i == 1 && j == 2 && k == 3 ||
                       i == 2 && j == 3 && k == 1 ||
                       i == 3 && j == 1 && k == 2) {
                epsilon(i, j, k) = 1;
            } else {
                epsilon(i, j, k) = -1;
            }
        }
    }
}

4. fix first indices
--------------------
Tensor2<double> a(10, 10);
for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
        a(i, j) = i * j;
    }
}
TensorBase1<double> b = a(5);
for (int i = 0; i < 10; ++i) {
    cout << b(i) << endl; // prints a(5, 0), a(5, 1), ...
}

5. get index range
------------------
Tensor2<double> a(-10, +10, -5, +5); // a(x, y) with -10 <= x <= +10 and -5 <= y +5
int x0 = f.baseIndex(0);
int x1 = x0 + f.size(0);
int y0 = f.baseIndex(1);
int y1 = y0 + f.size(1);
for (int x = x0; x <= x1; ++x) {
    for (int y = y0; y <= y1; ++y) {
        a(x, y) = x + y;
    }
}

6. resize
---------
Tensor2<double> a(10, 15); // a(x, y) with 0 <= x < 10 and 0 <= y < 15
...
a.resize(20, 25); // now a(x, y) with 0 <= x < 20 and 0 <= y < 25
...
a.resize(-10, +10, -20, +20); // now a(x, y) with -10 <= x <= +10 and -20 <= x <= +20

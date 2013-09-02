tensor
======

this is a small c++ program to generate tensor classes up to an arbitrary rank

also supports tensor slices, e.g.:
Tensor3<double> a(3, 3, 3);
TensorSlice2<double> b = a(0);
--> now b(i, j) == a(0, i, j)
--> just wrapping an instance of TensorSlice around the memory of the original Tensor instance

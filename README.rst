========================================================
ranlxd - A c++ wrapepr for Martin Lüscher's RANLUX [1]_
========================================================

The *ranlux* random number generator [1]_ is widely used in the
lattice QCD community. This package provides a c++ wrapper for
M. Lüscher's c implementation.

Files
=======

The files included are

``ranlxd.hpp``
  The header file containing the declarations.

``ranlxd.cc``
   The implementation file.

``Makefile``
   To compile and test the code.

``test/test.cc``
   Martin's original tests.

Usage
=======

After you download the repository, you should run

::

  make check

to compile and test the code.

.. [1] M. Lüscher 
   *A portable high-quality random number generator for
   lattice field theory simulations*, 
   Computer Physics Communications **79 (1994) 100**

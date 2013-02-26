////////////////////////////////////////////////////////////
//
// file ranlxd.hpp
//
// Copyright (C) 2005 Martin Luescher
// Copyright (C) 2013 Dirk Hesse
//
// This software is distributed under the terms of the GNU General
// Public License (GPL)
//
// The original version of randlx was published by Martin Luescher,
// this is virtually a c++ wrapper of Martin's methods.
//
////////////////////////////////////////////////////////////

#ifndef RANLXD_H
#define RANLXD_H

namespace ranlxd {

  class Rand {
  public:
    Rand (int seed, int level = 1) : init(1) { rlx_init(level, seed); }
    template <class OutputIterator>
    void ranlxd(OutputIterator begin, OutputIterator end);
    int size(void) { return 105; };
    // extern void rlxd_init(int level,int seed);
    template <class OutputIterator>
    void get(OutputIterator result);
    template <class InputIterator>
    void reset(InputIterator begin);
  private:
    void rlx_init(int level, int seed);
    void define_constants(void);
    void update(void);
#if (defined SSE)
    typedef struct
    {
      float c1,c2,c3,c4;
    } vec_t __attribute__ ((aligned (16)));
    
    typedef struct
    {
      vec_t c1,c2;
    } dble_vec_t __attribute__ ((aligned (16)));
    
    int init,pr,prm,ir,jr,is,is_old,next[96];
    vec_t one,one_bit,carry;
    
    union
    {
      dble_vec_t vec[12];
      float num[96];
    } x __attribute__ ((aligned (16)));
#else
    typedef struct
    {
      int c1,c2,c3,c4;
    } vec_t;
    
    typedef struct
    {
      vec_t c1,c2;
    } dble_vec_t;
    
    int init,pr,prm,ir,jr,is,is_old,next[96];
    double one_bit;
    vec_t carry;
    
    union
    {
      dble_vec_t vec[12];
      int num[96];
    } x;
#endif
  };
}

#endif

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
https://www.etlcpp.com

Copyright(c) 2017 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef __ETL_TYPE_LOOKUP__
#define __ETL_TYPE_LOOKUP__

#include <limits.h>

#include "type_traits.h"

#undef ETL_FILE
#define ETL_FILE "41"

/*[[[cog
import cog
cog.outl("#if 0")
]]]*/
/*[[[end]]]*/
#error THIS HEADER IS A GENERATOR. DO NOT INCLUDE.
/*[[[cog
import cog
cog.outl("#endif")
]]]*/
/*[[[end]]]*/

/*[[[cog
import cog
cog.outl("//***************************************************************************")
cog.outl("// This file has been auto generated. Do not edit this file.")
cog.outl("//***************************************************************************")
]]]*/
/*[[[end]]]*/

namespace etl
{
  //***************************************************************************
  /// The type/id pair type to use for type/id lookup template parameters.
  //***************************************************************************
  template <typename T = void, size_t ID_ = 0>
  struct type_id_pair
  {
    typedef T type;

    enum
    {
      ID = ID_
    };
  };

  //***************************************************************************
  /// The type/type pair type to use for type/type lookup template parameters.
  //***************************************************************************
  template <typename T1 = void, typename T2 = void>
  struct type_type_pair
  {
    typedef T1 type1;
    typedef T2 type2;
  };

  /*[[[cog
  import cog
  cog.outl("//***************************************************************************")
  cog.outl("// Default for %s types." % int(NTypes))
  cog.outl("//***************************************************************************")
  cog.outl("template <typename T1,")
  for n in range(2, int(NTypes)):
      cog.outl("          typename T%s = etl::type_id_pair<>," %n)
  cog.outl("          typename T%s = etl::type_id_pair<> >" %NTypes)
  cog.outl("struct type_id_lookup")
  cog.outl("{")
  cog.outl("  //************************************")
  cog.outl("  template <size_t ID>")
  cog.outl("  struct type_from_id")
  cog.outl("  {")
  cog.outl("    typedef ")
  for n in range(1, int(NTypes) + 1):
      cog.outl("          typename etl::conditional<ID == T%s::ID,  typename T%s::type," %(n, n))
  cog.out("          void>")
  for n in range(1, int(NTypes) + 1):
      if n == int(NTypes):
          cog.outl("::type type;")
      else:
          cog.out("::type>")
      if n % 4 == 0:          
          if n != int(NTypes):
              cog.outl("")
              cog.out("               ")
  cog.outl("  };")
  cog.outl("")
  cog.outl("  //************************************")
  cog.outl("  enum")
  cog.outl("  {")
  cog.outl("    UNKNOWN = UINT_MAX")
  cog.outl("  };")
  cog.outl("")
  cog.outl("  template <typename T>")
  cog.outl("  struct id_from_type")
  cog.outl("  {")
  cog.outl("    enum")
  cog.outl("    {")
  cog.outl("      value =")
  for n in range(1, int(NTypes) + 1) :
      cog.outl("        (unsigned int) etl::is_same<T, typename T%s::type>::value ? T%s::ID :" % (n, n))
  cog.outl("        (unsigned int) UNKNOWN")
  cog.outl("    };")
  cog.outl("  };")
  cog.outl("};")
  for n in range(int(NTypes) - 1, 0, -1):
      cog.outl("")
      cog.outl("//***************************************************************************")
      if n == 1:
          cog.outl("// Specialisation for %d type." % n)
      else:
          cog.outl("// Specialisation for %d types." % n)
      cog.outl("//***************************************************************************")
      cog.out("template <")
      for t in range(1, n + 1):
          cog.out("typename T%s" %t)
          if t == n:
              cog.outl(">")
          else:
              cog.outl(",")
              cog.out("          ")
      cog.out("struct type_id_lookup<")
      for t in range(1, n + 1):
          cog.out("T%s, " %t)
          if t % 4 == 0:
              cog.outl("")
              cog.out("                      ")
      for t in range(n, int(NTypes) - 1):
          cog.out("etl::type_id_pair<>, ")
          if t % 4 == 0:
              cog.outl("")
              cog.out("                      ")
      cog.outl("etl::type_id_pair<> >")
      cog.outl("{")
      cog.outl("  //************************************")
      cog.outl("  template <size_t ID>")
      cog.outl("  struct type_from_id")
      cog.outl("  {")
      cog.outl("    typedef ")
      for t in range(1, n + 1):
          cog.outl("          typename etl::conditional<ID == T%s::ID,  typename T%s::type," %(t, t))
      cog.out("          void>")
      for t in range(1, n + 1):
          if t == n:
              cog.outl("::type type;")
          else:
              cog.out("::type>")
          if t % 8 == 0:
              cog.outl("")
              cog.out("               ")
      cog.outl("  };")
      cog.outl("")
      cog.outl("  //************************************")
      cog.outl("  enum")
      cog.outl("  {")
      cog.outl("    UNKNOWN = UINT_MAX")
      cog.outl("  };")
      cog.outl("")
      cog.outl("  template <typename T>")
      cog.outl("  struct id_from_type")
      cog.outl("  {")
      cog.outl("    enum")
      cog.outl("    {")
      cog.outl("      value =")
      for t in range(1, n + 1) :
          cog.outl("        (unsigned int) etl::is_same<T, typename T%s::type>::value ? T%s::ID :" % (t, t))
      cog.outl("        (unsigned int) UNKNOWN")
      cog.outl("    };")
      cog.outl("  };")
      cog.outl("};")
  cog.outl("//***************************************************************************")
  cog.outl("// Default for %s types." % int(NTypes))
  cog.outl("//***************************************************************************")
  cog.outl("template <typename T1,")
  for n in range(2, int(NTypes)):
      cog.outl("          typename T%s = etl::type_type_pair<>," %n)
  cog.outl("          typename T%s = etl::type_type_pair<> >" %NTypes)
  cog.outl("struct type_type_lookup")
  cog.outl("{")
  cog.outl("  //************************************")
  cog.outl("  template <typename T>")
  cog.outl("  struct type_from_type")
  cog.outl("  {")
  cog.outl("    typedef ")
  for n in range(1, int(NTypes) + 1):
      cog.outl("          typename etl::conditional<etl::is_same<T, typename T%s::type1>::value, typename T%s::type2," %(n, n))
  cog.out("          void>")
  for n in range(1, int(NTypes) + 1):
      if n == int(NTypes):
          cog.outl("::type type;")
      else:
          cog.out("::type>")
      if n % 8 == 0:
          if n != int(NTypes):
              cog.outl("")
              cog.out("               ")
  cog.outl("  };")
  cog.outl("};")
  for n in range(int(NTypes) - 1, 0, -1):
    cog.outl("")
    cog.outl("//***************************************************************************")
    if n == 1:
        cog.outl("// Specialisation for %d type." % n)
    else:
        cog.outl("// Specialisation for %d types." % n)
    cog.outl("//***************************************************************************")
    cog.out("template <")
    for t in range(1, n + 1):
        cog.out("typename T%s" %t)
        if t == n:
            cog.outl(">")
        else:
            cog.outl(",")
            cog.out("          ")
    cog.out("struct type_type_lookup<")
    for t in range(1, n + 1):
        cog.out("T%s, " %t)
        if t % 4 == 0:
            cog.outl("")
            cog.out("                        ")
    for t in range(n, int(NTypes) - 1):
        cog.out("etl::type_type_pair<>, ")
        if t % 4 == 0:
            cog.outl("")
            cog.out("                        ")
    cog.outl("etl::type_type_pair<> >")
    cog.outl("{")
    cog.outl("  //************************************")
    cog.outl("  template <typename T>")
    cog.outl("  struct type_from_type")
    cog.outl("  {")
    cog.outl("    typedef ")
    for t in range(1, n + 1):
        cog.outl("          typename etl::conditional<etl::is_same<T, typename T%s::type1>::value, typename T%s::type2," %(t, t))
    cog.out("          void>")
    for t in range(1, n + 1):
        if t == n:
            cog.outl("::type type;")
        else:
            cog.out("::type>")
            if t % 8 == 0:
                cog.outl("")
                cog.out("               ")
    cog.outl("  };")
    cog.outl("};")
  ]]]*/
  /*[[[end]]]*/
}

#undef ETL_FILE

#endif

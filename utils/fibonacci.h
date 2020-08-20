#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <boost/version.hpp>

#if BOOST_VERSION > 106700
#include <boost/gil.hpp>
#include <boost/gil/extension/io/jpeg/old.hpp>
#include <boost/hof.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#else
#include <boost/gil/extension/io/jpeg_dynamic_io.hpp>
#include <boost/gil/gil_all.hpp>
#endif

#include <iostream>
#include <sstream>
#include <string>

#if BOOST_VERSION > 106700

namespace mp = boost::multiprecision;

typedef mp::uint512_t myint;

template <uint64_t n>
struct fibonacci {
  enum { value = fibonacci<n - 1>::value + fibonacci<n - 2>::value };
};

template <>
struct fibonacci<0> {
  enum { value = 1 };
};

template <>
struct fibonacci<1> {
  enum { value = 1 };
};

extern uint64_t fib40;

template <class T, class U>
auto sum(T x, U y) {
  return x + y;
}

BOOST_HOF_STATIC_LAMBDA_FUNCTION(stringify) = boost::hof::first_of(
    [](auto x) BOOST_HOF_RETURNS(std::to_string(x)),
    [](auto x) BOOST_HOF_RETURNS(
        static_cast<std::ostringstream&>(std::ostringstream() << x).str()));

BOOST_HOF_STATIC_FUNCTION(make_tuple) = boost::hof::construct<std::tuple>();
#endif

using namespace boost::gil;
// models PixelDereferenceAdaptorConcept
struct mandelbrot_fn {
  typedef point<ptrdiff_t> point_t;

  typedef mandelbrot_fn const_t;
  typedef gray8_pixel_t value_type;
  typedef value_type reference;
  typedef value_type const_reference;
  typedef point_t argument_type;
  typedef reference result_type;
  static bool constexpr is_mutable = false;

  mandelbrot_fn() {}
  mandelbrot_fn(const point_t& sz) : _img_size(sz) {}

  result_type operator()(const point_t& p) const {
    // normalize the coords to (-2..1, -1.5..1.5)
    double t =
        get_num_iter(point<double>(p.x / (double)_img_size.x * 3 - 2,
                                   p.y / (double)_img_size.y * 3 - 1.5f));
    return value_type(
        (uint8_t)(pow(t, 0.5) * 255));  // raise to power suitable for viewing
  }

 private:
  point_t _img_size;

  double get_num_iter(const point<double>& p) const {
    point<double> Z(0, 0);
    for (int i = 0; i < 300; ++i)  // 100 iterations
    {
      Z = point<double>(Z.x * Z.x - Z.y * Z.y + p.x, 2 * Z.x * Z.y + p.y);
      if (Z.x * Z.x + Z.y * Z.y > 4) return i / (double)300;
    }
    return 0;
  }
};

template <typename SrcView, typename DstView>
void x_gradient(const SrcView& src, const DstView& dst) {
  for (int y = 0; y < src.height(); ++y) {
    typename SrcView::x_iterator src_it = src.row_begin(y);
    typename DstView::x_iterator dst_it = dst.row_begin(y);

    for (int x = 1; x < src.width() - 1; ++x)
      for (int c = 0; c < num_channels<SrcView>::value; ++c)
        dst_it[x][c] = (src_it[x - 1][c] - src_it[x + 1][c]) / 2;
  }
}

extern void mandel(int size);
#endif  // FIBONACCI_H

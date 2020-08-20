#include "fibonacci.h"

#if BOOST_VERSION > 106500

uint64_t fib40 = fibonacci<40>::value;
auto sum_f = BOOST_HOF_LIFT(sum);

#endif

void mandel(int size) {
  typedef mandelbrot_fn::point_t point_t;
  typedef virtual_2d_locator<mandelbrot_fn, false> locator_t;
  typedef image_view<locator_t> my_virt_view_t;

  point_t dims(size, size);

  // Construct a Mandelbrot view with a locator, taking top-left corner (0,0)
  // and step (1,1)
  my_virt_view_t mandel(
      dims, locator_t(point_t(0, 0), point_t(1, 1), mandelbrot_fn(dims)));

  //  gray8s_image_t img(dims);
  //  x_gradient(rotated90cw_view(mandel), view(img));

  // Save the Mandelbrot set and its 90-degree rotated gradient (jpeg cannot
  // save signed char; must convert to unsigned char)
  jpeg_write_view("mandel.jpg", mandel);
  //  jpeg_write_view("mandel_grad.jpg",
  //                  color_converted_view<gray8_pixel_t>(const_view(img)));
}

// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>
#include <iostream>
#include <climits>
#include <cfloat>
#include <cstdint>
#include <string>
#include <algorithm>
#include "test_array_generator.hpp"

#include "rosidl_generator_cpp/msg/empty.hpp"

#include "rosidl_generator_cpp/msg/bounded_array_bounded.hpp"
#include "rosidl_generator_cpp/msg/bounded_array_static.hpp"
#include "rosidl_generator_cpp/msg/bounded_array_unbounded.hpp"

#include "rosidl_generator_cpp/msg/primitive_static_arrays.hpp"

#include "rosidl_generator_cpp/msg/primitives_bounded.hpp"
#include "rosidl_generator_cpp/msg/primitives_static.hpp"
#include "rosidl_generator_cpp/msg/primitives_unbounded.hpp"

#include "rosidl_generator_cpp/msg/static_array_bounded.hpp"
#include "rosidl_generator_cpp/msg/static_array_static.hpp"
#include "rosidl_generator_cpp/msg/static_array_unbounded.hpp"

#include "rosidl_generator_cpp/msg/unbounded_array_bounded.hpp"
#include "rosidl_generator_cpp/msg/unbounded_array_static.hpp"
#include "rosidl_generator_cpp/msg/unbounded_array_unbounded.hpp"

#define TEST_VECTOR_SIZE 10


TEST(Test_rosidl_generator_traits, has_fixed_size) {
  static_assert(
    rosidl_generator_traits::has_fixed_size<rosidl_generator_cpp::msg::Empty>::value,
    "Empty::has_fixed_size is false");

  static_assert(
    rosidl_generator_traits::has_fixed_size<rosidl_generator_cpp::msg::PrimitivesStatic>::value,
    "PrimitivesStatic::has_fixed_size is false");

  static_assert(
    !rosidl_generator_traits::has_fixed_size<rosidl_generator_cpp::msg::PrimitivesBounded>::value,
    "PrimitivesBounded::has_fixed_size is true");

  static_assert(
    !rosidl_generator_traits::has_fixed_size<rosidl_generator_cpp::msg::PrimitivesUnbounded>::value,
    "PrimitivesUnbounded::has_fixed_size is true");

  static_assert(
    rosidl_generator_traits::has_fixed_size<
      rosidl_generator_cpp::msg::PrimitiveStaticArrays>::value,
    "PrimitivesStaticArray::has_fixed_size is false");

  static_assert(
    rosidl_generator_traits::has_fixed_size<rosidl_generator_cpp::msg::StaticArrayStatic>::value,
    "StaticArrayStatic::has_fixed_size is false");

  static_assert(
    !rosidl_generator_traits::has_fixed_size<rosidl_generator_cpp::msg::StaticArrayBounded>::value,
    "StaticArrayBounded::has_fixed_size is true");

  static_assert(
    !rosidl_generator_traits::has_fixed_size<
      rosidl_generator_cpp::msg::StaticArrayUnbounded>::value,
    "StaticArrayUnbounded::has_fixed_size is true");

  static_assert(
    !rosidl_generator_traits::has_fixed_size<rosidl_generator_cpp::msg::BoundedArrayStatic>::value,
    "BoundedArrayStatic::has_fixed_size is true");

  static_assert(
    !rosidl_generator_traits::has_fixed_size<rosidl_generator_cpp::msg::BoundedArrayBounded>::value,
    "BoundedArrayBounded::has_fixed_size is true");

  static_assert(
    !rosidl_generator_traits::has_fixed_size<
      rosidl_generator_cpp::msg::BoundedArrayUnbounded>::value,
    "BoundedArrayUnbounded::has_fixed_size is true");

  static_assert(
    !rosidl_generator_traits::has_fixed_size<
      rosidl_generator_cpp::msg::UnboundedArrayStatic>::value,
    "UnboundedArrayStatic::has_fixed_size is true");

  static_assert(
    !rosidl_generator_traits::has_fixed_size<
      rosidl_generator_cpp::msg::UnboundedArrayBounded>::value,
    "UnboundedArrayBounded::has_fixed_size is true");

  static_assert(
    !rosidl_generator_traits::has_fixed_size<
      rosidl_generator_cpp::msg::UnboundedArrayUnbounded>::value,
    "UnboundedArrayUnbounded::has_fixed_size is true");
}

TEST(Test_messages, primitives_static) {
  rosidl_generator_cpp::msg::PrimitivesStatic message;

  message.bool_value = false;
  ASSERT_EQ(false, message.bool_value);
  message.bool_value = true;
  ASSERT_EQ(true, message.bool_value);

  message.byte_value = 0;
  ASSERT_EQ(0, message.byte_value);
  message.byte_value = 255;
  ASSERT_EQ(255, message.byte_value);

  message.char_value = CHAR_MIN;
  ASSERT_EQ(CHAR_MIN, message.char_value);
  message.char_value = CHAR_MAX;
  ASSERT_EQ(CHAR_MAX, message.char_value);

  message.float32_value = FLT_MIN;
  ASSERT_EQ(FLT_MIN, message.float32_value);
  message.float32_value = FLT_MAX;
  ASSERT_EQ(FLT_MAX, message.float32_value);

  message.float64_value = DBL_MIN;
  ASSERT_EQ(DBL_MIN, message.float64_value);
  message.float64_value = DBL_MAX;
  ASSERT_EQ(DBL_MAX, message.float64_value);

  message.int8_value = INT8_MIN;
  ASSERT_EQ(INT8_MIN, message.int8_value);
  message.int8_value = INT8_MAX;
  ASSERT_EQ(INT8_MAX, message.int8_value);

  message.uint8_value = 0;
  ASSERT_EQ(0, message.uint8_value);
  message.uint8_value = UINT8_MAX;
  ASSERT_EQ(UINT8_MAX, message.uint8_value);

  message.int16_value = INT16_MIN;
  ASSERT_EQ(INT16_MIN, message.int16_value);
  message.int16_value = INT16_MAX;
  ASSERT_EQ(INT16_MAX, message.int16_value);

  message.uint16_value = 0;
  ASSERT_EQ(0, message.uint16_value);
  message.uint16_value = UINT16_MAX;
  ASSERT_EQ(UINT16_MAX, message.uint16_value);

  message.int32_value = INT32_MIN;
  ASSERT_EQ(INT32_MIN, message.int32_value);
  message.int32_value = INT32_MAX;
  ASSERT_EQ(INT32_MAX, message.int32_value);

  message.uint32_value = 0;
  ASSERT_EQ(0, message.uint32_value);
  message.uint32_value = UINT32_MAX;
  ASSERT_EQ(UINT32_MAX, message.uint32_value);

  message.int64_value = INT64_MIN;
  ASSERT_EQ(INT64_MIN, message.int64_value);
  message.int64_value = INT64_MAX;
  ASSERT_EQ(INT64_MAX, message.int64_value);

  message.uint64_value = 0;
  ASSERT_EQ(0, message.uint64_value);
  message.uint64_value = UINT64_MAX;
  ASSERT_EQ(UINT64_MAX, message.uint64_value);
}

/**
 * Check if the arrays are identical element by element.
 */
template<class T, std::size_t SIZE>
void assert_array(const std::array<T, SIZE> & a, const std::array<T, SIZE> & b)
{
  for (int i = 0; i < SIZE; i++) {
    ASSERT_EQ(a[i], b[i]);
  }
}

// Primitives bounded arrays
TEST(Test_messages, primitives_bounded) {
  rosidl_generator_cpp::msg::PrimitivesBounded message;

  // bool
  std::array<bool, 10> pattern_bool;
  test_array_bool<10>(&pattern_bool);
  std::copy_n(pattern_bool.begin(), 10, message.bool_value.begin());
  assert_array<bool, 10>(pattern_bool, message.bool_value);

  // char
  std::array<char, TEST_VECTOR_SIZE> pattern_char;
  test_array_integer_type<char, TEST_VECTOR_SIZE>(&pattern_char, CHAR_MIN, CHAR_MAX);
  std::copy_n(pattern_char.begin(), TEST_VECTOR_SIZE, message.char_value.begin());
  assert_array<char, TEST_VECTOR_SIZE>(pattern_char, message.char_value);

  // byte
  std::array<uint8_t, TEST_VECTOR_SIZE> pattern_byte;
  test_array_integer_type<uint8_t, TEST_VECTOR_SIZE>(&pattern_byte, 0, UINT8_MAX);
  std::copy_n(pattern_byte.begin(), TEST_VECTOR_SIZE, message.byte_value.begin());
  assert_array<uint8_t, 10>(pattern_byte, message.byte_value);

  // float32
  std::array<float, TEST_VECTOR_SIZE> pattern_float;
  test_array_float_type<float, TEST_VECTOR_SIZE>(&pattern_float, FLT_MIN, FLT_MAX);
  std::copy_n(pattern_float.begin(), TEST_VECTOR_SIZE, message.float32_value.begin());
  assert_array<float, TEST_VECTOR_SIZE>(pattern_float, message.float32_value);

  // float64
  std::array<double, TEST_VECTOR_SIZE> pattern_double;
  test_array_float_type<double, TEST_VECTOR_SIZE>(&pattern_double, DBL_MIN, DBL_MAX);
  std::copy_n(pattern_double.begin(), TEST_VECTOR_SIZE, message.float64_value.begin());
  assert_array<double, TEST_VECTOR_SIZE>(pattern_double, message.float64_value);

  // int8
  std::array<int8_t, TEST_VECTOR_SIZE> pattern_int8;
  test_array_integer_type<int8_t, TEST_VECTOR_SIZE>(&pattern_int8, INT8_MIN, INT8_MAX);
  std::copy_n(pattern_int8.begin(), TEST_VECTOR_SIZE, message.int8_value.begin());
  assert_array<int8_t, TEST_VECTOR_SIZE>(pattern_int8, message.int8_value);

  // uint8
  std::array<uint8_t, TEST_VECTOR_SIZE> pattern_uint8;
  test_array_integer_type<uint8_t, TEST_VECTOR_SIZE>(&pattern_uint8, 0, UINT8_MAX);
  std::copy_n(pattern_uint8.begin(), TEST_VECTOR_SIZE, message.uint8_value.begin());
  assert_array<uint8_t, TEST_VECTOR_SIZE>(pattern_uint8, message.uint8_value);

  // int16
  std::array<int16_t, TEST_VECTOR_SIZE> pattern_int16;
  test_array_integer_type<int16_t, TEST_VECTOR_SIZE>(&pattern_int16, INT16_MIN, INT16_MAX);
  std::copy_n(pattern_int16.begin(), TEST_VECTOR_SIZE, message.int16_value.begin());
  assert_array<int16_t, TEST_VECTOR_SIZE>(pattern_int16, message.int16_value);

  // uint16
  std::array<uint16_t, TEST_VECTOR_SIZE> pattern_uint16;
  test_array_integer_type<uint16_t, TEST_VECTOR_SIZE>(&pattern_uint16, 0, UINT16_MAX);
  std::copy_n(pattern_uint16.begin(), TEST_VECTOR_SIZE, message.uint16_value.begin());
  assert_array<uint16_t, TEST_VECTOR_SIZE>(pattern_uint16, message.uint16_value);

  // int32
  std::array<int32_t, TEST_VECTOR_SIZE> pattern_int32;
  test_array_integer_type<int32_t, TEST_VECTOR_SIZE>(&pattern_int32, INT32_MIN, INT32_MAX);
  std::copy_n(pattern_int32.begin(), TEST_VECTOR_SIZE, message.int32_value.begin());
  assert_array<int32_t, TEST_VECTOR_SIZE>(pattern_int32, message.int32_value);

  // uint32
  std::array<uint32_t, TEST_VECTOR_SIZE> pattern_uint32;
  test_array_integer_type<uint32_t, TEST_VECTOR_SIZE>(&pattern_uint32, 0, UINT32_MAX);
  std::copy_n(pattern_uint32.begin(), TEST_VECTOR_SIZE, message.uint32_value.begin());
  assert_array<uint32_t, TEST_VECTOR_SIZE>(pattern_uint32, message.uint32_value);

  // int64
  std::array<int64_t, TEST_VECTOR_SIZE> pattern_int64;
  test_array_integer_type<int64_t, TEST_VECTOR_SIZE>(&pattern_int64, INT64_MIN, INT64_MAX);
  std::copy_n(pattern_int64.begin(), TEST_VECTOR_SIZE, message.int64_value.begin());
  assert_array<int64_t, TEST_VECTOR_SIZE>(pattern_int64, message.int64_value);

  // uint64
  std::array<uint64_t, TEST_VECTOR_SIZE> pattern_uint64;
  test_array_integer_type<uint64_t, TEST_VECTOR_SIZE>(&pattern_uint64, 0, UINT64_MAX);
  std::copy_n(pattern_uint64.begin(), TEST_VECTOR_SIZE, message.uint64_value.begin());
  assert_array<uint64_t, TEST_VECTOR_SIZE>(pattern_uint64, message.uint64_value);

  // string
  std::string pattern_string = "Deep into that darkness peering";
  message.string_value = pattern_string;
  ASSERT_EQ(0, pattern_string.compare(message.string_value));
}

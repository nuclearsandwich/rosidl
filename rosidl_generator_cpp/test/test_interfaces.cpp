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
  int i;

  for (i = 0; i < SIZE; i++) {
    ASSERT_EQ(a[i], b[i]);
  }
}

// Primitives bounded arrays
TEST(Test_messages, primitives_bounded) {
  rosidl_generator_cpp::msg::PrimitivesBounded message;

  // bool
  std::array<bool, 10> * pattern_bool = new std::array<bool, 10>;
  test_array_bool<10>(pattern_bool);
  std::copy_n(pattern_bool->begin(), 10, message.bool_value.begin());
  assert_array<bool, 10>(*pattern_bool, message.bool_value);
  delete pattern_bool;

  // char
  std::array<char, 10> * pattern_char = new std::array<char, 10>;
  test_array_char<10>(pattern_char);
  std::copy_n(pattern_char->begin(), 10, message.char_value.begin());
  assert_array<char, 10>(*pattern_char, message.char_value);
  delete pattern_char;

  // byte
  std::array<uint8_t, 10> * pattern_byte = new std::array<uint8_t, 10>;
  test_array_uint8<10>(pattern_byte);
  std::copy_n(pattern_byte->begin(), 10, message.byte_value.begin());
  assert_array<uint8_t, 10>(*pattern_byte, message.byte_value);
  delete pattern_byte;

  // float32
  std::array<float, 10> * pattern_float = new std::array<float, 10>;
  test_array_float<10>(pattern_float);
  std::copy_n(pattern_float->begin(), 10, message.float32_value.begin());
  assert_array<float, 10>(*pattern_float, message.float32_value);
  delete pattern_float;

  // float64
  std::array<double, 10> * pattern_double = new std::array<double, 10>;
  test_array_double<10>(pattern_double);
  std::copy_n(pattern_double->begin(), 10, message.float64_value.begin());
  assert_array<double, 10>(*pattern_double, message.float64_value);
  delete pattern_double;

  // int8
  std::array<int8_t, 10> * pattern_int8 = new std::array<int8_t, 10>;
  test_array_int8<10>(pattern_int8);
  std::copy_n(pattern_int8->begin(), 10, message.int8_value.begin());
  assert_array<int8_t, 10>(*pattern_int8, message.int8_value);
  delete pattern_int8;

  // uint8
  std::array<uint8_t, 10> * pattern_uint8 = new std::array<uint8_t, 10>;
  test_array_uint8<10>(pattern_uint8);
  std::copy_n(pattern_uint8->begin(), 10, message.uint8_value.begin());
  assert_array<uint8_t, 10>(*pattern_uint8, message.uint8_value);
  delete pattern_uint8;

  // int16
  std::array<int16_t, 10> * pattern_int16 = new std::array<int16_t, 10>;
  test_array_int16<10>(pattern_int16);
  std::copy_n(pattern_int16->begin(), 10, message.int16_value.begin());
  assert_array<int16_t, 10>(*pattern_int16, message.int16_value);
  delete pattern_int16;

  // uint16
  std::array<uint16_t, 10> * pattern_uint16 = new std::array<uint16_t, 10>;
  test_array_uint16<10>(pattern_uint16);
  std::copy_n(pattern_uint16->begin(), 10, message.uint16_value.begin());
  assert_array<uint16_t, 10>(*pattern_uint16, message.uint16_value);
  delete pattern_uint16;

  // int32
  std::array<int32_t, 10> * pattern_int32 = new std::array<int32_t, 10>;
  test_array_int32<10>(pattern_int32);
  std::copy_n(pattern_int32->begin(), 10, message.int32_value.begin());
  assert_array<int32_t, 10>(*pattern_int32, message.int32_value);
  delete pattern_int32;

  // uint32
  std::array<uint32_t, 10> * pattern_uint32 = new std::array<uint32_t, 10>;
  test_array_uint32<10>(pattern_uint32);
  std::copy_n(pattern_uint32->begin(), 10, message.uint32_value.begin());
  assert_array<uint32_t, 10>(*pattern_uint32, message.uint32_value);
  delete pattern_uint32;

  // int64
  std::array<int64_t, 10> * pattern_int64 = new std::array<int64_t, 10>;
  test_array_int64<10>(pattern_int64);
  std::copy_n(pattern_int64->begin(), 10, message.int64_value.begin());
  assert_array<int64_t, 10>(*pattern_int64, message.int64_value);
  delete pattern_int64;

  // uint64
  std::array<uint64_t, 10> * pattern_uint64 = new std::array<uint64_t, 10>;
  test_array_uint64<10>(pattern_uint64);
  std::copy_n(pattern_uint64->begin(), 10, message.uint64_value.begin());
  assert_array<uint64_t, 10>(*pattern_uint64, message.uint64_value);
  delete pattern_uint64;

  // string
  std::string pattern_string = "Deep into that darkness peering";
  message.string_value = pattern_string;
  ASSERT_EQ(0, pattern_string.compare(message.string_value));
}

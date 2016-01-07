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
#include <climits>
#include <cfloat>
#include <cstdint>
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


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

#ifndef TEST_ARRAY_GENERATOR_HPP_
#define TEST_ARRAY_GENERATOR_HPP_

#include <climits>
#include <random>

/**
 * Helper function to generate a test pattern for boolean type.
 * Alternates true and false values.
 */
template<std::size_t SIZE>
void test_array_bool(std::array<bool, SIZE> * dst_array)
{
  int i;

  for (i = 0; i < SIZE; i++) {
    if ((i % 2) == 0) {
      (*dst_array)[i] = true;
    } else {
      (*dst_array)[i] = false;
    }
  }
}

/**
 * Helper function to generate a test pattern for char type.
 * Mininum and maximum for the type and random values in the middle.
 */
template<std::size_t SIZE>
void test_array_char(std::array<char, SIZE> * dst_array)
{
  int i;

  std::default_random_engine rand_generator;
  std::uniform_int_distribution<char> randnum(CHAR_MIN, CHAR_MAX);

  if (SIZE > 0) {
    (*dst_array)[0] = CHAR_MIN;
    for (i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = CHAR_MAX;
  }
}

/**
 * Helper function to generate a test pattern for float type.
 * Mininum and maximum for the type and random numbers in the middle.
 */
template<std::size_t SIZE>
void test_array_float(std::array<float, SIZE> * dst_array)
{
  int i;

  std::default_random_engine rand_generator;
  std::uniform_real_distribution<float> randnum(FLT_MIN, FLT_MAX);

  if (SIZE > 0) {
    (*dst_array)[0] = FLT_MIN;
    for (i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = FLT_MAX;
  }
}

/**
 * Helper function to generate a test pattern for double float type.
 * Mininum and maximum for the type and random numbers in the middle.
 */
template<std::size_t SIZE>
void test_array_double(std::array<double, SIZE> * dst_array)
{
  int i;

  std::default_random_engine rand_generator;
  std::uniform_real_distribution<double> randnum(DBL_MIN, DBL_MAX);

  if (SIZE > 0) {
    (*dst_array)[0] = DBL_MIN;
    for (i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = DBL_MAX;
  }
}

/**
 * Helper function to generate a test pattern for integer type.
 * Mininum and maximum for the type and random values in the middle.
 */
template<std::size_t SIZE>
void test_array_int8(std::array<int8_t, SIZE> * dst_array)
{
  int i;

  std::default_random_engine rand_generator;
  std::uniform_int_distribution<int8_t> randnum(INT8_MIN, INT8_MAX);

  if (SIZE > 0) {
    (*dst_array)[0] = INT8_MIN;
    for (i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = INT8_MAX;
  }
}

/**
 * Helper function to generate a test pattern for integer type.
 * Mininum and maximum for the type and random values in the middle.
 */
template<std::size_t SIZE>
void test_array_uint8(std::array<uint8_t, SIZE> * dst_array)
{
  int i;

  std::default_random_engine rand_generator;
  std::uniform_int_distribution<uint8_t> randnum(0, UINT8_MAX);

  if (SIZE > 0) {
    (*dst_array)[0] = 0;
    for (i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = UINT8_MAX;
  }
}

/**
 * Helper function to generate a test pattern for integer type.
 * Mininum and maximum for the type and random values in the middle.
 */
template<std::size_t SIZE>
void test_array_int32(std::array<int32_t, SIZE> * dst_array)
{
  int i;

  std::default_random_engine rand_generator;
  std::uniform_int_distribution<int32_t> randnum(INT32_MIN, INT32_MAX);

  if (SIZE > 0) {
    (*dst_array)[0] = INT32_MIN;
    for (i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = INT32_MAX;
  }
}

#endif

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
void test_array_int16(std::array<int16_t, SIZE> * dst_array)
{
  int i;

  std::default_random_engine rand_generator;
  std::uniform_int_distribution<int16_t> randnum(INT16_MIN, INT16_MAX);

  if (SIZE > 0) {
    (*dst_array)[0] = INT16_MIN;
    for (i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = INT16_MAX;
  }
}

/**
 * Helper function to generate a test pattern for integer type.
 * Mininum and maximum for the type and random values in the middle.
 */
template<std::size_t SIZE>
void test_array_uint16(std::array<uint16_t, SIZE> * dst_array)
{
  int i;

  std::default_random_engine rand_generator;
  std::uniform_int_distribution<uint16_t> randnum(0, UINT16_MAX);

  if (SIZE > 0) {
    (*dst_array)[0] = 0;
    for (i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = UINT16_MAX;
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

/**
 * Helper function to generate a test pattern for integer type.
 * Mininum and maximum for the type and random values in the middle.
 */
template<std::size_t SIZE>
void test_array_uint32(std::array<uint32_t, SIZE> * dst_array)
{
  int i;

  std::default_random_engine rand_generator;
  std::uniform_int_distribution<uint32_t> randnum(0, UINT32_MAX);

  if (SIZE > 0) {
    (*dst_array)[0] = 0;
    for (i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = UINT32_MAX;
  }
}

/**
 * Helper function to generate a test pattern for integer type.
 * Mininum and maximum for the type and random values in the middle.
 */
template<std::size_t SIZE>
void test_array_int64(std::array<int64_t, SIZE> * dst_array)
{
  int i;

  std::default_random_engine rand_generator;
  std::uniform_int_distribution<int64_t> randnum(INT64_MIN, INT64_MAX);

  if (SIZE > 0) {
    (*dst_array)[0] = INT64_MIN;
    for (i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = INT64_MAX;
  }
}

/**
 * Helper function to generate a test pattern for integer type.
 * Mininum and maximum for the type and random values in the middle.
 */
template<std::size_t SIZE>
void test_array_uint64(std::array<uint64_t, SIZE> * dst_array)
{
  int i;

  std::default_random_engine rand_generator;
  std::uniform_int_distribution<uint64_t> randnum(0, UINT64_MAX);

  if (SIZE > 0) {
    (*dst_array)[0] = 0;
    for (i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = UINT64_MAX;
  }
}

#endif

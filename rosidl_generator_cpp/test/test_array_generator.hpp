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
  for (int i = 0; i < SIZE; i++) {
    if ((i % 2) == 0) {
      (*dst_array)[i] = true;
    } else {
      (*dst_array)[i] = false;
    }
  }
}

/**
 * Helper function to generate a test pattern for integer number types.
 * The template type parameter must be an integer number type.
 * Mininum and maximum values for the type and random values in the middle.
 */
template<typename T, std::size_t SIZE>
void test_array_integer_type(std::array<T, SIZE> * dst_array, T min, T max)
{
  std::default_random_engine rand_generator;
  std::uniform_int_distribution<T> randnum(min, max);

  if (SIZE > 0) {
    (*dst_array)[0] = min;
    for (int i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = max;
  }
}

/**
 * Helper function to generate a test pattern for float number types.
 * Mininum and maximum values for the type and random numbers in the middle.
 */
template<typename T, std::size_t SIZE>
void test_array_float_type(std::array<T, SIZE> * dst_array, T min, T max)
{
  std::default_random_engine rand_generator;
  std::uniform_real_distribution<T> randnum(min, max);

  if (SIZE > 0) {
    (*dst_array)[0] = min;
    for (int i = 1; i < SIZE - 1; i++) {
      (*dst_array)[i] = randnum(rand_generator);
    }
    (*dst_array)[SIZE - 1] = max;
  }
}

#endif

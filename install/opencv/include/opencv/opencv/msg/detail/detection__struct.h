// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from opencv:msg/Detection.idl
// generated code does not contain a copyright notice

#ifndef OPENCV__MSG__DETAIL__DETECTION__STRUCT_H_
#define OPENCV__MSG__DETAIL__DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Detection in the package opencv.
typedef struct opencv__msg__Detection
{
  int32_t red;
  int32_t yellow;
  int32_t blue;
} opencv__msg__Detection;

// Struct for a sequence of opencv__msg__Detection.
typedef struct opencv__msg__Detection__Sequence
{
  opencv__msg__Detection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opencv__msg__Detection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENCV__MSG__DETAIL__DETECTION__STRUCT_H_

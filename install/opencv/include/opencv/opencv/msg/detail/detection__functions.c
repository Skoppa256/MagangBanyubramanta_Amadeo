// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from opencv:msg/Detection.idl
// generated code does not contain a copyright notice
#include "opencv/msg/detail/detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
opencv__msg__Detection__init(opencv__msg__Detection * msg)
{
  if (!msg) {
    return false;
  }
  // red
  // yellow
  // blue
  return true;
}

void
opencv__msg__Detection__fini(opencv__msg__Detection * msg)
{
  if (!msg) {
    return;
  }
  // red
  // yellow
  // blue
}

bool
opencv__msg__Detection__are_equal(const opencv__msg__Detection * lhs, const opencv__msg__Detection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // red
  if (lhs->red != rhs->red) {
    return false;
  }
  // yellow
  if (lhs->yellow != rhs->yellow) {
    return false;
  }
  // blue
  if (lhs->blue != rhs->blue) {
    return false;
  }
  return true;
}

bool
opencv__msg__Detection__copy(
  const opencv__msg__Detection * input,
  opencv__msg__Detection * output)
{
  if (!input || !output) {
    return false;
  }
  // red
  output->red = input->red;
  // yellow
  output->yellow = input->yellow;
  // blue
  output->blue = input->blue;
  return true;
}

opencv__msg__Detection *
opencv__msg__Detection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opencv__msg__Detection * msg = (opencv__msg__Detection *)allocator.allocate(sizeof(opencv__msg__Detection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opencv__msg__Detection));
  bool success = opencv__msg__Detection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opencv__msg__Detection__destroy(opencv__msg__Detection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opencv__msg__Detection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opencv__msg__Detection__Sequence__init(opencv__msg__Detection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opencv__msg__Detection * data = NULL;

  if (size) {
    data = (opencv__msg__Detection *)allocator.zero_allocate(size, sizeof(opencv__msg__Detection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opencv__msg__Detection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opencv__msg__Detection__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
opencv__msg__Detection__Sequence__fini(opencv__msg__Detection__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      opencv__msg__Detection__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

opencv__msg__Detection__Sequence *
opencv__msg__Detection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opencv__msg__Detection__Sequence * array = (opencv__msg__Detection__Sequence *)allocator.allocate(sizeof(opencv__msg__Detection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opencv__msg__Detection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opencv__msg__Detection__Sequence__destroy(opencv__msg__Detection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opencv__msg__Detection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opencv__msg__Detection__Sequence__are_equal(const opencv__msg__Detection__Sequence * lhs, const opencv__msg__Detection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opencv__msg__Detection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opencv__msg__Detection__Sequence__copy(
  const opencv__msg__Detection__Sequence * input,
  opencv__msg__Detection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opencv__msg__Detection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opencv__msg__Detection * data =
      (opencv__msg__Detection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opencv__msg__Detection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opencv__msg__Detection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opencv__msg__Detection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from opencv:msg/Detection.idl
// generated code does not contain a copyright notice

#ifndef OPENCV__MSG__DETAIL__DETECTION__TRAITS_HPP_
#define OPENCV__MSG__DETAIL__DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "opencv/msg/detail/detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace opencv
{

namespace msg
{

inline void to_flow_style_yaml(
  const Detection & msg,
  std::ostream & out)
{
  out << "{";
  // member: red
  {
    out << "red: ";
    rosidl_generator_traits::value_to_yaml(msg.red, out);
    out << ", ";
  }

  // member: yellow
  {
    out << "yellow: ";
    rosidl_generator_traits::value_to_yaml(msg.yellow, out);
    out << ", ";
  }

  // member: blue
  {
    out << "blue: ";
    rosidl_generator_traits::value_to_yaml(msg.blue, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: red
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red: ";
    rosidl_generator_traits::value_to_yaml(msg.red, out);
    out << "\n";
  }

  // member: yellow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yellow: ";
    rosidl_generator_traits::value_to_yaml(msg.yellow, out);
    out << "\n";
  }

  // member: blue
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blue: ";
    rosidl_generator_traits::value_to_yaml(msg.blue, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace opencv

namespace rosidl_generator_traits
{

[[deprecated("use opencv::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opencv::msg::Detection & msg,
  std::ostream & out, size_t indentation = 0)
{
  opencv::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opencv::msg::to_yaml() instead")]]
inline std::string to_yaml(const opencv::msg::Detection & msg)
{
  return opencv::msg::to_yaml(msg);
}

template<>
inline const char * data_type<opencv::msg::Detection>()
{
  return "opencv::msg::Detection";
}

template<>
inline const char * name<opencv::msg::Detection>()
{
  return "opencv/msg/Detection";
}

template<>
struct has_fixed_size<opencv::msg::Detection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<opencv::msg::Detection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<opencv::msg::Detection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OPENCV__MSG__DETAIL__DETECTION__TRAITS_HPP_

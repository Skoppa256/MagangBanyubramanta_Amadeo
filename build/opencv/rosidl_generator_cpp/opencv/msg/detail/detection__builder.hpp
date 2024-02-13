// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opencv:msg/Detection.idl
// generated code does not contain a copyright notice

#ifndef OPENCV__MSG__DETAIL__DETECTION__BUILDER_HPP_
#define OPENCV__MSG__DETAIL__DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opencv/msg/detail/detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opencv
{

namespace msg
{

namespace builder
{

class Init_Detection_blue
{
public:
  explicit Init_Detection_blue(::opencv::msg::Detection & msg)
  : msg_(msg)
  {}
  ::opencv::msg::Detection blue(::opencv::msg::Detection::_blue_type arg)
  {
    msg_.blue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opencv::msg::Detection msg_;
};

class Init_Detection_yellow
{
public:
  explicit Init_Detection_yellow(::opencv::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_blue yellow(::opencv::msg::Detection::_yellow_type arg)
  {
    msg_.yellow = std::move(arg);
    return Init_Detection_blue(msg_);
  }

private:
  ::opencv::msg::Detection msg_;
};

class Init_Detection_red
{
public:
  Init_Detection_red()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_yellow red(::opencv::msg::Detection::_red_type arg)
  {
    msg_.red = std::move(arg);
    return Init_Detection_yellow(msg_);
  }

private:
  ::opencv::msg::Detection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::opencv::msg::Detection>()
{
  return opencv::msg::builder::Init_Detection_red();
}

}  // namespace opencv

#endif  // OPENCV__MSG__DETAIL__DETECTION__BUILDER_HPP_

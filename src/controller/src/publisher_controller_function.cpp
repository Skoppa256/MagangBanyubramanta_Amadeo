#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "controller/msg/motion.hpp"

using std::placeholders::_1;

enum Buttons{
    A,
    B,
    X,
    Y,
    LB,
    RB,
    BACK,
    START,
    POWER,
    LEFT_STICK,
    RIGHT_STICK,
};

enum Axes{
    LR_LEFT,
    UD_LEFT,
    LT,
    LR_RIGHT,
    UD_RIGHT,
    RT,
    LR_CROSS,
    UD_CROSS,
};

// Joy Axes Output : [-1, 1]
// Required Output : [-500, 500]
#define SCALE 500

class Controller : public rclcpp::Node
{
public:
  Controller()
  : Node("controller")
  {
    publisher_ = this->create_publisher<controller::msg::Motion>("motion_command", 10);  
    subscriber_ = this->create_subscription<sensor_msgs::msg::Joy>("joy", 10, std::bind(&Controller::topic_callback, this, _1));
  }

private:
  void topic_callback(const sensor_msgs::msg::Joy &joy_data)
  {
    auto data = controller::msg::Motion();                                   
    data.x_cmd = joy_data.axes[LR_LEFT] * SCALE;
    data.y_cmd = joy_data.axes[UD_LEFT] * SCALE;
    data.yaw = joy_data.axes[LR_RIGHT] * SCALE;
    data.depth = joy_data.axes[UD_RIGHT] * SCALE;                                                 
    publisher_->publish(data);
    RCLCPP_INFO_STREAM(this->get_logger(), "Published motion commands");    
  }
  
  rclcpp::Publisher<controller::msg::Motion>::SharedPtr publisher_;             
  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscriber_; 

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Controller>());
  rclcpp::shutdown();
  return 0;
}
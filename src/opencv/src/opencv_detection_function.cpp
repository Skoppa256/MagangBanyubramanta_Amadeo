#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "opencv2/opencv.hpp"
#include "opencv/msg/detection.hpp"

using std::placeholders::_1;
using namespace std;
using namespace cv;

#define RED_H 0
#define YELLOW_H 30
#define BLUE_H 120
#define THRESH 20
#define MIN_S 50
#define MIN_V 50

class ColorDet : public rclcpp::Node
{
public:
  ColorDet()
  : Node("ColorDet")
  {
    publisher_ = this->create_publisher<opencv::msg::Detection>("object_detected", 10);  
    timer_ = this->create_wall_timer(500ms, std::bind(&ColorDet::topic_callback, this));
    cam = VideoCapture(0);

    if(!cam.isOpened()){
        RCLCPP_ERROR(this->get_logger(), "Error opening video stream or file");
    }

  }

  ~ColorDet()
  {
    cam.release();
    destroyAllWindows();
  }

private:
  void topic_callback()
  {

    Mat frame;

    if(!cam.read(frame)){
        RCLCPP_ERROR(this->get_logger(), "Error reading frame");
        return;
    }

    imshow("Frame", frame);

    Mat frameHSV;
    cvtColor(frame, frameHSV, COLOR_BGR2HSV);

    Scalar Red_Min = Scalar(RED_H - THRESH, MIN_S, MIN_V);
    Scalar Red_Max = Scalar(RED_H + THRESH, 255, 255);
    Scalar Yellow_Min = Scalar(YELLOW_H - THRESH, MIN_S, MIN_V);
    Scalar Yellow_Max = Scalar(YELLOW_H + THRESH, 255, 255);
    Scalar Blue_Min = Scalar(BLUE_H - THRESH, MIN_S, MIN_V);
    Scalar Blue_Max = Scalar(BLUE_H + THRESH, 255, 255);

    Mat redHSV, yellowHSV, blueHSV;
    inRange(frameHSV, Red_Min, Red_Max, redHSV);
    inRange(frameHSV, Yellow_Min, Yellow_Max, yellowHSV);
    inRange(frameHSV, Blue_Min, Blue_Max, blueHSV);

    auto message = opencv::msg::Detection();
    message.red = countNonZero(redHSV) > 0;
    message.yellow = countNonZero(yellowHSV) > 0;
    message.blue = countNonZero(blueHSV) > 0;

    publisher_->publish(message);

  }
  
  rclcpp::Publisher<opencv::msg::Detection>::SharedPtr publisher_;             
  rclcpp::TimerBase::SharedPtr timer_;
  VideoCapture cam; 

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ColorDet>());
  rclcpp::shutdown();
  return 0;
}
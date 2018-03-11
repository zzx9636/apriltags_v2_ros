#ifndef Im_Conv
#define Im_Conv
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../include/april_detector.h"


class ImageConverter
{
public:
  ImageConverter();
  ~ImageConverter();
  void ros2cv(const sensor_msgs::ImageConstPtr& msg);  


private: 
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  april_detector detector;

};
#endif


#include "../include/ImageConverter.h"

static const std::string OPENCV_WINDOW = "Image window";

ImageConverter::ImageConverter():it_(nh_)
{
// Subscrive to input video feed and publish output video feed
image_sub_ = it_.subscribe("/kinect2/qhd/image_mono", 1,
    &ImageConverter::ros2cv, this);
cv::namedWindow(OPENCV_WINDOW);
}

ImageConverter::~ImageConverter()
{
cv::destroyWindow(OPENCV_WINDOW);
}

void ImageConverter::ros2cv(const sensor_msgs::ImageConstPtr& msg)
{
cv_bridge::CvImagePtr cv_ptr;
try
{
    cv_ptr = cv_bridge::toCvCopy(msg);
}
catch (cv_bridge::Exception& e)
{
    ROS_ERROR("cv_bridge exception: %s", e.what());
    return;
}

detector.detection(cv_ptr->image);
// Update GUI Window
cv::imshow(OPENCV_WINDOW, cv_ptr->image);
cv::waitKey(3);


}
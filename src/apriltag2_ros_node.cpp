#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>

#include "../include/ImageConverter.h"

using namespace std;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_converter");
  ImageConverter ic;
  ros::spin();
  return 0;
}
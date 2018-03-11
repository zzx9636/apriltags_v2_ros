#ifndef april_det
#define april_det

#include <iostream>
#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"

#include "april_lib/apriltag.h"
#include "april_lib/tag36h11.h"
#include "april_lib/tag36h10.h"
#include "april_lib/tag36artoolkit.h"
#include "april_lib/tag25h9.h"
#include "april_lib/tag25h7.h"
#include "april_lib/common/getopt.h"


class april_detector
{
public:
    april_detector();
    ~april_detector();

    void detection(cv::Mat gray);

    
private:
    apriltag_family_t *aprilopt;
    apriltag_detector_t* april_det_opt;
   
};

#endif
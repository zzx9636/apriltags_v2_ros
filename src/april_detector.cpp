#include "../include/april_detector.h"

april_detector::april_detector()
{
    // default class as 36h11
    aprilopt=tag36h10_create();
    april_det_opt=apriltag_detector_create();
    apriltag_detector_add_family(april_det_opt,aprilopt);
    
    //default parameters
    april_det_opt->quad_decimate=1.0;
    april_det_opt->quad_sigma=0.0;
    april_det_opt->nthreads=4;
    april_det_opt->debug=0;
    april_det_opt->refine_edges=0;
    april_det_opt->refine_decode=0;
    april_det_opt->refine_pose=0;
    std::cout<<"Default Apriltag detector configuration set"<<std::endl;
}

april_detector::~april_detector()
{
    if(aprilopt!=NULL)
        tag36h10_destroy(aprilopt);
    
    if(april_det_opt!=NULL)
        apriltag_detector_destroy(april_det_opt);
}

void april_detector::detection(cv::Mat gray)
{
    image_u8_t im = { .width = gray.cols,
    .height = gray.rows,
    .stride = gray.cols,
    .buf = gray.data
    };
    zarray_t *detections = apriltag_detector_detect(april_det_opt, &im);
    std::cout << zarray_size(detections) << " tags detected" << std::endl;
}
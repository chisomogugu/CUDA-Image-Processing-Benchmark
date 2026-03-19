#ifndef CPU_OPS_H
#define CPU_OPS_H

#include <opencv2/opencv.hpp>

cv::Mat grayscaleCPU(const cv::Mat& input);
cv::Mat blurCPU(const cv::Mat& input);

#endif
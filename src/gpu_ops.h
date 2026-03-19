#ifndef GPU_OPS_H
#define GPU_OPS_H

#include <opencv2/opencv.hpp>

cv::Mat grayscaleGPU(const cv::Mat& input);
cv::Mat blurGPU(const cv::Mat& input);

#endif
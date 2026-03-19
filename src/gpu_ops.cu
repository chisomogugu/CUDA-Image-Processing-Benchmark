#include "gpu_ops.h"

cv::Mat grayscaleGPU(const cv::Mat& input) {
    return input.clone();
}

cv::Mat blurGPU(const cv::Mat& input) {
    return input.clone();
}
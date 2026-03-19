#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>

#include "cpu_ops.h"
#include "gpu_ops.h"

int main() {
    cv::Mat image = cv::imread("images/test.jpg");

    if (image.empty()) {
        std::cerr << "Failed to load image." << std::endl;
        return 1;
    }

    auto cpuGrayStart = std::chrono::high_resolution_clock::now();
    cv::Mat grayCPU = grayscaleCPU(image);
    auto cpuGrayEnd = std::chrono::high_resolution_clock::now();

    auto cpuBlurStart = std::chrono::high_resolution_clock::now();
    cv::Mat blurCpuImg = blurCPU(image);
    auto cpuBlurEnd = std::chrono::high_resolution_clock::now();

    cv::Mat grayGPU = grayscaleGPU(image);
    cv::Mat blurGPUImg = blurGPU(image);

    std::chrono::duration<double, std::milli> grayCpuTime = cpuGrayEnd - cpuGrayStart;
    std::chrono::duration<double, std::milli> blurCpuTime = cpuBlurEnd - cpuBlurStart;

    std::cout << "CPU Grayscale time: " << grayCpuTime.count() << " ms" << std::endl;
    std::cout << "CPU Blur time: " << blurCpuTime.count() << " ms" << std::endl;

    cv::imwrite("gray_cpu.jpg", grayCPU);
    cv::imwrite("blur_cpu.jpg", blurCpuImg);
    cv::imwrite("gray_gpu.jpg", grayGPU);
    cv::imwrite("blur_gpu.jpg", blurGPUImg);

    std::cout << "Output images saved." << std::endl;

    return 0;
}
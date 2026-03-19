#include "cpu_ops.h"

cv::Mat grayscaleCPU(const cv::Mat& input) {
    cv::Mat output(input.rows, input.cols, input.type());

    for (int y = 0; y < input.rows; y++) {
        for (int x = 0; x < input.cols; x++) {
            cv::Vec3b pixel = input.at<cv::Vec3b>(y, x);

            unsigned char gray = static_cast<unsigned char>(
                0.114 * pixel[0] + 0.587 * pixel[1] + 0.299 * pixel[2]
            );

            output.at<cv::Vec3b>(y, x) = cv::Vec3b(gray, gray, gray);
        }
    }

    return output;
}

cv::Mat blurCPU(const cv::Mat& input) {
    cv::Mat output = input.clone();

    for (int y = 1; y < input.rows - 1; y++) {
        for (int x = 1; x < input.cols - 1; x++) {
            int sumB = 0, sumG = 0, sumR = 0;

            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    cv::Vec3b pixel = input.at<cv::Vec3b>(y + ky, x + kx);
                    sumB += pixel[0];
                    sumG += pixel[1];
                    sumR += pixel[2];
                }
            }

            output.at<cv::Vec3b>(y, x) = cv::Vec3b(sumB / 9, sumG / 9, sumR / 9);
        }
    }

    return output;
}
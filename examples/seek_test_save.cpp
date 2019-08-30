/*
 *
 *  Test program SEEK Thermal CompactPRO
 *  Author: Maarten Vandersteegen
 */
#include <unistd.h>
#include <iostream>
#include <iterator>
#include <vector>

#include "seek.h"
#include <iostream>
#include <publisher.hpp>

static Publisher img_pub("tcp://0.0.0.0:14313");

int main(int argc, char** argv)
{
    LibSeek::SeekThermalPro seek(argc == 2 ? argv[1] : "");
    cv::Mat frame;

    if (!seek.open()) {
        std::cout << "failed to open seek cam" << std::endl;
        return -1;
    }
    std::cout << "Seek opened" << std::endl;

    while(1) {
        if (!seek.read(frame)) {
            std::cout << "no more LWIR img" << std::endl;
            return -1;
        }

        cv::Mat grey_frame(240, 320, CV_16U);
        cv::Mat grey_small(240, 320, CV_8UC1);
        cv::Mat color;
        cv::normalize(frame, grey_frame, 0, 255, cv::NORM_MINMAX);

        grey_frame.convertTo(grey_small, CV_8UC1);

        cv::Mat grey_small_rotated(320, 240, CV_8UC1);
        cv::rotate(grey_small, grey_small_rotated, cv::RotateFlags::ROTATE_90_CLOCKWISE);
        cv::applyColorMap(grey_small_rotated, color, cv::COLORMAP_HOT);

        std::vector<uchar> buffer(200000);
        cv::imencode(".jpg", color, buffer);
        img_pub.publish(buffer);
        std::cout << "Published " << std::to_string(buffer.size()) << std::endl;

//        usleep(100000);

    }
}

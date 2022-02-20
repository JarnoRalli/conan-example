#include "library/library.hpp"

namespace library {
    int normal_function()
    {
        return 1;
    }

    cv::Mat opencv_function()
    {
        return cv::Mat::Mat::ones(3, 3, CV_8U);
    }
}

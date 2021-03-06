#include <opencv2/highgui.hpp>

#include "face_detector.hpp"
#include "realsense.hpp"

/* RealSense demonstration for faces in angles from 0 to 30 degrees in the
 * x-axis, -20 to 20 in the y-xis and no rotation in the z-axis */

int main() {
  RealSense rs;
  FaceDetector detector;

  while (true) {
    rs.get_images();
    auto dets =
        detector.range_detect(rs.depth, rs.calibration, 0, -20, 0, 30, 20, 0);
    cvtColor(rs.depth, rs.depth, CV_GRAY2RGB);
    for (auto det : dets)
      cv::rectangle(rs.depth, det, cv::Scalar((1 << 16) - 1, 0, 0), 1);

    cv::imshow("depth", rs.depth);
    cv::waitKey(10);
  }
}

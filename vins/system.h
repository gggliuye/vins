#pragma once

#include <map>
#include <mutex>
#include <queue>

#include "sophus/se3.hpp"
#include "vins/estimator.h"
#include "vins/proto/vins_config.pb.h"

#include <pangolin/pangolin.h>

namespace vins {

class System {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

  explicit System(const vins::proto::VinsConfig& vins_config);
  ~System();

  // push in real image and IMU data (depth should be float scalar)
  bool PublishImageData(int64_t timestamp, cv::Mat& img, cv::Mat& depth);
  bool PublishImuData(int64_t timestamp, const Eigen::Vector3d& acc, const Eigen::Vector3d& gyr);
  void ShowTrack(cv::Mat* image);

  // functions for visualization
  void Draw();

  // private:
  const vins::proto::VinsConfig vins_config_;

  feature::FeatureTracker feature_tracker_;
  Estimator estimator_;

  double current_time_ = -1;

  // buffer the trajectory
  std::map<int64_t, Sophus::SE3d> camera_poses_;
};

}  // namespace vins

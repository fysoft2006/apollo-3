/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <ros/ros.h>

#include "velodyne_pointcloud/convert.h"

namespace apollo {
namespace drivers {
namespace velodyne {

class ConvertNodelet : public nodelet::Nodelet {
 public:
  ConvertNodelet() {}
  ~ConvertNodelet() {}

 private:
  virtual void onInit();
  boost::shared_ptr<Convert> _conv;
};

/** @brief Nodelet initialization. */
void ConvertNodelet::onInit() {
  ROS_INFO("Point cloud nodelet init");
  _conv.reset(new Convert());
  _conv->init(getNodeHandle(), getPrivateNodeHandle());
}

}  // namespace velodyne
}  // namespace drivers
}  // namespace apollo

// Register this plugin with pluginlib.  Names must match nodelet_velodyne.xml.
//
// parameters: package, class name, class type, base class type
PLUGINLIB_DECLARE_CLASS(velodyne_pointcloud, ConvertNodelet,
                        apollo::drivers::velodyne::ConvertNodelet,
                        nodelet::Nodelet);

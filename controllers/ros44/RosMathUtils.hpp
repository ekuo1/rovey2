#ifndef ROS_MATH_UTILS_HPP
#define ROS_MATH_UTILS_HPP

#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>

namespace RosMathUtils {
  void matrixToQuaternion(const double *matrix, geometry_msgs::Quaternion &q);
  void axisAngleToQuaternion(const double *axisAngle, geometry_msgs::Quaternion &q);
  void quaternionToAxisAngle(const geometry_msgs::Quaternion &q, double *axisAngle);
}

#endif

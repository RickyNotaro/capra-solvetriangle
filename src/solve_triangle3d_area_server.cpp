#include "ros/ros.h"
#include "capra_solve_triangle/CalculateTriangle3dArea.h"
#include <math.h>

bool calculate3dArea(capra_solve_triangle::CalculateTriangle3dArea::Request  &req,
         capra_solve_triangle::CalculateTriangle3dArea::Response &res)
{
  // Calculate length of the 3 sides of the triangle ( https://www.engineeringtoolbox.com/distance-relationship-between-two-points-d_1854.html )
  float ab = sqrt(pow(req.triangle.a.x - req.triangle.b.x, 2) + pow(req.triangle.a.y - req.triangle.b.y, 2) + pow(req.triangle.a.z - req.triangle.b.z, 2));
  float bc = sqrt(pow(req.triangle.c.x - req.triangle.b.x, 2) + pow(req.triangle.c.y - req.triangle.b.y, 2) + pow(req.triangle.c.z - req.triangle.b.z, 2));
  float ca = sqrt(pow(req.triangle.c.x - req.triangle.a.x, 2) + pow(req.triangle.c.y - req.triangle.a.y, 2) + pow(req.triangle.c.z - req.triangle.a.z, 2));
  // half perimeter (https://www.mathopenref.com/heronsformula.html)
  float hp= (ab + bc + ca) / 2;

  res.area = sqrt(hp * ( hp - ab) * (hp - bc) * (hp - ca) );

  // @TODO : Send dubug info with request info
  //ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  //ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "solve_triangle3d_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("CalculateTriangle3dArea", calculate3dArea);
  ROS_INFO("Ready to solve triangles.");
  ros::spin();

  return 0;
}
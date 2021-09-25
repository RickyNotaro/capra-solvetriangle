#include "ros/ros.h"
#include "capra_solve_triangle/CalculateTriangle3dArea.h"

bool calculate3dArea(capra_solve_triangle::CalculateTriangle3dArea::Request  &req,
         capra_solve_triangle::CalculateTriangle3dArea::Response &res)
{
  // @TODO : Somae magic math to retrieves triangle3d points object and values then calculate area
  // see https://math.stackexchange.com/questions/128991/how-to-calculate-the-area-of-a-3d-triangle/128995
  // req.triangle = Le trianlge avec les 3 points ? (X,Y,Z)^????/
  // double area1 = req.triangle.b.x + req.triangle.a.x;
   // res.area = area11;
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
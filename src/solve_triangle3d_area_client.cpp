#include "ros/ros.h"
#include "capra_solve_triangle/CalculateTriangle3dArea.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "solve_triangle3d_area_client");
  if (argc != 10)
  {
    ROS_INFO("usage: solve_triangle3d_area_client aX aY aZ bX bY bZ cX cY cZ");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<capra_solve_triangle::CalculateTriangle3dArea>("CalculateTriangle3dArea");
  capra_solve_triangle::CalculateTriangle3dArea srv;
  srv.request.triangle.a.x = atoll(argv[1]);
  srv.request.triangle.a.y = atoll(argv[2]);
  srv.request.triangle.a.z = atoll(argv[3]);

  srv.request.triangle.b.x = atoll(argv[4]);
  srv.request.triangle.b.y = atoll(argv[5]);
  srv.request.triangle.b.z = atoll(argv[6]);

  srv.request.triangle.c.x = atoll(argv[7]);
  srv.request.triangle.c.y = atoll(argv[8]);
  srv.request.triangle.c.z = atoll(argv[9]);

  if (client.call(srv))
  {
    ROS_INFO("Area: %6.4lf", srv.response.area);
  }
  else
  {
    ROS_ERROR("Failed to call service solve_triangle3d");
    return 1;
  }

  return 0;
}


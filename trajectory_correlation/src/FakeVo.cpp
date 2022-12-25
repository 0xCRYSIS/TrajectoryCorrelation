#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

int main(int argc , char **argv)
{
    ros::init(argc,argv,"fake_vo_node");
    ros::NodeHandle nh;

    ros::Publisher fake_vo_pub = nh.advertise<nav_msgs::Odometry>("/fake_vo",1000);

    ros::Rate rate(1);

    double x = 0;

    while (ros::ok())
    {
        nav_msgs::Odometry fake_vo_msg;

        fake_vo_msg.header.stamp = ros::Time::now();
        fake_vo_msg.header.frame_id = "map";
        fake_vo_msg.pose.pose.position.x = x;
        fake_vo_msg.pose.pose.position.y = 1;
        fake_vo_msg.pose.pose.position.z = 1;

        fake_vo_pub.publish(fake_vo_msg);

        x += 1;

        rate.sleep();
    }

    return 0;
    
}
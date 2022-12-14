#include <iostream>
#include <cmath>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>

class Controller : public rclcpp::Node
{
public:
    Controller(std::string name="Controller") : Node(name)
    {
        sub_state_est = this->create_subscription<std_msgs::msg::Float64MultiArray>("/demo/state_est",
                                                                                    10,
                                                                                    std::bind(&Controller::callback_state_estimate, this, std::placeholders::_1));
        sub_laser_out = this->create_subscription<sensor_msgs::msg::LaserScan>("/demo/laser/out",
                                                                                10,
                                                                                std::bind(&Controller::callback_scan, this, std::placeholders::_1));
        pub_cmd_vel = this->create_publisher<geometry_msgs::msg::Twist>("/demo/cmd_vel", 10);
    }
private:
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr sub_state_est;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr sub_laser_out;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_cmd_vel;

    double left_dist = 999999.9f;
    double leftfront_dist = 999999.9f;
    double right_dist = 999999.9f;
    double rightfront_dist = 999999.9f;
    double front_dist = 999999.9f;

    double forward_speed = 0.025;
    double current_x = 0.0f;
    double current_y = 0.0f;
    double current_yaw = 0.0f;
    std::string wall_following_state = "turn left";

    double turning_speed_wf_fast = 3.0;
    double turning_speed_wf_slow = 0.05;
    double dist_thresh_wf = 0.5;
    double dist_too_close_to_wall = 0.19;

    void callback_state_estimate(const std_msgs::msg::Float64MultiArray::SharedPtr  msg)
    {
        current_x = msg->data[0];
        current_y = msg->data[1];
        current_yaw = msg->data[2];
        this->follow_wall();
    }
    /**
     * # Read the laser scan data that indicates distances
     * to obstacles (e.g. wall) in meters and extract
     * 5 distinct laser readings to work with.
     * Each reading is separated by 45 degrees.
     * Assumes 181 laser readings, separated by 1 degree. 
     * (e.g. -90 degrees to 90 degrees....0 to 180 degrees)
     * number_of_laser_beams = str(len(msg.ranges)) 
     */ 
    void callback_scan(const sensor_msgs::msg::LaserScan::SharedPtr msg)
    {
        right_dist      = msg->ranges[0];
        rightfront_dist = msg->ranges[45];
        front_dist      = msg->ranges[90];
        leftfront_dist  = msg->ranges[135];
        left_dist       = msg->ranges[180];
    }
    void follow_wall()
    {
        geometry_msgs::msg::Twist msg;

        double d  = this->dist_thresh_wf;
        if((leftfront_dist > d) && (front_dist > d) && (rightfront_dist > d))
        {
            this->wall_following_state = "search for wall";
            msg.linear.x = forward_speed;
            msg.angular.z = -turning_speed_wf_slow;
        }
        else if((leftfront_dist > d) && (front_dist < d) && (rightfront_dist > d))
        {
            this->wall_following_state = "turn left";
            msg.angular.z = -turning_speed_wf_fast;
        }
        else if((leftfront_dist > d) && (front_dist > d) && (rightfront_dist < d))
        {
            if(rightfront_dist < dist_too_close_to_wall)
            {
                this->wall_following_state = "turn left";
                msg.linear.x = forward_speed;
                msg.angular.z = -turning_speed_wf_fast;
            }
            else
            {
                this->wall_following_state = "follow wall";
                msg.linear.x = forward_speed;
            }
        }
        else if((leftfront_dist < d) && (front_dist > d) && (rightfront_dist > d))
        {
            this->wall_following_state = "search for wall";
            msg.linear.x = forward_speed;
            msg.angular.z = -turning_speed_wf_slow;
        }
        else if((leftfront_dist > d) && (front_dist < d) && (rightfront_dist < d))
        {
            this->wall_following_state = "turn left";
            msg.angular.z = -turning_speed_wf_fast;
        }
        else if((leftfront_dist < d) && (front_dist < d) && (rightfront_dist > d))
        {
            this->wall_following_state = "turn left";
            msg.angular.z = -turning_speed_wf_fast;
        }
        else if((leftfront_dist < d) && (front_dist < d) && (rightfront_dist < d))
        {
            this->wall_following_state = "turn left";
            msg.angular.z = -turning_speed_wf_fast;
        }
        else if((leftfront_dist < d) && (front_dist > d) && (rightfront_dist < d))
        {
            this->wall_following_state = "search for wall";
            msg.linear.x = forward_speed;
            msg.angular.z = -turning_speed_wf_slow;
        }
        this->pub_cmd_vel->publish(msg);
    }
};


int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    std::shared_ptr<Controller> node = std::make_shared<Controller>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
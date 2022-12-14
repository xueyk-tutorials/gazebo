#include <iostream>
#include <string>
#include <cmath>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>

class Estimator : public rclcpp::Node
{
public:
    Estimator(std::string name="Estimator") : Node(name)
    {
        sub_odom = this->create_subscription<nav_msgs::msg::Odometry>("/demo/odom",
                                                10,
                                                std::bind(&Estimator::callback_odom, this, std::placeholders::_1));
        sub_velocity = this->create_subscription<geometry_msgs::msg::Twist>("/demo/cmd_vel",
                                                                            10,
                                                                            std::bind(&Estimator::callback_velocity, this, std::placeholders::_1));
        pub_state_est = this->create_publisher<std_msgs::msg::Float64MultiArray>("/demo/state_est", 10);
    
    }
private:
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr sub_odom;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr sub_velocity;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_state_est;

    void callback_odom(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        double roll, pitch, yaw;
        this->euler_from_quaternion(msg->pose.pose.orientation.x,
                                    msg->pose.pose.orientation.y,
                                    msg->pose.pose.orientation.z,
                                    msg->pose.pose.orientation.w, 
                                    roll, pitch, yaw);
        std_msgs::msg::Float64MultiArray obs_state_vector_x_y_yaw;
        obs_state_vector_x_y_yaw.data = {msg->pose.pose.position.x, msg->pose.pose.position.y, yaw};

        // RCLCPP_INFO(this->get_logger(), "x=%f, y=%f, yaw=%f", msg->pose.pose.position.x, msg->pose.pose.position.y, yaw);
        // 发布
        this->pub_state_est->publish(obs_state_vector_x_y_yaw);
    }
    /**
     * $ ros2 interface show geometry_msgs/msg/Twist
     * Vector3  linear
     * Vector3  angular
     */ 
    void callback_velocity(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        // 机器人前进速度
        double v = msg->linear.x;
        // 机器人转动速度
        double yaw_rate = msg->angular.z;
    }

    void euler_from_quaternion(double x, double y, double z, double w, 
                            double &roll_x, double &pitch_y, double &yaw_z)
    {
        double t0 = 2.0 * (w * x + y * z);
        double t1 = 1.0 - 2.0 * (x * x + y * y);
        roll_x = std::atan2(t0, t1);
    
        double t2 = 2.0 * (w * y - z * x);
        t2 = t2 > 1.0 ? 1.0 : t2;
        t2 = t2 < -1.0 ? -1.0 : t2;
        pitch_y = std::asin(t2);
    
        double t3 = 2.0 * (w * z + x * y);
        double t4 = 1.0 - 2.0 * (y * y + z * z);
        yaw_z = std::atan2(t3, t4);
    }

};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    std::shared_ptr<Estimator> node = std::make_shared<Estimator>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
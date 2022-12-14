#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

#include <gazebo_msgs/srv/spawn_entity.hpp>
#include <rclcpp/rclcpp.hpp>
using namespace std;

std::string readTextFile(const std::string& filename) {
    std::ifstream ifs(filename, std::ios::in);
    assert(ifs.is_open());
    std::stringstream ss;
    ss << ifs.rdbuf();
    ifs.close();
    return ss.str();
}

void spawn()
{

}


int main(int argc, char *argv[])
{
    std::cout << ">>>>> spawn_demo" << std::endl;
    rclcpp::init(argc, argv);
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("spawn_warehouse_robot");

    //
    std::string ns(argv[1]);
    double px, py, pz;
    std::stringstream ss(argv[2]);
    ss >> px;
    ss = std::stringstream(argv[3]);
    ss >> py;
    ss =  std::stringstream(argv[4]);
    ss >> pz;
    std::cout << "argv: ns=" << ns << " ,px=" << px << ", py=" << py << ", pz=" << pz << std::endl;
    //
    rclcpp::Client<gazebo_msgs::srv::SpawnEntity>::SharedPtr cli_spawn = node->create_client<gazebo_msgs::srv::SpawnEntity>("/spawn_entity");
    if(!cli_spawn->service_is_ready())
    {
        RCLCPP_INFO(node->get_logger(), "waiting for service connected");
        cli_spawn->wait_for_service();
    }

    std::cout << ">>>>> load sdf file" << std::endl;
    std::string robot_xml = readTextFile("/media/alex/Develop/alex-github/drone_tutorials/gazebo/demos/demo_WarehouseRobot/models/mobile_warehouse_robot/model.sdf");

    auto request = std::make_shared<gazebo_msgs::srv::SpawnEntity::Request>();
    request->name = "warehouse_robot";
    request->xml = robot_xml;
    request->robot_namespace = ns;
    request->initial_pose.position.x = px;
    request->initial_pose.position.y = py;
    request->initial_pose.position.z = pz;
    
    auto result = cli_spawn->async_send_request(request);
    if(rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(node->get_logger(), "spawn success");
    }
    else
    {
        RCLCPP_INFO(node->get_logger(), "spawn failed");
    }
    
    // rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
#include <iostream>
#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>

using namespace std;

namespace gazebo
{
    class AlexWheelSpeed : public ModelPlugin
    {
    public: 
        AlexWheelSpeed() : ModelPlugin()
        {
            printf(">>>>> ALex: AlexWheelSpeed\n");
        }
        void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf)
        {
            printf(">>>>> ALex: AlexWheelSpeed::Load()\n");
            // Store the pointer to the model
            this->model_ = _parent;
            if(_sdf->HasElement("jointName")){
                this->joint_name_ = _sdf->GetElement("jointName")->Get<std::string>();
                cout << "<<<<< Alex: joint_name_=" << this->joint_name_ << endl;
            }
            else{
                gzerr << "[gazebo_motor_model] Please specify a jointName, where the rotor is attached.\n";
            }
            joint_ = model_->GetJoint(joint_name_);
            if (joint_ == NULL){
                gzthrow("[gazebo_motor_model] Couldn't find specified joint \"" << joint_name_ << "\".");
            }
            
            // Listen to the update event. This event is broadcast every
            // simulation iteration.
            this->updateConnection_ = event::Events::ConnectWorldUpdateBegin(
                std::bind(&AlexWheelSpeed::OnUpdate, this));
        }

        // Called by the world update start event
        public: void OnUpdate()
        {
            this->joint_->SetVelocity(0, 0.2);
            float velocity = this->joint_->GetVelocity(0);
            // cout << "<<<<< Alex: velocity=" << velocity << endl;
        }
    private:
        physics::ModelPtr model_;
        std::string joint_name_;
        physics::JointPtr joint_;
        event::ConnectionPtr updateConnection_;
    };
    // 注册插件
    GZ_REGISTER_MODEL_PLUGIN(AlexWheelSpeed)
}
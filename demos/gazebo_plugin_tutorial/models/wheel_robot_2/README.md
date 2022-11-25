参考：https://zhuanlan.zhihu.com/p/367660310

## 模型说明
添加plug

## 运行

### 添加模型路径至环境变量
```shell
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/media/allex/Develop/alex-github/drone_tutorials/gazebo/demos/gazebo_plugin_tutorial/models
```
### 
打开终端，输入gazebo
```shell
$ gazebo
```

通过左侧insert插入模型后，选中模型，在左侧拉开Joints面板，可以通过施加力矩和速度等控制机器人运动。
如果模型文件更改，则将模型删掉后重新导入即可。
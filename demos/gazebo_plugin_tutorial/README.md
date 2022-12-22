
## 打开模型
```shell
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/media/alex/Develop/alex-github/drone_tutorials/gazebo/demos/gazebo_plugin_tutorial/models
```


## 编译
```shell
$ mkdir build && cd build
$ cmake ..
$ make
```

## 添加环境变量
将插件编译后生成路径添加至环境变量，打开~/.bashrc，添加如下内容
```shell
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:~/gazebo_plugin_tutorial/build
```


## 运行
### world插件
```shell
$ gzserver hello.world --verbose
```
在终端会打印：
```shell
Gazebo multi-robot simulator, version 9.0.0
Copyright (C) 2012 Open Source Robotics Foundation.
Released under the Apache 2 License.
http://gazebosim.org

[Msg] Waiting for master.
[Msg] Connected to gazebo master @ http://127.0.0.1:11345
[Msg] Publicized address: 192.168.43.59
Hello World!
```
### model插件
打开一个终端启动服务，运行如下命令
```shell
gzserver -u model_push.world
```
> 参数-u使得gazebo处于静止状态

打开第二个终端启动客户端，运行如下命令打开gazebo界面
```shell
gzclient
```
这时gazebo是静止的，点击play按钮（gazebo界面下方），即可看到模型在运动。

### world_edit
```shell
$ gazebo world_edit.world
```
打开gazebo界面后，放置一个立方体，然后立方体会垂直飞走！


### system_gui
以后台方式开启gzserver:
```shell
$ gzserver &
```
启动客户端并加载插件:
```shell
$ gzclient -g libsystem_gui.so
```
在/tmp/gazebo_frames看到由当前插件保存的图片.

Note: Remember to also terminate the background server process after you quit the client. In the same terminal, bring the process to foreground:
```shell
$ fg
```
and press Ctrl-C to abort the process. Alternatively, just kill the gzserver process:
```shell
$ killall gzserver
````

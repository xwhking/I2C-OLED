步骤：

1.按照接线图连接好硬件

2.把Keil工程的代码下载到STM32中

3.运行Python代码，通过串口把处理后的数据发送给STM32进行显示



注意：

1. Python需要预先安装依赖包，可以执行以下命令进行安装：
    - pip install numpy
    - pip install opencv-python	
    - pip install pyserial

2. 打开串口时，串口号需要根据自己的设备进行指定，可以打开设备管理器查看

![image-20250520152102510](C:\Users\28374\Desktop\Personal\STUDY\STM32入门教程资料\MyCode\写I2C测试\assets\image-20250520152102510.png)

3. 打开视频的文件可以自行指定

![image-20250520152113801](C:\Users\28374\Desktop\Personal\STUDY\STM32入门教程资料\MyCode\写I2C测试\assets\image-20250520152113801.png)

4. 播放视频时，按q键退出



5. 串口收发部分并没有帧同步的操作，所以需要保证每次收发都是一个完整的数据帧，如果显示中途被打断，最好把STM32复位一下，避免帧数据错位
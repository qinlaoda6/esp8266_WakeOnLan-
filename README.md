# esp8266_WakeOnLan 小爱同学语音远程开机（点灯科技）只需电源线

#### 软件介绍
其原理就是通过MQTT发送指令到esp8266,
esp8266和电脑同一局域网中使用WakeOnLan呼醒功能


#### 使用说明

1.  电脑必须是插网线
2.  打开主板BIOS中的网络呼醒功能
3.  esp8266只能使用2.4g频段WiFi
4.  电脑关机后5分钟后左右才能再次开机


#### 安装教程

1.  申请点灯科技密钥 
    手机APP下载点灯科技APP,申请一个设备(名称改为"电脑")，得到设备密钥
    
2.  Arduino配置点灯SDK
    SDK安装包：https://links.jianshu.com/go?to=https%3A%2F%2Fcodeload.github.com%2Fblinker-iot%2Fblinker-library%2Fzip%2Fmaster
![输入图片说明](import-lib.png)

3.  修改源码带有注释部分的设备密钥、WiFi账号密码、电脑MAC地址、IP (代码见)


4.编译通过上传电脑


5.手机软件控制(电灯科技)
界面配置，复制代码打开设备，找到界面配置，复制上去。 
{¨version¨¨2.0.0¨¨config¨{¨headerColor¨¨transparent¨¨headerStyle¨¨dark¨¨background¨{¨img¨¨assets/img/bg/f1.jpg¨¨isFull¨»}}¨dashboard¨|{¨type¨¨deb¨¨mode¨É¨bg¨É¨cols¨Ñ¨rows¨Í¨key¨¨debug¨´x´É´y´Ì¨speech¨|÷¨lstyle¨Ê}{ßC¨btn¨¨ico¨¨fal fa-power-off¨ßEÉ¨t0¨¨开机¨¨t1¨¨文本2¨ßFÌßGÍßHÍßI¨OPEN¨´x´Ë´y´ÑßK|÷ßLË}÷¨actions¨|¦¨cmd¨¦¨switch¨‡¨text¨‡¨on¨¨打开?name¨¨off¨¨关闭?name¨—÷¨triggers¨|{¨source¨ßW¨source_zh¨¨开关状态¨¨state¨|ßYßa÷¨state_zh¨|¨打开¨¨关闭¨÷}÷}
![输入图片说明](%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20221225172903.jpg)


#### 使用教程
1. 打开点灯科技APP 点击界面开机按钮
2. 米家APP 绑定点灯科技，同步设备，即可使用小爱语音控制。例:"打开电脑" 
3. 电脑安装远程桌面软件，设置开机启动，然后想干嘛就干嘛...

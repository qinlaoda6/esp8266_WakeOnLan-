#define BLINKER_WIFI
#define BLINKER_MIOT_OUTLET
#include <Blinker.h>
char auth[] = "349950b1880a";//点灯密钥
char ssid[] = "qinlaoda2.4g";//WiFi名称
char pswd[] = "qin.268268";//WiFi密码

WiFiUDP udp;
bool oState = false;
//宏定义按键名称
#define BUTTON_1 "OPEN"

//新建组件对象
BlinkerButton Button1(BUTTON_1);
//回调函数
void button1_callback(const String & state)
{
  BLINKER_LOG("get button1 state: ", state);

  if (state == BLINKER_CMD_BUTTON_TAP) 
  { 
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    BLINKER_LOG("Button1 tap!");
    pcawaking();
    Serial.println("发送成功！");
  }
  else {
    BLINKER_LOG("Get user setting: ", state);
  }
}

//小爱电源类回调
void miotPowerState(const String & state)
{
  BLINKER_LOG("need set power state: ",state);
  if (state == BLINKER_CMD_ON)
  {
    BlinkerMIOT.powerState("on");
    BlinkerMIOT.print();
    pcawaking();
    oState = false;
  }
  else if (state == BLINKER_CMD_OFF)
  {
     BlinkerMIOT.powerState("off");
     pcawaking();
     oState = false;
  }  
}

void miotQuery(int32_t querycode)
{
  BLINKER_LOG("MIOT Query Codes: ", querycode);
  switch (querycode)
  {
    case BLINKER_CMD_QUERY_ALL_NUMBER :
        BLINKER_LOG ("MIOT Query All");
        BlinkerMIOT.powerState(oState ? "on" : "off");
        BlinkerMIOT.print();
        break;
    case BLINKER_CMD_QUERY_POWERSTATE_NUMBER:
        BLINKER_LOG ("MIOT Query Power State");
        BlinkerMIOT.powerState (oState ? "on" : "off");
        BlinkerMIOT.print();
        break;
    default :
        BlinkerMIOT.powerState (oState ? "on" : "off");
        BlinkerMIOT.print();
        break;
  }
}

//发送数据包
void pcawaking()
{
  int i=0;
  char mac[6]={0x00,0xE0,0x67,0x25,0x20,0x6E};//电脑MAC地址,查看命令ipconfig -all
  char pac[102];
  char * Address = "192.168.110.255";//局域网地址,只需修改110处,255是广播地址
  int Port = 3333;
  for(i=0;i<6;i++)
  {
    pac[i]=0xFF;
  }
  for(i=6;i<102;i+=6)
  {
   memcpy(pac+i,mac,6); 
  }
  udp.beginPacket(Address, Port);
  udp.write((byte*) pac, 102);
  udp.endPacket();
}
  

void setup() {
  Serial.begin(115200);
  //指定DEBUG信息输出的串口号
  BLINKER_DEBUG.stream(Serial);
  //初始化LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Blinker.begin(auth,ssid,pswd);
  //注册回调函数
  Button1.attach(button1_callback);
  BlinkerMIOT.attachPowerState(miotPowerState);
  BlinkerMIOT.attachQuery(miotQuery);

}

void loop()
{
  Blinker.run();
}

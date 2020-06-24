/*
  校准

演示一种校准传感器输入的技术。这个草图前5秒的传感器读数执行定义期望值的最小值和最大值连接到传感器引脚。

传感器的最小和最大初始值可能向后。最初，你把最小值设得很高，然后听任何东西降低，将其保存为新的最小值。同样，你设置最大值低，听任何更高的作为新的最大值。
电路：
 * 模拟传感器（电位器可以）连接到模拟输入0
 * 从数字管脚9接地的LED
*/

// 这些常数不会改变：
const int sensorPin = A0;    // 传感器连接到的针脚
const int ledPin = 9;        //LED连接到的引脚

//变量：
int sensorValue = 0;         // 传感器值
int sensorMin = 1023;        // 最小传感器值
int sensorMax = 0;           // 最大传感器值


void setup() {
  //打开LED指示校准周期开始：
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);//璁剧疆杈撳嚭

  //在前5秒内校准
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    //  记录最大传感器值
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // 记录最小传感器值
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  //发出校准周期结束的信号
  digitalWrite(13, LOW);
}

void loop() {
  // 读取传感器：
  sensorValue = analogRead(sensorPin);

  // 对传感器读数进行校准
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // 如果传感器值超出校准过程中看到的范围
  sensorValue = constrain(sensorValue, 0, 255);

  // 使用校准值使LED变暗：
  analogWrite(ledPin, sensorValue);
}	

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int currentAngle1 = 90; // 初始化当前角度为90度
int currentAngle2 = 90; // 初始化当前角度为90度
int currentAngle1_r;
int currentAngle2_r;
int servo3Angle = 0; // 用于跟踪servo3的角度，初始设为0度


void setup() {
  Serial.begin(9600); // 用于调试的串口
  Serial1.begin(9600); // HC-05默认波特率
  servo1.attach(9);  // 第一个伺服电机连接到引脚90
  servo2.attach(10); // 第二个伺服电机连接到引脚10
  servo3.attach(11); // 将servo3连接到引脚11
  Serial.println("Bluetooth Serial started at 9600 Baud.");

  servo1.write(currentAngle1_r);
  servo2.write(currentAngle2_r);
  servo3.write(servo3Angle); // 设置servo3到初始位置
}

void convertToAngles(int x, int y, int *angleX, int *angleY) {
    *angleX = (x / -540.0) * 90.0;
    *angleY = (y / 1000.0) * 90.0;
}

void loop() {
  if (Serial1.available() > 0) {
    String data = Serial1.readStringUntil('\n');
    data.trim(); // 清除可能的前后空格
    Serial.println("Received data: " + data); // 打印接收到的完整数据
    
    
    // 检查是否接收到重置命令 'R'
    if (data == "reset") {
      currentAngle1 = 90;
      currentAngle2 = 90;
      currentAngle1_r = (currentAngle1)*0.667;
      currentAngle2_r = (currentAngle2)*0.667;
      servo1.write(currentAngle1_r);
      servo2.write(currentAngle2_r);
      Serial.println("Both servos reset to 90 degrees");
    }  else if (data == "rotate") {
      // 切换servo3的状态
      servo3Angle = servo3Angle == 0 ? 90 : 0; // 如果当前角度是0，则切换到90度，否则切换到0度
      servo3.write(servo3Angle);
      Serial.println("Servo3 rotated to " + String(servo3Angle) + " degrees");
    } else {
      int xIndex = data.indexOf('x');
      int yIndex = data.indexOf('y');

      if (xIndex != -1 && yIndex != -1) {
        String xValue = data.substring(xIndex + 1, yIndex);
        xValue.trim();
        String yValue = data.substring(yIndex + 1);
        yValue.trim();

        int angleChange1 = xValue.toInt();
        int angleChange2 = yValue.toInt();

        // 应用转换
        convertToAngles(angleChange1, angleChange2, &angleChange1, &angleChange2);

        Serial.println("Parsed angles: x=" + String(angleChange1) + ", y=" + String(angleChange2)); // 打印解析后的角度值

        currentAngle1 += angleChange1;
        currentAngle2 += angleChange2;

        currentAngle1 = constrain(currentAngle1, 0, 180);
        currentAngle2 = constrain(currentAngle2, 0, 180);

        currentAngle1_r= (currentAngle1)*0.667;
        currentAngle2_r= (currentAngle2)*0.667;

        servo1.write(currentAngle1_r);
        servo2.write(currentAngle2_r);

        Serial.println("Angle change applied. New angles: x=" + String(currentAngle1) + ", y=" + String(currentAngle2));
      } else {
        Serial.println("Invalid data format");
      }
    }
  }
}
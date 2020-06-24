/*
  У׼

��ʾһ��У׼����������ļ����������ͼǰ5��Ĵ���������ִ�ж�������ֵ����Сֵ�����ֵ���ӵ����������š�

����������С������ʼֵ�����������������Сֵ��úܸߣ�Ȼ�����κζ������ͣ����䱣��Ϊ�µ���Сֵ��ͬ�������������ֵ�ͣ����κθ��ߵ���Ϊ�µ����ֵ��
��·��
 * ģ�⴫��������λ�����ԣ����ӵ�ģ������0
 * �����ֹܽ�9�ӵص�LED
*/

// ��Щ��������ı䣺
const int sensorPin = A0;    // ���������ӵ������
const int ledPin = 9;        //LED���ӵ�������

//������
int sensorValue = 0;         // ������ֵ
int sensorMin = 1023;        // ��С������ֵ
int sensorMax = 0;           // ��󴫸���ֵ


void setup() {
  //��LEDָʾУ׼���ڿ�ʼ��
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);//设置输出

  //��ǰ5����У׼
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    //  ��¼��󴫸���ֵ
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // ��¼��С������ֵ
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  //����У׼���ڽ������ź�
  digitalWrite(13, LOW);
}

void loop() {
  // ��ȡ��������
  sensorValue = analogRead(sensorPin);

  // �Դ�������������У׼
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // ���������ֵ����У׼�����п����ķ�Χ
  sensorValue = constrain(sensorValue, 0, 255);

  // ʹ��У׼ֵʹLED�䰵��
  analogWrite(ledPin, sensorValue);
}	

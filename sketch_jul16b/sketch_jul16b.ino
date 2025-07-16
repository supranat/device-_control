bool isOn = false;
int countdownSeconds = 0;
bool readyToStart = false;

void setup() {
  Serial.begin(9600);
  Serial.println("ใส่จำนวนวินาทีสำหรับนับถอยหลัง:");
}

void loop() {
  if (Serial.available() > 0) {
    countdownSeconds = Serial.parseInt(); // รับค่าจาก Serial

    if (countdownSeconds > 0) {
      readyToStart = true;
    } else {
      Serial.println("กรุณาใส่ค่ามากกว่า 0");
    }
  }

  if (readyToStart && !isOn) {
    // แสดง Ready Set Go
    Serial.println("Ready...");
    delay(1000);
    Serial.println("Set...");
    delay(1000);
    Serial.println("Go!");
    delay(500);

    // เริ่มนับถอยหลัง
    isOn = true;
    Serial.println("on");
    for (int i = countdownSeconds; i > 0; i--) {
      Serial.print("Light - ");
      Serial.println(i);
      delay(1000);
    }

    Serial.println("หมดเวลา");
    Serial.println("off");
    isOn = false;
    readyToStart = false;
    Serial.println("ใส่จำนวนวินาทีสำหรับนับถอยหลัง:");
  }
}


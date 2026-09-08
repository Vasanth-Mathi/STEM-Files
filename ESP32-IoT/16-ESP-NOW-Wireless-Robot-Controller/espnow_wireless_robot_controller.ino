#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const bool REMOTE_MODE = true;
const int ESPNOW_CHANNEL = 1;

const int JOYSTICK_X = 34;
const int JOYSTICK_Y = 35;

const int LEFT_IN1 = 25;
const int LEFT_IN2 = 26;
const int RIGHT_IN1 = 27;
const int RIGHT_IN2 = 14;

uint8_t robotMac[] = {0x24, 0x6F, 0x28, 0x00, 0x00, 0x30};

struct ControlPacket {
  int x;
  int y;
};

void stopRobot() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, LOW);
}

void moveForward() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void moveBackward() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, HIGH);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, HIGH);
}

void turnLeft() {
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(LEFT_IN2, HIGH);
  digitalWrite(RIGHT_IN1, HIGH);
  digitalWrite(RIGHT_IN2, LOW);
}

void turnRight() {
  digitalWrite(LEFT_IN1, HIGH);
  digitalWrite(LEFT_IN2, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  digitalWrite(RIGHT_IN2, HIGH);
}

void driveFromJoystick(const ControlPacket& control) {
  const int LOW_LIMIT = 1400;
  const int HIGH_LIMIT = 2700;

  if (control.y > HIGH_LIMIT) {
    moveForward();
  } else if (control.y < LOW_LIMIT) {
    moveBackward();
  } else if (control.x < LOW_LIMIT) {
    turnLeft();
  } else if (control.x > HIGH_LIMIT) {
    turnRight();
  } else {
    stopRobot();
  }
}

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (REMOTE_MODE || length != sizeof(ControlPacket)) {
    return;
  }

  ControlPacket control;
  memcpy(&control, data, sizeof(control));
  driveFromJoystick(control);
}

void setup() {
  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);

  stopRobot();

  WiFi.mode(WIFI_STA);
  esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE);

  if (esp_now_init() != ESP_OK) {
    return;
  }

  esp_now_register_recv_cb(onReceive);

  if (REMOTE_MODE) {
    esp_now_peer_info_t peer = {};
    memcpy(peer.peer_addr, robotMac, 6);
    peer.channel = ESPNOW_CHANNEL;
    peer.encrypt = false;

    esp_now_add_peer(&peer);
  }
}

void loop() {
  if (!REMOTE_MODE) {
    delay(100);
    return;
  }

  ControlPacket control;
  control.x = analogRead(JOYSTICK_X);
  control.y = analogRead(JOYSTICK_Y);

  esp_now_send(
    robotMac,
    (uint8_t*)&control,
    sizeof(control)
  );

  delay(100);
}

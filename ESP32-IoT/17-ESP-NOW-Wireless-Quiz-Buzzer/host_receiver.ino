/*
  Project 17 - ESP32 Wireless Classroom Quiz Buzzer Using ESP-NOW
  Host ESP32 Receiver
  Locks onto the first valid player press until the reset button is pressed.
  Target: Arduino-ESP32 3.x
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

const uint8_t ESPNOW_CHANNEL = 6;
const uint32_t PACKET_MAGIC = 0x17001700;

const int WINNER_LED_PIN = 23;
const int BUZZER_PIN = 22;
const int RESET_BUTTON_PIN = 19;

struct BuzzerPacket {
  uint32_t magic;
  uint8_t playerId;
  bool pressed;
  uint32_t sequence;
};

portMUX_TYPE winnerMux = portMUX_INITIALIZER_UNLOCKED;
volatile uint8_t pendingWinnerId = 0;
volatile bool winnerPending = false;

bool roundLocked = false;
uint8_t winnerId = 0;

void onReceive(
  const esp_now_recv_info_t* info,
  const uint8_t* data,
  int length
) {
  if (length != sizeof(BuzzerPacket)) {
    return;
  }

  BuzzerPacket incoming;
  memcpy(&incoming, data, sizeof(incoming));

  if (incoming.magic != PACKET_MAGIC || !incoming.pressed) {
    return;
  }

  portENTER_CRITICAL(&winnerMux);
  if (!winnerPending) {
    pendingWinnerId = incoming.playerId;
    winnerPending = true;
  }
  portEXIT_CRITICAL(&winnerMux);
}

bool startEspNow() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  if (esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE) != ESP_OK) {
    return false;
  }

  if (esp_now_init() != ESP_OK) {
    return false;
  }

  return esp_now_register_recv_cb(onReceive) == ESP_OK;
}

void clearRound() {
  roundLocked = false;
  winnerId = 0;

  portENTER_CRITICAL(&winnerMux);
  pendingWinnerId = 0;
  winnerPending = false;
  portEXIT_CRITICAL(&winnerMux);

  digitalWrite(WINNER_LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  Serial.println("Round reset.");
}

void setup() {
  Serial.begin(115200);

  pinMode(WINNER_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RESET_BUTTON_PIN, INPUT_PULLUP);

  clearRound();

  if (!startEspNow()) {
    Serial.println("ESP-NOW setup failed.");
    while (true) {
      delay(1000);
    }
  }
}

void loop() {
  if (digitalRead(RESET_BUTTON_PIN) == LOW) {
    clearRound();

    while (digitalRead(RESET_BUTTON_PIN) == LOW) {
      delay(10);
    }
  }

  if (roundLocked) {
    delay(5);
    return;
  }

  uint8_t newWinner = 0;
  bool hasWinner = false;

  portENTER_CRITICAL(&winnerMux);
  if (winnerPending) {
    newWinner = pendingWinnerId;
    winnerPending = false;
    hasWinner = true;
  }
  portEXIT_CRITICAL(&winnerMux);

  if (hasWinner) {
    winnerId = newWinner;
    roundLocked = true;

    digitalWrite(WINNER_LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(250);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.print("Winner: Player ");
    Serial.println(winnerId);
  }

  delay(5);
}

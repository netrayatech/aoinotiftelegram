#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(2, 0);

char ssid[] = "DIV2 Customer";     // your network SSID (name)
char password[] = "s@tnusa8888"; // your network key
String welcomeMSG = "";
String from_name = "";
String chat_id = "-1001510224847";

// Initialize Telegram BOT
#define BOTtoken "5451965896:AAF7DODkfc54KUpEtAH9zwAZqGSV6YUh8o4" // your Bot Token (Get from Botfather)

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

int botRequestDelay = 500;
unsigned long lastTimeBotRan;

int L1Status = 0, L11Status = 0;
int L2Status = 0, L22Status = 0;
int L3Status = 0, L33Status = 0;
int L4Status = 0, L44Status = 0;
int L5Status = 0, L55Status = 0;

int pushBtn1 = D1; //Push Button 1
int pushBtn2 = D2; //Push Button 2
int pushBtn3 = D5; //Push Button 3
int pushBtn4 = D7; //Push Button 4
int pushBtn5 = D6; //Push Button 5

void handleButtonPressed()
{
  int readPushBtn1 = digitalRead(pushBtn1);

  delay(20);

  if (readPushBtn1 == HIGH) {
    Serial.println("Button Line#1 detected");
    welcomeMSG = "False NG High!!! On FACT 5 LINE #1.\nPlease check immediately.\n\n";
    welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #1.\n\n";
    welcomeMSG += "/L1OTW : OKE, saya akan handle issue LINE #1\n";
    welcomeMSG += "/L1SOLVE : Masalah LINE #1 sudah teratasi\n";
    bot.sendMessage(chat_id, welcomeMSG, "Markdown");
    mp3_play (6);
    delay(2500);
  }

  //--------------------------

  int readPushBtn2 = digitalRead(pushBtn2);

  delay(20);

  if (readPushBtn2 == HIGH) {
    Serial.println("Button Line#2 detected");
    welcomeMSG = "False NG High!!! On FACT 5 LINE #2.\nPlease check immediately.\n\n";
    welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #2.\n\n";
    welcomeMSG += "/L2OTW : OKE, saya akan handle issue LINE #2\n";
    welcomeMSG += "/L2SOLVE : Masalah LINE #2 sudah teratasi\n";
    bot.sendMessage(chat_id, welcomeMSG, "Markdown");
    mp3_play (6);
    delay(2500);
  }

  //--------------------------

  int readPushBtn3 = digitalRead(pushBtn3);

  delay(20);

  if (readPushBtn3 == HIGH) {
    Serial.println("Button Line#3 detected");
    welcomeMSG = "False NG High!!! On FACT 5 LINE #3.\nPlease check immediately.\n\n";
    welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #3.\n\n";
    welcomeMSG += "/L3OTW : OKE, saya akan handle issue LINE #3\n";
    welcomeMSG += "/L3SOLVE : Masalah LINE #3 sudah teratasi\n";
    bot.sendMessage(chat_id, welcomeMSG, "Markdown");
    mp3_play (6);
    delay(2500);
  }

  //--------------------------

  int readPushBtn4 = digitalRead(pushBtn4);

  delay(20);

  if (readPushBtn4 == HIGH) {
    Serial.println("Button Line#4 detected");
    welcomeMSG = "False NG High!!! On FACT 5 LINE #4.\nPlease check immediately.\n\n";
    welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #4.\n\n";
    welcomeMSG += "/L4OTW : OKE, saya akan handle issue LINE #4\n";
    welcomeMSG += "/L4SOLVE : Masalah LINE #4 sudah teratasi\n";
    bot.sendMessage(chat_id, welcomeMSG, "Markdown");
    mp3_play (6);
    delay(2500);
  }

  //--------------------------

  int readPushBtn5 = digitalRead(pushBtn5);

  delay(20);

  if (readPushBtn5 == HIGH) {
    Serial.println("Button Line#5 detected");
    welcomeMSG = "False NG High!!! On FACT 5 LINE #5.\nPlease check immediately.\n\n";
    welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #5.\n\n";
    welcomeMSG += "/L5OTW : OKE, saya akan handle issue LINE #5\n";
    welcomeMSG += "/L5SOLVE : Masalah LINE #5 sudah teratasi\n";
    bot.sendMessage(chat_id, welcomeMSG, "Markdown");
    mp3_play (6);
    delay(2500);
  }
}

void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i = 0; i < numNewMessages; i++) {
    chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    from_name = bot.messages[i].from_name;
    if (from_name == "") from_name = " Guest";

    if (text.indexOf("/L1OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 1", "");
      L1Status = 1;
      mp3_play (1);
      delay(2500);
    }

    if (text.indexOf("/L1SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 1", "");
      L11Status = 1;
      mp3_play (11);
      delay(2500);
    }

    if (text.indexOf("/L2OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 2", "");
      L2Status = 1;
      mp3_play (2);
      delay(2500);
    }

    if (text.indexOf("/L2SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 2", "");
      L22Status = 1;
      mp3_play (22);
      delay(2500);
    }

    if (text.indexOf("/L3OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 3", "");
      L3Status = 1;
      mp3_play (3);
      delay(2500);
    }

    if (text.indexOf("/L3SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 3", "");
      L33Status = 1;
      mp3_play (33);
      delay(2500);
    }

    if (text.indexOf("/L4OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 4", "");
      L4Status = 1;
      mp3_play (4);
      delay(2500);
    }

    if (text.indexOf("/L4SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 4", "");
      L44Status = 1;
      mp3_play (44);
      delay(2500);
    }

    if (text.indexOf("/L5OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 5", "");
      L5Status = 1;
      mp3_play (5);
      delay(2500);
    }

    if (text.indexOf("/L5SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 5", "");
      L55Status = 1;
      mp3_play (55);
      delay(2500);
    }
  }
}


void setup() {
  Serial.begin(115200);
  mySerial.begin (9600);
  mp3_set_serial (mySerial);
  delay(10);
  mp3_set_volume (30);

  client.setInsecure();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  String localIPAddr = WiFi.localIP().toString().c_str();

  pinMode(pushBtn1, INPUT); //Button Line#1
  pinMode(pushBtn2, INPUT); //Button Line#2
  pinMode(pushBtn3, INPUT); //Button Line#3
  pinMode(pushBtn4, INPUT); //Button Line#4
  pinMode(pushBtn5, INPUT); //Button Line#5

  String message = String("SMT AOI Monitoring System is UP AND RUNNING.\n") + String("IP addr : ") + String(localIPAddr);
  bot.sendMessage(chat_id, message, "");
}

void loop() {
  handleButtonPressed();

  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages) {
      Serial.println("got response from Telegram");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    lastTimeBotRan = millis();
  }
}

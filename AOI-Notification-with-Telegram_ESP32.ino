#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "DFRobotDFPlayerMini.h"

#define RXD2 4
#define TXD2 2
HardwareSerial mySoftwareSerial(1);
DFRobotDFPlayerMini myDFPlayer;

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

int L6Status = 0, L66Status = 0;
int L7Status = 0, L77Status = 0;
int L8Status = 0, L88Status = 0;
int L9Status = 0, L99Status = 0;
int L10Status = 0, L100Status = 0;
int L11Status = 0, L110Status = 0;
int L12Status = 0, L120Status = 0;
int L13Status = 0, L130Status = 0;

int pushBtnLine6 = 25; //LINE#6
int pushBtnLine7 = 27; //LINE#7
int pushBtnLine8 = 26; //LINE#8
int pushBtnLine9 = 18; //LINE#9
int pushBtnLine10 = 19; //LINE#10
int pushBtnLine11 = 23; //LINE#11
int pushBtnLine12 = 5;  //LINE#12
int pushBtnLine13 = 33; //LINE#13

int buttonState6, buttonState7, buttonState8, buttonState9, buttonState10, buttonState11, buttonState12, buttonState13;
int lastButtonState6 = LOW, lastButtonState7 = LOW, lastButtonState8 = LOW, lastButtonState9 = LOW, lastButtonState10 = LOW;
int lastButtonState11 = LOW, lastButtonState12 = LOW, lastButtonState13 = LOW;

unsigned long lastDebounceTime6 = 0, lastDebounceTime7 = 0, lastDebounceTime8 = 0, lastDebounceTime9 = 0, lastDebounceTime10 = 0;
unsigned long lastDebounceTime11 = 0, lastDebounceTime12 = 0, lastDebounceTime13 = 0;
unsigned long debounceDelay = 50;

void handleButtonPressed()
{
  int readDataPush6 = digitalRead(pushBtnLine6);

  if (readDataPush6 != lastButtonState6) {
    lastDebounceTime6 = millis();
  }

  if ((millis() - lastDebounceTime6) > debounceDelay) {
    if (readDataPush6 != buttonState6) {
      buttonState6 = readDataPush6;

      if (buttonState6 == HIGH) {
        Serial.println("Button Line#6 detected");
        welcomeMSG = "False NG High!!! On FACT 8 LINE #6.\nPlease check immediately.\n\n";
        welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #6.\n\n";
        welcomeMSG += "/L6OTW : OKE, saya akan handle issue LINE #6\n";
        welcomeMSG += "/L6SOLVE : Masalah LINE #6 sudah teratasi\n";
        bot.sendMessage(chat_id, welcomeMSG, "Markdown");
        myDFPlayer.play (6);
        delay(3000);
      }
    }
  }

  lastButtonState6 = readDataPush6;

  //--------------------------

  int readDataPush7 = digitalRead(pushBtnLine7);

  if (readDataPush7 != lastButtonState7) {
    lastDebounceTime7 = millis();
  }

  if ((millis() - lastDebounceTime7) > debounceDelay) {
    if (readDataPush7 != buttonState7) {
      buttonState7 = readDataPush7;

      if (buttonState7 == HIGH) {
        Serial.println("Button Line#7 detected");
        welcomeMSG = "False NG High!!! On FACT 8 LINE #7.\nPlease check immediately.\n\n";
        welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #7.\n\n";
        welcomeMSG += "/L7OTW : OKE, saya akan handle issue LINE #7\n";
        welcomeMSG += "/L7SOLVE : Masalah LINE #7 sudah teratasi\n";
        bot.sendMessage(chat_id, welcomeMSG, "Markdown");
        myDFPlayer.play (6);
        delay(3000);
      }
    }
  }

  lastButtonState7 = readDataPush7;

  //--------------------------

  int readDataPush8 = digitalRead(pushBtnLine8);

  if (readDataPush8 != lastButtonState8) {
    lastDebounceTime8 = millis();
  }

  if ((millis() - lastDebounceTime8) > debounceDelay) {
    if (readDataPush8 != buttonState8) {
      buttonState8 = readDataPush8;

      if (buttonState8 == HIGH) {
        Serial.println("Button Line#8 detected");
        welcomeMSG = "False NG High!!! On FACT 8 LINE #8.\nPlease check immediately.\n\n";
        welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #8.\n\n";
        welcomeMSG += "/L8OTW : OKE, saya akan handle issue LINE #8\n";
        welcomeMSG += "/L8SOLVE : Masalah LINE #8 sudah teratasi\n";
        bot.sendMessage(chat_id, welcomeMSG, "Markdown");
        myDFPlayer.play (6);
        delay(3000);
      }
    }
  }

  lastButtonState8 = readDataPush8;
  //--------------------------

  int readDataPush9 = digitalRead(pushBtnLine9);

  if (readDataPush9 != lastButtonState9) {
    lastDebounceTime9 = millis();
  }

  if ((millis() - lastDebounceTime9) > debounceDelay) {
    if (readDataPush9 != buttonState9) {
      buttonState9 = readDataPush9;

      if (buttonState9 == HIGH) {
        Serial.println("Button Line#9 detected");
        welcomeMSG = "False NG High!!! On FACT 8 LINE #9.\nPlease check immediately.\n\n";
        welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #9.\n\n";
        welcomeMSG += "/L9OTW : OKE, saya akan handle issue LINE #9\n";
        welcomeMSG += "/L9SOLVE : Masalah LINE #9 sudah teratasi\n";
        bot.sendMessage(chat_id, welcomeMSG, "Markdown");
        myDFPlayer.play (6);
        delay(3000);
      }
    }
  }

  lastButtonState9 = readDataPush9;
  //--------------------------

  int readDataPush10 = digitalRead(pushBtnLine10);

  if (readDataPush10 != lastButtonState10) {
    lastDebounceTime10 = millis();
  }

  if ((millis() - lastDebounceTime10) > debounceDelay) {
    if (readDataPush10 != buttonState10) {
      buttonState10 = readDataPush10;

      if (buttonState10 == HIGH) {
        Serial.println("Button Line#10 detected");
        welcomeMSG = "False NG High!!! On FACT 8 LINE #10.\nPlease check immediately.\n\n";
        welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #10.\n\n";
        welcomeMSG += "/L10OTW : OKE, saya akan handle issue LINE #10\n";
        welcomeMSG += "/L10SOLVE : Masalah LINE #10 sudah teratasi\n";
        bot.sendMessage(chat_id, welcomeMSG, "Markdown");
        myDFPlayer.play (6);
        delay(3000);
      }
    }
  }

  lastButtonState10 = readDataPush10;
  //--------------------------

  int readDataPush11 = digitalRead(pushBtnLine11);

  if (readDataPush11 != lastButtonState11) {
    lastDebounceTime11 = millis();
  }

  if ((millis() - lastDebounceTime11) > debounceDelay) {
    if (readDataPush11 != buttonState11) {
      buttonState11 = readDataPush11;

      if (buttonState11 == HIGH) {
        Serial.println("Button Line#11 detected");
        welcomeMSG = "False NG High!!! On FACT 8 LINE #11.\nPlease check immediately.\n\n";
        welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #11.\n\n";
        welcomeMSG += "/L11OTW : OKE, saya akan handle issue LINE #11\n";
        welcomeMSG += "/L11SOLVE : Masalah LINE #11 sudah teratasi\n";
        bot.sendMessage(chat_id, welcomeMSG, "Markdown");
        myDFPlayer.play (6);
        delay(3000);
      }
    }
  }

  lastButtonState11 = readDataPush11;
  //--------------------------

  int readDataPush12 = digitalRead(pushBtnLine12);

  if (readDataPush12 != lastButtonState12) {
    lastDebounceTime12 = millis();
  }

  if ((millis() - lastDebounceTime12) > debounceDelay) {
    if (readDataPush12 != buttonState12) {
      buttonState12 = readDataPush12;

      if (buttonState12 == HIGH) {
        Serial.println("Button Line#12 detected");
        welcomeMSG = "False NG High!!! On FACT 8 LINE #12.\nPlease check immediately.\n\n";
        welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #12.\n\n";
        welcomeMSG += "/L12OTW : OKE, saya akan handle issue LINE #12\n";
        welcomeMSG += "/L12SOLVE : Masalah LINE #12 sudah teratasi\n";
        bot.sendMessage(chat_id, welcomeMSG, "Markdown");
        myDFPlayer.play (6);
        delay(3000);
      }
    }
  }

  lastButtonState12 = readDataPush12;
  //--------------------------

  int readDataPush13 = digitalRead(pushBtnLine13);

  if (readDataPush13 != lastButtonState13) {
    lastDebounceTime13 = millis();
  }

  if ((millis() - lastDebounceTime13) > debounceDelay) {
    if (readDataPush13 != buttonState13) {
      buttonState13 = readDataPush13;

      if (buttonState13 == HIGH) {
        Serial.println("Button Line#13 detected");
        welcomeMSG = "False NG High!!! On FACT 8 LINE #13.\nPlease check immediately.\n\n";
        welcomeMSG += "Silakan pencet opsi dibawah jika sudah menuju LINE #13.\n\n";
        welcomeMSG += "/L13OTW : OKE, saya akan handle issue LINE #13\n";
        welcomeMSG += "/L13SOLVE : Masalah LINE #13 sudah teratasi\n";
        bot.sendMessage(chat_id, welcomeMSG, "Markdown");
        myDFPlayer.play (6);
        delay(3000);
      }
    }
  }

  lastButtonState13 = readDataPush13;
}

void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i = 0; i < numNewMessages; i++) {
    chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    from_name = bot.messages[i].from_name;
    if (from_name == "") from_name = " Guest";

    if (text.indexOf("/L6OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 6", "");
      L6Status = 1;
      myDFPlayer.play (1);
      delay(3000);
    }

    if (text.indexOf("/L6SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 6", "");
      L66Status = 1;
      myDFPlayer.play (11);
      delay(3000);
    }

    if (text.indexOf("/L7OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 7", "");
      L7Status = 1;
      myDFPlayer.play (2);
      delay(3000);
    }

    if (text.indexOf("/L7SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 7", "");
      L77Status = 1;
      myDFPlayer.play (22);
      delay(3000);
    }

    if (text.indexOf("/L8OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 8", "");
      L8Status = 1;
      myDFPlayer.play (3);
      delay(3000);
    }

    if (text.indexOf("/L8SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 8", "");
      L88Status = 1;
      myDFPlayer.play (33);
      delay(3000);
    }

    if (text.indexOf("/L9OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 9", "");
      L9Status = 1;
      myDFPlayer.play (4);
      delay(3000);
    }

    if (text.indexOf("/L9SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 9", "");
      L99Status = 1;
      myDFPlayer.play (44);
      delay(3000);
    }

    if (text.indexOf("/L10OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 10", "");
      L10Status = 1;
      myDFPlayer.play (5);
      delay(3000);
    }

    if (text.indexOf("/L10SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 10", "");
      L100Status = 1;
      myDFPlayer.play (55);
      delay(3000);
    }

    if (text.indexOf("/L11OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 11", "");
      L11Status = 1;
      myDFPlayer.play (5);
      delay(3000);
    }

    if (text.indexOf("/L11SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 11", "");
      L110Status = 1;
      myDFPlayer.play (55);
      delay(3000);
    }

    if (text.indexOf("/L12OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 12", "");
      L12Status = 1;
      myDFPlayer.play (5);
      delay(3000);
    }

    if (text.indexOf("/L12SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 12", "");
      L120Status = 1;
      myDFPlayer.play (55);
      delay(3000);
    }

    if (text.indexOf("/L13OTW") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sedang menuju LINE 13", "");
      L13Status = 1;
      myDFPlayer.play (5);
      delay(3000);
    }

    if (text.indexOf("/L13SOLVE") != -1) {
      bot.sendMessage(chat_id, "Teknisi " + from_name + " sudah berhasil mengatasi masalah LINE 13", "");
      L130Status = 1;
      myDFPlayer.play (55);
      delay(3000);
    }
  }
}


void setup() {
  mySoftwareSerial.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.begin(115200);
  myDFPlayer.begin(mySoftwareSerial);

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

  pinMode(pushBtnLine6, INPUT); //Button Line#6
  pinMode(pushBtnLine7, INPUT); //Button Line#7
  pinMode(pushBtnLine8, INPUT); //Button Line#8
  pinMode(pushBtnLine9, INPUT); //Button Line#9
  pinMode(pushBtnLine10, INPUT); //Button Line#10
  pinMode(pushBtnLine11, INPUT); //Button Line#11
  pinMode(pushBtnLine12, INPUT); //Button Line#12
  pinMode(pushBtnLine13, INPUT); //Button Line#13  

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

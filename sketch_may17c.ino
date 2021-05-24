#include "Bridge.h"
#include "YunServer.h"
#include "YunClient.h"
#include "SPI.h"

YunServer server;

void setup() {
  // Bridge startup
  pinMode(13,OUTPUT);
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
}

void loop() {
  YunClient client = server.accept();
  if (client) {
    process(client);
    client.stop();
  }
  delay(50);
}

void process(YunClient client) {
  String command = client.readStringUntil('/');
  if (command == "message") {
    messageCommand(client);
  }
}

void messageCommand(YunClient client) {
  String message = client.readStringUntil('/');
  client.print(F("Message"));
  client.print(F(" set to "));
  client.println(message);
  String key = "Message";
  Bridge.put(key, message);
  Serial.print(message);
  if(message == "start\r\n") {
    choregraphie();
  }
}

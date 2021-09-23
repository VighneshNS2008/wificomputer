/**
   This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
*/
#include <BleKeyboard.h>
BleKeyboard bleKeyboard;
#include <WebServer.h>

#define username "vighnesh"
#define password "vighnesh"

WebServer server;

String webpage = "<html><head><title>ESP32 WiFi</title></head><body style=\"background-color:rgba(110, 94, 179, 0.616)\"><center><h1> IoT Computer control </h1></center><br><form><center><button style=\"font-size:25\" type=\"submit\" value=\"KEY_LEFT_CTRL\" name=\"ButtonToBePressedNow\"> Ctrl </button><button style=\"font-size:25\" type=\"submit\" value=\"KEY_LEFT_SHIFT\" name=\"ButtonToBePressedNow\"> Shift </button><button style=\"font-size:25\" type=\"submit\" value=\"KEY_LEFT_ALT\" name=\"ButtonToBePressedNow\"> Alt </button><br><br><button style=\"font-size:25\" type=\"submit\" value=\"KEY_LEFT_GUI\" name=\"ButtonToBePressedNow\"> Windows </button><br><br><button style=\"font-size:25\" type=\"submit\" value=\"KEY_UP_ARROW\" name=\"ButtonToBePressedNow\"> Up </button><br><button style=\"font-size:25\" type=\"submit\" value=\"KEY_LEFT_ARROW\" name=\"ButtonToBePressedNow\"> Left </button><button style=\"font-size:25\" type=\"submit\" value=\"KEY_RIGHT_ARROW\" name=\"ButtonToBePressedNow\"> Right </button><br><button style=\"font-size:25\" type=\"submit\" value=\"KEY_DOWN_ARROW\" name=\"ButtonToBePressedNow\"> Down </button><br><br><button style=\"font-size:25\" type=\"submit\" value=\"KEY_RETURN\" name=\"ButtonToBePressedNow\"> Enter </button><button style=\"font-size:25\" type=\"submit\" value=\"KEY_ESC\" name=\"ButtonToBePressedNow\"> Escape </button><button style=\"font-size:25\" type=\"submit\" value=\"KEY_DELETE\" name=\"ButtonToBePressedNow\"> Delete </button><br><br><br><br><button style=\"font-size:25\" type=\"submit\" value=\"Script1\" name=\"ButtonToBePressedNow\"> Script 1 </button><br><br><br><br> <form action=\"/get\">  Text: <input type=\"text\" name=\"Text\">  <input type=\"submit\" value=\"Send\"></form><br></center></form></body></html>";
void setup()
{
  Serial.begin(115200);
  pinMode(16, OUTPUT);
  WiFi.softAP(username, password);
  Serial.println(WiFi.softAPIP());
  server.begin();
  server.on("/led", Led);
  bleKeyboard.begin();
}

void loop()
{
  server.handleClient();
}

void Led()
{
  server.send(200, "text/html", webpage);
  
  if (bleKeyboard.isConnected()) {
    
    if (server.arg("ButtonToBePressedNow") == "Script1")
    {
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press(KEY_F4);
      delay(50);
      bleKeyboard.releaseAll();
      bleKeyboard.press(KEY_RETURN);
      delay(50);
      bleKeyboard.releaseAll();
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press(KEY_F4);
      delay(50);
      bleKeyboard.releaseAll();
      bleKeyboard.press(KEY_RETURN);
      delay(50);
      bleKeyboard.releaseAll();
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press(KEY_F4);
      delay(50);
      bleKeyboard.releaseAll();
      bleKeyboard.press(KEY_RETURN);
      delay(50);
      bleKeyboard.releaseAll();
    }
    
    bleKeyboard.print(server.arg("Text"));
    
    if (server.arg("ButtonToBePressedNow") == "KEY_LEFT_CTRL")
    {
      bleKeyboard.press(KEY_LEFT_CTRL);
      delay(50);
      bleKeyboard.releaseAll();
    }
    if (server.arg("ButtonToBePressedNow") == "KEY_LEFT_ALT")
    {
      bleKeyboard.press(KEY_LEFT_ALT);
      delay(50);
      bleKeyboard.releaseAll();
    } if (server.arg("ButtonToBePressedNow") == "KEY_LEFT_GUI")
    {
      bleKeyboard.press(KEY_LEFT_GUI);
      delay(50);
      bleKeyboard.releaseAll();
    }
    if (server.arg("ButtonToBePressedNow") == "KEY_UP_ARROW")
    {
      bleKeyboard.press(KEY_UP_ARROW);
      delay(50);
      bleKeyboard.releaseAll();
    }
    if (server.arg("ButtonToBePressedNow") == "KEY_DOWN_ARROW")
    {
      bleKeyboard.press(KEY_DOWN_ARROW);
      delay(50);
      bleKeyboard.releaseAll();
    }
    if (server.arg("ButtonToBePressedNow") == "KEY_LEFT_ARROW")
    {
      bleKeyboard.press(KEY_LEFT_ARROW);
      delay(50);
      bleKeyboard.releaseAll();
    }
    if (server.arg("ButtonToBePressedNow") == "KEY_RIGHT_ARROW")
    {
      bleKeyboard.press(KEY_RIGHT_ARROW);
      delay(50);
      bleKeyboard.releaseAll();
    }
    if (server.arg("ButtonToBePressedNow") == "KEY_RETURN")
    {
      bleKeyboard.press(KEY_RETURN);
      delay(50);
      bleKeyboard.releaseAll();
    }
    if (server.arg("ButtonToBePressedNow") == "KEY_ESC")
    {
      bleKeyboard.press(KEY_ESC);
      delay(50);
      bleKeyboard.releaseAll();
    }
    if (server.arg("ButtonToBePressedNow") == "KEY_DELETE")
    {
      bleKeyboard.press(KEY_DELETE);
      delay(50);
      bleKeyboard.releaseAll();
    }
  }
}

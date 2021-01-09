#include <ESP8266WiFi.h>
#define SW D2                   //กำหนดรับ input จาก Switch ที่ Pin D2
const char* ssid = "stk";               //กำหนด SSID (อย่าลืมเปลี่ยนเป็นของตัวเอง)
const char* password = "stk123456";     //กำหนด password (อย่าลืมเปลี่ยนเป็นของตัวเอง)
WiFiServer server(80);              //กำหนดใช้งาน TCP Server ที่ Port 80
void setup() {
  Serial.begin(115200);
  pinMode(SW,INPUT);                //กำหนดให้ pin D2 เป็น input
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);           // เชื่อมต่อกับ AP
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();                   //เริ่มใช้งาน TCP Server
  Serial.println("Server started");
  Serial.println(WiFi.localIP());           //แสดง IP
}
 
void loop() {
  WiFiClient client = server.available();       //รอรับ การเชื่อมต่อจาก Client
  if (!client) {                //ถ้าไม่มี Client เข้ามาให้เริ่มกับไปวน loop รอรับใหม่
    return;
  }
   
  Serial.println("new client");
  while(!client.available())
  {
    delay(1);
  }
  String req = client.readStringUntil('\r');        //อ่านค่าที่ได้รับจากclient จากข้อมูลแรกถึง ‘\r’
  Serial.println(req);
  client.flush();
 
// เก็บ HTML Code ลงในตัวแปร String web
  String web = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  web += "<html>\r\n";
  web += "<body>\r\n";
  web += "<head>Read Switch\r\n";
  web += "<style>\r\n";
  web += ".circle-gray,.circle-yellow\r\n";
  web += "{width: 100px;\r\n";
  web += "height: 100px;\r\n";
  web += "border-radius: 50%;}\r\n";
  web += ".circle-gray\r\n";
  web += "{background-color: gray}\r\n";
  web += ".circle-yellow\r\n";
  web += "{background-color: yellow}\r\n";
  web += "</style>\r\n";  
  web += "</head>\r\n";
  web += "<meta http-equiv=\"refresh\" content=\"1\">";
  web += "<p>\r\n";
  unsigned char sw_input = digitalRead(SW);     //อ่านค่าจาก Switch  
}
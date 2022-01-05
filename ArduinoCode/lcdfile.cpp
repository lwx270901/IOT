#include "lcdfile.h"
static LiquidCrystal_I2C lcd(0x27, 16, 2);
const int DHTPIN = 8;       //Đọc dữ liệu từ DHT11 ở chân 2 trên mạch Arduino
const int DHTTYPE = DHT11;  //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
DHT dht(DHTPIN, DHTTYPE);
void init_lcd()
{
  lcd.init();
  lcd.backlight();
  dht.begin();
}


void display_dht()
{
  float h = dht.readHumidity();    //Đọc độ ẩm
  float t = dht.readTemperature(); //Đọc nhiệt độ
  lcd.begin(16, 2);
  lcd.print("Nhiet do: ");
  lcd.print(t);
  lcd.setCursor(0, 1);
  // In ra dong chu
  lcd.print("Do am:   :");
  lcd.print(h);
  String temp = String(t);
  String humi = String(h);
  Serial.println("!TEMP:"+temp+"##sgrgre!HUMI:"+humi+"##");//for Adafruit
  //Serial.println(temp+"x"+humi);//for thingspeak
}

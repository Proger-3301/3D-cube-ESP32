#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include "vector3.h"
 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BUTTON_1 16
#define BUTTON_2 17

#define SSD1306_I2C_ADDRESS 0x3C
 
Adafruit_SSD1306 dpl(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

vec3 vertices[] = {
  {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0},
  {0, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 1, 1}
};

int triangles[] = {
  0, 1, 2, 0, 2, 3, 1, 6, 5, 1, 6, 2, 
  3, 6, 7, 3, 6, 2, 4, 1, 5, 4, 1, 0, 
  5, 7, 6, 5, 4, 7, 4, 3, 0, 4, 3, 7
};

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  if(!dpl.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  dpl.display();
  delay(2000);
  drawCube();
}

float t = 0.0, k = 0.0;

vec3 transf(vec3 a){
  a = sub(a, {0.5, 0.5, 0.5});
  a = rotateXZ(a, t);
  a = rotateYZ(a, k);
  a.x *= 70;
  a.y *= 70;
  a.z += 2;
  return a;
}
void drawText(){
  dpl.setTextSize(1);
  dpl.setTextColor(SSD1306_WHITE);
  dpl.setCursor(0, 0);
  dpl.println(F("3D cube npuMep"));
}

void drawCube(){
  dpl.setCursor(0, 0);
  for(int i = 0; i < 12 * 3 - 3; i+=3){
    vec3 a = vertices[triangles[i]];
    vec3 b = vertices[triangles[i + 1]];
    vec3 c = vertices[triangles[i + 2]];
    a = transf(a);
    b = transf(b);
    c = transf(c);
    dpl.drawTriangle(a.x / a.z + SCREEN_WIDTH / 2, a.y / a.z + SCREEN_HEIGHT / 2, 
    b.x / b.z + SCREEN_WIDTH / 2, b.y / b.z + SCREEN_HEIGHT / 2, 
    c.x / c.z + SCREEN_WIDTH / 2, c.y / c.z + SCREEN_HEIGHT / 2, WHITE);
  }
}

void loop() {
  if(!digitalRead(BUTTON_1)) t += 0.08;
  if(!digitalRead(BUTTON_2)) k += 0.08;
  dpl.clearDisplay();
  drawText();
  drawCube();
  dpl.display();
  delay(50);
}
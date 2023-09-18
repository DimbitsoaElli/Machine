#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const byte ROWS = 4; // Nombre de rangées du clavier
const byte COLS = 3; // Nombre de colonnes du clavier

char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'Y','0','n'}
};

byte rowPins[ROWS] = {43, 41, 39, 37}; // Broches de rangée connectées au clavier
byte colPins[COLS] = {35, 33, 31}; // Broches de colonne connectées au clavier

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); // Crée un objet Keypad
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
lcd.init(); // initialize the lcd
lcd.init();
// Print a message to the LCD.
lcd.backlight();
Serial.begin(9600); // Initialise la communication série avec une vitesse de 9600 bauds
}

int huile; // Déclare la variable huile en dehors de la boucle while

void loop() {
char key = keypad.getKey();

if (key == 'Y') {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Huile et Cl: ");
String valeur = "";


while (true) {
char key = keypad.getKey();

if (key) {
if (key == 'Y') {
break;
} else {
valeur += key;
lcd.print(key);
huile = valeur.toInt(); // Utilise la variable huile déclarée en dehors de la boucle
}
}
}

}

if (key) {
lcd.print(key);
}

float soude =0.35* huile * 1.4;
float eau = huile * 0.3;
lcd.setCursor(0,0);
lcd.print("Soude : " + String(soude)+"Gr");
lcd.setCursor(0, 1);
lcd.print("Eau : " + String(eau)+"cl");
float somme=eau+soude+huile;
Serial.println("la somme de solution est"+String(somme));
}

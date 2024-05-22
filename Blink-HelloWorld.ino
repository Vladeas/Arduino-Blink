/*
  Blink - BuiltIn LED

  Hello World - connection test

  Vlad Danciu
*/

String Hello = "Hello World";
const int unit = 300 ;
const int dot = unit;
const int dash = unit * 3;
const int newLetter = unit * 3;
const int newWord = unit * 7;

void blink(int value);
String translateMorse(char c);



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Start:\n");
}

void loop() {
  if (Serial.available() > 0) {
    Hello.toUpperCase();
    for (int i = 0; i < Hello.length(); i++) {
      char c = Hello.charAt(i);
      if (c == ' ') {
        Serial.println("\n");
        delay(newWord); // Space between words
      } else {
        String m = translateMorse(c);
        String out = String(c) + " " + String(m);
        Serial.println(out);
        for (int j = 0; j < m.length(); j++) {
          if (m.charAt(j) == '.') {
            blink(dot);
          } else if (m.charAt(j) == '-') {
            blink(dash);
          }
          delay(unit); // Space between parts of the same letter
        }
        delay(newLetter); // Space between letters
      }
    }
  }
}

String translateMorse(char c) {
  const String morseCode[36] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",  // A,B,C,D,E,F,G,H,I,J,K,L,M
    "-.", "---", ".--.", "--.-", ".-.", "...", "-","..-", "...-", ".--", "-..-", "-.--", "--..",  // N,O,P,Q,R,S,T,U,V,W,X,Y,Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0-9
  };

  if (c >= 'A' && c <= 'Z') {
    return morseCode[c - 'A'];
  } else if (c >= '0' && c <= '9') {
    return morseCode[c - '0' + 26];
  } else {
    return "";
  }
}

void blink(int value){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(value);
  digitalWrite(LED_BUILTIN, LOW);
  delay(unit);
}


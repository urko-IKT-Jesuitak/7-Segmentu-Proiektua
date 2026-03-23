int e = 2;
int d = 3;
int c = 4;
int b = 5;
int a = 6;
int f = 7;
int g = 8;


void setup() {
  Serial.begin(9600);

pinMode(e, OUTPUT);
pinMode(d, OUTPUT);
pinMode(c, OUTPUT);
pinMode(b, OUTPUT);
pinMode(a, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
 

  Serial.println("Konfigurazioa eginda!!");
  Serial.println("Sartu zenbaki bat (0-9):");
}

void loop() {

  if (Serial.available() > 0) {

    String sarrera = Serial.readStringUntil('\n');  
    int z = sarrera.toInt();

    Serial.print("Jasotako zenbakia: ");
    Serial.println(z);

    zenbakia_idatzi(z);
  }
}


void zenbakia_idatzi(int z){

  // Lehenengo eta behin guztia amatatu
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);

  if (z == 0) // 0 : pin guztiak HIGH(1), g izan ezik LOW(0)
  {
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }

  if (z == 1) // 1 : B,C HIGH(1), besteak LOW(0)
  {
    digitalWrite(a,0);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
  }

  if (z == 2) // 2 : C,F LOW(0), besteak HIGH(1)
  {
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,0);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,0);
    digitalWrite(g,1);
  }

  if (z == 3) // 3 : E,F LOW(0), besteak HIGH(1)
  {
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,1);
  }

  if (z == 4) // 4 : A,D,E LOW(0), B,C,F,G HIGH(1)
  {
    digitalWrite(a,0);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,1);
    digitalWrite(g,1);
  }

  if (z == 5) // 5 : B,E LOW(0), besteak HIGH(1)
  {
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,0);
    digitalWrite(f,1);
    digitalWrite(g,1);
  }

  if (z == 6) // 6 : B LOW(0), besteak HIGH(1)
  {
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
  }

  if (z == 7) // 7 : D,E,F,G LOW(0), A,B,C HIGH(1)
  {
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
  }

  if (z == 8) // 8 : segmentu guztiak HIGH(1)
  {
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
  }

  if (z == 9) // 9 : E LOW(0), besteak HIGH(1)
  {
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,0);
    digitalWrite(f,1);
    digitalWrite(g,1);
  }
}


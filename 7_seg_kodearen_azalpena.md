
```markdown
# 💻 Softwarearen Bihotza: 7-Segmentuak Serial Bidez Kontrolatzen

## 🗺️ 0. Urratsa: 7-Segmentuko Pantailaren "Anatomia"

Kodean eta ingranaje birtualetan murgildu baino lehen, ezinbestekoa da pantailaren "mapa" ulertzea. Zergatik erabiltzen ditugu `a, b, c, d, e, f, g` letrak? Hau ez da ausazkoa, elektronikaren munduan erabiltzen den estandar unibertsala baizik!

Pantailako LED bakoitza (edo segmentua) letra bati esleituta dago. Goitik hasita eta erlojuaren orratzen norabidean jarraituz, erdikoa azkenerako utziz, hau da antolaketa:



* **a**: Goiko segmentua.
* **b**: Goiko-eskuineko segmentua.
* **c**: Beheko-eskuineko segmentua.
* **d**: Beheko segmentua.
* **e**: Beheko-ezkerreko segmentua.
* **f**: Goiko-ezkerreko segmentua.
* **g**: Erdiko segmentua.

*(Oharra: Askotan **dp** edo "decimal point" izeneko zortzigarren LED bat ere egoten da, behe-eskuinaldeko puntua pizteko).*

Orain mapa argi dugula, askoz errazagoa izango da ulertzea zergatik piztu behar ditugun letra batzuk edo besteak zenbakiak sortzeko. Goazen kodera!

---

## 1. Aldagaiak eta Pin-en Mapatzea

Lehenengo urratsa Arduinori esatea da pantailaren zein atal (segmentu) zein pin-etara konektatu dugun.

```cpp
// Segmentu bakoitzari bere Arduinoko pin-a esleitzen diogu
int e = 2;
int d = 3;
int c = 4;
int b = 5;
int a = 6;
int f = 7;
int g = 8;
```
**Zergatik horrela?** Aldagaiak `a`-tik `g`-ra izendatzeak kodea irakurtzea askoz errazagoa egiten du. Geroago `digitalWrite(a, 1)` idazten badugu, badakigu goiko marra pizten ari garela, pin zenbakia gogoratu beharrik gabe.

## 2. `setup()` Funtzioa: Hasierako Konfigurazioa

`setup()` funtzioa behin bakarrik exekutatzen da Arduinoa piztean. Hemen bi gauza garrantzitsu prestatzen ditugu:

```cpp
void setup() {
  // 1. Komunikazioa hasi
  Serial.begin(9600);

  // 2. Pinak irteera (OUTPUT) gisa ezarri
  pinMode(e, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  // 3. Erabiltzaileari argibideak eman
  Serial.println("Konfigurazioa eginda!!");
  Serial.println("Sartu zenbaki bat (0-9):");
}
```
* **`Serial.begin(9600);`**: Funtsezkoa da. Ordenagailuaren eta Arduinoren arteko bide bat irekitzen du `9600 baud`-eko abiaduran. Horri esker bidaliko ditugu zenbakiak teklatutik.
* **`OUTPUT`**: Arduinori esaten diogu pin horietatik energia *aterako* dela LED-ak pizteko (ez dugula informaziorik jasoko bertatik).

## 3. `loop()` Funtzioa: Garunaren Funtzionamendu Jarraitua

Hau da etengabe biraka dabilen zatia, ordenagailutik aginduak jasotzeko zain.

```cpp
void loop() {
  // Ba al dago datu berririk Serieko Monitoreko sarreran?
  if (Serial.available() > 0) {
    
    // Testu osoa irakurri 'Enter' sakatu arte (\n)
    String sarrera = Serial.readStringUntil('\n');  
    
    // String (testua) Int (zenbaki osoa) bihurtu
    int z = sarrera.toInt();

    // Debugging: Zer jaso dugun inprimatu pantailan
    Serial.print("Jasotako zenbakia: ");
    Serial.println(z);

    // Funtzio nagusiari deitu pantaila eguneratzeko
    zenbakia_idatzi(z);
  }
}
```
**Softwarearen Gakoa:** Arduinora zenbaki bat bidaltzen dugunean (adibidez, "5"), ez da zenbaki matematiko gisa iristen, testu-karaktere (String) gisa baizik. Ezinbestekoa da `toInt()` funtzioa erabiltzea testu hori gure baldintzetan (IF) erabil dezakegun aldagai matematiko (`int`) bihurtzeko.

## 4. `zenbakia_idatzi(int z)`: Logika Birtuala Fisiko Bihurtzen

Hemen dago "magia". Funtzio honek zenbaki bat jasotzen du eta badaki zein segmentu piztu behar dituen hura irudikatzeko.

```cpp
void zenbakia_idatzi(int z){

  // 1. Urratsa: Garbiketarako errutina (Dena itzali)
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);

  // 2. Urratsa: Zenbakiaren araberako IF baldintzak
  if (z == 0) // 0: 'g' (erdikoa) izan ezik, denak HIGH (1)
  {
    digitalWrite(a,1); digitalWrite(b,1); digitalWrite(c,1);
    digitalWrite(d,1); digitalWrite(e,1); digitalWrite(f,1);
    digitalWrite(g,0);
  }

  if (z == 1) // 1: Eskuineko biak ('b' eta 'c') bakarrik HIGH (1)
  {
    digitalWrite(a,0); digitalWrite(b,1); digitalWrite(c,1);
    digitalWrite(d,0); digitalWrite(e,0); digitalWrite(f,0);
    digitalWrite(g,0);
  }
  
  // ... (Gainerako IF blokeak hemen doaz, 9-ra arte) ...
}
```

### Zergatik garbitu lehenengo?
Pentsa ezazu '8' zenbakia erakusten ari garela (LED guztiak piztuta). Gero '1' idazten badugu, eta ez baditugu lehenik denak itzaltzen, '8'-ko argiak piztuta geratuko lirateke pantailan akats bat sortuz. `0` edo `LOW` idaztean, mihisea garbitzen dugu zenbaki berria margotu aurretik.

*Oharra: Kode honek suposatzen du **Katodo Komuneko** pantaila bat darabilgula (non `1` edo `HIGH` aginduak LED-a pizten duen).*

---

## 🚀 Pro-Tips: Nola hobetu dezakegu kode hau? (Erronka aurreratuak)

Ikasle ausartenentzat, hona hemen kodea profesionalagoa egiteko bideak:

1.  **Sarreraren Balidazioa (Error Handling):** Zer gertatzen da erabiltzaileak letra bat sartzen badu zenbaki baten ordez? Kodean IF txiki bat gehi dezakegu hori saihesteko:
    ```cpp
    if (z < 0 || z > 9) {
      Serial.println("Errorea: Mesedez, sartu 0 eta 9 arteko zenbaki bat.");
      return; // Funtziotik irten ezer egin gabe
    }
    ```
2.  **`switch-case` egitura:** IF pila bat jarri beharrean, `switch (z)` erabiltzeak kodea askoz garbiagoa eta irakurgarriagoa egingo luke.
3.  **Array-ak eta Bitarrak (Maila Pro):** IF guztiak ezabatu ditzakegu, onartutako egoera guztiak `byte` motako Array batean gordez (adib. `byte digits[10] = {0b00111111, 0b00000110...}`). Hau litzateke industriako estandarra!

```

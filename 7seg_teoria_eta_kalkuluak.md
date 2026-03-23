# ⚙️ Teoria Teknikoa eta Historia

## 1. Zazpi Segmentuen Garrantzia Elektronikaren Historian

7-segmentuko pantaila ez da soilik LED multzo bat; elektronikaren historian **izen berezi bat** du. Zergatik?

1.  **Zenbakizko Interfazearen Democratizazioa**: 7-segmentuak agertu aurretik (1960ko eta 1970eko hamarkadetan), zenbakiak erakustea zaila eta garestia zen (adibidez, Nixie hodiak, argi handiak eta konplexuak zirenak). 7-segmentua irtenbide merkea, txikia eta fidagarria izan zen.
2.  **Kalkulagailuaren Iraultza**: Lehen kalkulagailu elektroniko eramangarriek (HP-35, adibidez) 7-segmentuko pantailak erabili zituzten. Horri esker, jendeak kalkulu konplexuak poltsikoan eraman ahal izan zituen.
3.  **Hizkuntza Unibertsala**: 10 zenbakiak (0-9) erakusteko modu estandarra bihurtu zen. Mundu osoko jendeak ulertzen zuen, eta horrek automatizazioaren eta kontsumo-elektronikaren hedapena erraztu zuen.
4.  **Diseinuaren Efizientzia**: Segmentu gutxi batzuekin informazio erabakigarria erakusteko gaitasunak (adibidez, ordua erloju digital batean edo tenperatura termometro batean) diseinu minimalistaren eta efizientearen adibide bikaina da.

Zazpi segmentuko pantailak **aro digitalaren oinarria** ezarri zuen, interfaze gizatiarragoak eta eskuragarriagoak sortuz.

## 2. Teoria eta Funtzionamendua

7-segmentuko pantaila bat **7 LED banatuk** osatzen dute, bakoitzak barra forma duena. Horrez gain, askotan puntu hamartarra (DP) erakusten duen zortzigarren LED bat izaten dute.

Segmentuak **a, b, c, d, e, f, g** letrekin identifikatzen dira, eta antolaketa estandarra dute.

### Mota desberdinak:
1.  **Katodo Komuna**: LED guztien katodoak (alderdi negatiboak) barnean lotuta daude eta **GND**-ra (lurra) konektatzen dira. Segmentu bat pizteko, 5V (HIGH) eman behar zaio bere pin-ari.
2.  **Anodo Komuna**: LED guztien anodoak (alderdi positiboak) barnean lotuta daude eta **5V**-ra konektatzen dira. Segmentu bat pizteko, GND (LOW) eman behar zaio bere pin-ari.

Gure proiektuan, **Katodo Komuneko** pantaila bat erabiltzen dugu.

## 3. Erresistentzien Kalkulua (Ohm-en Legea)

## Zergatik erabili behar ditugu erresistentziak?
LED bakoitzak korronte kopuru mugatu bat onartzen du. Erresistentziarik gabe:
1.  LEDa erre daiteke.
2.  Arduinoko pin-a kaltetu daiteke gehiegizko intentsitateagatik.

Erresistentziak **korronte-mugatzaile** gisa funtzionatzen du, soberan dagoen tentsioa "jan" egiten baitu.

## Kalkulua (Ohm-en Legea)
Kalkulua egiteko formula hau erabiltzen dugu:
$$R = \frac{V_{cc} - V_f}{I}$$

Non:
* **$V_{cc}$**: Arduinoko tentsioa (5V).
* **$V_f$**: LEDaren tentsio-erorketa (normalean 2V inguru LED gorrietan).
* **$I$**: LEDak behar duen intentsitatea (20mA edo 0.02A, adibidez).

**Adibidea:**
$$R = \frac{5V - 2V}{0.02A} = \frac{3V}{0.02A} = 150\ \Omega$$
Guk segurtasunagatik **220Ω edo 330Ω**-koak erabiltzen ditugu, argitasun ona mantenduz baina osagaiak babestuz. Gure Mega-n 220Ω-koak erabili ditugu.


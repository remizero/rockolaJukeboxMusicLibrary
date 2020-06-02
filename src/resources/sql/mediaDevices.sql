CREATE TABLE `mediaDevices` (
  `id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
  `device`	TEXT NOT NULL,
  `mediaType`	INTEGER NOT NULL,
  `descriptionEN`	TEXT NOT NULL,
  `descriptionES`	TEXT NOT NULL
);

INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "A", 1, "Analogue transfer from media", "Transferencia analógica desde medios" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "WAC", 2, "Wax cylinder", "Cilindro de cera" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "8CA", 2, "8-track tape cassette", "Casete de cinta de 8 pistas" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "A", 3, "Analogue transfer from media", "Transferencia analógica desde medios" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "DD", 3, "DDD", "DDD" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "AD", 3, "ADD", "ADD" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "AA", 3, "AAD", "AAD" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "33", 5, "33.33 rpm", "33.33 rpm" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "45", 5, "45 rpm", "45 rpm" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "71", 5, "71.29 rpm", "71.29 rpm" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "76", 5, "76.59 rpm", "76.59 rpm" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "78", 5, "78.26 rpm", "78.26 rpm" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "80", 5, "80 rpm", "80 rpm" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "A", 6, "Analogue transfer from media", "Transferencia analógica desde medios" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "A", 7, "Analogue transfer from media", "Transferencia analógica desde medios" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "1", 7, "Standard, 48 kHz/16 bits, linear", "Estándar, 48 kHz/16 bits, lineal" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "2", 7, "Mode 2, 32 kHz/16 bits, linear", "Modo 2, 32 kHz/16 bits, lineal" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "3", 7, "Mode 3, 32 kHz/12 bits, non-linear, low speed", "Modo 3, 32 kHz/12 bits, no-lineal, baja velocidad" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "4", 7, "Mode 4, 32 kHz/12 bits, 4 channels", "Modo 4, 32 kHz/12 bits, 4 canales" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "5", 7, "Mode 5, 44.1 kHz/16 bits, linear", "Modo 5, 44.1 kHz/16 bits, lineal" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "6", 7, "Mode 6, 44.1 kHz/16 bits, 'wide track' play", "Modo 6, 44.1 kHz/16 bits, Reproducción de 'pista ancha'" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "A", 8, "Analogue transfer from media", "Transferencia analógica desde medios" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "A", 9, "Analogue transfer from media", "Transferencia analógica desde medios" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "PAL", 10, "PAL", "PAL" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "NTSC", 10, "NTSC", "NTSC" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "SECAM", 10, "SECAM", "SECAM" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "PAL", 11, "PAL", "PAL" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "NTSC", 11, "NTSC", "NTSC" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "SECAM", 11, "SECAM", "SECAM" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "VHS", 11, "VHS", "VHS" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "SVHS", 11, "SVHS", "S-VHS" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "BETA", 11, "BETAMAX", "BETAMAX" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "FM", 12, "FM", "FM" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "AM", 12, "AM", "AM" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "LW", 12, "LW", "LW" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "MW", 12, "MW", "MW" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "I", 13, "ISDN Integrated Services Digital Network", "RDSI Red digital de servicios integrados - ISDN" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "4", 14, "4.75 cm/s (normal speed for a two sided cassette)", "4.75 cm/s (velocidad normal para un cassette de dos lados)" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "9", 14, "9.5 cm/s", "9.5 cm/s" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "I", 14, "Type I cassette (ferric/normal)", "Casete tipo I (férrico/normal)" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "II", 14, "Type II cassette (chrome)", "Casete tipo II (cromo)" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "III", 14, "Type III cassette (ferric chrome)", "Casete tipo III (cromo férrico)" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "IV", 14, "Type IV cassette (metal)", "Casete tipo IV (metal)" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "9", 15, "9.5 cm/s", "9.5 cm/s" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "19", 15, "19 cm/s", "19 cm/s" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "38", 15, "38 cm/s", "38 cm/s" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "76", 15, "76 cm/s", "76 cm/s" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "I", 15, "Type I cassette (ferric/normal)", "Casete tipo I (férrico/normal)" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "II", 15, "Type II cassette (chrome)", "Casete tipo II (cromo)" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "III", 15, "Type III cassette (ferric chrome)", "Casete tipo III (cromo férrico)" );
INSERT INTO mediaDevices ( device, mediaType, descriptionEN, descriptionES ) VALUES ( "IV", 15, "Type IV cassette (metal)", "Casete tipo IV (metal)" );

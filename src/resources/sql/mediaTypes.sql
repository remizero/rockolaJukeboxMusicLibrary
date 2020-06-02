CREATE TABLE `mediaTypes` (
  `id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
  `medio`	TEXT NOT NULL,
  `descriptionEN`	TEXT NOT NULL,
  `descriptionES`	TEXT NOT NULL
);

INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "DIG", "Other digital media", "Otros Medios digitales" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "ANA", "Other analogue media", "Otros Medios Analógicos" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "CD", "Compact Disc", "Disco Compacto" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "LD", "Laserdisc", "Disco Laser" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "TT", "Turntable records", "Grabación de Tocadiscos" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "MD", "MiniDisc", "Mini Disco" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "DAT", "Digital Audio Tape", "Cinta de Audio Digital" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "DCC", "Digital Compact Cassette", "Casete Compacto Digital" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "DVD", "Digital Versatile Disc", "Disco Versátil Digital" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "TV", "Television", "Televisión" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "VID", "Video", "Video" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "RAD", "Radio", "Radio" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "TEL", "Telephone", "Teléfono" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "MC", "Normal Cassette", "Casete Normal" );
INSERT INTO mediaTypes ( medio, descriptionEN, descriptionES ) VALUES ( "REE", "Reel", "Carrete" );

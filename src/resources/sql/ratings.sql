CREATE TABLE `ratings` (
  `id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
  `ratingEN`	TEXT NOT NULL,
  `ratingES`	TEXT NOT NULL
);

INSERT INTO ratings ( ratingEN, ratingES ) VALUES ( "None", "Ninguno" );
INSERT INTO ratings ( ratingEN, ratingES ) VALUES ( "Excellent", "Excelente" );
INSERT INTO ratings ( ratingEN, ratingES ) VALUES ( "Very Good", "Muy Buena" );
INSERT INTO ratings ( ratingEN, ratingES ) VALUES ( "Good", "Buena" );
INSERT INTO ratings ( ratingEN, ratingES ) VALUES ( "Regular", "Regular" );
INSERT INTO ratings ( ratingEN, ratingES ) VALUES ( "Deficient", "Deficiente" );
INSERT INTO ratings ( ratingEN, ratingES ) VALUES ( "Tasteless", "De mal gusto" );

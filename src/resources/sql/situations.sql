CREATE TABLE `situations` (
  `id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
  `situationEN`	TEXT NOT NULL,
  `situationES`	TEXT NOT NULL
);

INSERT INTO situations ( situationEN, situationES ) VALUES ( "None", "Ninguna" );
INSERT INTO situations ( situationEN, situationES ) VALUES ( "Dance", "Baile" );
INSERT INTO situations ( situationEN, situationES ) VALUES ( "Party", "Fiesta" );
INSERT INTO situations ( situationEN, situationES ) VALUES ( "Romantic", "Romántica" );
INSERT INTO situations ( situationEN, situationES ) VALUES ( "Dinner", "Cena" );
INSERT INTO situations ( situationEN, situationES ) VALUES ( "Environmental", "Ambiental" );
INSERT INTO situations ( situationEN, situationES ) VALUES ( "Station", "De estación" );
INSERT INTO situations ( situationEN, situationES ) VALUES ( "Rave", "Rave" );
INSERT INTO situations ( situationEN, situationES ) VALUES ( "Drunken brawl", "Reyerta de borrachos" );

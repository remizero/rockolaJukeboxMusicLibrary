CREATE TABLE `tempos` (
  `id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
  `tempoEN`	TEXT NOT NULL,
  `tempoES`	TEXT NOT NULL
);

INSERT INTO tempos ( tempoEN, tempoES ) VALUES ( "None", "Ninguno" );
INSERT INTO tempos ( tempoEN, tempoES ) VALUES ( "Fast", "Rápido" );
INSERT INTO tempos ( tempoEN, tempoES ) VALUES ( "Very Fast", "Muy Rápido" );
INSERT INTO tempos ( tempoEN, tempoES ) VALUES ( "Moderate", "Moderado" );
INSERT INTO tempos ( tempoEN, tempoES ) VALUES ( "Very Slow", "Muy Lento" );
INSERT INTO tempos ( tempoEN, tempoES ) VALUES ( "Slow", "Lento" );

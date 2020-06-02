CREATE TABLE `moods` (
  `id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
  `moodEN`	TEXT NOT NULL,
  `moodES`	TEXT NOT NULL
);

INSERT INTO moods ( moodEN, moodES ) VALUES ( "None", "Ninguno" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Cheerful", "Animado" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Reflective", "Reflexivo" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Gloomy", "Melancólico" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Humorous", "Humorístico" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Melancholy", "Melancólico" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Idyllic", "Idílico" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Whimsical", "Caprichoso" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Romantic", "Romántico" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Mysterious", "Misterioso" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Ominous", "Ominoso" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Calm", "Calma" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Lighthearted", "Ligero" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Hopeful", "Esperanzado" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Angry", "Enojado" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Fearful", "Temeroso" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Tense", "Tenso" );
INSERT INTO moods ( moodEN, moodES ) VALUES ( "Lonely", "Solitario" );

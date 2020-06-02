CREATE TABLE `languages` (
  `id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
  `iso_369_1`	TEXT NOT NULL,
  `iso_369_2`	TEXT NOT NULL,
  `descriptionEN`	TEXT NOT NULL,
  `descriptionES`	TEXT NOT NULL
);

INSERT INTO languages ( iso_369_1, iso_369_2, descriptionEN, descriptionES ) VALUES ( "es-VE", "spa", "Spanish", "Español" );
INSERT INTO languages ( iso_369_1, iso_369_2, descriptionEN, descriptionES ) VALUES ( "en-US", "eng", "English", "Inglés" );

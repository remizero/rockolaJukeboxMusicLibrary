CREATE TABLE `typeFormats` (
  `id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
  `typeFormat`	TEXT NOT NULL
);

INSERT INTO typeFormats ( typeFormat ) VALUES ( "Audio" );
INSERT INTO typeFormats ( typeFormat ) VALUES ( "Video" );
INSERT INTO typeFormats ( typeFormat ) VALUES ( "Image" );
INSERT INTO typeFormats ( typeFormat ) VALUES ( "Playlist" );

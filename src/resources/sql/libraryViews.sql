CREATE TABLE `libraryViews` (
  `id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
  `libraryView`	TEXT NOT NULL,
  `dataView`	TEXT NOT NULL,
  `descriptionEN`	TEXT NOT NULL,
  `descriptionES`	TEXT NOT NULL
);

INSERT INTO libraryViews ( libraryView, dataView, descriptionEN, descriptionES ) VALUES ( "Track View", "", "Track View", "Vista por Pista" );
INSERT INTO libraryViews ( libraryView, dataView, descriptionEN, descriptionES ) VALUES ( "Album View", "", "Album View", "Vista por Álbum" );
INSERT INTO libraryViews ( libraryView, dataView, descriptionEN, descriptionES ) VALUES ( "Tile Covers", "", "Tile Covers", "Vista por Carátulas" );
INSERT INTO libraryViews ( libraryView, dataView, descriptionEN, descriptionES ) VALUES ( "Cover Slider", "", "Cover Slider", "Carátulas Deslizables" );

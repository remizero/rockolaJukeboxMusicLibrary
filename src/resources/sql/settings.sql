CREATE TABLE `settings` (
  `id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
  `language`	INTEGER NOT NULL,
  `libraryView`	INTEGER NOT NULL,
  `headerMinimumSectionSize`	INTEGER NOT NULL,
  `headerState`	TEXT NOT NULL,
  `headerStretchLastSection`	INTEGER NOT NULL,
  `headerTooltipDuration`	INTEGER NOT NULL
);

INSERT INTO settings ( language, libraryView, headerMinimumSectionSize, headerState, headerStretchLastSection, headerTooltipDuration ) VALUES ( 1, 0, 50, "", 1, 5 );

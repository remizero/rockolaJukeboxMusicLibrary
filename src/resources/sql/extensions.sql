CREATE TABLE `extensions` ( 
  `id` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, 
  `extension` TEXT NOT NULL, 
  `description` TEXT NOT NULL, 
  `mimetype` TEXT NOT NULL, 
  `idTypeFormat` INTEGER NOT NULL
);

INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "3g2", "MPEG-4 Mobile Phone Audio File", "audio/3gpp2", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "3gp", "MPEG-4 Mobile Phone Audio File", "audio/3gpp", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "aac", "Advanced Audio Coding", "audio/aac, audio/x-aac", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "ac3", "Advanced Audio Coding", "audio/ac3", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "afc", "AIFF audio file", "audio/aiff, audio/x-aiff", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "aif", "AIFF audio file", "audio/aiff, audio/x-aiff", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "aifc", "AIFF audio file", "audio/aiff, audio/x-aiff", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "aiff", "AIFF audio file", "audio/aiff, audio/x-aiff", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "alac", "Apple Lossless Audio Codec", "audio/aiff, audio/x-aiff", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "ape", "Monkey's Audio lossless audio compression format", "audio/ape", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "asf", "Advanced Streaming Format", "audio/asf", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "au", "Audio file", "audio/basic", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "dsm", "Musical Instrument Digital Interface Audio File", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "far", "Musical Instrument Digital Interface Audio File", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "fla", "Free Lossless Audio Codec", "audio/flac", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "flac", "Free Lossless Audio Codec", "audio/flac", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "gmf", "Musical Instrument Digital Interface Audio File", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "hmp", "Musical Instrument Digital Interface Audio File", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "it", "Impulse Tracker Audio File", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "m4a", "MPEG-4 Audio File", "audio/m4a", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "m4b", "Audiobook/podcast Audio File", "audio/m4b", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "m4p", "Apple iTunes Music", "audio/m4p", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "m4r", "Apple iPhone MPEG-4 audio File", "audio/m4r", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "mid", "Musical Instrument Digital Interface Audio File", "audio/mid, audio/x-mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "midi", "Musical Instrument Digital Interface Audio File", "audio/midi, audio/x-midi", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "mod", "Module Music Formats", "audio/mod, audio/x-mod", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "mogg", "Multi-Track-Single-Logical-Stream Ogg-Vorbis", "audio/", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "mp2", "MPEG-1 Audio Layer 2", "audio/mpeg2, audio/x-mpeg2, audio/mpeg", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "mp3", "MPEG Layer III Audio", "audio/mp3, audio/mpeg", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "mp4", "MPEG-4 Digital Multimedia Container Format", "audio/mp4", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "mpa", "MPEG Audio Stream", "audio/mpa, audio/mpeg", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "mpc", "Musepack Audio File", "audio/", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "mtm", "Musical Instrument Digital Interface Audio File", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "mus", "Musical Instrument Digital Interface Audio File", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "oga", "Audio Format Vorbis", "audio/ogg, audio/x-ogg", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "ogg", "Audio Format Vorbis", "audio/ogg, audio/x-ogg, audio/vorbis", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "opus", "Lossy Audio Coding Format Audio File", "audio/opus", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "pcm", "Pulse Code Modulation", "audio/L24", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "ra", "RealAudio Format Audio File", "audio/vnd.rn-realaudio, audio/x-realaudio, audio/x-pn-realaudio", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "ram", "RealAudio Format Audio File", "audio/vnd.rn-realaudio, audio/x-pn-realaudio", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "raw", "========================================", "audio/raw, audio/x-raw", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "rm", "RealAudio Format Audio File", "audio/x-realaudio, audio/x-pn-realaudio", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "rmi", "Radio MIDI File", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "s3m", "Scream Tracker 3 S3M format", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "stm", "Musical Instrument Digital Interface Audio File", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "tta", "True Audio", "audio/x-tta", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "ult", "Musical Instrument Digital Interface Audio File", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "vorbis", "True Audio", "audio/vorbis", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "wav", "Standard audio file", "audio/wav, audio/x-wav", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "wave", "Standard audio file", "audio/wave, audio/vnd.wave", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "weba", "Audiovisual Media File Format", "audio/webm", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "webm", "Audiovisual Media File Format", "audio/webm", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "wma", "Windows Media Audio format", "audio/x-ms-wma", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "xm", "XM format, FastTracker 2", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "xmi", "Musical Instrument Digital Interface Audio File", "audio/mid", 1 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "asx", "Advanced Stream Redirector Playlist.", "video/x-ms-asf", 4 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "m3u", "MPEG 3.0 URL Playlist.", "audio/x-mpegurl", 4 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "m3u8", "MPEG 3.0 URL UTF-8 Playlist.", "audio/x-mpegurl", 4 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "pls", "Playlist", "audio/x-scpls", 4 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "sami", "Synchronized Accessible Media Interchange Closed Caption", "application/octet-stream", 4 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "smi", "Synchronized Accessible Media Interchange Closed Caption", "application/octet-stream", 4 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "smil", "Synchronized Multimedia Integration Language Playlist", "application/smil+xml", 4 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "wpl", "Windows Media Player Playlist", "application/vnd.ms-wpl", 4 );
INSERT INTO extensions ( extension, description, mimetype, idTypeFormat ) VALUES ( "xspf", "XML Shareable Playlist Format", "application/xspf+xml", 4 );

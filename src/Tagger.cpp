#include "Tagger.h"

Mp3Info getMp3Info(string filePath){
  TagLib::FileRef f(filePath.c_str());
  Mp3Info mp3Info;
  if(!f.isNull()){
    mp3Info.artist = f.tag()->artist().to8Bit();
    mp3Info.album = f.tag()->album().to8Bit();
    mp3Info.title = f.tag()->title().to8Bit();
  }
  return mp3Info;
}

void tagFile(string filePath,string album,string artist,string titlePattern){
  TagLib::FileRef f(filePath.c_str());
  f.tag()->setAlbum(album);
  f.tag()->setArtist(artist);
  f.tag()->setTitle(calculateName(getFileNameFromPath(filePath),titlePattern));
  f.save();
}

void updateTracksInformation(string dir, string album, string artist, string tittlePattern){
  vector<string> files = getFilesFromDir(dir);
  auto i = files.begin();
  while(i != files.end()){
    if(i->find(".mp3") != string::npos){ //If file path contains .mp3
      tagFile(*i, album, artist, tittlePattern);
    }
    ++i;
  }
}

/*
  This function is in charge of "calculating" the song title that we want in the tag. We use a pattern to determine how to derive the song title form the file name. The idea is every files name follow a pattern that includes the track name we want. We only have two special chars. -#- is the name we want, ? represents any sigle char. So foe example -01 Last of the Mohicans.mp3- and -??#.mp3-, would return -Last of the Mohicans- which is the name we want for the tag.
*/
string calculateName(string filename,string pattern){
  string trackTitle = "";
  bool match = true;
  for ( int i=0, j=0; i < pattern.length() ; i++ && match){
    switch(pattern[i]){
    case '#':
      while(pattern[i + 1] != filename[j]){
        trackTitle += filename[j];
        j++;
      }
      break;
    case '?':
      j++;
      break;
    default:
      if(pattern[i] == filename[j]){
        j++;
      }else{
        trackTitle = "";
        match = false;
      }
    }
  }
  return trackTitle;
}

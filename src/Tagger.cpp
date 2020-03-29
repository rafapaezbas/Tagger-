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

void tagFile(string path,string artist,string album,string title, string year){
  TagLib::FileRef f(path.c_str());
  if(!album.empty())
    f.tag()->setAlbum(album);
  if(!artist.empty())
    f.tag()->setArtist(artist);
  if(!title.empty())
    f.tag()->setTitle(title);
  if(!year.empty())
    f.tag()->setYear(std::stoi(year));
  f.save();
}

void tagAlbum(string dir, string pattern){
  vector<string> files = getFilesFromDir(dir);
  auto i = files.begin();
  while(i != files.end()){
    if(i->find(".mp3") != string::npos){ //If file path contains .mp3
      std::string title = calculateMp3Info(getFileNameFromPath(*i),pattern).title;
      tagFile(*i, "", "", title,"");
    }
    ++i;
  }
}

void tagAlbum(string dir, string artist, string album, string year){
  vector<string> files = getFilesFromDir(dir);
  auto i = files.begin();
  while(i != files.end()){
    if(i->find(".mp3") != string::npos){ //If file path contains .mp3
      tagFile(*i, artist, album, "", year);
    }
    ++i;
  }
}

void tagCollection(string dir, string pattern){
  vector<string> albums = getChildrenDirs(dir);
  auto i = albums.begin();
  while(i != albums.end()){
    std::string artist = calculateMp3Info(getFileNameFromPath(*i),pattern).artist;
    std::string album = calculateMp3Info(getFileNameFromPath(*i),pattern).album;
    std::string year = calculateMp3Info(getFileNameFromPath(*i),pattern).year;
    tagAlbum(*i,artist,album,year);
    ++i;
  }
}

/*
  This function is in charge of "calculating" the song title that we want in the tag. We use a pattern to determine how to derive the song title form the file name. The idea is every files name follow a pattern that includes the track name we want. We only have two special chars. -#- is the name we want, ? represents any sigle char. So foe example -01 Last of the Mohicans.mp3- and -??#.mp3-, would return -Last of the Mohicans- which is the name we want for the tag.
*/
Mp3Info calculateMp3Info(string filename,string pattern){
  Mp3Info mp3Info;
  string trackTitle = "";
  bool match = true;
  for ( int i=0, j=0; i < pattern.length() ; i++ && match){
    switch(pattern[i]){
    case '#':
      while(pattern[i + 1] != filename[j]){
        mp3Info.title += filename[j];
        j++;
      }
      break;
    case '$':
      while(pattern[i + 1] != filename[j]){
        mp3Info.artist += filename[j];
        j++;
      }
      break;
    case '%':
      while(pattern[i + 1] != filename[j]){
        mp3Info.album += filename[j];
        j++;
      }
      break;
    case '=':
      while(pattern[i + 1] != filename[j]){
        mp3Info.year += filename[j];
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
  return mp3Info;
}

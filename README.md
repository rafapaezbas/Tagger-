# Tagger++
## What is Tagger++?
Tagger++ is a command line tool for ID3 tagging mp3 files. The main use of the tool is to generate the title of the track for every file, solving the situation when every files has a the name of the track in the filename, but the ID3 tag is empty. 
## How to use Tagger++?
Use the following arguments:
* -d Specifies the directory where the mp3 files are.
* -a The value of the Artist ID3 tag.
* -l The value of the Album ID3 tag.
* -t The value of the title pattern present in the name file.

## What is a title pattern?
Is the pattern followed by the filenames, containing the track name. There are three special characters for the pattern.
* * Indicates any number of characters.
* ? Indicates one single character.
* # Indicates the name of the track.

So for example, if we have a set of files with these names:
- 01 - Track 1.mp3
- 02 - Track 2.mp3
- ...

The pattern *?? - #.mp3* would result in Track 1, Track 2 ... as track names.

## To-do:
+ Year tag.
+ Special mode for getting the files with missing ID3 information.

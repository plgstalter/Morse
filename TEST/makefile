CC = g++
CFLAGS = -Wall -g

 
main: main.o morse_fr.o audio_txt.o
    $(CC) $(CFLAGS) -o main main.o morse_fr.o audio_txt.o

main.o: main.cpp morse_fr.h audio_txt.h
    $(CC) $(CFLAGS) -c main.cpp
 
morse_fr.o: morse_fr.h audio_txt.h
 
audio_txt.o: audio_txt.h morse_fr.h
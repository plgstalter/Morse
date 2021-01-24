#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include<cstdlib>
#include<cstring>

int what_to_write (std::string morse, int rang) {
  int n = morse.size();
  if (morse[rang]=='.') {
    if (rang >= n-3) {
      return 0;
    }
    if (morse[rang+1]=='.'&&morse[rang+2]=='.'&&morse[rang+3]=='=') {
      return 1;
    }
    if (rang >= n - 7) {
      return 0;
    }
    if (morse[rang+1]=='.'&&morse[rang+2]=='.'&&morse[rang+3]=='.'&&morse[rang+4]=='.'&&morse[rang+5]=='.'&&morse[rang+6]=='.') {
      return 2;
    }
    return 0;
    
  }
  else {
    if (rang >= n-3) {
      return 3;
    }
    if (morse[rang+1]=='='&&morse[rang+2]=='=') {
      return 4;
    }
    return 3;
  }
}

namespace little_endian_io
{
  template <typename Word>
  std::ostream& write_word( std::ostream& outs, Word value, unsigned size = sizeof( Word ) )
  {
    for (; size; --size, value >>= 8)
      outs.put( static_cast <char> (value & 0xFF) );
    return outs;
  }
}
using namespace little_endian_io;


void create_wave_file(std::string morse, const char * pname) {
    std::ofstream f(pname, std::ios::binary );

    // Write the file headers
    f << "RIFF----WAVEfmt ";     // (chunk size to be filled in later)
    write_word( f,     16, 4 );  // no extension data
    write_word( f,      1, 2 );  // PCM - integer samples
    write_word( f,      2, 2 );  // two channels (stereo file)
    write_word( f,  44100, 4 );  // samples per second (Hz)
    write_word( f, 176400, 4 );  // (Sample Rate * BitsPerSample * Channels) / 8
    write_word( f,      4, 2 );  // data block size (size of two integer samples, one for each channel, in bytes)
    write_word( f,     16, 2 );  // number of bits per sample (use a multiple of 8)

    // Write the data chunk header
    size_t data_chunk_pos = f.tellp();
    f << "data----";  // (chunk size to be filled in later)

    const double two_pi = 6.283185307179586476925286766559;
    const double max_amplitude = 32760;  // "volume"

    double hz        = 44100;    // samples per second
    double frequency = 261.626;  // middle C
    double seconds   = 0.1;      // time
    int N = hz * seconds;  // total number of samples

    int a;
    double b;
    int i=0;

    while (i<morse.size()) {
      switch (what_to_write(morse, i)) {
        case 0:
          a = 1;
          b = 0.0;
          i++;
          break;
        case 1:
          a = 3;
          b = 0.0;
          i = i + 3;
          break;
        case 2:
          a = 7;
          b = 0.0;
          i = i + 7;
          break;
        case 3:
          a = 1;
          b = 1.0;
          i++;
          break;
        case 4:
          a = 3;
          b = 1.0;
          i = i + 3;
          break;
      }
      for (int n = 0; n < a*N; n++)
            {
                double amplitude = (double)n /(a*N) * max_amplitude;
                double value     = b*sin( (two_pi * n * frequency) / hz );
                write_word( f, (int)(                 amplitude  * value), 2 );
                write_word( f, (int)((max_amplitude - amplitude) * value), 2 );
            }
    }
    
    // file closing
    // (We'll need the final file size to fix the chunk sizes above)
    size_t file_length = f.tellp();

    // Fix the data chunk header to contain the data size
    f.seekp( data_chunk_pos + 4 );
    write_word( f, file_length - data_chunk_pos + 8 );

    // Fix the file header to contain the proper RIFF chunk size, which is (file size - 8) bytes
    f.seekp( 0 + 4 );
    write_word( f, file_length - 8, 4 ); 
}
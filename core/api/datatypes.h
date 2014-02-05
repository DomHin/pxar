#ifndef PXAR_TYPES_H
#define PXAR_TYPES_H

#include <stdint.h>
#include <iostream>
#include <vector>
#include <map>

/** Export classes from the DLL under WIN32 */
#ifdef WIN32
#define DLLEXPORT __declspec( dllexport )
#else
#define DLLEXPORT
#endif

namespace pxar {

  /** Class for storing decoded pixel readout data
   */
  class DLLEXPORT pixel {
  public:

    /** Default constructor for pixel objects, defaulting all member variables to zero
     */
  pixel() : roc_id(0), column(0), row(0), value(0) {};

    /** Constructor for pixel objects with address and value initialization.
     */
  pixel(int32_t address, int32_t data) : value(data) { decode(address); };

    /** Constructor for pixel objects with rawdata pixel address & value initialization.
     */
  pixel(uint32_t rawdata) : roc_id(0) { decodeRaw(rawdata); };

    /** Function to fill the pixel with linear encoded data from RPC transfer.
     *  The address transmitted from the NIOS soft core is encoded in the following
     *  way:
     *
     *  Split the address and distribute it over ROC, column and row:
     *   * pixel column: max(51 -> 110011), requires 6 bits (R)
     *   * pixel row: max(79 -> 1001111), requires 7 bits (C)
     *   * roc id: max(15 -> 1111), requires 4 bits (I)
     *
     *  So everything can be stored in one 32 bits variable:
     *
     *   ........ ....IIII ..CCCCCC .RRRRRRR
     */
    inline void decode(int32_t address) {
      roc_id = (address>>16)&15;
      column = (address>>8)&63;
      row = (address)&127;
    };
    // FIXME does not work with inverted address yet!
    inline void decodeRaw(uint32_t raw) {
      value = (raw & 0x0f) + ((raw >> 1) & 0xf0);
      int c =    (raw >> 21) & 7;
      c = c*6 + ((raw >> 18) & 7);
      int r =    (raw >> 15) & 7;
      r = r*6 + ((raw >> 12) & 7);
      r = r*6 + ((raw >>  9) & 7);
      row = 80 - r/2;
      column = 2*c + (r&1);
    };
    uint8_t roc_id;
    uint8_t column;
    uint8_t row;
    int32_t value;

  private:
    /** Overloaded ostream operator for simple printing of pixel data
     */
    friend std::ostream & operator<<(std::ostream &out, pixel& px) {
      out << static_cast<int>(px.roc_id)
	  << " [" << static_cast<int>(px.column) << "," << static_cast<int>(px.row) 
	  << "," << static_cast<int>(px.value) << "]";
      return out;
    };
  };

  /** Class to store events containing a header and a std::vector of pixels
   */
  class DLLEXPORT event {
  public:
    uint16_t header;
    std::vector<pixel> pixels;
  private:
    /** Overloaded ostream operator for simple printing of event data
     */
    friend std::ostream & operator<<(std::ostream &out, event& evt) {
      out << "====== " << std::hex << static_cast<uint16_t>(evt.header) << " ====== ";
      for (std::vector<pixel>::iterator it = evt.pixels.begin(); it != evt.pixels.end(); ++it)
	out << (*it) << " ";
      return out;
    };
  };


  /** Class to store raw evet data records containing a list of flags to indicate the 
   *  event status as well as a vector of uint16_t data records containing the actual
   *  event data in undecoded raw format.
   */
  class rawEvent {
    /*
      bit 0 = misaligned start
      bit 1 = no end detected
      bit 2 = overflow
    */
    std::vector<uint16_t> data;
    unsigned int flags;
  public:
    void SetStartError() { flags |= 1; }
    void SetEndError()   { flags |= 2; }
    void SetOverflow()   { flags |= 4; }
    void ResetStartError() { flags &= ~1; }
    void ResetEndError()   { flags &= ~2; }
    void ResetOverflow()   { flags &= ~4; }
    void Clear() { flags = 0; data.clear(); }
    bool IsStartError() { return (flags & 1) != 0; }
    bool IsEndError()   { return (flags & 2) != 0; }
    bool IsOverflow()   { return (flags & 4) != 0; }
	
    unsigned int GetSize() { return data.size(); }
    void Add(uint16_t value) { data.push_back(value); }
    uint16_t operator[](int index) { return data.at(index); }
  };

  /** Class to store the configuration for single pixels (i.e. their mask state,
   *  trim bit settings and whether they belong to the currently run test ("enable").
   *  By default, pixelConfigs have the  mask bit set.
   */
  class DLLEXPORT pixelConfig {
  public:
  pixelConfig() : 
    column(0), row(0), 
      trim(15), mask(true), enable(false) {};
  pixelConfig(uint8_t _column, uint8_t _row, uint8_t _trim) : 
    column(_column), row(_row), trim(_trim),
      mask(true), enable(false) {};
    uint8_t column;
    uint8_t row;
    uint8_t trim;
    bool mask;
    bool enable;
  };

  /** Class for ROC states
   *
   *  Contains a DAC map for the ROC programming settings, a type flag, enable switch
   *  and a vector of pixelConfigs.
   */
  class DLLEXPORT rocConfig {
  public:
  rocConfig() : pixels(), dacs(), type(0), enable(true) {};
    std::vector< pixelConfig > pixels;
    std::map< uint8_t,uint8_t > dacs;
    uint8_t type;
    uint8_t i2c_address;
    bool enable;
  };

  /** Class for TBM states
   *
   *  Contains a register map for the device register settings, a type flag and an enable switch
   */
  class DLLEXPORT tbmConfig {
  public:
  tbmConfig() : dacs(), type(0), enable(true) {};
    std::map< uint8_t,uint8_t > dacs;
    uint8_t type;
    bool enable;
  };

}
#endif
/*
***************************************************************************
*
* Author: Teunis van Beelen
*
* Copyright (C) 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014 Teunis van Beelen
*
* teuniz@gmail.com
*
***************************************************************************
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation version 2 of the License.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*
***************************************************************************
*
* This version of GPL is at http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
*
***************************************************************************
*/

/* last revision: Januari 31, 2014 */

/* For more info and how to use this library, visit: http://www.teuniz.net/RS-232/ */

#include "rs232.h"
#include "log.h"

#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#include <cstdio>

using namespace pxar;
using namespace std;

#define NULL_FD -1

RS232Conn::RS232Conn(const string &portName, int baudRate){
  this->portName = portName;
  this->baudRate = baudRate;
  port = NULL_FD;
  writeSuffix = "\r\n";
  readSuffix = "\r\n";
}
RS232Conn::RS232Conn() : RS232Conn("",0) { }

RS232Conn::~RS232Conn(){
  if(port != NULL_FD){
    closePort();
  }
}

void RS232Conn::setPortName(const string &portName){
  if (port != NULL_FD){
    perror("Cannot change port name while port is open");
    return;
  }
  this->portName = portName;
}

void RS232Conn::setBaudRate(int baudRate){
  if (this->port != NULL_FD){
    perror("Cannot change baud rate while port is open");
    return;
  }
  this->baudRate = baudRate;
}

void RS232Conn::setReadSuffix(const std::string &suffix){
  readSuffix = suffix;
}

void RS232Conn::setWriteSuffix(const std::string &suffix){
  writeSuffix = suffix;
}

bool RS232Conn::openPort(){
  int baudr;
  switch(baudRate)
    {
    case      50 : baudr = B50;
      break;
    case      75 : baudr = B75;
      break;
    case     110 : baudr = B110;
      break;
    case     134 : baudr = B134;
      break;
    case     150 : baudr = B150;
      break;
    case     200 : baudr = B200;
      break;
    case     300 : baudr = B300;
      break;
    case     600 : baudr = B600;
      break;
    case    1200 : baudr = B1200;
      break;
    case    1800 : baudr = B1800;
      break;
    case    2400 : baudr = B2400;
      break;
    case    4800 : baudr = B4800;
      break;
    case    9600 : baudr = B9600;
      break;
    case   19200 : baudr = B19200;
      break;
    case   38400 : baudr = B38400;
      break;
    case   57600 : baudr = B57600;
      break;
    case  115200 : baudr = B115200;
      break;
    case  230400 : baudr = B230400;
      break;
    default      : LOG(logCRITICAL) << "Invalid baud rate " << baudRate << "!";
      return(1);
      break;
    }

  printf("Opening com port: %s with baud: %d\n", portName.c_str(), baudRate);
  this->port = open(portName.c_str(), O_RDWR | O_NOCTTY);
  if(port==-1)
  {
    port = NULL_FD;
    perror("unable to open comport ");
    return false;
  }
  
  int rsError;
  rsError = tcgetattr(port, &oldPortSettings);
  if(rsError==-1){
    closePort();
    perror("unable to read portsettings ");
    return false;
  }
  
  struct termios newPortSettings;
  memset(&newPortSettings, 0, sizeof(newPortSettings));
  newPortSettings.c_cflag = CS8 | CLOCAL | CREAD;
  newPortSettings.c_iflag = IGNPAR;
  cfsetspeed(&newPortSettings,baudr);
  
  rsError = tcsetattr(port, TCSANOW, &newPortSettings);
  if(rsError==-1){
    closePort();
    perror("unable to adjust portsettings ");
    return false;
  }
  
  int status = 0;
  rsError = ioctl(port, TIOCMGET, &status);
  if(rsError == -1){
    closePort();
    perror("unable to get portstatus");
    return false;
  }

  status |= TIOCM_DTR;    /* turn on DTR */
  status |= TIOCM_RTS;    /* turn on RTS */

  rsError = ioctl(port, TIOCMSET, &status);
  if(rsError == -1){
    closePort();
    perror("unable to set portstatus");
    return false;
  }

  return true;
}

void RS232Conn::closePort(){
  if(port == NULL_FD) return;
  int status;
  if(ioctl(port, TIOCMGET, &status) == -1){
    perror("unable to get portstatus");
  }

  status &= ~TIOCM_DTR;    /* turn off DTR */
  status &= ~TIOCM_RTS;    /* turn off RTS */

  if(ioctl(port, TIOCMSET, &status) == -1){
    perror("unable to set portstatus");
  }

  tcsetattr(port, TCSANOW, &oldPortSettings);
  close(port);
  port = NULL_FD;
}


int RS232Conn::writeBuf(const char *buf, int len){
  if (port == NULL_FD){
    perror("Cannot write to non-open port");
    return 0;
  }
  int status = write(port, buf, len);
  if (status == -1){
    perror("Error writing to RS232 Port");
    return 0;
  }
  return status;
}

int RS232Conn::writeData(const string &data)
{
  unsigned int bytesWritten = 0;
  bytesWritten += writeBuf(data.c_str(), data.size());
  bytesWritten += writeBuf(writeSuffix.c_str(), writeSuffix.size());
  usleep(1E6*.001);
  return bytesWritten;
}

int RS232Conn::pollPort(char &buf){
  if(port == NULL_FD){
    perror("Cannot poll non-open port!");
    return -1;
  }
  int status = read(port, &buf, 1);
  return status;
}

bool stringEndsWith(string &data, string &suffix){
  unsigned int dataSize = data.size();
  unsigned int suffixSize = suffix.size();
  if (dataSize < suffixSize)
    return false;
  else
    return data.substr(dataSize-suffixSize,suffixSize) == suffix;
}

int RS232Conn::readData(string &data){
  unsigned int suffixSize = this->readSuffix.size();
  unsigned int dataSize = data.size();
  unsigned int readSize = 0;
  while (data.size() < suffixSize || !stringEndsWith(data, readSuffix)){
    char buf;
    int status = pollPort(buf);
    if(status == 1) {
      data.append(1,buf);
      readSize++;
    }
    dataSize = data.size();
  }
  data = data.substr(0,dataSize-suffixSize);
  return readSize;
}

void RS232Conn::writeReadBack(const string &dataOut, string &dataIn){
  writeData(dataOut);
  readData(dataIn);
}


/*
  Constant  Description
  TIOCM_LE  DSR (data set ready/line enable)
  TIOCM_DTR DTR (data terminal ready)
  TIOCM_RTS RTS (request to send)
  TIOCM_ST  Secondary TXD (transmit)
  TIOCM_SR  Secondary RXD (receive)
  TIOCM_CTS CTS (clear to send)
  TIOCM_CAR DCD (data carrier detect)
  TIOCM_CD  Synonym for TIOCM_CAR
  TIOCM_RNG RNG (ring)
  TIOCM_RI  Synonym for TIOCM_RNG
  TIOCM_DSR DSR (data set ready)

  http://linux.die.net/man/4/tty_ioctl
*/

bool RS232Conn::isDCDEnabled(){
  int status;
  ioctl(port, TIOCMGET, &status);
  return status & TIOCM_CAR;
}

bool RS232Conn::isCTSEnabled(){
  int status;
  ioctl(port, TIOCMGET, &status);
  return status & TIOCM_CTS;
}

bool RS232Conn::isDSREnabled(){
  int status;
  ioctl(port, TIOCMGET, &status);
  return status & TIOCM_DSR;
}

void RS232Conn::enableDTR(){
  int status;
  if(ioctl(port, TIOCMGET, &status) == -1){
    perror("unable to get portstatus");
  }
  status |= TIOCM_DTR;    /* turn on DTR */
  if(ioctl(port, TIOCMSET, &status) == -1){
    perror("unable to set portstatus");
  }
}

void RS232Conn::disableDTR(){
  int status;
  if(ioctl(port, TIOCMGET, &status) == -1){
    perror("unable to get portstatus");
  }
  status &= ~TIOCM_DTR;    /* turn off DTR */
  if(ioctl(port, TIOCMSET, &status) == -1){
    perror("unable to set portstatus");
  }
}

void RS232Conn::enableRTS(){
  int status;
  if(ioctl(port, TIOCMGET, &status) == -1){
    perror("unable to get portstatus");
  }
  status |= TIOCM_RTS;    /* turn on RTS */
  if(ioctl(port, TIOCMSET, &status) == -1){
    perror("unable to set portstatus");
  }
}

void RS232Conn::disableRTS(){
  int status;
  if(ioctl(port, TIOCMGET, &status) == -1){
    perror("unable to get portstatus");
  }
  status &= ~TIOCM_RTS;    /* turn off RTS */
  if(ioctl(port, TIOCMSET, &status) == -1){
    perror("unable to set portstatus");
  }
}

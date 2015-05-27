// RPC functions for the DTB emulator
#include "rpc_calls.h"
#include "generator.h"
#include "helper.h"
#include "config.h"
#include "constants.h"
#include <vector>

using namespace pxar;

void CTestboard::GetInfo(std::string &message) {
  LOG(pxar::logDEBUGRPC) << "called.";
  message = " pxarCore DTB Emulator \n "
    + std::string(PACKAGE_STRING)
    + "\n";
}

uint16_t CTestboard::GetBoardId() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return 0x0;
}

void CTestboard::GetHWVersion(std::string &rpc_par1) {
  LOG(pxar::logDEBUGRPC) << "called.";
  rpc_par1 = "Hardware Revision 0";
}

uint16_t CTestboard::GetFWVersion() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return 0x0;
}

uint16_t CTestboard::GetSWVersion() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return 0x0;
}

uint16_t CTestboard::UpgradeGetVersion() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return 0x0100;
}

uint8_t CTestboard::UpgradeStart(uint16_t rpc_par1) {
  LOG(pxar::logDEBUGRPC) << "called.";
  return 0;
}

uint8_t CTestboard::UpgradeData(std::string &rpc_par1) {
  LOG(pxar::logDEBUGRPC) << "called.";
  return 0;
}

uint8_t CTestboard::UpgradeError() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return 0;
}

void CTestboard::UpgradeErrorMsg(std::string &rpc_par1) {
  LOG(pxar::logDEBUGRPC) << "called.";
  rpc_par1 = "No error.";
}

void CTestboard::UpgradeExec(uint16_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Init() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Welcome() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::SetLed(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::cDelay(uint16_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::uDelay(uint16_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
  pxar::mDelay(1);
}

// Emulator always has the same clock:
void CTestboard::SetClockSource(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::IsClockPresent() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return true;
}

void CTestboard::SetClock(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::SetClockStretch(uint8_t, uint16_t, uint16_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Sig_SetMode(uint8_t, uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Sig_SetPRBS(uint8_t, uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Sig_SetDelay(uint8_t, uint16_t, int8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Sig_SetLevel(uint8_t, uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Sig_SetOffset(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Sig_SetLVDS() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Sig_SetLCDS() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Sig_SetRdaToutDelay(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::SignalProbeD1(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::SignalProbeD2(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::SignalProbeA1(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::SignalProbeA2(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::SignalProbeADC(uint8_t, uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Pon() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Poff() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::_SetVD(uint16_t voltage) {
  LOG(pxar::logDEBUGRPC) << "called.";
  vd = voltage;
}

void CTestboard::_SetVA(uint16_t voltage) {
  LOG(pxar::logDEBUGRPC) << "called.";
  va = voltage;
}

void CTestboard::_SetID(uint16_t current) {
  LOG(pxar::logDEBUGRPC) << "called.";
  id = current;
}

void CTestboard::_SetIA(uint16_t current) {
  LOG(pxar::logDEBUGRPC) << "called.";
  ia = current;
}

uint16_t CTestboard::_GetVD() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return vd;
}

uint16_t CTestboard::_GetVA() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return va;
}

uint16_t CTestboard::_GetID() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return id;
}

uint16_t CTestboard::_GetIA() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return ia;
}

uint16_t CTestboard::_GetVD_Reg() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return vd;
}

uint16_t CTestboard::_GetVDAC_Reg() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return vd;
}

uint16_t CTestboard::_GetVD_Cap() {
  LOG(pxar::logDEBUGRPC) << "called.";
  return vd;
}

void CTestboard::HVon() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::HVoff() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::ResetOn() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::ResetOff() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

uint8_t CTestboard::GetStatus() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::SetRocAddress(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Pg_SetCmd(uint16_t, uint16_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

// FIXME PG could be used for real.
void CTestboard::Pg_SetCmdAll(std::vector<uint16_t> &) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Pg_SetSum(uint16_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Pg_Stop() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Pg_Single() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Pg_Trigger() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

// Receiving triggers for PG:
void CTestboard::Pg_Triggers(uint32_t nTriggers, uint16_t) {
  LOG(pxar::logDEBUGRPC) << "called.";

  // Check how many open DAQ channels we have:
  size_t channels = std::count(daq_status.begin(), daq_status.end(), true);
  // Distribute the ROCs evenly:
  size_t roc_per_ch = roci2c.size()/channels;

  for(size_t i = 0; i < nTriggers; i++) {
    for(size_t ch = 0; ch < channels; ch++) {
      fillRawData(i,daq_buffer.at(ch),tbmtype,roc_per_ch,true,0,0);
    }
  }
}

// FIXME Receiving loop command
void CTestboard::Pg_Loop(uint16_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
  // Set DAQ into state where it always returns events.
}

// Trigger selection
void CTestboard::Trigger_Select(uint16_t src) {
  LOG(pxar::logDEBUGRPC) << "called.";
  LOG(pxar::logDEBUGRPC) << "called, updated TBM to 0x" << std::hex << (int)tbmtype << std::dec;
  // Triggers via TBM Emulator:
  if((src & 0x00f0) != 0 || src == 0x0100) tbmtype = TBM_EMU;
  LOG(pxar::logDEBUGRPC) << "called, updated TBM to 0x" << std::hex << (int)tbmtype << std::dec;
}

void CTestboard::Trigger_Delay(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Trigger_Timeout(uint16_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Trigger_SetGenPeriodic(uint32_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Trigger_SetGenRandom(uint32_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Trigger_Send(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

// DAQ Open
uint32_t CTestboard::Daq_Open(uint32_t buffersize, uint8_t channel) {
  LOG(pxar::logDEBUGRPC) << "called.";

  if(channel > daq_buffer.size()) return 0;
  
  // Reserve some memory (not necessary but nice...)
  daq_buffer.at(channel).reserve(buffersize/2);

  return daq_buffer.at(channel).capacity();
}

void CTestboard::Daq_Close(uint8_t channel) {
  LOG(pxar::logDEBUGRPC) << "called.";
  // Clear DAQ buffer
  daq_buffer.at(channel).clear();
  daq_status.at(channel) = false;
}

void CTestboard::Daq_Start(uint8_t channel) {
  LOG(pxar::logDEBUGRPC) << "called.";
  daq_status.at(channel) = true;
}

void CTestboard::Daq_Stop(uint8_t rpc_par1) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

uint32_t CTestboard::Daq_GetSize(uint8_t channel) {
  LOG(pxar::logDEBUGRPC) << "called.";
  if(daq_status.at(channel)) return daq_buffer.at(channel).size();
  else return 0;
}

uint8_t CTestboard::Daq_FillLevel(uint8_t rpc_par1) {
  LOG(pxar::logDEBUGRPC) << "called.";
  // We are always on 30%:
  return 30;
}

uint8_t CTestboard::Daq_FillLevel() {
  LOG(pxar::logDEBUGRPC) << "called.";
  // We are always on 30%:
  return 30;
}

uint8_t CTestboard::Daq_Read(std::vector<uint16_t> &data, uint32_t blocksize, uint8_t channel) {
  LOG(pxar::logDEBUGRPC) << "called.";
  uint32_t available = 0;
  return Daq_Read(data, blocksize, available, channel);
}

uint8_t CTestboard::Daq_Read(std::vector<uint16_t> &data, uint32_t blocksize, uint32_t &available, uint8_t channel) {
  LOG(pxar::logDEBUGRPC) << "called.";
  data.clear();

  if(!daq_status.at(channel)) { available = 0; return 0; }

  // Return correct blocksize. Since this is given in Bytes,
  // we deliver blocksize/2 16bit words:

  std::vector<uint16_t>::iterator copy_end =
    (blocksize/2 < daq_buffer.at(channel).size() ? (daq_buffer.at(channel).begin() + blocksize/2) : daq_buffer.at(channel).end());

  data.insert(data.end(),daq_buffer.at(channel).begin(),copy_end);
  daq_buffer.at(channel).erase(daq_buffer.at(channel).begin(),copy_end);
  
  return 0;
}

void CTestboard::Daq_Select_ADC(uint16_t rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint8_t rpc_par4) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Daq_Select_Deser160(uint8_t rpc_par1) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Daq_Select_Deser400() {
  LOG(pxar::logDEBUGRPC) << "called.";
  // Produce TBM headers!
}

void CTestboard::Daq_Deser400_Reset(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Daq_Deser400_OldFormat(bool) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Daq_Select_Datagenerator(uint16_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::Daq_DeselectAll() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

// Collect all ROCs that have ever been programmed:
void CTestboard::roc_I2cAddr(uint8_t i2c) {
  LOG(pxar::logDEBUGRPC) << "called.";
  std::vector<uint8_t>::iterator thisroc = std::find(roci2c.begin(),roci2c.end(),i2c);
  if(thisroc == roci2c.end()) roci2c.push_back(i2c);
}

void CTestboard::roc_ClrCal() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::roc_SetDAC(uint8_t, uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::roc_Pix(uint8_t, uint8_t, uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::roc_Pix_Trim(uint8_t, uint8_t, uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::roc_Pix_Mask(uint8_t, uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::roc_Pix_Cal(uint8_t, uint8_t, bool) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::roc_Col_Enable(uint8_t, bool) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::roc_AllCol_Enable(bool) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::roc_Col_Mask(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::roc_Chip_Mask() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::TBM_Present() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::tbm_Enable(bool tbm) {
  LOG(pxar::logDEBUGRPC) << "called.";
  if(tbm) tbmtype = TBM_08;
  else tbmtype = TBM_NONE;
}

void CTestboard::tbm_Addr(uint8_t, uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::mod_Addr(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::tbm_Set(uint8_t, uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::tbm_Get(uint8_t, uint8_t &) {
  LOG(pxar::logDEBUGRPC) << "called.";
  return true;
}

bool CTestboard::tbm_GetRaw(uint8_t, uint32_t &) {
  LOG(pxar::logDEBUGRPC) << "called.";
  return true;
}

int16_t CTestboard::TrimChip(std::vector<int16_t> &) {
  LOG(pxar::logDEBUGRPC) << "called.";
  return 0;
}

// FIXME do we emulate loop interrupts?
void CTestboard::LoopInterruptReset() {
  LOG(pxar::logDEBUGRPC) << "called.";
}

void CTestboard::SetLoopTriggerDelay(uint16_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::SetI2CAddresses(std::vector<uint8_t> &rpc_par1) {
  LOG(pxar::logDEBUGRPC) << "called.";
  nrocs_loops = rpc_par1.size();
  return true;
}

// FIXME here we could implement masked pixels
bool CTestboard::SetTrimValues(uint8_t, std::vector<uint8_t> &) {
  LOG(pxar::logDEBUGRPC) << "called.";
  return true;
}

bool CTestboard::LoopMultiRocAllPixelsCalibrate(std::vector<uint8_t> &roci2cs, uint16_t nTriggers, uint16_t flags) {
  LOG(pxar::logDEBUGRPC) << "called.";

  // Check how many open DAQ channels we have:
  size_t channels = std::count(daq_status.begin(), daq_status.end(), true);
  // Distribute the ROCs evenly:
  size_t roc_per_ch = roci2cs.size()/channels;

  uint32_t event = 0;
  for(size_t i = 0; i < ROC_NUMCOLS; i++) {
    for(size_t j = 0; j < ROC_NUMROWS; j++) {
      for(size_t k = 0; k < nTriggers; k++) {
	for(size_t ch = 0; ch < channels; ch++) {
	  fillRawData(event,daq_buffer.at(ch),tbmtype,roc_per_ch,false,i,j,flags);
	}
	event++;
      }
    }
  }
  
  return 1;
}

bool CTestboard::LoopMultiRocOnePixelCalibrate(std::vector<uint8_t> &rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint16_t rpc_par4, uint16_t rpc_par5) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopSingleRocAllPixelsCalibrate(uint8_t rpc_par1, uint16_t rpc_par2, uint16_t rpc_par3) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopSingleRocOnePixelCalibrate(uint8_t rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint16_t rpc_par4, uint16_t rpc_par5) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopMultiRocAllPixelsDacScan(std::vector<uint8_t> &rpc_par1, uint16_t rpc_par2, uint16_t rpc_par3, uint8_t rpc_par4, uint8_t rpc_par5, uint8_t rpc_par6) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopMultiRocAllPixelsDacScan(std::vector<uint8_t> &rpc_par1, uint16_t rpc_par2, uint16_t rpc_par3, uint8_t rpc_par4, uint8_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopMultiRocOnePixelDacScan(std::vector<uint8_t> &rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint16_t rpc_par4, uint16_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopMultiRocOnePixelDacScan(std::vector<uint8_t> &rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint16_t rpc_par4, uint16_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8, uint8_t rpc_par9) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopSingleRocAllPixelsDacScan(uint8_t rpc_par1, uint16_t rpc_par2, uint16_t rpc_par3, uint8_t rpc_par4, uint8_t rpc_par5, uint8_t rpc_par6) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopSingleRocAllPixelsDacScan(uint8_t rpc_par1, uint16_t rpc_par2, uint16_t rpc_par3, uint8_t rpc_par4, uint8_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopSingleRocOnePixelDacScan(uint8_t rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint16_t rpc_par4, uint16_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopSingleRocOnePixelDacScan(uint8_t rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint16_t rpc_par4, uint16_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8, uint8_t rpc_par9) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopMultiRocAllPixelsDacDacScan(std::vector<uint8_t> &rpc_par1, uint16_t rpc_par2, uint16_t rpc_par3, uint8_t rpc_par4, uint8_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8, uint8_t rpc_par9) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopMultiRocAllPixelsDacDacScan(std::vector<uint8_t> &rpc_par1, uint16_t rpc_par2, uint16_t rpc_par3, uint8_t rpc_par4, uint8_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8, uint8_t rpc_par9, uint8_t rpc_par10, uint8_t rpc_par11) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopMultiRocOnePixelDacDacScan(std::vector<uint8_t> &rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint16_t rpc_par4, uint16_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8, uint8_t rpc_par9, uint8_t rpc_par10, uint8_t rpc_par11) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopMultiRocOnePixelDacDacScan(std::vector<uint8_t> &rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint16_t rpc_par4, uint16_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8, uint8_t rpc_par9, uint8_t rpc_par10, uint8_t rpc_par11, uint8_t rpc_par12, uint8_t rpc_par13) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopSingleRocAllPixelsDacDacScan(uint8_t rpc_par1, uint16_t rpc_par2, uint16_t rpc_par3, uint8_t rpc_par4, uint8_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8, uint8_t rpc_par9) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopSingleRocAllPixelsDacDacScan(uint8_t rpc_par1, uint16_t rpc_par2, uint16_t rpc_par3, uint8_t rpc_par4, uint8_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8, uint8_t rpc_par9, uint8_t rpc_par10, uint8_t rpc_par11) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopSingleRocOnePixelDacDacScan(uint8_t rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint16_t rpc_par4, uint16_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8, uint8_t rpc_par9, uint8_t rpc_par10, uint8_t rpc_par11) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

bool CTestboard::LoopSingleRocOnePixelDacDacScan(uint8_t rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint16_t rpc_par4, uint16_t rpc_par5, uint8_t rpc_par6, uint8_t rpc_par7, uint8_t rpc_par8, uint8_t rpc_par9, uint8_t rpc_par10, uint8_t rpc_par11, uint8_t rpc_par12, uint8_t rpc_par13) {
  LOG(pxar::logDEBUGRPC) << "called.";
}

uint16_t CTestboard::GetADC(uint8_t) {
  LOG(pxar::logDEBUGRPC) << "called.";
  return 0;
}


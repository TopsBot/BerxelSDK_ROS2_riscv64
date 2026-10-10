#ifndef __BERXEL_HAWK_DEVICE_H__
#define __BERXEL_HAWK_DEVICE_H__

#include <map>
#include <vector>
#include <BerxelHawkPlatform.h>
#include <BerxelHawkDefines.h>
#include <BerxelHawkFrame.h>


namespace berxel
{
class BERXEL_HAWK_API_EXPORT BerxelHawkDevice
{
public:
    BerxelHawkDevice();
    virtual ~BerxelHawkDevice();

public:
	virtual int32_t setStreamFlagMode(BerxelHawkStreamFlagMode flagMode) = 0;
    virtual int32_t startStreams(int streamFlags) = 0;
	virtual int32_t startStreams(int streamFlags, BerxelHawkNewFrameCallBack callBack, void* pUserData) = 0;
    virtual int32_t stopStreams(int streamFlags) = 0;
    virtual int32_t getSupportFrameModes(BerxelHawkStreamType streamType, const BerxelHawkStreamFrameMode** pModes, uint32_t* pCount) = 0;
    virtual int32_t setFrameMode(BerxelHawkStreamType streamType, BerxelHawkStreamFrameMode *mFrameMode) = 0;
    virtual int32_t getCurrentFrameMode(BerxelHawkStreamType streamType, BerxelHawkStreamFrameMode* frameMode) = 0;
    virtual int32_t readColorFrame(BerxelHawkFrame* &pFrame,int32_t timeout = 30) = 0;
	virtual int32_t readDepthFrame(BerxelHawkFrame* &pFrame,int32_t timeout = 30) = 0;
	virtual int32_t readIrFrame(BerxelHawkFrame* &pFrame,int32_t timeout = 30) = 0;
	virtual int32_t readLightIrFrame( BerxelHawkFrame* &pSteamFrame,int32_t timeout = 30) = 0;
    virtual int32_t releaseFrame(BerxelHawkFrame* &pHawFrame) = 0;
    virtual int32_t startUpgrade(BerxelHawkUpgradeProcessCallBack pCallbacks, void* pUserData, const char* pFwFilePath) = 0;
	virtual int32_t convertDepthToPointCloud(BerxelHawkFrame* pFrame , float factor, BerxelHawkPoint3D* pPointClouds, bool bPointCloudWall = false) = 0;
	virtual int32_t getVersion(BerxelHawkVersions* versions) = 0;
	virtual int32_t getCurrentDeviceInfo(BerxelHawkDeviceInfo* pDeviceInfo) = 0;
	virtual int32_t getCameraIntriscParams(BerxelHawkCameraIntrinsic *pParams ) = 0;
	virtual int32_t getDeviceIntriscParams(BerxelHawkDeviceIntrinsicParams *pParams ) = 0;
	virtual int32_t setStreamMirror(bool bNeedMirror) = 0;
	virtual int32_t setRegistrationEnable(bool bEnable) = 0;
	virtual int32_t setFactoryBurnEnable(bool bEnable) = 0;
	virtual int32_t setTemperatureCompensationEnable(bool bEnable) = 0;
	virtual int32_t setFrameSync(bool bEnable) = 0;
	virtual int32_t setFillHoleStatus(bool bEnable) = 0;
	virtual int32_t setDenoiseStatus(bool bEnable) = 0;
	virtual int32_t setSystemClock() = 0;
	virtual int32_t getSystemClock(uint32_t *sec, uint32_t* usec) = 0;
	virtual int32_t setNetParams(void* pData, uint32_t dataSize) = 0;
	virtual int32_t getNetParams(void* pData, uint32_t needDataSize) = 0;
	virtual int32_t setTemperatureParams(void* pData, uint32_t dataSize) = 0;
	virtual int32_t getTemperatureParams(void* pData,  uint32_t *dataSize) = 0;
	virtual int32_t openNoiseFilter(bool bEnable) = 0;
	virtual int32_t setDepthCloseRangeDefaultGainAndExposure() = 0;
	virtual int32_t setEdgeOptimizationStatus(bool bEnable) = 0;
	virtual int32_t setDepthRemoteMode(bool bEnable) = 0;
	virtual int32_t getDeviceHighPrecisionTemperature(float* temperature) = 0;
	virtual int32_t getDeviceRxHighPrecisionTemperature(BerxelHawkDeviceTemperature* temperature) = 0;
	virtual int32_t getDeviceTemperature(int32_t* temperature) = 0;
	virtual int32_t setAdbMode(bool bOpen) = 0;
	virtual int32_t setSafetyMode(bool bOpen) = 0;
	virtual int32_t setSafetyDistance(uint32_t nDistance) = 0; 
	virtual int32_t getSafetyDistance(uint32_t* nDistance) = 0; 
	virtual int32_t setArParams(void* pData, uint32_t dataSize, uint32_t Offset) = 0;
	virtual int32_t setCameraIntrisc(void* pData, uint32_t dataSize, uint32_t Offset) = 0;
	virtual int32_t setFactoryBurnFirmwareHawk300(void* pData, uint32_t dataSize, uint32_t Offset) = 0;
	virtual int32_t setHawk300Groundtruth(void* pData, uint32_t dataSize, uint32_t Offset) = 0;
	virtual int32_t getArParams(void* pData, uint32_t needDataSize, uint32_t Offset) = 0;
	virtual int32_t getCameraIntrisc(void* pData, uint32_t dneeDataSize, uint32_t Offset) = 0;
	virtual int32_t resetUsb() = 0;
	virtual int32_t setChipDenoiseStatus(bool bEnable) = 0;
	virtual int32_t setSonixSerialNumber(void* pData, uint32_t dataSize) = 0;
	virtual int32_t getSonixSerialNumber(void* pData, uint32_t dataSize) = 0;
	virtual int32_t setColorExposureGain(uint32_t exposureTime, uint32_t gain) = 0;
	virtual int32_t getColorExposureGain(uint32_t* exposureTime, uint32_t* gain, uint8_t* aeStatus) = 0;
	virtual int32_t enableColorAutoExposure() = 0;
	virtual int32_t reconnectNetDevice() = 0;
	virtual int32_t setDepthElectricCurrent(uint32_t value) = 0;
	virtual int32_t getDepthElectricCurrent(uint32_t* value) = 0;
	virtual int32_t setDepthExposure(uint32_t value) = 0;
	virtual int32_t getDepthExposure(uint32_t* value) = 0;
	virtual int32_t setDepthGain(uint32_t value) = 0;
	virtual int32_t getDepthGain(uint32_t* value) = 0;
	virtual int32_t setDepthAEStatus(bool bEnable) = 0;
	virtual int32_t getDepthAEStatus(uint32_t* value) = 0;
	virtual int32_t enableDeviceSlaveMode(bool bEnable) = 0;
	virtual int32_t getDeviceMasterSlaveMode(uint32_t* value) = 0;
	virtual int32_t setColorQuality(uint32_t nValue) = 0;
	virtual int32_t getColorQuality(uint32_t* value) = 0;
	virtual int32_t setUserGpioCtrl(uint32_t gpio_nr, uint32_t gpio_number) = 0;
	virtual int32_t getUserGpioCtrl(uint32_t gpio_nr, uint32_t* gpio_number) = 0;
	virtual int32_t setCurveFilteringStatus(bool bEnable) = 0;
	virtual int32_t setDeviceBandwidth(BerxelHawkDeviceBandwidth bandwidth) = 0;
	virtual int32_t setStreamStatus(bool bEnable) = 0;
	virtual int32_t setBindCpuCore(uint32_t pData[], uint32_t nSize) = 0;
	virtual int32_t setDepthConfidence(uint32_t nValue) = 0;
	virtual int32_t getDepthConfidence(uint32_t* value) = 0;
	virtual int32_t enableHightFpsMode(bool bEnable) = 0;
	virtual int32_t setDepthTxStatus(bool bEnable) = 0;
	virtual int32_t setMaxDepthValue(uint32_t nValue) = 0;
	virtual int32_t setFilterGroundValue(BerxelHawkFilterRange range) = 0;
	virtual int32_t setTemperatureParamsFilePath(const char* filePath) = 0;
	virtual int32_t setDepthAEGainRange(uint32_t min, uint32_t max) = 0;
	virtual int32_t getDepthAEGainRange(uint32_t* min, uint32_t* max) = 0;
	virtual int32_t setDepthAEExposureRange(uint32_t min, uint32_t mid, uint32_t max) = 0;
	virtual int32_t getDepthAEExposureRange(uint32_t* min, uint32_t* mid, uint32_t* max) = 0;
	virtual int32_t getDeviceLogSize(uint32_t* size) = 0;
	virtual	int32_t getDeviceLog(void* pData, uint32_t dataSize) = 0;
	virtual int32_t setDevHwThremalStatus(bool bEnable) = 0;
	virtual int32_t getDevHwThremalStatus(uint32_t* value) = 0;
	virtual int32_t setDeviceTransferMode(BerxelHawkUVCMode mode) = 0;
	virtual int32_t setTemporalDenoiseStatus(bool bEnable) = 0;
	virtual int32_t setSpatialDenoiseStatus(bool bEnable) = 0;
	virtual int32_t setSyncHostTime(BerxelHawkSyncTimeType type) = 0;
	virtual int32_t rebootDevice() = 0;
	virtual bool	deviceSupportHwTempCompenSation() = 0;
	virtual int32_t setDevHwAutoTemCtrlStatus(bool bEnable) = 0;
	virtual int32_t getDevHwAutoTemCtrlStatus(uint32_t* value) = 0;
	virtual int32_t enableDecodeColorData(bool bEnable) = 0;

	virtual int32_t setDeviceWatchDogStatus(bool bEnable) = 0;
	virtual int32_t getDeviceWatchDogStatus(uint32_t* nValue) = 0;
	virtual int32_t setDeviceDepthGTFlash() = 0;
	virtual int32_t getDeviceDepthGTFlash(uint32_t* nValue) = 0;
	virtual int32_t setDeviceCDCStatus(bool bEnable) = 0;
	virtual int32_t getDeviceCDCStatus(uint32_t* nValue) = 0;
	virtual int32_t transparentTransmission(uint8_t* pSend, uint32_t nSendSize, uint8_t* pRecv, uint32_t* nRecvSize) = 0;
	virtual int32_t getChipType(BerxelHawkChipType& type) = 0;
	virtual int32_t setDepthOptimizationStatus(bool bOptimizeX, bool  bOptimizeY, bool bOptimizeAccuracy) = 0;
	virtual int32_t setPlaneFilterStatus(bool bEnable) = 0;
	virtual int32_t setFrameDropValue(uint32_t nValue) = 0;
	virtual int32_t enableRgbTimeStamp(bool bEnable) = 0;
	virtual int32_t setSyncMode(uint8_t nValue) = 0;
	virtual int32_t getSyncMode(uint8_t* nValue) = 0;

	virtual int32_t setRGBAEBoundary(uint32_t nId, uint32_t minValue, uint32_t maxValue) = 0;
	virtual int32_t getRGBAEBoundary(uint32_t nId, uint32_t* minValue, uint32_t* maxValue) = 0;
	virtual int32_t setRGBGainBoundary(uint32_t nId, uint32_t minValue, uint32_t maxValue) = 0;
	virtual int32_t getRGBGainBoundary(uint32_t nId, uint32_t* minValue, uint32_t* maxValue) = 0;

	virtual int32_t setSonixSlaveStatus(bool bEnable) = 0;
	virtual int32_t setSonixAEStatus(bool bEnable) = 0;
	virtual int32_t getSonixAEStatus(uint8_t* value) = 0;

	virtual int32_t setSonixExposureTime(uint32_t value) = 0;
	virtual int32_t getSonixExposureTime(uint32_t* value) = 0;

	virtual int32_t setSonixGain(uint8_t value) = 0;
	virtual int32_t getSonixGain(uint8_t* value) = 0;
	virtual int32_t SetRgbDistortionCorrectionStatus(bool bEnable) = 0;

	virtual int32_t setExternalTriggerSignalForward(uint8_t nStatus, uint8_t nFps, uint8_t nType) = 0;

	virtual int32_t getFlashRomcodeParams(void* pData, uint32_t nAddr, uint32_t nDataSize) = 0;

	virtual int32_t setHV3LSyncOutStatus(uint8_t nFlag, uint8_t nStatus, uint16_t nTime) = 0;
	virtual int32_t getHV3LSyncOutStatus(uint8_t nFlag, uint8_t* nStatus, uint16_t* nTime) = 0;

	virtual int32_t setExternalTriggerMode(uint8_t nType) = 0;

	virtual int32_t getTriggerMode(uint8_t* nType) = 0;

	//-----------------debug------------------
	virtual int32_t setNCCThreshold(uint8_t nValue) = 0;
	virtual int32_t getNCCThreshold(uint8_t* nValue) = 0;
	virtual int32_t setPatchSize(uint8_t nValue) = 0;
	virtual int32_t getPatchSize(uint8_t* nValue) = 0;
	virtual int32_t setQutlierRemoval(uint8_t nValue) = 0;
	virtual int32_t getQutlierRemoval(uint8_t* nValue) = 0;
	virtual int32_t setDisplayDenoise(uint8_t nValue) = 0;
	virtual int32_t getDisplayDenoise(uint8_t* nValue) = 0;
	virtual int32_t setDisplayDenoiseLevel(uint8_t nValue) = 0;
	virtual int32_t getDisplayDenoiseLevel(uint8_t* nValue) = 0;
	virtual int32_t setDisplayDenoiseThreshold(uint8_t nValue) = 0;
	virtual int32_t getDisplayDenoiseThreshold(uint8_t* nValue) = 0;
	virtual int32_t setMedianFilter(uint8_t nValue) = 0;
	virtual int32_t getMedianFilter(uint8_t* nValue) = 0;
	virtual int32_t setMedianFilterKernelSize(uint8_t nValue) = 0;
	virtual int32_t getMedianFilterKernelSize(uint8_t* nValue) = 0;
	virtual int32_t setMedianFilterValidPixelThreshold(uint8_t nValue) = 0;
	virtual int32_t getMedianFilterValidPixelThreshold(uint8_t* nValue) = 0;
	virtual int32_t setMedianFilterSameDisparityThreshold(uint8_t nValue) = 0;
	virtual int32_t getMedianFilterSameDisparityThreshold(uint8_t* nValue) = 0;
	virtual int32_t setConfigParams(void* pData, uint32_t dataSize, uint32_t Offset, BerxelHawkWriteFlashProcessCallback pCallback = NULL, void* pUser = NULL) = 0;
	virtual int32_t getConfigParams(void* pData, uint32_t dataSize, uint32_t Offset, BerxelHawkWriteFlashProcessCallback pCallback = NULL, void* pUser = NULL) = 0;
	virtual int32_t setCustomizeUSBDescriptor(void* pData, uint32_t dataSize) = 0;
	virtual int32_t setCustomizeDefaultValue(void* pData, uint32_t dataSize) = 0;
	virtual int32_t setHV3LGroundtruth(void* pData, uint32_t dataSize) = 0;
	virtual int32_t setHV3LSerialNumber(void* pData, uint32_t dataSize) = 0;
	virtual int32_t setHV3L2DFmean(uint32_t nFmean, uint32_t nBoundary) = 0;
	virtual int32_t getHV3L2DTargetFmean(uint32_t* nFmean, uint32_t* nBoundary) = 0;
	virtual int32_t getHV3L2DCurrentFmean(uint32_t* nFmean) = 0;
	virtual int32_t setHV3L2DGainRange(uint32_t minValue, uint32_t maxValue) = 0;
	virtual int32_t getHV3L2DGainRange(uint32_t* minValue, uint32_t* maxValue) = 0;
	virtual int32_t getHV3L2DAGain(uint32_t* nValue) = 0;
	virtual int32_t setHV3L2DAEExposureTimeRange(uint32_t minValue, uint32_t midValue, uint32_t maxValue) = 0;
	virtual int32_t getHV3L2DAEExposureTimeRange(uint32_t* minValue, uint32_t* midValue, uint32_t* maxValue) = 0;
	virtual int32_t getHV3L2DExposureTime(uint32_t* nValue) = 0;
	virtual int32_t setHV3L3DFmean(uint32_t nFmean, uint32_t nBoundary) = 0;
	virtual int32_t getHV3L3DTargetFmean(uint32_t* nFmean, uint32_t* nBoundary) = 0;
	virtual int32_t getHV3L3DCurrentFmean(uint32_t* nFmean) = 0;
	virtual int32_t setHV3L3DGainRange(uint32_t minValue, uint32_t maxValue) = 0;
	virtual int32_t getHV3L3DGainRange(uint32_t* minValue, uint32_t* maxValue) = 0;
	virtual int32_t getHV3L3DAGain(uint32_t* nValue) = 0;
	virtual int32_t setHV3L3DAEExposureTimeRange(uint32_t minValue, uint32_t midValue, uint32_t maxValue) = 0;
	virtual int32_t getHV3L3DAEExposureTimeRange(uint32_t* minValue, uint32_t* midValue, uint32_t* maxValue) = 0;
	virtual int32_t getHV3L3DExposureTime(uint32_t* nValue) = 0;
	virtual int32_t setHV3LTXTCAutoDetection(bool bStatus) = 0;
	virtual int32_t getHV3LTXTCAutoDetection(uint8_t* nValue) = 0;
	virtual int32_t setHV3LTXTCTemperature(uint8_t nValue) = 0;
	virtual int32_t getHV3LTXTCTemperature(uint8_t* nValue) = 0;
	virtual int32_t setHV3LTXTCStatus(bool bStatus) = 0;
	virtual int32_t getHV3LADCValue(uint16_t* nValue) = 0;

	virtual int32_t setTofAEFmean(uint16_t nFmean, uint8_t nBoundary) = 0;
	virtual int32_t getTofAETargetFmean(uint16_t* nFmean, uint8_t* nBoundary) = 0;
	virtual int32_t setTofAEConversionStep(uint8_t nKp) = 0;
	virtual int32_t getTofAEConversionStep(uint8_t* nKnp) = 0;
	virtual int32_t setTofAEExposureTimeRange(uint16_t minValue, uint16_t midValue, uint16_t maxValue) = 0;
	virtual int32_t getTofAEExposureTimeRange(uint16_t* minValue, uint16_t* midValue, uint16_t* maxValue) = 0;
	virtual int32_t setTofAERegionOfInterestSetting(uint16_t nROIX_MIN, uint16_t nROIX_MAX, uint16_t nROIY_MIN, uint16_t nROIY_MAX) = 0;
	virtual int32_t getTofAERegionOfInterestSetting(uint16_t* nROIX_MIN, uint16_t* nROIX_MAX, uint16_t* nROIY_MIN, uint16_t* nROIY_MAX) = 0;
	virtual int32_t setTofExposureTimeFrequency0(uint16_t nExposureTime) = 0;
	virtual int32_t getTofExposureTimeFrequency0(uint16_t* nExposureTime) = 0;
	virtual int32_t setTofExposureTimeFrequency1(uint16_t nExposureTime) = 0;
	virtual int32_t getTofExposureTimeFrequency1(uint16_t* nExposureTime) = 0;
	virtual int32_t setTofPostProcessingStatus(uint8_t nStatus) = 0;
	virtual int32_t getTofPostProcessingStatus(uint8_t* nStatus) = 0;
	virtual int32_t setTofFlyingPixelRemovalStatus(uint8_t nStatus) = 0;
	virtual int32_t getTofFlyingPixelRemovalStatus(uint8_t* nStatus) = 0;
	virtual int32_t setTofKernelRadiusFlyingPixelRemoval(uint8_t nStatus) = 0;
	virtual int32_t getTofKernelRadiusFlyingPixelRemoval(uint8_t* nStatus) = 0;
	virtual int32_t setTofStandardDeviationMultiplierFlyingPixelRemoval(uint8_t nValue) = 0;
	virtual int32_t getTofStandardDeviationMultiplierFlyingPixelRemoval(uint8_t* nValue) = 0;
	virtual int32_t setTofStandardDeviationThresholdForFlyingPixelRemoval(uint8_t nValue) = 0;
	virtual int32_t getTofStandardDeviationThresholdForFlyingPixelRemoval(uint8_t* nValue) = 0;
	virtual int32_t setTofBilateralFilterStatus(uint8_t nStatus) = 0;
	virtual int32_t getTofBilateralFilterStatus(uint8_t* nStatus) = 0;
	virtual int32_t setTofWidthOfSmoothingKernelForBilateralFilter(uint8_t nValue) = 0;
	virtual int32_t getTofWidthOfSmoothingKernelForBilateralFilter(uint8_t* nValue) = 0;
	virtual int32_t setTofRangeFilterSettingForBilateralFilter(uint8_t nValue) = 0;
	virtual int32_t getTofRangeFilterSettingForBilateralFilter(uint8_t* nValue) = 0;
	virtual int32_t setTofKalmanFilterStatus(uint8_t nStatus) = 0;
	virtual int32_t getTofKalmanFilterStatus(uint8_t* nStatus) = 0;
	virtual int32_t setTofResetThresholdForKalmanFilter(uint16_t nValue) = 0;
	virtual int32_t getTofResetThresholdForKalmanFilter(uint16_t* nValue) = 0;
	virtual int32_t setTofWeightingForKalmanFilter(uint8_t nValue) = 0;
	virtual int32_t getTofWeightingForKalmanFilter(uint8_t* nValue) = 0;
	virtual int32_t berxelRestKalmanFilter() = 0;
	virtual int32_t setTofMedianFilterStatus(uint8_t nValue) = 0;
	virtual int32_t getTofMedianFilterStatus(uint8_t* nValue) = 0;
	virtual int32_t setTofMedianFilterKernelSize(uint8_t nValue) = 0;
	virtual int32_t getTofMedianFilterKernelSize(uint8_t* nValue) = 0;
	virtual int32_t setTofRangeDependenceConfidenceThresholdStatus(uint8_t nValue) = 0;
	virtual int32_t getTofRangeDependenceConfidenceThresholdStatus(uint8_t* nValue) = 0;
	virtual int32_t setTofDeAmbiguousStatus(uint8_t nValue) = 0;
	virtual int32_t setTofSingleFrequencyModulationStatus(uint8_t nValue) = 0;
	virtual int32_t getTofSingleFrequencyModulationStatus(uint8_t* nValue) = 0;
	virtual int32_t setTofPostProcessingScheme(uint8_t nValue) = 0;
	virtual int32_t getTofPostProcessingScheme(uint8_t* nValue) = 0;
	virtual int32_t setTofPictureQualityMode(uint8_t nValue) = 0;
	virtual int32_t setTofImageUndistortionStatus(uint8_t nValue) = 0;
	virtual int32_t getTofImageUndistortionStatus(uint8_t* nValue) = 0;
	virtual int32_t setTofFixPhasePatternNoiseStatus(uint8_t nValue) = 0;
	virtual int32_t getTofFixPhasePatternNoiseStatus(uint8_t* nValue) = 0;
	virtual int32_t setTofWigglingStatus(uint8_t nValue) = 0;
	virtual int32_t getTofWigglingStatus(uint8_t* nValue) = 0;
	virtual int32_t setTofRangetoDepthStatus(uint8_t nValue) = 0;
	virtual int32_t getTofRangetoDepthStatus(uint8_t* nValue) = 0;
	virtual int32_t setTofFrequency0MinimumConfidenceThreshold(uint16_t nValue) = 0;
	virtual int32_t getTofFrequency0MinimumConfidenceThreshold(uint16_t* nValue) = 0;
	virtual int32_t setTofFrequency0MaximumConfidenceThreshold(uint16_t nValue) = 0;
	virtual int32_t getTofFrequency0MaximumConfidenceThreshold(uint16_t* nValue) = 0;
	virtual int32_t setTofFrequency1MinimumConfidenceThreshold(uint16_t nValue) = 0;
	virtual int32_t getTofFrequency1MinimumConfidenceThreshold(uint16_t* nValue) = 0;
	virtual int32_t setTofFrequency1MaximumConfidenceThreshold(uint16_t nValue) = 0;
	virtual int32_t getTofFrequency1MaximumConfidenceThreshold(uint16_t* nValue) = 0;

	virtual int32_t setITofLTC1706Voltge(float fVoltage) = 0;
	virtual int32_t getITofLTC1706Voltge(float* fVoltage) = 0;
	virtual int32_t setITofEnterDownloadMode() = 0;

	virtual int32_t setNetUdpPort(uint16_t nPort) = 0;

};

}

#endif

#ifndef __BERXEL_CONTEXT_H__
#define __BERXEL_CONTEXT_H__

#include <BerxelHawkPlatform.h>
#include <BerxelHawkDefines.h>


namespace berxel
{

class BerxelHawkDevice;

class BERXEL_HAWK_API_EXPORT BerxelHawkContext
{
public:
    BerxelHawkContext();
    static BerxelHawkContext* getBerxelContext();
	static BerxelHawkContext* getBerxelContext(const char* strLogPath);
    static void destroyBerxelContext(BerxelHawkContext* &pBerxelContext);
public:
    virtual int32_t getDeviceList(BerxelHawkDeviceInfo** pDeviceList, uint32_t* pDeviceCount) = 0;
    virtual int32_t getDeviceList(BerxelHawkGmslDeviceInfo** pDeviceInfoList, uint32_t* pDeviceCount) = 0;
    virtual BerxelHawkDevice* openDevice(const BerxelHawkDeviceInfo deviceInfo) = 0;
	virtual BerxelHawkDevice* openDeviceByFd(uint32_t vid, uint32_t pid, uint32_t fd, const char* pUsbFilePath) = 0;
    virtual BerxelHawkDevice* openDevice(const BerxelHawkGmslDeviceInfo deviceInfo) = 0;
    virtual int32_t closeDevice(BerxelHawkDevice* hawkDevice) = 0;
    virtual int32_t setDeviceStateCallback(BerxelHawkDeviceStatusChangeCallback callback, void* pData) = 0;
	virtual int32_t setLogLevel(uint32_t level) = 0;
    virtual int32_t setGmslI2CStats(bool bEnable) = 0;
	virtual int32_t setGmslI2CAddress(const char* strI2CAddress) = 0;
    virtual int32_t setDeserializerCSIOutStatus(bool bStatus) = 0;
    virtual int32_t setTSCForwardStatus(bool bStatus, uint8_t frame_sync_gpio) = 0;
	// virtual int32_t set_deserializer_setup_framesync_internal_trigger() = 0;
	// virtual int32_t set_deserializer_setup_framesync_external_trigger_mfpx(uint8_t frame_sync_gpio) = 0;
    virtual int32_t setDeserializerTriggerMode(bool bEnable, uint8_t nTriggerMode, uint8_t frame_sync_gpio) = 0;
protected:
    virtual ~BerxelHawkContext();
};

}

#endif

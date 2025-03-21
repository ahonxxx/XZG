#ifndef ETC_H
#define ETC_H

#include <Arduino.h>

#include <ETH.h>
#include "const/hw.h"

void getReadableTime(String &readableTime, unsigned long beginTime);

String sha1(String payloadStr);

int check1wire();
void setup1wire(int pin);
float get1wire();

extern BrdConfigStruct brdConfigs[BOARD_CFG_CNT];

ThisConfigStruct *findBrdConfig(int searchId);

float getCPUtemp(bool clear = false);

void zigbeeRouterRejoin();
void zigbeeEnableBSL();
void zigbeeRestart();

void usbModeSet(usbMode mode);

void writeDefaultDeviceId(char *arr, bool ethernet);
//void writeDefaultConfig(const char *path, DynamicJsonDocument &doc);

#define TIMEOUT_FACTORY_RESET 3

void factoryReset();

void setLedsDisable(bool all = false);
void cronTest();
void nmActivate();
//bool checkDNS(bool setup = false);
void setupCron();

void setClock(void *pvParameters);
void setTimezone(String timezone);
const char *getGmtOffsetForZone(const char *zone);
char *convertTimeToCron(const String &time);

void wgBegin();
void wgLoop();

void hnBegin();

void ledTask(void *parameter);
String getTime();

void checkUpdateAvail();

bool isIpInSubnet(IPAddress ip, IPAddress subnet, IPAddress subnetMask);
bool isValidIp(IPAddress ip);
String getHostFromUrl(const String& url);
String getRadioRoleKey();
String removeLeadingZeros(const String& block);
String getShortenedIPv6(const String& ipv6);
void restartDevice();
void freeHeapPrint();
bool dnsLookup(const String &url);
void firstUpdCheck();

struct FirmwareInfo {
    String url;
    String version;
    String sha;
};

#endif // ETC_H

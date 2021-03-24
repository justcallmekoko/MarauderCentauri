#ifndef WiFiScan_h
#define WiFiScan_h

//#include <BLEDevice.h>
//#include <BLEUtils.h>
//#include <BLEScan.h>
//#include <BLEAdvertisedDevice.h>
#include <ArduinoJson.h>

// Testing NimBLE
#include <NimBLEDevice.h>
#include <NimBLEAdvertisedDevice.h>

#include <WiFi.h>
#include <math.h>
#include "esp_wifi.h"
#include "esp_wifi_types.h"
#include "esp_bt.h"
#include "Display.h"
#include "SDInterface.h"
#include "Buffer.h"
#include "BatteryInterface.h"
#include "TemperatureInterface.h"
#include "Assets.h"
//#include "MenuFunctions.h"

#define bad_list_length 3

#define OTA_UPDATE 100
#define SHOW_INFO 101
#define ESP_UPDATE 102
#define WIFI_SCAN_OFF 0
#define WIFI_SCAN_PROBE 1
#define WIFI_SCAN_AP 2
#define WIFI_SCAN_PWN 3
#define WIFI_SCAN_EAPOL 4
#define WIFI_SCAN_DEAUTH 5
#define WIFI_SCAN_ALL 6
#define WIFI_PACKET_MONITOR 7
#define WIFI_ATTACK_BEACON_SPAM 8
#define WIFI_ATTACK_RICK_ROLL 9
#define BT_SCAN_ALL 10
#define BT_SCAN_SKIMMERS 11
#define WIFI_SCAN_ESPRESSIF 12
#define LV_JOIN_WIFI 13
#define LV_ADD_SSID 14
#define WIFI_ATTACK_BEACON_LIST 15

#define GRAPH_REFRESH 100

#define MAX_CHANNEL 14

extern Display display_obj;
extern SDInterface sd_obj;
extern Buffer buffer_obj;
extern BatteryInterface battery_obj;
extern TemperatureInterface temp_obj;

esp_err_t esp_wifi_80211_tx(wifi_interface_t ifx, const void *buffer, int len, bool en_sys_seq);

struct ssid {
  String essid;
  int bssid[6];
};

class WiFiScan
{
  private:
    int x_pos; //position along the graph x axis
    float y_pos_x; //current graph y axis position of X value
    float y_pos_x_old = 120; //old y axis position of X value
    float y_pos_y; //current graph y axis position of Y value
    float y_pos_y_old = 120; //old y axis position of Y value
    float y_pos_z; //current graph y axis position of Z value
    float y_pos_z_old = 120; //old y axis position of Z value
    int midway = 0;
    byte x_scale = 1; //scale of graph x axis, controlled by touchscreen buttons
    byte y_scale = 1;

    bool do_break = false;

    //int num_beacon = 0; // GREEN
    //int num_probe = 0; // BLUE
    //int num_deauth = 0; // RED

    uint32_t initTime = 0;
    bool run_setup = true;
    int bluetoothScanTime = 5;
    int packets_sent = 0;
    const wifi_promiscuous_filter_t filt = {.filter_mask=WIFI_PROMIS_FILTER_MASK_MGMT | WIFI_PROMIS_FILTER_MASK_DATA};
    BLEScan* pBLEScan;

    //String connected_network = "";
    String alfa = "1234567890qwertyuiopasdfghjkklzxcvbnm QWERTYUIOPASDFGHJKLZXCVBNM_";

    char* rick_roll[8] = {
      "01 Never gonna give you up",
      "02 Never gonna let you down",
      "03 Never gonna run around",
      "04 and desert you",
      "05 Never gonna make you cry",
      "06 Never gonna say goodbye",
      "07 Never gonna tell a lie",
      "08 and hurt you"
    };

    char* prefix = "G";

    typedef struct
    {
      int16_t fctl;
      int16_t duration;
      uint8_t da;
      uint8_t sa;
      uint8_t bssid;
      int16_t seqctl;
      unsigned char payload[];
    } __attribute__((packed)) WifiMgmtHdr;
    
    typedef struct {
      WifiMgmtHdr hdr;
      uint8_t payload[0];
    } wifi_ieee80211_packet_t;

    // barebones packet
    uint8_t packet[128] = { 0x80, 0x00, 0x00, 0x00, //Frame Control, Duration
                    /*4*/   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //Destination address 
                    /*10*/  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, //Source address - overwritten later
                    /*16*/  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, //BSSID - overwritten to the same as the source address
                    /*22*/  0xc0, 0x6c, //Seq-ctl
                    /*24*/  0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, //timestamp - the number of microseconds the AP has been active
                    /*32*/  0x64, 0x00, //Beacon interval
                    /*34*/  0x01, 0x04, //Capability info
                    /* SSID */
                    /*36*/  0x00
                    };

    void packetMonitorMain(uint32_t currentTime);
    void eapolMonitorMain(uint32_t currentTime);
    void changeChannel();
    void updateMidway();
    void tftDrawXScalButtons();
    void tftDrawYScaleButtons();
    void tftDrawChannelScaleButtons();
    void tftDrawColorKey();
    void tftDrawGraphObjects();
    void broadcastRandomSSID(uint32_t currentTime);
    void broadcastCustomBeacon(uint32_t current_time, ssid custom_ssid);
    void broadcastSetSSID(uint32_t current_time, char* ESSID);
    void RunRickRoll(uint8_t scan_mode, uint16_t color);
    void RunBeaconSpam(uint8_t scan_mode, uint16_t color);
    void RunBeaconList(uint8_t scan_mode, uint16_t color);
    void RunEspressifScan(uint8_t scan_mode, uint16_t color);
    void RunPwnScan(uint8_t scan_mode, uint16_t color);
    void RunBeaconScan(uint8_t scan_mode, uint16_t color);
    void RunDeauthScan(uint8_t scan_mode, uint16_t color);
    void RunEapolScan(uint8_t scan_mode, uint16_t color);
    void RunProbeScan(uint8_t scan_mode, uint16_t color);
    void RunPacketMonitor(uint8_t scan_mode, uint16_t color);
    void RunBluetoothScan(uint8_t scan_mode, uint16_t color);
    void RunLvJoinWiFi(uint8_t scan_mode, uint16_t color);
    static void scanCompleteCB(BLEScanResults scanResults);

  public:
    WiFiScan();

    //LinkedList<ssid>* ssids;

    int set_channel = 1;

    int old_channel = 0;

    bool orient_display = false;
    bool wifi_initialized = false;
    bool ble_initialized = false;

    String free_ram = "";
    String old_free_ram = "";
    String connected_network = "";

    //lv_obj_t * scr = lv_cont_create(NULL, NULL);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();    

    void RunSetup();
    int clearSSIDs();
    bool addSSID(String essid);
    int generateSSIDs();
    bool shutdownWiFi();
    bool shutdownBLE();
    void joinWiFi(String ssid, String password);
    String getStaMAC();
    String getApMAC();
    String freeRAM();
    void RunInfo();
    void RunShutdownWiFi();
    void RunShutdownBLE();
    void RunGenerateSSIDs();
    void RunClearSSIDs();
    void channelHop();
    uint8_t currentScanMode = 0;
    void main(uint32_t currentTime);
    void StartScan(uint8_t scan_mode, uint16_t color = 0);
    void StopScan(uint8_t scan_mode);
    
    static void getMAC(char *addr, uint8_t* data, uint16_t offset);
    static void espressifSnifferCallback(void* buf, wifi_promiscuous_pkt_type_t type);
    static void pwnSnifferCallback(void* buf, wifi_promiscuous_pkt_type_t type);
    static void beaconSnifferCallback(void* buf, wifi_promiscuous_pkt_type_t type);
    static void deauthSnifferCallback(void* buf, wifi_promiscuous_pkt_type_t type);
    static void probeSnifferCallback(void* buf, wifi_promiscuous_pkt_type_t type);
    static void beaconListSnifferCallback(void* buf, wifi_promiscuous_pkt_type_t type);
    static void eapolSnifferCallback(void* buf, wifi_promiscuous_pkt_type_t type);
    static void wifiSnifferCallback(void* buf, wifi_promiscuous_pkt_type_t type);
};
#endif
